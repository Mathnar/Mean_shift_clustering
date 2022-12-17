#include "Tests.h"

using namespace std;



/*void testBandwidth(const std::string& input_data, const std::string& output_data){
    std::cout << "Running different bandwidth from 1.0 to 10.0" << std::endl;
    std::string out_file = output_data + "blob_bdw/";

    std::vector<std::string> f_name;
    for (const auto & entry : std::experimental::filesystem::directory_iterator(input_data))
        f_name.emplace_back(entry.path().filename());
    std::sort(f_name.begin(), f_name.end());

    std::vector<float> BDWS;
    BDWS.push_back(1.0);
    BDWS.push_back(5.0);
    BDWS.push_back(10.0);
    BDWS.push_back(15.0);

    for(const auto bdw: BDWS) {
        for (const auto &fl : f_name) {
            cluster_launch(bdw, input_data + fl, output_data + "bdw_from_1_to_15");
            std::cout << "" << std::endl;
        }
    }
    std::cout << "\n\n" << std::endl;
}*/

void increasing(const string& input_data, const string& output_data){
    cout << "\nincreasing_from10k_to_120k" << endl;
    cout << "..." << endl;
    string output_data_name = output_data + "blobs/";
    vector<string> f_name;
    for (const auto & e : experimental::filesystem::directory_iterator(input_data))
        f_name.emplace_back(e.path().filename());
    sort(f_name.begin(), f_name.end());
    for (const auto & f : f_name) {
        cluster_launch(BDW, input_data + f, output_data + "from10k_to_120k");
        cout << "" << endl;
    }

    cout << "\n\n" << endl;
}

void cluster_launch(float btw, const string& input_data_name, const string& output_data_name) {
    vector<Point> points = get_points_coords(input_data_name);

    for (int t = 2; t <= omp_get_max_threads(); t+=2) {
        float tot_time = 0;
        int n_cl = 0;
        for (int k = 0; k < ITER; k++) {

            chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

            vector<Point> shifted = mean_shift(points, btw, t);

            chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
            float partial_time = chrono::duration_cast<chrono::duration<float>>(end - start).count();

            ClusterBuilder cluster_builder = ClusterBuilder(points, shifted, CLUSTER_TH);
            cluster_builder.make_a_cluster();
            n_cl = cluster_builder.get_n_cl();
            tot_time += partial_time;
        }
        cout << "\nthreads: " << t << "\nNumber of points " << points.size() << "\nTime: " << tot_time << endl;
        save_exe_time(output_data_name, t, tot_time / ITER, points.size(), points[0].get_value_size(), btw, n_cl);
    }
}