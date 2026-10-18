#include <algorithm>
#include <deque>
#include <format>
#include <array>
#include <iostream>
#include "..//01_BuildingBlocks/Hellpers.h"


static void deque_example_1() {
    std::deque<int> d1{10, 20, 30, 40, 50};
    std::deque<int> d2(d1.size());
    print_container("d2:", d2);
    //size_t usa lo jsuto para un contador mucho mas eficienteque int
    for (size_t i = 0; i < d1.size(); i++) {
        d2[i] = d1.at(i) * 5;

    }

    print_container("d2 (after initialization):", d2);
    //create deque
    std::deque<long> d3{100, 200, 300, 400, 500};
    std::deque<long> d4(d3.size(), 1000);
    print_container("d4 (after initialization):", d4);
    //iterators
    auto it3 = d3.begin();
    auto it4 = d4.begin();
    for (;it3 != d3.end(); ++it3, ++it4) {
        *it4 = *it3/2;
    }
    print_container("d4 (after iterators):", d4);

}

static void deque_example_2() {
    std::deque<double> d1{};
    d1.push_back(50.0);
    d1.push_back(60.0);
    d1.push_back(70.0);
    d1.push_back(80.0);
    print_container("d1 (after push_back):", d1);
    d1.push_front(40.0);
    d1.push_front(30.0);
    d1.push_front(20.0);
    d1.push_front(10.0);
    print_container("d1 (after push_front):", d1);
    //add elements
    std::array<double, 5> array1{1000, 2000, 3000, 4000, 5000};
    d1.insert(d1.begin() + 2, array1.begin(), array1.end());//.edn es el limite se agrega hasta uno antes de este limite
    print_container("d1 (after insert):", d1);
}

static void deque_example_3() {
    std::deque<std::string> d1{"January", "February", "March", "April", "May", "June", "July", "August","September","October", "November","December"};
    print_container("d1 (initial values):", d1);

    std::array<std::string, 6> array1{"July", "August", "September", "October", "November", "December"};
    std::deque d2{d1};

    //macros son para dieferenciar entornos que por su naturaleza son incompatibles

#ifdef def __cpp_lib_containers_ranges
    std::cout << "C++23" << std::endl; //en el main no lo reconocera por que estamos en el c++20 en el cmakelist
    d1.eppend_range(array1);
#else
    std::cout << "C++20" << std::endl;  //solo obedece a lo que esta dentro de la macro
    d1.insert(d1.end(), array1.begin(), array1.end());
#endif
    print_container("d1 (after insert):", d1);
    //sort
    std::ranges::sort(d1);
    print_container("d1 (after sort):", d1);
    std::ranges::sort(d1, std::greater<>());
    print_container("d1 (after sort greater):", d1);
    //relational operators
    std::cout << std::format("d1 == d2: {:s}", d1 == d2) << std::endl;
    std::cout << std::format("d1 <= d2: {:s}", d1 <= d2) << std::endl;
    std::cout << std::format("d1 >= d2: {:s}", d1 >= d2) << std::endl;
    //parcial : de estos operadores relacionales
}

int main () {
    std::cout << "Deque !!!" << std::endl;
    //deque_example_1();
    //deque_example_2();
    deque_example_3();
}