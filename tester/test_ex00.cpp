
#include <iostream>
#include <string>
#include <vector>
#include "../Vector.hpp"
#include "../Matrix.hpp"
#include "tester.hpp"


static void test_v_add()
{
    std::cout << BOLDYELLOW << "---- TESTS ON add---- \n" << RESET;

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
    std::cout << BOLDYELLOW << "---- TESTS ON sub---- \n" << RESET;
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
    std::cout << BOLDYELLOW << "---- TESTS ON scl---- \n" << RESET;
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
    std::cout << BOLDYELLOW << "---- TESTS ON add---- \n" << RESET;

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
    std::cout << BOLDYELLOW << "---- TESTS ON SUB---- \n" << RESET;

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
    std::cout << BOLDMAGENTA << "---- EX00---- \n" << RESET;
    std::cout << BOLDYELLOW << "---- VECTOR---- \n" << RESET;
    test_v_add();
    test_v_sub();
    test_v_scl();
    std::cout << BOLDYELLOW << "---- MATRIX---- \n" << RESET;
    test_m_add();
    test_m_sub();
    test_m_scl();
}