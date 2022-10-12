
#include "point.h"
#include <vector>
#include <iostream>

class Cluster {

public:
    explicit Cluster(point &centroid) {
        this->centroid = move(centroid);
        this->shifted_points.push_back(this->centroid);
    }

    void add_pivot(const point &point){
        zero_points.push_back(point);
    }

    void add_shifted_p(const point &point){
        shifted_points.push_back(point);
        create_centroid();
    }

    const vector<point> &get_shifted_p() const {
        return shifted_points;
    }

    const vector<point> &get_pivot() const {
        return zero_points;
    }

    const point &get_centroid() const {
        return centroid;
    }

    void create_centroid();

private:
    point centroid;
    vector<point> zero_points;
    vector<point> shifted_points;
};

