#include "Graph.h"
#include "math.h"
#include "parser.h"

Graph::Graph(std::string& function)
	: n(1000), scale(1.0f), function(function)
{
	points = sf::VertexArray(sf::LineStrip, n); 
}

void Graph::update(int width, int height)
{
	points.clear();

	std::vector<Token> postfixTokens = parser::parse(function);
	
	for(int i = 0; i <= n; i++)
	{
		// Creates n+1 points separated equally from 0 to width
		float currentX = (float)width / n * i; 

		// Map x between scale * PI in both directions
		float mappedX = math::map(currentX, 0.0f, (float)width, -scale * math::PI, scale * math::PI);

		// Actual function
		float funVal = calcY(mappedX, postfixTokens);
		float currentY = (float)height / 2.0f - 20.0f * funVal;

		points.append(sf::Vertex(sf::Vector2f(currentX, currentY), sf::Color(0, 0, 0, 255)));
	}
}

float Graph::calcY(float x, std::vector<Token> postfixTokens)
{
	for(int i = 0; i < postfixTokens.size(); i++)
	{
		Token& currentToken = postfixTokens[i];

		if(currentToken.type == VARIABLE)
		{
			currentToken.variableName = "";
			currentToken.type = NUMBER;
			currentToken.value = x;
		}

		if(currentToken.type == OPERATION)
		{
			switch(postfixTokens[i].operation)
			{
			case ADD:
				postfixTokens[i - 2].value = postfixTokens[i - 2].value + postfixTokens[i - 1].value;
				postfixTokens.erase(postfixTokens.begin() + i - 1, postfixTokens.begin() + i + 1);
				break;
			case SUBTRACT:
				postfixTokens[i - 2].value = postfixTokens[i - 2].value - postfixTokens[i - 1].value;
				postfixTokens.erase(postfixTokens.begin() + i - 1, postfixTokens.begin() + i + 1);
				break;
			case MULTIPLY:
				postfixTokens[i - 2].value = postfixTokens[i - 2].value * postfixTokens[i - 1].value;
				postfixTokens.erase(postfixTokens.begin() + i - 1, postfixTokens.begin() + i + 1);
				break;
			case DIVIDE:
				postfixTokens[i - 2].value = postfixTokens[i - 2].value / postfixTokens[i - 1].value;
				postfixTokens.erase(postfixTokens.begin() + i - 1, postfixTokens.begin() + i + 1);
				break;
			case POW:
				postfixTokens[i - 2].value = pow(postfixTokens[i - 2].value, postfixTokens[i - 1].value);
				postfixTokens.erase(postfixTokens.begin() + i - 1, postfixTokens.begin() + i + 1);
				break;
			case SQRT:
				postfixTokens[i - 1].value = sqrt(postfixTokens[i - 1].value);
				postfixTokens.erase(postfixTokens.begin() + i, postfixTokens.begin() + i + 1);
				break;
			case SIN:
				postfixTokens[i - 1].value = sin(postfixTokens[i - 1].value);
				postfixTokens.erase(postfixTokens.begin() + i, postfixTokens.begin() + i + 1);
				break;
			case COS:
				postfixTokens[i - 1].value = cos(postfixTokens[i - 1].value);
				postfixTokens.erase(postfixTokens.begin() + i, postfixTokens.begin() + i + 1);
				break;
			case TAN:
				postfixTokens[i - 1].value = tan(postfixTokens[i - 1].value);
				postfixTokens.erase(postfixTokens.begin() + i, postfixTokens.begin() + i + 1);
				break;
			case COT:
				postfixTokens[i - 1].value = 1.0f / tan(postfixTokens[i - 1].value);
				postfixTokens.erase(postfixTokens.begin() + i, postfixTokens.begin() + i + 1);
				break;
			}

			i = -1;
		}
	}

	return postfixTokens.back().value;
}
