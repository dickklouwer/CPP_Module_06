/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serialization.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 07:22:10 by dickklouwer   #+#    #+#                 */
/*   Updated: 2023/10/18 09:16:11 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>
#include <string.h>

/*	Non-Empty Data structure. 
 */
typedef struct	Data
{
	std::string _name;
	int			age;
	struct Data	*next;
}				Data;

/*	Class Serializer. 
 */
class Serializer {
	private:
		
	public:
		Serializer();
		~Serializer();

		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		/* Methods */
		uintptr_t	serialize(Data *ptr); // It takes a pointer and converts it to the unsigned integer type uintptr_t.
		Data*		deserialize(uintptr_t raw); // It takes an unsigned integer parameter and converts it to a pointer to Data.
		
};