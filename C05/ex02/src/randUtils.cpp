/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:05:44 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/04 18:08:19 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/randUtils.hpp"
#include <random>

int rollDie(int min, int max)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}