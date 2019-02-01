#pragma once
#include <SFML/Graphics.hpp>

struct Graph
{
	int n;
	float scale;
	
	sf::VertexArray points;

	Graph();

	void update(int width, int height);
};