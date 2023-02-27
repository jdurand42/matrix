
#include <iostream>
#include <string>
#include <vector>
#include "../Vector.hpp"
#include "../Matrix.hpp"
#include "tester.hpp"
#include <limits>

#define EPSILON std::numeric_limits<float>::epsilon()


static bool float_comp(const double& a, const double& b)
{
    // std::cout << fabs(a - b) << std::endl;
    return fabs(a - b) <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * EPSILON);
    // return fabs(a - b) < EPSILON;
}


static void test_v_add()
{
    print_title("v_add");

    Vector<> u = {1, 2, 4};
    Vector<> bu = {1, 2, 4};
    Vector<> v = {3, 2, 1};
    Vector<> bv = {3, 2, 1};

    Vector<> upv = {4, 4, 5};
    u.add(v);
    ft_print("u.add(v)", u, upv);
    ft_print("v == v", v, bv);
    v.add(bu);
    ft_print("v.add(u)", v, upv);
}

static void test_v_sub()
{
    print_title("v_sub");
    Vector<> u = {1, 2, 4};
    Vector<> bu = {1, 2, 4};
    Vector<> v = {3, 2, 1};
    Vector<> bv = {3, 2, 1};

    Vector<> umv = {1 - 3, 2 - 2, 4 - 1};
    Vector<> vmu = {3 - 1, 2 - 2, 1 - 4};

    u.sub(v);
    ft_print("u.sub(v)", u, umv);
    ft_print("v == v", v, bv);
    v.sub(bu);
    ft_print("v.sub(u)", v, vmu); 
}

static void test_v_scl()
{
    print_title("v_scl");
    Vector<> u = {1, 2, 4};
    Vector<> bu = {1, 2, 4};

    int k = 2;
    float k05 = 0.5;

    Vector<> k05u = {k05 * 1, k05 * 2, k05 * 4};
    Vector<> ku = {k * 1.f, k *2.f, k * 4.f};

    u.scl(k);
    ft_print("u.scl(2)", u, ku);
    bu.scl(k05);
    ft_print("u.scl(0.5)", bu, k05u); 
}

static void test_m_add()
{
    print_title("m_add");

    Matrix<> u = {{1, 2, 4}, {1, 2, 4}};
    Matrix<> bu = {{1, 2, 4}, {1, 2, 4}};
    Matrix<> v = {{3, 2, 1}, {3, 2, 1}};
    Matrix<> bv = {{3, 2, 1}, {3, 2, 1}};
    Matrix<> upv = {{4, 4, 5}, {4, 4, 5}};
    u.add(v);
    ft_print("u.add(v)", u, upv);
    ft_print("v == v", v, bv);
    v.add(bu);
    ft_print("v.add(u)", v, upv);
}

static void test_m_sub()
{
    print_title("m_sub");
    Matrix<> u = {{1, 2, 4}, {1, 2, 4}};
    Matrix<> bu = {{1, 2, 4}, {1, 2, 4}};
    Matrix<> v = {{3, 2, 1}, {3, 2, 1}};
    Matrix<> bv = {{3, 2, 1}, {3, 2, 1}};
    Matrix<> upv = {{4, 4, 5}, {4, 4, 5}};

    Matrix<> umv = {{1 - 3, 2 - 2, 4 - 1}, {1 - 3, 2 - 2, 4 - 1}};
    Matrix<> vmu = {{3 - 1, 2 - 2, 1 - 4}, {3 - 1, 2 - 2, 1 - 4}};
    u.sub(v);
    ft_print("u.sub(v)", u, umv);
    ft_print("v == v", v, bv);
    v.sub(bu);
    ft_print("v.sub(u)", v, vmu); 
}

static void test_m_scl()
{
    print_title("m_scl");
    Matrix<> u = {{1, 2, 4}, {1, 2, 4}};
    Matrix<> bu = {{1, 2, 4}, {1, 2, 4}};

    int k = 2;
    float k05 = 0.5;

    Matrix<> k05u = {{k05 * 1, k05 * 2, k05 * 4}, {k05 * 1, k05 * 2, k05 * 4}};
    Matrix<> ku = {{k * 1.f, k *2.f, k * 4.f},{k * 1.f, k *2.f, k * 4.f}};

    u.scl(k);
    ft_print("u.scl(2)", u, ku);
    bu.scl(k05);
    ft_print("u.scl(0.5)", bu, k05u); 
}

void test_ex00()
{
    print_title("Ex00", 1);
    test_v_add();
    test_v_sub();
    test_v_scl();
    test_m_add();
    test_m_sub();
    test_m_scl();
}

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

