#ifndef TESTER_HPP
#define TESTER_HPP

#include "../Vector.hpp"
#include "../Matrix.hpp"

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

// void print_title(const std::string& t, const int i = 0)
// {
	// const char *color = BOLDYELLOW;
	// if (i == 1)
	// {
		// std::cout << std::endl;
		// color = BOLDMAGENTA;
	// }
	// std::cout << color << t << std::endl << "-------" << std::endl <<  RESET;
// };


void print_title(const std::string &t, const int i=0);

void test_vector_basic();
void test_matrix_basic();
void test_ex00();
void test_ex01();	
void test_ex02();
void test_ex03();
void test_ex04();
void test_ex05();
void test_ex06();
void test_ex07();
void test_ex08();
void test_ex09();
void test_ex10();
void test_ex11();
void test_ex12();
void test_ex13();
bool float_eq(const double& a, const double& b);
template<typename T>
bool matrix_float_eq(const Matrix<T>& u, const Matrix<T>& v);

class Ft_cmp
{
	public:
	bool ft_cmp(const double& a, const double& b)
	{
		return float_eq(a, b);
	};

	template<typename T>
	bool ft_cmp(const Matrix<T>& u, const Matrix<T>& v)
	{
		return matrix_float_eq(u, v);
	};

	template<typename T>
	bool ft_cmp(const Vector<T>& u, const Vector<T>& v)
	{
		return (u == v);
	};


	// template<typename Y>
	// bool ft_cmp(const Y& a, const Y& b)
	// {
		// std::cout <<"hello" << std::endl;
		// return (a == b);
	// };
	private:
};


template<typename T>
void ft_print(const std::string& method, const T& tested, const T& result)
{
	usleep(TIME);
	std::cout << "- " << method << ": " << std::endl;
	bool cmp_res;
	Ft_cmp cmpf;

	cmp_res = cmpf.ft_cmp(tested, result);

	if (cmp_res == true)
		std::cout << GREEN << "OK -> ";
	else
		std::cout << RED << "ERROR -> ";
	std::cout << "Got: " << tested << " | " << "Excepted: " << result;
	std::cout << RESET << std::endl;
};
#endif