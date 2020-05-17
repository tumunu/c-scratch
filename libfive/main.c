#include <libfive.h>
#include <stdio.h>
#include <unistd.h>
#include "viewer.h"

const int square = 7;
const int add = 17;
const int sub = 21;
const int root = 8;
const int max = 20;

#define op1(op, x) libfive_tree_unary((op), (x))
#define op2(op, x, y) libfive_tree_binary((op), (x), (y))

libfive_tree sphere(float r)
{
    libfive_tree x = libfive_tree_x();
    libfive_tree y = libfive_tree_y();
    libfive_tree z = libfive_tree_z();

    libfive_tree r_t = libfive_tree_const(r);

    libfive_tree square_x = op1(square, x);
    libfive_tree square_y = op1(square, y);
    libfive_tree square_z = op1(square, z);

    /* sqrt(x^2 + y^2 + z^2) - r */
    return op2(sub,
               op1(root,
                   op2(add,
                       op2(add, square_x, square_y),
                       square_z)),
               r_t);
}

libfive_tree circle(float r)
{
    libfive_tree x = libfive_tree_x();
    libfive_tree y = libfive_tree_y();

    libfive_tree square_x = op1(square, x);
    libfive_tree square_y = op1(square, y);
    libfive_tree r_t = libfive_tree_const(r);

    /* sqrt(x^2 + y^2) - r */
    return op2(sub,
               op1(root,
                   op2(add, square_x, square_y)),
               r_t);
}

libfive_tree cylinder(float r, float zmin, float zmax)
{
    libfive_tree z = libfive_tree_z();

    libfive_tree s = sphere(r);
    libfive_tree c = circle(r);
    libfive_tree r_t = libfive_tree_const(r);
    libfive_tree zmin_t = libfive_tree_const(zmin);
    libfive_tree zmax_t = libfive_tree_const(zmax);

    /* max(c, zmin_t - z, z - z_max) */
    return op2(max, c,
               op2(max,
                   c,
                   op2(max,
                       op2(sub, zmin_t, z),
                       op2(sub, z, zmax_t))));
}

// int main()
int main(int argc, char *argv[])
{
    printf("libfive test\n\n");

    libfive_tree c = cylinder(1.0f, -5.0f, 5.0f);
    libfive_region3 r = {{-5.0f, 5.0f}, {-5.0f, 5.0f}, {-5.0f, 5.0f}};

#if 0
  if (!libfive_tree_save_mesh(c, r, 10, "cylinder.stl")) {
    fprintf(stderr, "could not save to 'cylinder.stl'");
  }
#endif

    if (!run_viewer(argc, argv, 640, 640))
    {
        fprintf(stderr, "Could not run viewer.\n");
        return 1;
    }

    pthread_t *viewer_thread = get_viewer_thread();

    if (!set_tree(c, r, 10))
    {
        fprintf(stderr, "Could not set shape.\n");
        return 1;
    }

    void *return_value;
    pthread_join(*viewer_thread, &return_value);

    /* deallocate the mesh */
    set_tree(0, r, 0);

    return *(bool *)return_value ? 0 : 1;
}