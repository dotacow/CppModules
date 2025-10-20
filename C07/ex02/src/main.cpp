/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:05:12 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/20 17:14:20 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <iostream>

int main(void)
{
	Array<int> numbers(5);
	Array<std::string> words;
	std::cout << "words size: " << words.size() << "\n";
	Array<std::string> moreWords(3);
	moreWords[0] = "Hello";
	moreWords[1] = "World";
	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;

	std::cout << "words size before copy: " << words.size() << "\n";
	std::cout << "moreWords size: " << moreWords.size() << "\n";
	words = moreWords;
	try
	{
		std::cout << "words size after copy: " << words.size() << "\n";
		std::cout << "moreWords size: " << moreWords.size() << "\n";
		for (unsigned int i = 0; i < moreWords.size(); i++)
			std::cout << "moreWords[" << i << "]: " << moreWords[i] << "\n";
		for (unsigned int i = 0; i <= numbers.size(); i++)
			std::cout << "numbers[" << i << "]: " << numbers[i] << "\n";
	}
	catch(const std::exception& e){
		std::cerr << e.what() << "\n";
	}
	return (0);
}