void test_ex02()
{
    print_title("Ex02", 1);
    ft_print("lerp(floats)", lerp(0.f, 1.f, 0.), 0.f);
    ft_print("lerp(floats)", lerp(0.f, 1.f, 1.f), 1.f);
    ft_print("lerp(floats)", lerp(0.f, 1.f, 0.5f), 0.5f);
    ft_print("lerp(floats)", lerp(21.f, 42.f, 0.3f), 27.3f);

    ft_print("lerp(vecs)", lerp(Vector<>({2, 1}), Vector<>({4, 2}), 0.3f), Vector<>({2.6, 1.3}));
    ft_print("lerp(vecs)", lerp(Matrix<>({{2, 1}, {3, 4}}), Matrix<>({{20, 10}, {30, 40}}), 0.5f), Matrix<>({{11, 5.5}, {16.5, 22}}));
}

void test_ex03()
{
    print_title("Ex03", 1);
    Vector<> u = {0, 0};
    Vector<> v = {1, 1};
    Vector<> u2 = {1, 1};
    Vector<> v2 = {1, 1};
    Vector<> u3 = {-1, 6};
    Vector<> v3 = {3, 2};

    ft_print("u.dot(v)", u.dot(v), 0.0f);
    ft_print("u.dot(v)", u2.dot(v2), 2.0f);
    ft_print("u.dot(v)", u3.dot(v3), 9.0f);
}

void test_ex04()
{
    print_title("Ex04", 1);
    Vector<> u = {0, 0, 0};
    Vector<> u2 = {1, 2, 3};
    Vector<> u3 = {-1, -2};

    // ft_print()
    ft_print("norm (eculi)", float_comp(u.norm(), 0.0), true);
    ft_print("norm (eculi)", float_comp(u2.norm(), 3.74165738), true);
    ft_print("norm (eculi)", float_comp(u3.norm(), 2.236067977), true);
    ft_print("norm_1 (manhatan)", float_comp(u.norm_1(), 0.0), true);
    ft_print("norm_1 (manhatan)", float_comp(u2.norm_1(), 6.0), true);
    ft_print("norm_1 (manhatan)", float_comp(u3.norm_1(), 3.0), true);
    ft_print("norm_inf", float_comp(u.norm_inf(), 0.0), true);
    ft_print("norm_inf", float_comp(u2.norm_inf(), 3.0), true);
    ft_print("norm_inf", float_comp(u3.norm_inf(), 2.0), true);
    // ft_print("norm_inf (inf)", std::vector<double>({u.norm_inf(), u2.norm_inf(), u3.norm_inf()}), std::vector<double>({0.0, 3.0, 2.0}));
}

void test_ex05()
{
    print_title("Ex05", 1);

    Vector<> u = {1, 0};
    Vector<> v = {1, 0};
    ft_print("cos()", float_comp(angle_cos(u, v), 1.0), true);
    u = {1, 0};
    v = {0, 1};
    ft_print("cos()", float_comp(angle_cos(u, v), 0.0), true);
    u = {-1, 1};
    v = {1, -1};
    ft_print("cos()", float_comp(angle_cos(u, v), -1.0), true);
    u = {2, 1};
    v = {4, 2};
    ft_print("cos()", float_comp(angle_cos(u, v), 1.0), true);
    u = {1, 2, 3};
    v = {4, 5, 6};
    ft_print("cos()", float_comp(angle_cos(u, v), 0.974631846), true);
}

void test_ex06()
{
    print_title("Ex06", 1);

    Vector<> u = {0, 0, 1};
    Vector<> v = {1, 0, 0};
    ft_print("cross_product(u, v)", cross_product(u, v), Vector<>({0, 1, 0}));
    u = {1, 2, 3};
    v = {4, 5, 6};
    ft_print("cross_product(u, v)", cross_product(u, v), Vector<>({-3, 6, -3}));
    u = {4, 2, -3};
    v = {-2, -5, 16};
    ft_print("cross_product(u, v)", cross_product(u, v), Vector<>({17.f, -58.f, -16.f}));
}

