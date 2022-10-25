#include "Cluster.h"
using namespace std;

void Cluster::create_centroid(){
    vector<float> avg_coords = vector<float>(this->centroid.get_value_size(), 0);
    for(const auto& point: shifted_points){
        for(int i = 0; i < point.get_value_size(); i++){
            avg_coords[i] += point.get_values()[i];
        }
    }
    for(auto& value: avg_coords){
        value /= shifted_points.size();
    }
    this->centroid = Point(avg_coords);
}