#include <iostream>
#include <array>
#include<format>
static void array_example_1() {
    std::array<int , 9> x_vals {100,200,300,400,500,600,700,800,900};
    std::cout<<"x_vals:" << std::endl;
    for (auto value : x_vals) {
        //std::cout<<value<<"";
        std::cout << std:: format("", value)<< std::endl;

    }
    std::cout<<std::endl;
    std::cout<< "size:"<< x_vals.size() << std::endl;

}


int main() {
    std::cout<<"Arrays!"<<std::endl;
    return 0;
}