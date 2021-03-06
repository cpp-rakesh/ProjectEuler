/*
  This is solution for problem 55 (Lychrel numbers) from ProjectEuler.net.
  Author : Rakesh Kumar @ cpp.rakesh@gmail.com
  Date : June 2nd, 2016
*/

#include "problem_55.h"
#include "integer.h"
#include "common.h"
#include <cstdio>

namespace pp = project_euler::problems;

pp::Problem_55::Problem_55() {}

pp::Problem_55::~Problem_55() {}

void pp::Problem_55::lychrel_numbers(int max) const {
    int count = 0;
    for (int i = 10; i < max; ++i)
	if (m_is_lychrel_number(i))
	    ++count;

    printf("Lychrel numbers under %d == [%d]\n", max, count);
}

bool pp::Problem_55::m_is_lychrel_number(int n) const {
    utility::integer::Integer number(n);
    utility::common::Common<int> common;

    for (int i = 0; i < 50; ++i) {
	number += number.get_reverse();
	if (common.is_palindrome(number.get_reverse()))
	    return false;
    }

    return true;
}
