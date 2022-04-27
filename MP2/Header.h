



#ifndef RATIONAL_HPP
#define RATIONAL_HPP
#include <iostream>

// 3/2, 5/1, 10/2, 1008882/23428, 1/2*1/3==1/6
// class invariant:
// _denominator is always > 0
class Rational {

private:
	int _numerator;
	int _denominator;
	void reduce();  // only Rational member fcns can call this

public:
	// Rational() { _numerator=0; _denominator=1; }
	Rational(int, int = 1);
	friend std::ostream& operator<<(std::ostream&, const Rational&);
	Rational& operator+=(const Rational&);
	friend Rational operator+(const Rational&, const Rational&);


//#if 0
	friend Rational operator-(const Rational& lhs);
	friend bool operator==(const Rational& lhs, const Rational& rhs);
	friend bool operator<(const Rational& lhs, const Rational& rhs);

public:
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);
	Rational& operator++();        //prefix ++
	Rational operator++(int); //postfix ++
	Rational& operator--();        //prefix --
	Rational operator--(int); //postfix --
private:

//#endif
};

//#if 0
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(Rational lhs, const Rational& rhs);
Rational operator/(Rational lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);
//#endif

#endif
