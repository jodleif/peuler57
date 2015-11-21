#pragma once
#include <utility>
#include <string>

namespace peuler57
{

	// Initial algorithm
	template<typename IntegerType>
	std::pair<IntegerType,IntegerType> next_expansion(const std::pair<IntegerType,IntegerType>& expansion, uint64_t n)
	{
		IntegerType numerator = expansion.second;
		IntegerType denominator = numerator;

		denominator *= numerator;

		(n&1) ? ++denominator : --denominator; 

		denominator /= expansion.first;

		return std::make_pair(numerator, denominator);
	}
	// Less compute intensive from project euler forum.
	template<typename IntegerType>
	std::pair<IntegerType,IntegerType> next_expansion_better(const std::pair<IntegerType,IntegerType>& expansion)
	{
		IntegerType numerator = expansion.second;
		IntegerType denominator = 2*expansion.second + expansion.first;
		return std::make_pair(numerator, denominator);
	}

	template<typename I>
	void next_expansion_better_inplace(std::pair<I,I>& expansion)
	{
		std::swap(expansion.first, expansion.second);
		expansion.second += expansion.first;
	}

	template<typename BoostInteger>
	std::size_t number_of_digits(const BoostInteger& integer)
	{
		auto str = integer.template convert_to<std::string>();
		return str.length();
	}
}