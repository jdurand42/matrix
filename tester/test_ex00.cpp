
#include <iostream>
#include <string>
#include <vector>
#include "../Vector.hpp"
#include "tester.hpp"


static void test_add()
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


    // Vector<> umv = {1 - 3, 2 - 2, 4 - 1};
    // Vector<> vmu = {3 - 1, 2 - 2, 1 - 4};

    // int k = 2;
    // float k05 = 0.5;

    // Vector<> k05u = {k05 * 1, k05 * 2, k05 * 4};
    // Vector<> ku = {k * 1.f, k *2.f, k * 4.f};

    // ft_print("u + v", u + v, upv);
    // ft_print("u", u, bu);
    // ft_print("v + u", u + v, upv);
    // ft_print("v", v, bv);
    // ft_print("u - v", u - v, umv);
    // ft_print("v - u", v - u, vmu);
    // ft_print("v", v, bv);
    // ft_print("u", u, bu);
    // ft_print("u * 0.5", u * k05, k05u);
    // ft_print("u", u, bu);
    // // ft_print("0.5 * u", k05 * u, k05u);
    // // ft_print("u", u, bu);
    // ft_print("u * 2 (int)", u * k, ku);
    // ft_print("u", u, bu);

    // ft_print("u == u", u == u, true);
    // ft_print("u != u", u != u, false);
    // ft_print("u != v", u != v, true);
}

static void test_sub()
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

static void test_scl()
{
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

void test_ex00()
{
    std::cout << BOLDMAGENTA << "---- EX00---- \n" << RESET;
    test_add();
    test_sub();
    test_scl();
}