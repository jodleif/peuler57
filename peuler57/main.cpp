/*
Project Euler Problem 57
Jo Øivind Gjernes
*/
#include <iostream>
#include "expansion.h"
#include <boost/multiprecision/cpp_int.hpp>
#include "timer/bench_timer.h"

using namespace boost::multiprecision;
using peuler57::number_of_digits;

void first_four()
{
	std::cout.sync_with_stdio(false);
	auto first = std::make_pair(cpp_int{ 1 }, cpp_int{ 2 });
	int count{ 0 };
	cpp_int numerator{ 0 };
	for (uint64_t i = 1;i < 1000;++i) {
		peuler57::next_expansion_better_inplace(first);
		numerator = first.first + first.second;
		if (number_of_digits(numerator) > number_of_digits(first.second)) count++;
	}
	std::cout << "Number: " << count;
}
int main()
{
	first_four();
	first_four();
	bench_timer bt;
	first_four();
	return 0;
}