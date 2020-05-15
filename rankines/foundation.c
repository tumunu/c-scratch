#include <stdio.h>

// TODO: use header / classes/ etcetera

void splash()
{

    printf("Minimum depth of foundation:\n\n");

    printf("D = p/w*((1-sin(theta)/1+sin(theta))*2)\n\n");
    printf("D = depth of foundation\n");
    printf("P = total load of the foundation/load of the structure\n");
    printf("W = unit of weight of soil/density of soil\n");
    printf("theta = angle of repose/internal friction of soil\n\n");

    printf("NOTE: theta = a/c or hypotenuse/height\n\n");
}

// basic bearing capacities
typedef struct bearing_capcity
{
    char soil[40];
    int kg_per_metre_square;
    int kn_per_metre_square;
} bearing_capcity;

bearing_capcity capacities[14];

void populate_capacities()
{
    capacities[0] = (bearing_capcity){"soft, wet clay or muddy clay", 5000, 50};
    capacities[1] = (bearing_capcity){"soft clay", 10000, 100};
    capacities[2] = (bearing_capcity){"fine, loose and dry sand", 10000, 100};
    capacities[3] = (bearing_capcity){"black cotton soil", 15000, 150};
    capacities[4] = (bearing_capcity){"moist clay, and sand/clay mixuture", 15000, 150};
    capacities[5] = (bearing_capcity){"loose gravel", 25000, 250};
    capacities[6] = (bearing_capcity){"medium clay", 25000, 250};
    capacities[7] = (bearing_capcity){"medium, compact, and dry clay", 25000, 250};
    capacities[8] = (bearing_capcity){"compact clay", 45000, 450};
    capacities[9] = (bearing_capcity){"compact sand", 45000, 450};
    capacities[10] = (bearing_capcity){"compact gravel", 45000, 450};
    capacities[11] = (bearing_capcity){"soft rocks", 45000, 450};
    capacities[12] = (bearing_capcity){"laminated rock (sandstone & limestone)", 165000, 1650};
    capacities[13] = (bearing_capcity){"hard rocks (granite, diorite, trap)", 330000, 3300};
}

// dead loading
typedef struct dead_loading
{
    char type[40];
    int kg_per_metre_square_max;
    char eg[200];
} dead_loading;

dead_loading dead_loads[6];

void populate_dead_loading(){
    dead_loads[0] = (dead_loading){"light external walls", 60, "timber framing with weather boards, and interior wall linings"};
    dead_loads[1] = (dead_loading){"heavy external walls", 290, "timber framing with masonary veneer, or partially filled 20 series masonary blocks"};
    dead_loads[2] = (dead_loading){"internal walls", 45, "timber framing, and interior wall linings"};
    dead_loads[3] = (dead_loading){"light roofs", 45, "ceiling linings, and metal roof, including framing"};
    dead_loads[4] = (dead_loading){"heavy roofs", 85, "ceiling linings, and concrete tiles, or slates, including framing"};
    dead_loads[5] = (dead_loading){"mid-floors", 60, "timber frsming, and flooring, including ceiling linings"};
}

// penetrometer blows
typedef struct penetrometer_blows
{
    int ultimate_bearing_capacity_kpa;
    int min_blows_per_300mm_depth;
} penetrometer_blows;

penetrometer_blows blows[6];

void populate_penetrometer_blows() {
    blows[0] = (penetrometer_blows) {140, 4};
    blows[1] = (penetrometer_blows) {175, 5};
    blows[2] = (penetrometer_blows) {210, 6};
    blows[3] = (penetrometer_blows) {240, 7};
    blows[4] = (penetrometer_blows) {275, 8};
    blows[5] = (penetrometer_blows) {999, 9}; // TODO: good ground
}

// TODO: seismic hazzard factor z to NZS 1170.5


int main()
{
    splash();
    populate_capacities();
    populate_dead_loading();
    populate_penetrometer_blows();

    // tests
    for (int i = 0; i < 14; ++i)
    {
        printf("%s\n", capacities[i].soil);
    }
        for (int i = 0; i < 6; ++i)
    {
        printf("%i\n", dead_loads[i].kg_per_metre_square_max);
    }

    return 0;
}