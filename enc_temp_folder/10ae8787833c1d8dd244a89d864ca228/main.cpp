
/*
* CS 202 homework 5
* 4/27/2022
*
* file containing main for the
* Main Program 3: includes both function defintions
* and the main where I test the functions
*/



#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int fib(int);
int fib_loop(int);

int main() {
	const int NUM_FIBS = 1000;

	for(int i=0; i<NUM_FIBS; i++){
		cout << fib(i) << " should equal " << fib_loop(i) << endl;
		if (fib(i) != fib_loop(i)) { cout << "ERROR THEY ARE NOT EQUAL\N"; }
		if ((fib(i) < 0) || (fib_loop(i) < 0)) { 
			cout << "OVERFLOW OCCURED STOPPING CALCULATION\N"; 
			break;
		}
	}

	return 0;
}



int fib(int n) {
	if (n == 0) { return 0; }
	else if (n == 1) { return 1;  }
	else {
		return fib(n - 1) + fib(n - 2);
	}
	
}

int fib_loop(int n) {
	if (n == 0) { return 0; }
	else if (n == 1) { return 1; }
	else {
		int lastLast = 0; // F0 to start in general Fn-2
		int last = 1; // F1 tp start in general Fn-1

		for (int i = 3; i <= n; i++) {
			int temp = lastLast;
			lastLast = last; 
			last = last + temp;
		}

		return last + lastLast; 
	}
}