#include "point.h"
#include "cluster_functions.h"
using namespace std;
#define NUM_ITER 10

vector<point> mean_shift(const vector<point> &points, float bdw, int num_threads=1);

point shift_point(const point &prev_point, const vector<point> &all_points, float bdw);
