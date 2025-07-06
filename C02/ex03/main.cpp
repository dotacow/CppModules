/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:18:42 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/07 00:55:59 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"


void test(const char* name, const Point& a, const Point& b, const Point& c, const Point& p, bool expected) {
	bool result = quickmafs::bsp(a, b, c, p);
	std::cout << name << ": " << (result == expected ? "PASS" : "FAIL")
	          << " (expected " << expected << ", got " << result << ")\n";
}

int main() {
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(10), Fixed(0));
	Point c(Fixed(0), Fixed(10));

	// Inside
	test("Inside triangle", a, b, c, Point(Fixed(2), Fixed(2)), true);

	// On edge
	test("On AB edge", a, b, c, Point(Fixed(5), Fixed(0)), false);
	test("On AC edge", a, b, c, Point(Fixed(0), Fixed(5)), false);
	test("On BC edge", a, b, c, Point(Fixed(5), Fixed(5)), false);

	// On vertex
	test("On vertex A", a, b, c, Point(Fixed(0), Fixed(0)), false);
	test("On vertex B", a, b, c, Point(Fixed(10), Fixed(0)), false);
	test("On vertex C", a, b, c, Point(Fixed(0), Fixed(10)), false);

	// Outside
	test("Outside right", a, b, c, Point(Fixed(11), Fixed(1)), false);
	test("Outside top", a, b, c, Point(Fixed(1), Fixed(11)), false);
	test("Outside far", a, b, c, Point(Fixed(100), Fixed(100)), false);

	// Edge case: zero area triangle (all points same)
	Point degenerate(Fixed(1), Fixed(1));
	test("Degenerate triangle", degenerate, degenerate, degenerate, degenerate, false);

	// Edge case: colinear triangle (no area)
	Point col1(Fixed(0), Fixed(0));
	Point col2(Fixed(5), Fixed(5));
	Point col3(Fixed(10), Fixed(10));
	test("Colinear point on line", col1, col2, col3, Point(Fixed(2), Fixed(2)), false);
	test("Colinear point not on line", col1, col2, col3, Point(Fixed(2), Fixed(3)), false);

	return 0;
}
