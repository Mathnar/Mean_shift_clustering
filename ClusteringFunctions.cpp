#include "ClusteringFunctions.h"

float euclidean_distance(const Point &p1, const Point &p2) {
    float d = 0.0;
    for (auto i = 0; i < p1.get_value_size(); i++) {
        d += powf(p1.get_values()[i] - p2.get_values()[i], 2);
    }
    return sqrt(d);
}

float gaussian_kernel(float d, float btw){
    return exp(-(d * d) / (2 * powf(btw, 2)));
}

vector<Point> get_points_coords(const string& f){
    vector<Point> points;
    ifstream data(f);
    string l;
    while (std::getline(data, l)) {
        stringstream str_l(l);
        string s;
        vector<float> point;
        while (std::getline(str_l, s, ',')) {
            point.push_back(stod(s));
        }
        points.emplace_back(Point(point));
    }
    return points;
}

void save_exe_time(const std::string& fileName, int numThreads, float time, int numPoints, int dimensions, float bdw, int num_cl){
    if(std::experimental::filesystem::exists(fileName + ".csv")){
        std::ofstream outputFile(fileName + ".csv", std::ios_base::app);
        outputFile << numThreads << "," << time << "," << numPoints << "," << dimensions << "," << bdw << "\n";
    } else{
        std::ofstream outputFile(fileName + ".csv");
        outputFile << "Num threads" << "," << "Time" << "," << "Num points" << "," << "Dimensions"  << "," << "Bandwidth" << "," << "num_cl" << "\n";
        outputFile << numThreads << "," << time << "," << numPoints << "," << dimensions << "," << bdw << "," << num_cl  << "\n";
    }
}