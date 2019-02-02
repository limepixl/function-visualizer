#pragma once
#include <string>
#include <vector>

namespace math
{
	static float PI = 3.141592f;

	// Map the value n between a new min and max value
	float map(float n, float min, float max, float newMin, float newMax);

}

namespace parser
{
	// Parse the function contained in a string
	std::vector<std::string> split(std::string& string);
}