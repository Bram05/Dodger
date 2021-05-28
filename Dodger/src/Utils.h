#ifndef UTILS_H
#define UTILS_H

#include <random>
#include <ctime>

namespace Utils
{
	
	float GenerateRandom()
	{
		static std::mt19937 mersenne{static_cast<std::mt19937::result_type>(std::time(nullptr))};
		static std::uniform_int_distribution generator{0, 100};
		
		return (generator(mersenne)/100.0f);
	}
	
}; // namespace utils

#endif // UTILS_H