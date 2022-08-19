#include <vector>
#include <random>
#include <fstream>
#include <iostream>
#include <fmt/core.h>

int main()
{
    size_t n; std::cin >> n;
    std::vector<int> arr; arr.reserve(n);
    std::mt19937_64 rng{std::random_device()()};
    std::uniform_int_distribution<int> dis(1, n);
    fmt::print("Generating {} random numbers between {} and {}\n", n, 1, n);
    while(n--)
        arr.push_back(dis(rng));
    fmt::print("Random numbers generated. Writing to file\n");
    std::ofstream out; out.open("test_data");
    out << arr.size() << '\n';
    for(const auto& i : arr)
        out << i << '\n';
    fmt::print("Test data generated\n");
}
