#include <stdio.h>

// instance
struct calculations
{
    float (*convert_mass_to_weight)(struct calculations *this, int mass);
    float (*calculate_base_reistence)(struct calculations *this);
    float (*calculate_rankines_formula)(struct calculations *this, float theta, float p, float w);
    float (*calculate_degrees_radians)(struct calculations *this, float degree);
    float (*calculate_with_theta)(struct calculations *this, float theta);
};

// object
extern const struct calculations_class
{
    struct calculations (*new)(void);
} calculations;