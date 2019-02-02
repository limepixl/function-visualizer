#include "math.h"
#include "utils.h"
#include <vector>
#include <iostream>

namespace math
{
	float map(float n, float min, float max, float newMin, float newMax)
	{
		return (n - min) / (max - min) * (newMax - newMin) + newMin;
	}
}

namespace parser
{
	std::vector<std::string> split(std::string& string)
	{
		std::vector<std::string> tokens;

		while(!string.empty())
		{
			auto pos = string.find_first_of(' ');

			if(pos != std::string::npos)
			{
				tokens.emplace_back(string.begin(), string.begin() + pos);
				string.erase(string.begin(), string.begin() + pos + 1);
			} else
			{
				tokens.emplace_back(string.begin(), string.end());
				string.erase(string.begin(), string.end());
			}
		}

		return tokens;
	}
}
