#ifndef MEANSHIFTFUNCTIONS_H
#define MEANSHIFTFUNCTIONS_H


#include "Point.h"
#include "ClusteringFunctions.h"
using namespace std;
#define MAX_ITER 5

vector<Point>mean_shift(const vector<Point> &points, float bdw, int t=1);

Point shift_p(const Point &prev_point, const vector<Point> &all_points, float bdw);

#endif