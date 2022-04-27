/*
* CS 202 homework 5
* 4/25/2022
*
* header for
* Main Program 2: template class declarations
* and member function definitions
* and related global functions
* 
*/



#ifndef RATIONAL_HPP
#define RATIONAL_HPP
#include <iostream>
#include <numeric>

// CLASS DECLARATIONS
// 3/2, 5/1, 10/2, 1008882/23428, 1/2*1/3==1/6
// class invariant:
// _denominator is always > 0
template<typename T>
class Rational {

private:
	T _numerator;
	T _denominator;
	void reduce();  // only Rational member fcns can call this

public:
	// Rational() { _numerator=0; _denominator=1; }
	Rational<T>(T=0, T = 1);       // do we not need the <T> ???? for it to match the defintions below?
   

    template<typename T>
	friend std::ostream& operator<<(std::ostream&, const Rational<T>&);

	Rational<T>& operator+=(const Rational<T>&); // does it need it own template thingy??

    template<typename T>
	friend Rational<T> operator+(const Rational<T>&, const Rational<T>&);


	//#if 0
    template<typename T>
	friend Rational<T> operator-(const Rational<T>& lhs);
    template<typename T>
	friend bool operator==(const Rational<T>& lhs, const Rational<T>& rhs);
    template<typename T>
	friend bool operator<(const Rational<T>& lhs, const Rational<T>& rhs);

public:
	Rational<T>& operator-=(const Rational<T>& rhs);
	Rational<T>& operator*=(const Rational<T>& rhs);
	Rational<T>& operator/=(const Rational& rhs);
	Rational<T>& operator++();        //prefix ++
	Rational<T> operator++(int); //postfix ++ // not sure we even need the input so I guess I'll just make it type T?
	Rational<T>& operator--();        //prefix --
	Rational<T> operator--(int); //postfix --
private:

	//#endif
};

//#if 0
// need to be templated sepparately since they are global functions
template<typename T>
Rational<T> operator-(const Rational<T>& lhs, const Rational<T>& rhs);
template<typename T>
Rational<T> operator*(Rational<T> lhs, const Rational<T>& rhs);
template<typename T>
Rational<T> operator/(Rational<T> lhs, const Rational<T>& rhs);
template<typename T>
bool operator!=(const Rational<T>& lhs, const Rational<T>& rhs);
template<typename T>
bool operator>(const Rational<T>& lhs, const Rational<T>& rhs);
template<typename T>
bool operator<=(const Rational<T>& lhs, const Rational<T>& rhs);
template<typename T>
bool operator>=(const Rational<T>& lhs, const Rational<T>& rhs);
//#endif





// CLASS DEFINITIONS 
template<typename T> /// feels wrong ??
Rational<T>::Rational<T>(T num, T den) : _numerator(num), _denominator(den) {
    reduce();
}


template<typename T>
void Rational<T>::reduce() {
    auto gcd = std::gcd(_numerator, _denominator);
    _numerator /= gcd;
    _denominator /= gcd;
    if (_denominator < 0) {
        _numerator *= -1;
        _denominator *= -1;
    }
}

template<typename T> // needs to be have this befor declaration and defintion (so they can look the same)
std::ostream& operator<<(std::ostream& os, const Rational<T>& rhs) {
    os << rhs._numerator;
    if (rhs._denominator != 1)
        os << "/" << rhs._denominator;
    return os;
}

template<typename T>
Rational<T>& Rational<T>::operator+=(const Rational<T>& rhs) {
    // a/b + c/d = (ad+bc)/ad
    _numerator = _numerator * rhs._denominator + rhs._numerator * _denominator;
    _denominator *= rhs._denominator;
    reduce();
    return *this;
}

template<typename T>
Rational<T> operator+(const Rational<T>& lhs, const Rational<T>& rhs) {
    auto temp{ lhs };
    temp += rhs;
    return temp;
}

//#if 0

template<typename T>
Rational<T> operator-(const Rational<T>& lhs) {
    return { -lhs._numerator, lhs._denominator }; // calls reduce since it builds a new one
}

template<typename T>
Rational<T>& Rational<T>::operator-=(const Rational<T>& rhs) { //Canonical
    *this = *this - rhs; //uses Rational::operator- to define operator-=
    return *this;
}

template<typename T>
Rational<T>& Rational<T>::operator*=(const Rational<T>& rhs) {
    _numerator *= rhs._numerator;
    _denominator *= rhs._denominator;
    reduce();
    return *this;
}

template<typename T>
Rational<T>& Rational<T>::operator/=(const Rational<T>& rhs) {
    return *this *= {rhs._denominator, rhs._numerator};
}

template<typename T>
Rational<T> operator-(const Rational<T>& lhs, const Rational<T>& rhs) {
    return lhs + -rhs;
}

// pass lhs by value because we were going to copy it anyway
template<typename T>
Rational<T> operator*(Rational<T> lhs, const Rational<T>& rhs) { //Canonical
    return lhs *= rhs;
}

// pass lhs by value because we were going to copy it anyway
template<typename T>
Rational<T> operator/(Rational<T> lhs, const Rational<T>& rhs) { //Canonical
    return lhs /= rhs;
}

template<typename T>
Rational<T>& Rational<T>::operator++() {//prefix ++
    return *this += 1;
}

template<typename T>
Rational<T> Rational<T>::operator++(int) {//postfix ++
    auto copy{ *this };
    ++(*this);
    return copy; 
}

template<typename T>
Rational<T>& Rational<T>::operator--() {//prefix --
    return *this -= 1;
}

template<typename T>
Rational<T> Rational<T>::operator--(int) {//postfix --
    auto copy{ *this };
    --(*this);
    return copy;
}

template<typename T>  
bool operator==(const Rational<T>& lhs, const Rational<T>& rhs) {
    return lhs._numerator == rhs._numerator && lhs._denominator == rhs._denominator;
}

template<typename T>
bool operator!=(const Rational<T>& lhs, const Rational<T>& rhs) {//canonical
    return !(rhs == lhs);
}

template<typename T>
bool operator<(const Rational<T>& lhs, const Rational<T>& rhs) {
    return lhs._numerator * rhs._denominator < rhs._numerator* lhs._denominator;
}

template<typename T>
bool operator>(const Rational<T>& lhs, const Rational<T>& rhs) {//canonical
    return rhs < lhs;
}

template<typename T>
bool operator<=(const Rational<T>& lhs, const Rational<T>& rhs) {//canonical
    return !(rhs > lhs);
}

template<typename T>
bool operator>=(const Rational<T>& lhs, const Rational<T>& rhs) {//canonical
    return !(rhs < lhs);
}
//#endif


#endif /*RATIONAL_HPP*/