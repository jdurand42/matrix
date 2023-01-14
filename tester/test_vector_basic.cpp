#include <iostream>
#include <string>
#include <vector>
#include "../Vector.hpp"
#include "tester.hpp"


static void test_constructors()
{
	print_title("Constructors");

    Vector<> v_0;
    std::cout << v_0.size();
    ft_print("Vector()",  v_0.size(), 0);

    Vector<float> v_02;
    ft_print("Vector<float>", v_02.size(), 0);

	std::cout << "Default constructor and template success\n";

    Vector<> v_03(8);
    ft_print("Vector(8)", v_03.size(), 8);
    ft_print("Vector(8)", v_03[7], 0.0f);

    Vector<> v2 = {2.5, 8.1, 3.2};
    ft_print("Vector = {a, b}", v2.size(), 3);
    ft_print("Vector = {a, b}", v2[1], 8.1f);

    Vector<> v3 = v2;
    ft_print("Vector = Vector", v2.size(), 3);
    ft_print("Vector = Vector", v2[1], 8.1f);
    v3[1] = 1.1f;
    ft_print("Vector = Vector", v2[1], 8.1f);
    ft_print("Vector = Vector", v3[1], 1.1f);

    Vector<> v4(v2);
    ft_print("Vector(Vector)", v4.size(), 3);
    ft_print("Vector(Vector)", v4[1], 8.1f);
    v4[1] = 1.1f;
    ft_print("Vector(Vector)", v2[1], 8.1f);
    ft_print("Vector(Vector)", v4[1], 1.1f);

    Vector<> v5; 
    v5 = v2;
    ft_print("Vector = Vector", v5.size(), 3);
    ft_print("Vector = Vector", v5[1], 8.1f);
    v5[1] = 1.1f;
    ft_print("Vector = Vector", v2[1], 8.1f);
    ft_print("Vector = Vector", v5[1], 1.1f);

    std::vector<float> vec = {12, 11, 10};
    Vector<> v6(vec);
    ft_print("Vector(std::vector)", v6.size(), 3);
    ft_print("Vector(std::vector)", v6[0], vec[0]);
}

static void test_basics()
{
    print_title("Basics");

    Vector<> u = {1, 2, 3};
    Vector<> v = {3, 2, 1};

    ft_print("Size", u.size(), v.size());

    // Reshape
    // print -> la flemme
}

static void test_math_operators()
{
    print_title("Math operators");

    Vector<> u = {1, 2, 4};
    Vector<> bu = {1, 2, 4};
    Vector<> v = {3, 2, 1};
    Vector<> bv = {3, 2, 1};

    Vector<> upv = {4, 4, 5};
    Vector<> umv = {1 - 3, 2 - 2, 4 - 1};
    Vector<> vmu = {3 - 1, 2 - 2, 1 - 4};

    int k = 2;
    float k05 = 0.5;

    Vector<> k05u = {k05 * 1, k05 * 2, k05 * 4};
    Vector<> ku = {k * 1.f, k *2.f, k * 4.f};

    ft_print("u + v", u + v, upv);
    ft_print("u", u, bu);
    ft_print("v + u", u + v, upv);
    ft_print("v", v, bv);
    ft_print("u - v", u - v, umv);
    ft_print("v - u", v - u, vmu);
    ft_print("v", v, bv);
    ft_print("u", u, bu);
    ft_print("u * 0.5", u * k05, k05u);
    ft_print("u", u, bu);
    // ft_print("0.5 * u", k05 * u, k05u);
    // ft_print("u", u, bu);
    ft_print("u * 2 (int)", u * k, ku);
    ft_print("u", u, bu);

    ft_print("u == u", u == u, true);
    ft_print("u != u", u != u, false);
    ft_print("u != v", u != v, true);
}


void test_vector_basic()
{
    print_title("Vectors", 1);
    try
    {
        test_constructors();
    }
    catch (...)
    {
        ;
    }
    try
    {
        test_basics();
    }
    catch (...)
    {
        ;
    }   try
    {
        test_math_operators();
    }
    catch (...)
    {
        ;
    }
}