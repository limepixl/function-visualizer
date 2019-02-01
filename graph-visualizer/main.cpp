#include <SFML/Graphics.hpp>
#include <iostream>

// Constants
const float PI = 3.1415926f;
const int width = 1280;
const int height = 720;

// Map the value n between a new min and max value
float map(float n, int min, int max, int newMin, int newMax)
{
	return (n - min) / (max - min) * (newMax - newMin) + newMin;
}

// Update vertex values based on scale 
void update(sf::VertexArray& vArray, int n, float scale)
{
	vArray.clear();

	for(int i = 0; i <= n; i++)
	{
		float currentX = (float)width / n * i;
		float currentY = (float)height / 2.0f + 50.0f * sin(map(currentX, 0, width, -scale * PI, scale * PI));
		vArray.append(sf::Vertex(sf::Vector2f(currentX, height - currentY), sf::Color(0, 0, 0, 255)));
	}
}

int main() {

	// Number of positions
	int n = 1000;
	float scale = 3.0f;

	sf::RenderWindow window(sf::VideoMode(width, height), "Graph visualizer");
	sf::Color clearColor(255, 255, 255, 255);

	sf::VertexArray graphArray(sf::LineStrip, n);

	// Grid lines
	sf::VertexArray gridX(sf::LineStrip, 2);
	gridX[0] = sf::Vertex(sf::Vector2f(0.0f, height / 2.0f), sf::Color(255, 0, 0, 255));
	gridX[1] = sf::Vertex(sf::Vector2f(width, height / 2.0f), sf::Color(255, 0, 0, 255));

	sf::VertexArray gridY(sf::LineStrip, 2);
	gridY[0] = sf::Vertex(sf::Vector2f(width / 2.0f, 0.0f), sf::Color(255, 0, 0, 255));
	gridY[1] = sf::Vertex(sf::Vector2f(width / 2.0f, height), sf::Color(255, 0, 0, 255));

	update(graphArray, n, scale);

	while(window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			// Closed event
			if(event.type == sf::Event::Closed)
			{
				window.close();
			}

			// Keyboard events
			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Add)
				{
					update(graphArray, n, ++scale);
				}
				 
				if(event.key.code == sf::Keyboard::Subtract)
				{
					update(graphArray, n, --scale);
				}
			}
		}

		window.clear(clearColor);

		window.draw(graphArray);

		window.draw(gridX);
		window.draw(gridY);

		window.display();
	}

	return 0;
}