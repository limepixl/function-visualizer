#include <SFML/Graphics.hpp>
#include "math.h"
#include "Graph.h"
#include <iostream>

// Constants
const int width = 1280;
const int height = 720;

int main() {
	sf::RenderWindow window(sf::VideoMode(width, height), "Graph visualizer");
	window.setFramerateLimit(60);

	sf::Color clearColor(255, 255, 255, 255);

	// Grid lines
	sf::VertexArray gridX(sf::LineStrip, 2);
	gridX[0] = sf::Vertex(sf::Vector2f(0.0f, height / 2.0f), sf::Color(255, 0, 0, 255));
	gridX[1] = sf::Vertex(sf::Vector2f(width, height / 2.0f), sf::Color(255, 0, 0, 255));

	sf::VertexArray gridY(sf::LineStrip, 2);
	gridY[0] = sf::Vertex(sf::Vector2f(width / 2.0f, 0.0f), sf::Color(255, 0, 0, 255));
	gridY[1] = sf::Vertex(sf::Vector2f(width / 2.0f, height), sf::Color(255, 0, 0, 255));

	// Vector of graphs (used for when user presses SPACE)
	std::vector<Graph> graphs;

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
				// If Space is pressed, create another graph and query for a function
				if(event.key.code == sf::Keyboard::Space)
				{
					// Insert the function via command prompt
					std::string function;
					std::getline(std::cin, function);

					graphs.emplace_back(function);

					for(auto& g : graphs)
					{
						g.update(width, height);
					}
				}

				// If + is pressed, modify the x and y scaling
				if(event.key.code == sf::Keyboard::Add)
				{
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
					{
						for(auto& g : graphs)
						{
							g.scaleY += 5;
							g.update(width, height);
						}
					} 
					else
					{
						for(auto& g : graphs)
						{
							g.scaleX += 5;
							g.update(width, height);
						}
					}
				}
				 
				// If - is pressed, modify the x and y scaling
				if(event.key.code == sf::Keyboard::Subtract)
				{
					if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
					{
						for(auto& g : graphs)
						{
							g.scaleY -= 5;
							g.update(width, height);
						}
					} 
					else
					{
						for(auto& g : graphs)
						{
							g.scaleX -= 5;
							g.update(width, height);
						}
					}
				}
			}
		}
		
		// Clear window with full white
		window.clear(clearColor);

		// Draw each graph
		for(auto& g : graphs)
		{
			window.draw(g.points);
		}
		
		// Draw gridlines (axes)
		window.draw(gridX);
		window.draw(gridY);

		window.display();
	}

	return 0;
}