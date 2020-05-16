#include <stdio.h>
#include "calculations.h"

void splash()
{
    printf("Minimum depth of foundation:\n\n");

    printf("D = p/w*((1-sin(theta)/1+sin(theta))*2)\n\n");
    printf("D = depth of foundation\n");
    printf("P = total load of the foundation/load of the structure (kN/m2)\n");
    printf("W = unit of weight of soil/density of soil (kN/m3)\n");
    printf("theta = angle of repose/internal friction of soil (in degrees)\n\n");

    printf("NOTE: theta = a/c or hypotenuse/height\n\n");
}


int main()
{
    splash();

    struct calculations c = calculations.new();

    // populate_capacities();
    // populate_dead_loading();
    // populate_penetrometer_blows();
    // populate_ground_conditions();
    // populate_cohesive_soils();
    // populate_site_subsoils();

    float theta, p, w;
    // average colluvium ~ 30 to 37
    theta = 33.5;
    p = 25;
    w = 18;

    // Calculate the minimum depth required for a foundation to transmit a pressure 
    // 55 kN/m2 in a cohesionless soil having density 16 kN/m3 and angle of repose 200?
    // expected result: 0.892m, calculated result: 0.826323
    // theta=20;
    // p=55;
    // w=16;

    c.calculate_rankines_formula(&c, theta, p, w);

    return 0;
}