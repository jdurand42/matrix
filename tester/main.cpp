#include "../Vector.hpp"
#include <vector>
#include "tester.hpp"


static void test_all()
{
	test_vector_basic();
    test_ex00();
    test_matrix_basic();
	// test_list();
	// test_queue();
	// test_stack();
	// test_map();
}

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
			else if (std::string(av[i]) == "ex00")
				test_ex00();
			else if (std::string(av[i]) == "matrix")
				test_matrix_basic();
			// else if (std::string(av[i]) == "queue")
				// test_queue();
			// else if (std::string(av[i]) == "stack")
				// test_stack();
		}
	}
	else
		test_all();
	//while (1);
	return (0);
}