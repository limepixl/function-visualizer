#include <SFML/Graphics.hpp>
#include "utils.h"
#include "Graph.h"
#include <iostream>
#include <string>
#include <vector>

// Constants
const int width = 1280;
const int height = 720;

int main() {
	// Number of positions
	int n = 1000;

	// Insert the function via command prompt
	std::string function;
	std::getline(std::cin, function);

	std::vector<std::string> splitString = parser::split(function);

	sf::RenderWindow window(sf::VideoMode(width, height), "Graph visualizer");
	sf::Color clearColor(255, 255, 255, 255);

	// Grid lines
	sf::VertexArray gridX(sf::LineStrip, 2);
	gridX[0] = sf::Vertex(sf::Vector2f(0.0f, height / 2.0f), sf::Color(255, 0, 0, 255));
	gridX[1] = sf::Vertex(sf::Vector2f(width, height / 2.0f), sf::Color(255, 0, 0, 255));

	sf::VertexArray gridY(sf::LineStrip, 2);
	gridY[0] = sf::Vertex(sf::Vector2f(width / 2.0f, 0.0f), sf::Color(255, 0, 0, 255));
	gridY[1] = sf::Vertex(sf::Vector2f(width / 2.0f, height), sf::Color(255, 0, 0, 255));

	Graph sin;
	sin.update(width, height);

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
					sin.scale++;
					sin.update(width, height);
				}
				 
				if(event.key.code == sf::Keyboard::Subtract)
				{
					sin.scale--;
					sin.update(width, height);
				}
			}
		}
		
		window.clear(clearColor);

		window.draw(sin.points);

		window.draw(gridX);
		window.draw(gridY);

		window.display();
	}

	return 0;
}