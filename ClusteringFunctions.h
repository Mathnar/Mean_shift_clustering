#ifndef CLUSTERINGFUNCTIONS_H
#define CLUSTERINGFUNCTIONS_H

#include "Point.h"
#include <iostream>
#include <cmath>
#include <omp.h>
#include <chrono>
#include <algorithm>
#include <experimental/filesystem>
#include <fstream>
#include <sstream>


using namespace std;
float euclidean_distance(const Point &p1, const Point &p2);
float gaussian_kernel(float d, float btw);
vector<Point> get_points_coords(const string& f);
void save_exe_time(const std::string& fileName, int numThreads, float time, int numPoints, int dimensions, float bdw, int n_cl);

#endif