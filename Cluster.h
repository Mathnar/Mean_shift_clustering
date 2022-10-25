#ifndef CLUSTER_H
#define CLUSTER_H

#include "Point.h"
#include <vector>
#include <iostream>

class Cluster {

public:
    explicit Cluster(Point &centroid) {
        this->centroid = std::move(centroid);
        this->shifted_points.push_back(this->centroid);
    }

    void add_pivot(const Point &point){
        zero_points.push_back(point);
    }

    void add_shifted_p(const Point &point){
        shifted_points.push_back(point);
        create_centroid();
    }

    const std::vector<Point> &get_shifted_p() const {
        return shifted_points;
    }

    const std::vector<Point> &get_pivot() const {
        return zero_points;
    }

    const Point &get_centroid() const {
        return centroid;
    }

    void create_centroid();

private:
    Point centroid;
    std::vector<Point> zero_points;
    std::vector<Point> shifted_points;
};

#endif