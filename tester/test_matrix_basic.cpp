#include <iostream>
#include "../Vector.hpp"
#include "../Matrix.hpp"
#include "tester.hpp"

static void test_constructors()
{
    std::cout << BOLDYELLOW << "---- TESTS ON CONSTRUCTORS ---- \n" << RESET;

    Matrix<> m;
    int s[2];

    s[0] = 0;
    s[1] = 0;
    ft_print("m()", m.shape()[0], s[0]);
    ft_print("m()", m.shape()[1], s[1]);


    // m2.shape()[0] = 8;
    //  
    // ft_print("m(shape)", m2.shape()[0], s[0]);
    Vector<> u = {1, 1, 1};
    Vector<> v = {2, 2, 2};
    Matrix<> m3 = {u, v};
    ft_print("Matrix m = {u, v}", m3.shape()[0], 2);
    ft_print("Matrix m = {u, v}", m3.shape()[1], 3);


    Matrix<> m4 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    ft_print("m = {{...}, {...}, {...}}", m4.shape()[0], 3);
    ft_print("m = {{...}, {...}, {...}}", m4.shape()[1], 3);

    Matrix<> m5(m4);
    ft_print("m(m2)", m4.shape()[0], 3);
    ft_print("m(m2)", m4.shape()[1], 3);

    Matrix<> m6(std::vector<Vector<float>>({Vector<>({1, 1}), Vector<>({2, 2})}));
    ft_print("m(std::vector<Vector>)", m6.shape()[0], 2);
    ft_print("m(std::vector<Vector>)", m6.shape()[1], 2);

    m6 = m4;
    ft_print("m = m", (m6 == m4), true);
}


static void test_operators()
{
    std::cout << BOLDYELLOW << "---- TESTS ON Operators ---- \n" << RESET;

    Matrix<> m(std::vector<Vector<float>>({Vector<>({1, 1}), Vector<>({2, 2})}));
    Matrix<> m2(std::vector<Vector<float>>({Vector<>({1, 1}), Vector<>({2, 2})}));
    Matrix<> m3 = {{1, 1}, {1, 2}};
    Matrix<> m4 = {{1, 1}};
    ft_print("m == m", (m == m), true);
    ft_print("m == m", (m == m2), true);
    ft_print("m != m", (m != m2), false);
    ft_print("m != m", (m != m3), true);
    ft_print("m == m", (m == m3), false);
    ft_print("m == m", (m == m4), false);
    ft_print("m != m", (m != m4), true);

    m[0][0] = 8;
    m[1][1] = 8.8f;
    ft_print("m[0][0] = a", m[0][0], 8.f);
    ft_print("m[0][0] = a", m[1][1], 8.8f);
    // std::cout << m << std::endl;    
}


void test_matrix_basic()
{
    std::cout << BOLDMAGENTA << "---- TESTS ON MATRIXS ---- \n" << RESET;
    test_constructors();
    test_operators();
}