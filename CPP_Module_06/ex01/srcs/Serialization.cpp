/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serialization.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 07:22:13 by dickklouwer   #+#    #+#                 */
/*   Updated: 2023/10/18 09:18:50 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serialization.hpp"

Serializer::Serializer() {
	
}

Serializer::~Serializer() {
	
}

Serializer::Serializer(const Serializer& other)
{
}

Serializer&	Serializer::operator=(const Serializer& other)
{
	if (this == &other)
		return (*this);
	return *this;
}

uintptr_t	Serializer::serialize(Data *ptr) 
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}