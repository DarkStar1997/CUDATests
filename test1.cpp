#include <iostream>
#include <chrono>
#include <fmt/core.h>
#include <algorithm>
#include <vector>
#include <execution>

int main()
{
    size_t n; std::cin >> n;
    const size_t buffer_size = 1024 * 1024;
    size_t count = 0, num = 0;
    std::vector<char> buffer; buffer.reserve(buffer_size + 100);
    std::vector<int> arr; arr.reserve(n);
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
                arr.push_back(num);
                num = 0;
                count++;
            }
        }
    }

    fmt::print("Starting sort\n");
    auto start = std::chrono::steady_clock::now();
    std::sort(std::execution::par, arr.begin(), arr.end());
    auto end = std::chrono::steady_clock::now();
    fmt::print("Parallel sorting on CPU took {}ms\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
}
