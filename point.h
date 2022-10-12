#include <vector>
#include <utility>
using namespace std;

class point {

public:
    explicit point(vector<float> values) : values(move(values)) {}

    explicit point(const int numDimensions){
        this->values = vector<float>(numDimensions, 0);
    }

    point(initializer_list<float> values) {
        this->values.assign(values);
    }
    point() = default;

    int get_num_dimensions() const {
        return values.size();
    }

    const vector<float> &get_values() const {
        return values;
    }

    void set_values(const vector<float> &new_val) {
        point::values = new_val;
    }

    point &operator/=(float d);
    point operator*(float d) const;
    point &operator+=(const point &otherPoint);


private:

    vector<float> values;
};

