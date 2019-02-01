#include "Graph.h"
#include "math.h"

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
		float currentX = (float)width / n * i; 
		float mappedX = math::map(currentX, 0.0f, (float)width, -scale * math::PI, scale * math::PI);

		float currentY = (float)height / 2.0f + 100.0f * sin(mappedX);
		points.append(sf::Vertex(sf::Vector2f(currentX, height - currentY), sf::Color(0, 0, 0, 255)));
	}
}
