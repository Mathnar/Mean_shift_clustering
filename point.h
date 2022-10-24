#ifndef MEAN_SHIFTCLUSTERINGPOINT_H
#define MEAN_SHIFTCLUSTERINGPOINT_H

#include <vector>
#include <utility>


class Point {

public:
    explicit Point(std::vector<float> values) : values(std::move(values)) {}
    explicit Point(const int value_size){
        this->values = std::vector<float>(value_size, 0);
    }
    Point &operator+=(const Point &p2);
    Point operator*(float d) const;
    Point &operator*=(float d);
    Point operator/(float d) const;
    Point &operator/=(float d);
    Point(std::initializer_list<float> values) {
        this->values.assign(values);
    }
    Point() = default;
    int get_value_size() const {
        return values.size();
    }
    const std::vector<float> &get_values() const {
        return values;
    }

private:
    std::vector<float> values;
};

#endif

