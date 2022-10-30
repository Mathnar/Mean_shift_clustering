#ifndef CLUSTERBUILDER_H
#define CLUSTERBUILDER_H

#include <vector>
#include "Cluster.h"
#include "ClusteringFunctions.h"
using namespace std;

class ClusterBuilder {
public:

    ClusterBuilder(std::vector<Point> &zero_points, std::vector<Point> &moved_pts, float cluster_th);

    std::vector<Cluster> make_a_cluster();


private:
    std::vector<Cluster> clusters;
    float cluster_th;
    std::vector<Point> zero_points;
    std::vector<Point> moved_pts;
};

#endif