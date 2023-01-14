#include <iostream>
#include <string>
#include <vector>
#include "../Vector.hpp"
#include "../Matrix.hpp"
#include "tester.hpp"

void test_ex01()
{
    print_title("Ex01", 1);

    Vector<> e1({1., 0., 0.});
    Vector<> e2({0., 1., 0.});
    Vector<> e3({0., 0., 1.});
    Vector<> v1({1., 2., 3.});
    Vector<> v2({0., 10., -100.});

    ft_print("", linear_combination(std::vector<Vector<float>>({e1, e2, e3}), std::vector<float>({10, -2, 0.5})), Vector<float>({10, -2, 0.5}));
    ft_print("", linear_combination(std::vector<Vector<float>>({v1, v2}), std::vector<float>({10, -2})), Vector<float>({10, 0, 230}));
}