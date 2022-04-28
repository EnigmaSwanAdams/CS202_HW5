
/*
* CS 202 homework 5
* 4/27/2022
*
*
* Main Program 3: file containing ack function definition
*/

unsigned int ack(unsigned int m, unsigned int n) {
	

	if (m == 0) {
		return n + 1;
	}
	else if ((m > 0) && (n == 0)) {
		return ack(m - 1, 1);
	}
	else {
		return ack(m - 1, ack(m, n - 1));
	}
}