#ifndef TESTER_HPP
#define TESTER_HPP

#include "../Vector.hpp"
// #include "../Matrix.hpp"

#include <vector>
#include <ctime>
#include <unistd.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"

#define TIME 0

template<typename T>
void ft_print(const std::string& method, const T& tested, const T& result)
{
	usleep(TIME);
	std::cout << "---- Test on " << method << ": " << std::endl;
	if (tested == result)
		std::cout << GREEN << "OK -> ";
	else
		std::cout << RED << "ERROR -> ";
	std::cout << "Got: " << tested << " | " << "Excepted: " << result;
	std::cout << RESET << std::endl;
};

void test_vector_basic();
void test_ex00();

#endif