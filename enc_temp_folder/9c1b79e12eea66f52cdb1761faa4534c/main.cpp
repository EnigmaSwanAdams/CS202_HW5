
/*
* CS 202 homework 5
* 4/27/2022
*
* file containing main for the
* Main Program 3: contains tests/proof of functionality 
* for all three functions in main program 3 (MP3)
*/



#include <iostream>
#include <vector>
#include "Header.h"
using std::cout;
using std::endl;
using std::vector;

int main() {
	const int MAX_NUM_FIBS = 1000;

	for(int i=0; i<MAX_NUM_FIBS; i++){
		//cout << fib(i) << " should equal " << fib_loop(i) << endl;
		if (fib(i) != fib_loop(i)) { cout << "ERROR THEY ARE NOT EQUAL\N"; }
		if ((fib(i) < 0) || (fib_loop(i) < 0)) { 
			cout << "OVERFLOW OCCURED STOPPING CALCULATION\N"; 
			break;
		}
	}
	cout << "finished" << endl;
	return 0;
}



