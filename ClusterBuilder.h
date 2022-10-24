#ifndef CLUSTERBUILDER_H
#define CLUSTERBUILDER_H

#include <vector>
#include "Cluster.h"
#include "ClusteringFunctions.h"
using namespace std;

class ClusterBuilder {

public:

    ClusterBuilder(vector<Point> &zero_points, vector<Point> &shifter_pts, float cluster_th);
    vector<Cluster> make_a_cluster();
private:
    vector<Cluster> clusters;
    vector<Point> zero_points;
    vector<Point> shifted_pts;
    float cluster_th;
};

#endif