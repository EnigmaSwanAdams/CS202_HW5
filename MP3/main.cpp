
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
#include "fibs.h"
#include "ack.h"
using std::cout;
using std::endl;
using std::vector;

int main() {
	// demonstration of fib and fib_loop 
	const int MAX_NUM_FIBS = 30;
	cout << "Printing fibbonacci test. Note the format is index: fib result, fib_loop result\n";
	cout << "An error should be printed out if an overflow occurs, or the function outputs aren't equal\n";
	for(int i=0; i<MAX_NUM_FIBS; i++){
		cout << i << ": ";
		cout << fib(i) << ", " << fib_loop(i) << endl;
		if (fib(i) != fib_loop(i)) { cout << "ERROR THEY ARE NOT EQUAL\N"; }
		if ((fib(i) < 0) || (fib_loop(i) < 0)) { 
			cout << "OVERFLOW OCCURED STOPPING CALCULATION\N"; 
		}
	}
	cout << "finished printing fibbonacci results\n" << endl;

	// demonstration of ack function 
	cout << ack(2,1);
	return 0;
}



