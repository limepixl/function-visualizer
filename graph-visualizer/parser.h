#pragma once
#include <string>
#include <vector>
#include "Graph.h"

enum TokenType
{
	NUMBER,
	OPERATION,
	LEFT_BRACKET,
	RIGHT_BRACKET,
	VARIABLE
};

enum Operation
{
	NULL_OP,
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	POW,
	SQRT,
	SIN,
	COS,
	TAN,
	COT
};

enum Assoc
{
	Left,
	Right
};

struct Token
{
	TokenType type;
	Operation operation;
	Assoc assoc;

	std::string variableName;
	int precedence;
	double value;
};


namespace parser
{
	// Parse the function into a vector of tokens
	std::vector<Token> parse(std::string& function);

	// Parse the function contained in a string
	std::vector<std::string> split(std::string string);

	// Uses the Shunting yard algorithm to convert tokens into postfix notation
	std::vector<Token> parseShuntingYard(std::vector<std::string>& tokens);

	// Parse string into token struct
	Token parseToken(std::string& token);
}