#include <iostream>
template<typename T>
void static Swap(T & a , T & b) {
    T temp = a;
    a = b;
    b = temp;
}
template<typename T>
static void Print(const T & A , size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << A[i] << " ";
    }
    std::cout<<std::endl;

}
template<typename T>
static void Print2(const T& array) {
    for (auto element : array) {
        std::cout << element << " ";
    }
    std::cout<<std::endl;
}
using namespace std;
int main() {
    cout<<"Building Blocks!!!" << endl;
    double A[] = {4.6, 4.8};
    //Print(A,2);
    Print2(A);
    //cout<< A[0]<<endl;
    //cout<< A[1]<<endl;
    Swap(A[0],A[1]);
    cout<< A[0]<<endl;
    cout<< A[1]<<endl;
    return 0;
}