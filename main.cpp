#include "Vector.hpp"
#include <vector>
#include <cmath>
#include <math.h>

int main()
{
    std::vector<float> i = {2, 4, 5};
    Vector<float> v(i);
    v.print();
    Vector<> v2 = {2.256, 4.5, 5.1};
    Vector<> v5 = {2, 4, 5, 8};
    v2.print();
    Vector<> v3(v2);
    v3.print();
    // std::cout << v3.size() << std::endl;
    // for (int i =0; i < v3.size(); i++)
    // {
    //     std::cout << v3[i] << std::endl;
    //     v3[i] = i;
    // };
    // for (int i =0; i < v3.size(); i++)
    // {
    //     std::cout << v3[i] << std::endl;
    // };
    // for (int i =0; i < v3.size(); i++)
    // {
    //     std::cout << v2[i] << std::endl;
    // };
    Vector<> v4 = v2;
    // v4.print();
    // std::cout << (v4 == v2) << std::endl;
    // std::cout << (v2 == v2) << std::endl;
    // std::cout << (v3 != v3) << std::endl;
    // std::cout << (v3 == i) << std::endl;
    // std::cout << (v3 == {2, 4, 5}) << std::endl;
    Vector<> v6 = {1, 1, 1};
    (v2 + v2).print();
    (v2 - v2).print();
    (v2 - v6).print();
    (v6 - v2).print();
    (v6 * 2).print();
    (v6 * 0.5).print();

    double a = 2;
    double b = 0.5;

    std::cout << std::pow(a, b) * std::pow(a, b) << std::endl;
}