
/*
* CS 202 homework 5
* 4/25/2022
*
* file containing main for the
* Main Program 2: just for personal testing 
*/




#include "Rational.hpp";




int main() {

	Rational<int> zero;
	auto half = Rational<int>(1, 2);
	std::cout << zero << "\n" << half << std::endl;
	
	Rational<int> oneThird = Rational(1, 3);
	zero *= half;
	std::cout << zero;
	return 0;
}