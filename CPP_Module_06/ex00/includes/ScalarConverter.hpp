/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 16:27:56 by dickklouwer   #+#    #+#                 */
/*   Updated: 2023/10/18 09:11:35 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>

/*	Static Class: ScalarConverter, the constructor is private.
 */
class ScalarConverter { 
	private:
		ScalarConverter();
		ScalarConverter(std::string& str);
		ScalarConverter(ScalarConverter &other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static bool isFloat(const std::string& str);
		static bool isInt(const std::string& str);

	public:
		static void	convert(std::string& literal);
};


#endif
