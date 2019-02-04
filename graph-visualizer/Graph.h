#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

struct Graph
{
	// Number of points composing each graph
	int n;

	// Scaling values
	float scaleX;
	float scaleY;
	
	// Array of points
	sf::VertexArray points;

	// Function to be evaluated
	std::string function;

	Graph(std::string& function);

	// Recalculate points based on scaling values
	void update(int width, int height);

	// Calculate the Y coordinate for a given X coordinate, and the given 
	// evaluated function in postfix notation
	double calcY(float x, std::vector<struct Token> postfixTokens);
};