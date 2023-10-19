/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 08:38:59 by dickklouwer   #+#    #+#                 */
/*   Updated: 2023/10/12 08:13:21 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv) 
{
	if (argc != 2)
		std::cerr << "Usage: ./ScalarConverter StringLiteral" << std::endl;
	
	std::string str = argv[1];

	ScalarConverter::convert(str);
}