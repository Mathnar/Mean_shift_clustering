#include "ClusterBuilder.h"


ClusterBuilder::ClusterBuilder(std::vector<Point> &zero_points, std::vector<Point> &moved_pts, float cluster_th){
    this->zero_points = zero_points;
    this->moved_pts = moved_pts;
    this->cluster_th = cluster_th;
}

int ClusterBuilder::get_n_cl(){
    return clusters.size();
}

const std::vector<Cluster> &ClusterBuilder::get_cl() const {
    return clusters;
}


std::vector<Cluster> ClusterBuilder::make_a_cluster(){

    for (int i = 0; i < zero_points.size(); ++i) {
        auto cl_start = clusters.begin();
        auto cl_end = clusters.end();
        while(cl_start != cl_end){
            if (euclidean_distance(cl_start->get_centroid(), moved_pts[i]) <= cluster_th){
                cl_start->add_pivot(zero_points[i]);
                cl_start->add_shifted_p(moved_pts[i]);
                break;
            }
            cl_start++;
        }
        if(cl_start == cl_end){
            Cluster newCluster(moved_pts[i]);
            newCluster.add_pivot(zero_points[i]);
            clusters.push_back(newCluster);
        }
    }

    return clusters;
}

