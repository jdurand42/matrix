#include "../Vector.hpp"
#include <vector>
#include "tester.hpp"


static void test_all()
{
	test_vector_basic();
    test_matrix_basic();
	test_ex00();
	test_ex01();
	test_ex02();
	test_ex03();
	test_ex04();
	test_ex05();
	test_ex06();
	test_ex07();
	test_ex08();
	// test_ex09();
	test_ex10();
	test_ex11();
	test_ex12();
}

void print_title(const std::string& t, const int i)
{
	const char *color = BOLDYELLOW;
	if (i == 1)
	{
		std::cout << std::endl;
		color = BOLDMAGENTA;
	}
	std::cout << color << t << std::endl << "-------" << std::endl <<  RESET;
};

int main(int ac, char** av)
{
	std::cout << "Type ./EXEC module_name module_name2 -> For specific module\n";
	std::cout << "Without arguments it will do all tests\n";

	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			if (std::string(av[i]) == "vector")
				test_vector_basic();
			else if (std::string(av[i]) == "matrix")
				test_matrix_basic();
			else if (std::string(av[i]) == "ex01")
				test_ex01();
			else if (std::string(av[i]) == "ex00")
				test_ex00();
			else if (std::string(av[i]) == "ex02")
				test_ex02();
			else if (std::string(av[i]) == "ex03")
				test_ex03();
			else if (std::string(av[i]) == "ex04")
				test_ex04();
			else if (std::string(av[i]) == "ex05")
				test_ex05();
			else if (std::string(av[i]) == "ex06")
				test_ex06();
			else if (std::string(av[i]) == "ex07")
				test_ex07();
			else if (std::string(av[i]) == "ex08")
				test_ex08();
			// else if (std::string(av[i]) == "ex09")
				// test_ex09();
			else if (std::string(av[i]) == "ex10")
				test_ex10();
			else if (std::string(av[i]) == "ex11")
				test_ex11();
			else if (std::string(av[i]) == "ex12")
				test_ex12();
		}
	}
	else
		test_all();
	//while (1);
	return (0);
}