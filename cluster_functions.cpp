#include "cluster_functions.h"
using namespace std;

float euclidean_distance(const point &x, const point &y) {
    float d = 0.0;
    for (auto i = 0; i < x.get_num_dimensions(); i++) {
        d += powf(x.get_values()[i] - y.get_values()[i], 2);
    }
    return sqrt(d);
}

float gaussian_kernel(float distance, float bandwidth){
    return exp(-(distance * distance) / (2 * powf(bandwidth, 2)));
}
