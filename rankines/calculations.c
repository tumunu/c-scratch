#include <stdio.h>
#include <math.h> // add -l flag
#include "calculations.h"

#define M_PI 3.14159265358979323846

// TODO: live loading, wind/earthquake loading
// TODO: seismic hazzard factor z to NZS 1170.5

// convert mass density (kg/m2) to weight density (kN/m2)
static float convert_mass_to_weight(struct calculations *this, int mass)
{
    float weight;
    float gravitational_acceleration = 9.81; // meters per second square

    weight = mass * gravitational_acceleration;

    return weight;
}

// Pbu = Ab(Fb + P0)
// Ab = area at the base of the pile
// Fb = net ultimate resistence per unit area of the base
//    = Nq * SigmaV
//    = ____ * (uni weight * depth)
// P0 = overburden area at the level of the base
static float calculate_base_reistence(struct calculations *this)
{
    float pbu, ab, fb, p0;

    pbu = ab * (fb + p0);
    return pbu;
}

// need to convert degrees into radians !!!
static float calculate_degrees_radians(struct calculations *this, float degree){
    float result = (degree / 180.0) * ((double)M_PI);

    return result;
}

static float calculate_with_theta(struct calculations *this, float theta)
{
    float formula, sine_theta, minus_sine, plus_sine;
    sine_theta = sin(calculate_degrees_radians(this, theta));
    minus_sine = 1 - sine_theta;
    plus_sine = 1 + sine_theta;

    formula = minus_sine / plus_sine;

    printf("formula: %f\n\n", formula);
    printf("theta: %f\n\n", theta);
    printf("sine theta: %f\n\n", sine_theta);
    printf("sine minus: %f\n\n", minus_sine);
    printf("sine plus: %f\n\n", plus_sine);

    return formula;
}

//
static float calculate_rankines_formula(struct calculations *this, float theta, float p, float w)
{
    float d, sine_result;
    sine_result = calculate_with_theta(this, theta);
    d = (p / w) * pow(sine_result, 2);

    printf("rankine's result: %f\n\n", d); // 0.82
    return d;
}

static struct calculations new (void)
{
    return (struct calculations){
        .convert_mass_to_weight=&convert_mass_to_weight,
        .calculate_base_reistence=&calculate_base_reistence,
        .calculate_degrees_radians=&calculate_degrees_radians,
        .calculate_with_theta=&calculate_with_theta,
        .calculate_rankines_formula=&calculate_rankines_formula
    };
}

const struct calculations_class calculations = {.new = &new};