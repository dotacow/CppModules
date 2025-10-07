/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:05:44 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/07 14:42:54 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/randUtils.hpp"
#include <ctime>
#include <cstdlib>

int rollDie(int min, int max)
{
	return min + rand() % (max - min + 1);
}