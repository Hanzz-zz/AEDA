#include <algorithm>
#include <iostream>
#include <array>

#include <format>

#include "../01_BuildingBlocks/Hellpers.h"
//#include <bits/locale_facets_nonio.h>

static void array_example_1() {
    std:: array<int, 9> x_vals{100,200,300,400,500,600,700,800,900};
    std:: cout << "x_vals" << std::endl;

    for (auto value : x_vals) {
        std::cout << value <<" ";
    }
    std::cout << std::endl;

    std::cout<<"x_vals: "<<std::endl;
    for (auto value : x_vals) {
        //std::cout<<value<<" ";
        std::cout<<std::format("{:6d}", value);
    }
    std::cout << std::endl;
    std::cout<<"size: "<<x_vals.size()<<std::endl;


}

static void array_example_2() {
    std::array<long,10> x_vals{1,2,3,4,5,6,7,8,9,10};
    std::cout<<std::endl;
    std::cout << "example 2" << std::endl;

    for (auto it = x_vals.begin(); it !=x_vals.end();++it) {
        std::cout<< std::format("{:6d} ", *it);
    }
    std::cout << std::endl;
    for (auto it= x_vals.begin(); it != x_vals.end(); ++it) {
        *it+=5;
    }
    for (auto it = x_vals.begin(); it !=x_vals.end();++it) {
        std::cout<< std::format("{:6d} ", *it);
    }
}

static void array_example_3() {
    std::array<double, 8> radios{1.0, 1.4, 2.0, 2.6, 4.0, 5.6, 8.0, 11.0};
    std::array<double, radios.size()> areas{};
    //calculo
    auto it_a = areas.begin();
    for (auto it_r = radios.begin(); it_r != radios.end(); ++it_r, ++it_a) {
        *it_a = std::numbers::pi * *it_r * *it_r;
    }
    //print
    it_a = areas.begin();
    std::cout << std::format("{:6s} {:12s}", "Radios", "Areas" );
    it_a = areas.begin();
    for (auto it_r = radios.begin(); it_r != radios.end(); ++it_r, ++it_a) {
        std::cout << std::format("{:6.1f} {:12.6f}", *it_r, *it_a) << std::endl;

    }
}
static void array_example_4 () {
    constexpr size_t epl_max{5};
    std::array<std::string, 15> colors_1{"Red", "Green", "Blue", "Cyan", "Magenta", "Yellow", "White", "Black", "Gray", "Brown", "Purple", "Amber", "Pink", "Teal"};
    auto colors_2 {colors_1};
    //le paso al header del que hablo
    print_container("colors_1", colors_1, epl_max);
    print_container("colors_2", colors_2, epl_max);
    //sort
    std::sort(colors_1.begin(), colors_1.end());
    print_container("colors_1 (after sort):", colors_1, epl_max);
    //std::ranges::sort
    std::ranges::sort(colors_2);
    print_container("colors_2 (after ranges::sort):", colors_2, epl_max);
    //comparacion
    std::cout << std::format("colors_1 == colors_2 : {:s}", colors_1 == colors_2) << std::endl;
}


int main() {
    std::cout << "Arrays" << std::endl;
    //array_example_1();
    //array_example_2();
    //array_example_3();
    //array_example_4();
    return 0;
}
