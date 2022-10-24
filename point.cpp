#include "Point.h"


Point &Point::operator+=(const Point &p2){
    for (int i = 0; i < this->get_value_size(); ++i) {
        this->values[i] += p2.get_values()[i];

    }
    return *this;
}
Point Point::operator*(const float d) const {
    Point point(this->values);
    return point *= d;
}

Point &Point::operator*=(const float d) {
    for (long i = 0; i < get_value_size(); ++i)
        this->values[i] *= d;
    return *this;
}
Point Point::operator/(const float d) const {
    Point point(this->values);
    return point /= d;
}
Point &Point::operator/=(const float d) {
    for (long i = 0; i < get_value_size(); ++i)
        this->values[i] /= d;
    return *this;
}