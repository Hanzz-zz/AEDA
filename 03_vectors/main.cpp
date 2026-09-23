#include <format>
#include <iostream>
#include <vector>

#include "../01_BuildingBlocks/Hellpers.h"

static void vector_example_1() {
    std::vector<int> v1{10, 20, 30, 40, 50};
    std::vector<int> v2(v1.size());
    std::vector<int> v3(v1.size(), 7);
    print_container("v1:", v1);
    print_container("v2 (initial values):", v2);
    print_container("v3:", v3);
    //operator[] .at()
    for (size_t i = 0; i < v1.size(); ++i) {
        v2[i] = v1[i] * v3.at(i);
    }
    //()----> inicializadpr
    //{}----> constructor
    //por eso v6 = 8
    print_container("v2 (after operation):", v2);
    std::vector<unsigned long long> v4{100, 200, 300, 400, 500, 600, 700, 800};
    std::vector<unsigned long long> v5(v4.size(), 100);
    std::vector<unsigned long long> v6{v4.size()};
    std::vector<unsigned long long> v7{};
    print_container("v4:", v4);
    print_container("v5:", v5);
    print_container("v6:", v6);
    print_container("v7:", v7);
    //interadores
    auto it4 = v4.begin();
    auto it5 = v5.begin();
    for (; it4 != v4.end(); ++it4, ++it5) {
        *it5 = *it4 / 2;
    }
    print_container("v5 (after operation):", v5);
    //front(), back()
    std::cout << std::format("v4.front(): {:6d}", v4.front()) << std::endl;
    std::cout << std::format("v4.back() : {:6d}", v4.back()) << std::endl;
    //clear()
    v5.clear();
    print_container("v5 (after clear):", v5);
}


int main () {
    std::cout << "Vectors !!!" << std::endl;
    vector_example_1();
    return 0;
}