/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dickklouwer <tklouwer@student.codam.nl>      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/19 07:15:05 by dickklouwer   #+#    #+#                 */
/*   Updated: 2023/10/19 07:51:23 by dickklouwer   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base*	generate(void) 
{
	switch(rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			std::cerr << "Error in switch statement" << std::endl;
			return (NULL);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer has been identified as: type A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer has been identified as: type B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer has been identified as: type C" << std::endl;
	else
		std::cout << "Unknown type ..." << std::endl;
}

void	identify(Base &p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "Reference to object has been identified as: Type A" << std::endl;
	}
	catch (...) {
		try {
			B &b = dynamic_cast<B&>(p);
			std::cout << "Reference to object has been identified as: Type B" << std::endl;
		}
		catch (...) {
			try
			{
				C &c = dynamic_cast<C &>(p);
				std::cout << "Reference to object has been identified as: Type C" << std::endl;
			}
			catch (...) {
				std::cerr << "Unkown type ..." << std::endl;
			}
		}
	}
}

int main() 
{
	srand(static_cast<unsigned int>(time(NULL)));

	const int numOfTests = 10;

	for (int i = 0; i < numOfTests; ++i)
	{
		Base *randomObject = generate();
	
		identify(randomObject);
		identify(*randomObject);

		std::cout << "-------------------" << std::endl;

		delete randomObject;
	}

	return 0;
}