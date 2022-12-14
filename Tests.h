#ifndef MEAN_SHIFT_PARALLEL_TESTS_H
#define MEAN_SHIFT_PARALLEL_TESTS_H
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include "MeanShiftFunctions.h"
#include "Point.h"
#include "ClusterBuilder.h"
#define BDW 14
#define CLUSTER_TH 1.0
#define ITER 5


void increasing(const std::string& input_data, const std::string& output_data);
void cluster_launch(float btw, const std::string& input_data_name, const std::string& output_data_name);
//void testBandwidth(const std::string& input_data, const std::string& output_data);

#endif
