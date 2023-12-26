#include <iostream>
#include <set>
#include <list>

std::set<long> seen;
// std::set<long> next;
std::list<long> next;

constexpr bool progress = false;


bool add(long value) {
    if (value <= 0) {
        return false;
    }
    auto it = seen.lower_bound(value);
    if (*it != value) {
        seen.insert(it, value);
        return true;
    } else {
        return false;
    }
}

void backwards(long start) {
    add(start);
    // next.insert(start);
    next.push_back(start);

    long max = 100000000;
    while (max-- > 0 && !next.empty()) {
        if (max % 1000000 == 0) {
            std::cout << "max:" << max << ", current lowest:" << *seen.begin() << std::endl;
        }
        long current = *next.begin();
        next.erase(next.begin());

        const long q1 = current * 2;
        if (add(q1)) {
            if (progress) std::cout << "adding " << q1 << " from " << current << std::endl;
            // next.insert(q1);
            next.push_back(q1);
        }
        const auto [q2, r2] = std::div(current - 1, 3L);
        if (r2 == 0 && q2 % 2 != 0) {
            if (add(q2)) {
                if (progress) std::cout << "adding " << q2 << " from " << current << std::endl;
                // next.insert(q2);
                next.push_back(q2);
            }
        }
    }

    std::cout << "max:" << max << ", next.size():" << next.size() << std::endl;
    std::cout << "lowest:" << *seen.begin() << std::endl;
}



int main() {
    backwards(2024);

    std::cout << "FORWARDS" << std::endl;

    long current = *seen.begin();
    long count = 10000;
    while (count-- > 0) {
        std::cout << current << ", ";
        if (current == 2024) break;
        if (current % 2 == 0) {
            current = current / 2;
        } else {
            current = 3 * current + 1;
        }
    }
    std::cout << std::endl;
}
