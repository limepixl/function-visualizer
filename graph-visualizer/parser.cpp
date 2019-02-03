#include "parser.h"
#include <vector>
#include <iostream>

namespace parser
{
	std::vector<Token> parse(std::string& function)
	{
		// Split string into tokens
		std::vector<std::string> tokens = split(function);

		// Parsed tokens arranged into postfix notation
		return parseShuntingYard(tokens);
	}

	std::vector<Token> parseShuntingYard(std::vector<std::string>& tokens)
	{
		std::vector<Token> outputQueue;
		std::vector<Token> operatorStack;

		for(auto& token : tokens)
		{
			Token current = parseToken(token);

			if(current.type == NUMBER)
			{
				outputQueue.push_back(current);
			} 
			else if(current.type == VARIABLE)
			{
				outputQueue.push_back(current);
			}
			else if(current.type == OPERATION)
			{
				while(!operatorStack.empty())
				{
					Token& topOfStack = operatorStack.back();
					if((current.assoc == Assoc::Left && current.precedence == topOfStack.precedence) || current.precedence < topOfStack.precedence)
					{
						outputQueue.push_back(operatorStack.back());
						operatorStack.pop_back();
					} else
						break;
				} 

				operatorStack.push_back(current);
			} 
			else if(current.type == TokenType::LEFT_BRACKET)
			{
				operatorStack.push_back(current);
			} 
			else if(current.type == TokenType::RIGHT_BRACKET)
			{
				while(operatorStack.back().type != TokenType::LEFT_BRACKET)
				{
					outputQueue.push_back(operatorStack.back());
					operatorStack.pop_back();
				}

				operatorStack.pop_back();
			}
		}

		while(!operatorStack.empty())
		{
			outputQueue.push_back(operatorStack.back());
			operatorStack.pop_back();
		}

		return outputQueue;
	}

	Token parseToken(std::string& token)
	{
		Token current;

		if(token == "+")
		{
			current.type = OPERATION;
			current.operation = ADD;
			current.assoc = Left;
			current.precedence = 2;
		} else if(token == "-")
		{
			current.type = OPERATION;
			current.operation = SUBTRACT;
			current.assoc = Left;
			current.precedence = 2;
		} else if(token == "*")
		{
			current.type = OPERATION;
			current.operation = MULTIPLY;
			current.assoc = Left;
			current.precedence = 3;
		} else if(token == "/")
		{
			current.type = OPERATION;
			current.operation = DIVIDE;
			current.assoc = Left;
			current.precedence = 3;
		} else if(token == "^")
		{
			current.type = OPERATION;
			current.operation = POW;
			current.assoc = Right;
			current.precedence = 4;
		} else if(token == "sqrt")
		{
			current.type = OPERATION;
			current.operation = SQRT;
			current.assoc = Left;
			current.precedence = 4;
		} else if(token == "(")
		{
			current.type = LEFT_BRACKET;
		} else if(token == ")")
		{
			current.type = RIGHT_BRACKET;
		} else if(isdigit(token[0]))
		{
			current.type = NUMBER;
			current.value = atof(token.c_str());
		} else if(token == "sin")
		{
			current.type = OPERATION;
			current.operation = SIN;
			current.assoc = Left;
			current.precedence = 4;
		} else if(token == "cos")
		{
			current.type = OPERATION;
			current.operation = COS;
			current.assoc = Left;
			current.precedence = 4;
		} else if(token == "tan")
		{
			current.type = OPERATION;
			current.operation = TAN;
			current.assoc = Left;
			current.precedence = 4;
		} else if(token == "cot")
		{
			current.type = OPERATION;
			current.operation = COT;
			current.assoc = Left;
			current.precedence = 4;
		} else if(token == "x")
		{
			current.type = VARIABLE;
			current.variableName = token;
		}

		return current;
	}

	std::vector<std::string> split(std::string string)
	{
		std::vector<std::string> tokens;

		while(!string.empty())
		{
			auto pos = string.find_first_of(' ');

			if(pos != std::string::npos)
			{
				tokens.emplace_back(string.begin(), string.begin() + pos);
				string.erase(string.begin(), string.begin() + pos + 1);
			} else
			{
				tokens.emplace_back(string.begin(), string.end());
				string.erase(string.begin(), string.end());
			}
		}

		return tokens;
	}
}
