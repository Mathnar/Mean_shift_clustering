#include <iostream>
#include "Tests.h"


int main() {
    std::string data_in_path = "../data/";
    std::string data_out_path = "../out/";

    increasing(data_in_path + "blobs/", data_out_path);
    return 0;
}
