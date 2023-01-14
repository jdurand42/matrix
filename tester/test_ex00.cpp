
#include <iostream>
#include <string>
#include <vector>
#include "../Vector.hpp"
#include "../Matrix.hpp"
#include "tester.hpp"


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