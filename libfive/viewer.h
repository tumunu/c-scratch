#include <stdbool.h>
#include <pthread.h>
#include <libfive.h>

bool run_viewer(int argc, char* argv[],
                      int width, int height);
pthread_t* get_viewer_thread();
bool set_tree(libfive_tree* new_tree,
              libfive_region3 new_bounds,
              float new_resolution);