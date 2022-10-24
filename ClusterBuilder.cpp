#include "ClusterBuilder.h"
using namespace std;

ClusterBuilder::ClusterBuilder(std::vector<Point> &zero_points, std::vector<Point> &shifter_pts, float cluster_th){
    this->zero_points = zero_points;
    this->shifted_pts = shifted_pts;
    this->cluster_th = cluster_th;
}

std::vector<Cluster> ClusterBuilder::make_a_cluster(){
    for (int i = 0; i < zero_points.size(); ++i) {
        auto j = clusters.begin();
        auto max_iter = clusters.end();
        while(j != max_iter){
            if (euclidean_distance(j->get_centroid(), shifted_pts[i]) <= cluster_th){
                j->add_pivot(zero_points[i]);
                j->add_shifted_p(zero_points[i]);
                break;
            }
            j++;
        }
        if(j == max_iter){
            Cluster new_cluster(shifted_pts[i]);
            new_cluster.add_pivot(zero_points[i]);
            clusters.push_back(new_cluster);
        }
    }

    return clusters;
}
