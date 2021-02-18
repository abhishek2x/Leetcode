// CPP program to illustrate
// std :: set_intersection

#include <bits/stdc++.h>

int main()
{
    int first[] = {5, 10, 15, 20, 25};
    int second[] = {50, 40, 30, 20, 10};
    int n = sizeof(first) / sizeof(first[0]);

    std::vector<int> v1(5);
    std::vector<int>::iterator it, ls;

    std::sort(first, first + 5);
    std::sort(second, second + 5);

    // std :: set_intersection
    ls = std::set_intersection(first, first + 5, second, second + 5, v1.begin());

    std::cout << "The intersection has " << (ls - v1.begin()) << " elements:";
    for (it = v1.begin(); it != ls; ++it)
        std::cout << ' ' << *it;
    std::cout << "\n";

    return 0;
}
