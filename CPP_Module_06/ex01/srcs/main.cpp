/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 08:11:35 by dickklouwer   #+#    #+#                 */
/*   Updated: 2023/10/18 08:48:47 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serialization.hpp"

int main() 
{
	Data	king;

	king._name = "Arthur";
	king.age = 42;
	king.next = NULL;

	std::cout << "Address: " << &king << " Name: " << king._name << " Age: " << king.age << std::endl << std::endl;

	Serializer serializer;

	std::cout << "Serializing ... " << std::endl;

	Data *serializedData = serializer.deserialize(serializer.serialize(&king));

	std::cout << "Original Data Name: 	" << king._name << " Address: "  << &king << " Age: " << king.age << std::endl;
	std::cout << "Deserialized Data Name: " << serializedData->_name << " Address: " << serializedData << " Age: " << serializedData->age << std::endl;
	
	std::cout << "Serialization complete!" << std::endl;
	return 0;
}