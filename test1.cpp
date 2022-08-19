#include <iostream>
#include <chrono>
#include <fmt/core.h>
#include <algorithm>
#include <vector>
#include <execution>

int main()
{
    size_t n; std::cin >> n;
    std::vector<int> arr; arr.reserve(n);
    fmt::print("Reading {} integers\n", n);
    while(n--) {
        int tmp; std::cin >> tmp;
        arr.push_back(tmp);
    }
    fmt::print("Starting sort\n");
    auto start = std::chrono::steady_clock::now();
    std::sort(std::execution::par, arr.begin(), arr.end());
    auto end = std::chrono::steady_clock::now();
    fmt::print("Parallel sorting on CPU took {}ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
}
