/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 16:27:53 by dickklouwer   #+#    #+#                 */
/*   Updated: 2023/10/18 09:12:24 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

/* Nothing to Copy, so an empty body.
 */
ScalarConverter::ScalarConverter(ScalarConverter& other)
{
}

/* 	No Data members so nothing to assign.
 */
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this == &other)
		return (*this);
	return *this;
}

/*	Identifies the str literal. 
 */
bool ScalarConverter::isInt(const std::string& str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (i == 0 && str[i] == '-')
			continue;
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool ScalarConverter::isFloat(const std::string& str)
{
	bool hasDot = false;

	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (i == 0 && str[i] == '-')
			continue;
		if (str[i] == '.' && hasDot == false)
		{
			hasDot = true;
			continue;
		}
		if (str[i] == 'f' && i == str.size() - 1)
			continue;
		if (!isdigit(str[i]))
			return false;
	}
	return (true);
}

/*	Print functions for after the conversions.  
 */
void	printValue(char val)
{
	if ((val >= 0 && val <= 31) || val == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << val << "'" << std::endl;
}

void	printValue(int val)
{
	std::cout << "int: " << val << std::endl;
}

void	printValue(float val)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << val << "f" << std::endl;
}

void	printValue(double val)
{
	std::cout << "double: " << val << std::endl;
}

/*	Check if the Conversion is between the boundaries and so is possible. 
 */
template <typename T>

bool isConversionPossible(T value, T minLimit, T maxLimit)
{
	return value >= minLimit && value <= maxLimit;
}

/*	 Converts and prints the value of the literal to Char conversion.
 */
void	convertChar(std::string& literal)
{
	char c = literal[0];
	printValue(c);

	int intVal = static_cast<int>(c);
	printValue(intVal);

	float floatVal = static_cast<float>(c);
	printValue(floatVal);

	double doubleVal = static_cast<double>(c);
	printValue(doubleVal);
}

/*	 Converts and prints the value of the literal to Integer conversion.
 */
void	convertInt(std::string& literal)
{
	int intVal = std::atoi(literal.c_str());
	if (isConversionPossible<int>(intVal, std::numeric_limits<char>::min(), std::numeric_limits<char>::max()))
		printValue(static_cast<char>(intVal));
	else
		std::cout << "char: impossible" << std::endl;

	printValue(intVal);

	float floatVal = static_cast<float>(intVal);
	printValue(floatVal);

	double doubleVal = static_cast<double>(intVal);
	printValue(doubleVal);
}

/*	 Converts and prints the value of the literal to Float conversion.
 */
void	convertFloat(std::string& literal)
{
	float floatVal = std::atof(literal.c_str());

	if (isConversionPossible<float>(floatVal, std::numeric_limits<char>::min(), std::numeric_limits<char>::max()))
		printValue(static_cast<char>(floatVal));
	else
		std::cout << "char: impossible" << std::endl;

	if (isConversionPossible<float>(floatVal, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()))
		printValue(static_cast<int>(floatVal));
	else
		std::cout << "int: impossible" << std::endl;

	printValue(floatVal);

	double doubleVal = static_cast<double>(floatVal);
	printValue(doubleVal);
}

void	ScalarConverter::convert(std::string& literal)
{
	if (literal.size() == 1 && !isdigit(literal[0]))
	{
		convertChar(literal);
	}
	else if (isInt(literal))
	{
		convertInt(literal);
	}
	else if (isFloat(literal))
	{
		convertFloat(literal);
	}
}