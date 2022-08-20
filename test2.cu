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
    const size_t buffer_size = 1024 * 1024;
    size_t count = 0, num = 0;
    std::vector<char> buffer; buffer.reserve(buffer_size + 100);
    thrust::host_vector<int> h_vec; h_vec.reserve(n);
    fmt::print("Reading {} integers\n", n);

    while(count < n) {
        std::cin.read(buffer.data(), buffer_size);
        size_t len = std::cin.gcount();
        if(len == 0)
            break;

        for(size_t i = 0; i < len; i++)
        {
            const char &ch = buffer[i];
            if(ch >= '0' && ch <= '9')
                num = num * 10 + ch - '0';
            else
            {
                h_vec.push_back(num);
                num = 0;
                count++;
            }
        }
    }

    thrust::device_vector<int> d_vec = h_vec;
    fmt::print("Starting sort\n");
    auto start = std::chrono::high_resolution_clock::now();
    sort(d_vec.begin(), d_vec.end());
    auto end = std::chrono::high_resolution_clock::now();
    fmt::print("Sorting on GPU took {}ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
}
