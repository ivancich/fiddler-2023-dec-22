#include <iostream>
#include <cmath>


int main() {
    constexpr long limit = 2024;
    constexpr long limit_sq = limit * limit;

    constexpr long a_start = ceil(sqrt(limit_sq / 3.0d));

    long best_volume = 0;
    long best_a, best_b, best_c;
    int solutions_found = 0;
    for (long a = a_start; true; ++a) {
        const long a_sq = a * a;
        if (a_sq > limit_sq) break;
        const long b_start = long(ceil(sqrt(double(limit_sq - a_sq))));
        for (long b = b_start; true; --b) {
            const long b_sq = b * b;
            const long c_sq = limit_sq - a_sq - b_sq;
            if (c_sq > b_sq) break;
            if (c_sq < 1) continue;

            // is c a perfect square?
            const long c = long(floor(sqrt(double(c_sq))));
            const long test_1 = c * c;
            const long test_2 = test_1 + 2 * c + 1;
            if (test_1 == c_sq || test_2 == c_sq) {
                solutions_found++;
                const long volume = a * b * c;
                if (volume > best_volume) {
                    best_volume = volume;
                    best_a = a;
                    best_b = b;
                    best_c = c;
                }
                std::cout << "Found: v=" << volume << ", a,b,c=" << a << "," << b << "," << c << std::endl;
            }
        }
    }

    std::cout << "Solutions Found: " << solutions_found << std::endl;
    std::cout << "Best: v=" << best_volume << ", a,b,c=" << best_a << "," << best_b << "," << best_c << std::endl;
}
