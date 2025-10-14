/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:13:07 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/14 20:30:32 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/data.hpp"
#include <iostream>
#include <stdint.h>

int main (void)
{
	Data data;
	Data *data2;
	uintptr_t ptr;

	data.n = 31415926;
	data.str = "data of no importance";
	ptr = Serializer::serialize(&data);
	data2 = Serializer::deserialize(ptr);
	std::cout << "data ptr representation: " << &data << "\n";
	std::cout << "data uintptr representation: " << ptr << "\n";
	std::cout << "data2 ptr representation: " << data2 << "\n";
	std::cout << "addresses before and after are "<< (&data == data2 ? "" : "not ") << "equal\n";
	return (0);
}