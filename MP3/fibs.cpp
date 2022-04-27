
/*
* CS 202 homework 5
* 4/27/2022
*
* 
* Main Program 3: file containing fib and fib_loop 
* function defintions
*/




int fib(int n) {
	if (n == 0) { return 0; }
	else if (n == 1) { return 1; }
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