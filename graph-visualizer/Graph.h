#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

struct Graph
{
	int n;
	float scale;
	
	sf::VertexArray points;

	std::string function;

	Graph(std::string& function);

	void update(int width, int height);

	float calcY(float x, std::vector<struct Token> postfixTokens);
};