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

static void test_basic()
{
    Matrix<> m = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    Matrix<> m2 = {{1, 1}, {2, 2}, {3, 3}};

    ft_print("issquare", m.issquare(), true);
    ft_print("issquare", m2.issquare(), false);

    // Reshape
}

static void test_math_operators()
{
    Matrix<> u = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    Matrix<> v = {{0, 0, 0}, {1, 1, 1}, {0.5, 0.5, 0.5}};
    Matrix<> bu(u);
    Matrix<> bv(v);
    Matrix<> upv = {{1, 1, 1}, {3, 3, 3}, {3.5, 3.5, 3.5}};

    ft_print("u + v", u + v, upv);
    ft_print("u + v", v + u, upv);
    ft_print("check no inplace", u, bu);
    ft_print("check no inplace", v, bv);


    ft_print("u - v", u - v, Matrix<>({{1, 1, 1}, {2-1,2-1,2-1}, {3-0.5, 3-0.5, 3-0.5}}));
    ft_print("u - v", v - u, Matrix<>({{-1, -1, -1}, {1-2, 1-2, 1-2}, {0.5-3, 0.5-3, 0.5-3}}));
    ft_print("check no inplace", u, bu);
    ft_print("check no inplace", v, bv);

    u = Matrix<>({{1, 2, 3}, {3, 2, 1}});
    bu = Matrix<>(u);
    ft_print("u * k", u * 0.5, Matrix<>({{0.5, 1, 1.5}, {1.5, 1, 0.5}}));
    ft_print("check no inplace", u, bu);
    int k = 2;
    ft_print("u * k", u * k, Matrix<>({{2, 4, 6}, {6, 4, 2}}));
    ft_print("check no inplace", u, bu);


    u = Matrix<>({{1.1, 1}, {2.1, 2}});
    v = Matrix<>({{1.1, 1}, {2.1, 2}});
    bu = Matrix<>(u);
    bv = Matrix<>(v);

    u += v;
    ft_print("u += v", u, bu * 2);
    ft_print("v", v, bv);
    
    u -= v;
    ft_print("u -= v", u, bu);
    ft_print("v", v, bv);
    
    v -= u;
    ft_print("v -= u", v, bv - u);
    ft_print("u", u, bu);

    u *= 2;
    ft_print("u *= k", u, bu * 2);
    u *= 0.5f;
    ft_print("u *= 0.5", u, bu * 2 * 0.5);
}

void test_matrix_basic()
{
    std::cout << BOLDMAGENTA << "---- TESTS ON MATRIXS ---- \n" << RESET;
    test_constructors();
    test_operators();
    test_basic();
    test_math_operators();
}