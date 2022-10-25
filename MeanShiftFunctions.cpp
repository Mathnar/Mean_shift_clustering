#include "MeanShiftFunctions.h"
using namespace std;

std::vector<Point> mean_shift(const std::vector<Point> &points, float bdw, int t) {

    std::vector<Point> shifted_p = points;

    for (int j = 0; j < MAX_ITER; j++) {
        #pragma omp parallel for default(none) shared(points, bdw, shifted_p) schedule(static) num_threads(t)
        for (int i = 0; i < points.size(); i++) {
            Point new_p = shift_p(shifted_p[i], points, bdw);
            shifted_p[i] = new_p;
        }
    }
    return shifted_p;
}

Point shift_p(const Point &prev_point, const std::vector<Point> &all_points, float bdw) {
    float totalWeight = 0.0;
    Point shifted_p(prev_point.get_value_size());
    float d;
    for (auto &point : all_points){
        d = euclidean_distance(prev_point, point);
        float gaussian = gaussian_kernel(d, bdw);
        shifted_p += point * gaussian;
        totalWeight += gaussian;
    }
    shifted_p /= totalWeight;
    return shifted_p;
}
