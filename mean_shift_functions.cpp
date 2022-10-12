#include "mean_shift_functions.h"
using namespace std;

vector<point> mean_shift(const vector<point> &points, float bdw, int my_num_threads) {
    vector<point> my_shift_points = points;

    for (int j = 0; j < NUM_ITER; j++) {
#pragma omp parallel for default(none) shared(points, bdw, shifted_pts) schedule(static) num_threads(my_num_threads)
        for (int i = 0; i < points.size(); i++) {
            point new_point = shift_point(my_shift_points[i], points, bdw);
            my_shift_points[i] = new_point;
        }
    }
    return my_shift_points;
}


point shift_point(const point &oldPoint, const vector<point> &allPoints, float bdw) {
    float total_weight = 0.0;
    point shifted_point(oldPoint.get_num_dimensions());
    float d;
    for (auto &point : allPoints){
        d = euclidean_distance(oldPoint, point);
        float gaussian = gaussian_kernel(d, bdw);
        shifted_point += point * gaussian;
        total_weight += gaussian;
    }

    shifted_point /= total_weight;
    return shifted_point;
}
