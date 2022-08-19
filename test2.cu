#include <iostream>
#include <fmt/core.h>
#include <chrono>
#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/sort.h>
#include <chrono>

int main()
{
    size_t n; std::cin >> n;
    thrust::host_vector<int> h_vec(n);
    fmt::print("Reading {} integers\n", n);
    for(auto& i : h_vec)
        std::cin >> i;
    thrust::device_vector<int> d_vec = h_vec;
    fmt::print("Starting sort\n");
    auto start = std::chrono::high_resolution_clock::now();
    sort(d_vec.begin(), d_vec.end());
    auto end = std::chrono::high_resolution_clock::now();
    fmt::print("Sorting on GPU took {}ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
}
