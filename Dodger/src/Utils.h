#ifndef UTILS_H
#define UTILS_H

#include <random>
#include <ctime>

namespace Utils
{
	
	// Generate a random float between 0 and 1
	float GenerateRandomFloat()
	{
		static std::mt19937 mersenne{static_cast<std::mt19937::result_type>(std::time(nullptr))};
		static std::uniform_int_distribution generator{0, 100};
		
		return (generator(mersenne)/100.0f);
	}
	
}; // namespace utils

#endif // UTILS_H