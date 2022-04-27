
/*
* CS 202 homework 5
* 4/27/2022
*
* file containing main for the
* Main Program 3: includes both function defintions
* and the main where I test the functions
*/
#include <iostream>
using std::cout;


int fib(int);
int fib_loop(int);

int main() {

	cout << fib_loop(7);

	return 0;
}



int fib(int n) {
	if (n == 0) { return 0; }
	else if (n == 1) { return 1;  }
	else {
		
	}
	return 0; // TEMP
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