#include "math.h"

namespace math
{
	float map(float n, float min, float max, float newMin, float newMax)
	{
		return (n - min) / (max - min) * (newMax - newMin) + newMin;
	}
}
