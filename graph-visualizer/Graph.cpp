#include "Graph.h"
#include "utils.h"

Graph::Graph()
	: n(1000), scale(1.0f)
{
	points = sf::VertexArray(sf::LineStrip, n); 
}

void Graph::update(int width, int height)
{
	points.clear();

	for(int i = 0; i <= n; i++)
	{
		// Creates n+1 points separated equally from 0 to width
		float currentX = (float)width / n * i; 

		// Map x between scale * PI in both directions
		float mappedX = math::map(currentX, 0.0f, (float)width, -scale * math::PI, scale * math::PI);

		// Actual function
		float funVal = sin(mappedX);
		float currentY = (float)height / 2.0f - 100.0f * funVal;

		points.append(sf::Vertex(sf::Vector2f(currentX, currentY), sf::Color(0, 0, 0, 255)));
	}
}
