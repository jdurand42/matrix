#include <iostream>
#include <string>
#include <vector>
#include "../Vector.hpp"
#include "../Matrix.hpp"
#include "tester.hpp"

void test_ex02()
{
    print_title("Ex02", 1);
    ft_print("lerp(floats)", lerp(0.f, 1.f, 0.), 0.f);
    ft_print("lerp(floats)", lerp(0.f, 1.f, 1.f), 1.f);
    ft_print("lerp(floats)", lerp(0.f, 1.f, 0.5f), 0.5f);
    ft_print("lerp(floats)", lerp(21.f, 42.f, 0.3f), 27.3f);

    ft_print("lerp(vecs)", lerp(Vector<>({2, 1}), Vector<>({4, 2}), 0.3f), Vector<>({2.6, 1.3}));
    ft_print("lerp(vecs)", lerp(Matrix<>({{2, 1}, {3, 4}}), Matrix<>({{20, 10}, {30, 40}}), 0.5f), Matrix<>({{11, 5.5}, {16.5, 22}}));
    // Vector<> e1({1., 0., 0.});
    // Vector<> e2({0., 1., 0.});
    // Vector<> e3({0., 0., 1.});
    // Vector<> v1({1., 2., 3.});
    // Vector<> v2({0., 10., -100.});
// 
    // ft_print("", linear_combination(std::vector<Vector<float>>({e1, e2, e3}), std::vector<float>({10, -2, 0.5})), Vector<float>({10, -2, 0.5}));
    // ft_print("", linear_combination(std::vector<Vector<float>>({v1, v2}), std::vector<float>({10, -2})), Vector<float>({10, 0, 0.5}));
}