void test_ex07()
{
    print_title("Ex07", 1);
    
    Matrix<> u = {{1, 0}, {0, 1}}; 
    Matrix<> v = {{1, 0}, {0, 1}};
    ft_print("Mat * Mat", u.mul_mat(v), Matrix<>({{1, 0}, {0, 1}}));
    v = {{2, 1}, {4, 2}};
    ft_print("Mat * Mat", u.mul_mat(v), Matrix<>({{2, 1}, {4, 2}}));
    u = {{3, -5}, {6, 8}};
    ft_print("Mat * Mat", u.mul_mat(v), Matrix<>({{-14, -7}, {44, 22}}));
    // u *= v;
    // ft_print("Mat * Mat", u, Matrix<>({{-14, -7}, {44, 22}}));

    u = {{1, 0}, {0, 1}};
    Vector<> a = {4, 2};
    ft_print("Mat * vec", u.mul_vec(a), Vector<>({4, 2}));
    u = {{2, 0}, {0, 2}};
    ft_print("Mat * vec", u.mul_vec(a), Vector<>({8, 4}));
    u = {{2, -2}, {-2, 2}};
    ft_print("Mat * vec", u.mul_vec(a), Vector<>({4, -4}));
}

void test_ex08()
{
    print_title("Ex08", 1);

    Matrix<> u = {{1, 0}, {0, 1}};
    ft_print("u.trace()", u.trace(), 2.0f);
    u = {{2, -5, 0}, {4, 3, 7}, {-2, 3, 4}};
    ft_print("u.trace()", u.trace(), 9.0f);
    u = {{-2, -8, 4}, {1, -23, 4}, {0, 6, 4}};
    ft_print("u.trace()", u.trace(), -21.0f);
}

void test_ex09()
{
    print_title("Ex09", 1);

    Matrix<> m = {{1, 2}, {1, 2}};
    ft_print("m.transpose()", m.transpose(), Matrix<>({{1, 1}, {2, 2}}));
    m = {{1, 1}, {2, 2}};
    ft_print("m.transpose()", m.transpose(), Matrix<>({{1, 2}, {1, 2}}));
    m = {{1, 1, 3}, {2, 2, 4}};
    ft_print("m.transpose()", m.transpose(), Matrix<>({{1, 2}, {1, 2}, {3, 4}}));
}

void test_ex10()
{
    print_title("Ex10", 1);
    Matrix<> m({{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}});
    ft_print("m.reduced_row_echelon()", m.reduced_row_echelon(), m);
    m = {{1, 2}, {3, 4}};
    ft_print("m.reduced_row_echelon()", m.reduced_row_echelon(), Matrix<>({{1, 0}, {0, 1}}));
    m = {{1, 2}, {2, 4}};
    ft_print("m.reduced_row_echelon()", m.reduced_row_echelon(), Matrix<>({{1, 2}, {0, 0}}));    
    m = {{8., 5., -2., 4., 28.}, {4., 2.5, 20., 4., -4.0}, {8., 5., 1., 4., 17.}};
    Matrix<> r({{1.0, 0.625, 0.0, 0.0, -12.1666667}, {0.0, 0.0, 1.0, 0.0, -3.6666667}, {0.0, 0.0, 0.0, 1.0, 29.5}}); 
    ft_print("m.reduced_row_echelon()", m.reduced_row_echelon(), r);       
}

void test_ex11()
{
    print_title("Ex11", 1);
    Matrix<> m({{1, -1}, {-1, 1}});
    ft_print("m.determinant()", m.determinant(), 0.0f);
    m = {{2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
    ft_print("m.determinant()", m.determinant(), 8.0f);
    m = {{8, 5, -2}, {4, 7, 20}, {7, 6, 1}};
    ft_print("m.determinant()", m.determinant(), -174.f);
    m = {{8, 5, -2, 4}, {4, 2.5, 20, 4}, {8, 5, 1, 4}, {28, -4, 17, 1}};
    ft_print("m.determinant()", m.determinant(), 1032.f);
}

void test_ex12()
{
    print_title("Ex12", 1);
    Matrix<> m({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
    ft_print("m.inverse()", m.inverse(), Matrix<>({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}));
    m = {{8, 5, -2}, {4, 7, 20}, {7, 6, 1}};
    ft_print("m.inverse()", m.inverse(), Matrix<>({{0.649425287, 0.097701149, -0.655172414}, {-0.781609195, -0.126436782, 0.965517241}, {0.143678161, 0.074712644, -0.206896552}}));
    m = {{2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
    ft_print("m.inverse()", m.inverse(), Matrix<>({{0.5, 0, 0}, {0, 0.5, 0}, {0, 0, 0.5}}));
}

void test_ex13()
{
    print_title("Ex13", 1);
    Matrix<> m({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}});
    ft_print("m.rank()", m.rank(), 3);
    m = {{1, 2, 0, 0}, {2, 4, 0, 0}, {-1, 2, 1, 1}};
    ft_print("m.rank()", m.rank(), 2);
    m = {{8, 5, -2}, {4, 7, 20}, {7, 6, 1}, {21, 18, 7}};
    ft_print("m.rank()", m.rank(), 3);
}