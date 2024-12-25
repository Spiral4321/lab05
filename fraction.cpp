#include "fraction.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a < 0 ? -a : a; 
}

void Fraction::simplify() {
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denom == 0) {
        throw invalid_argument("Denominator cannot be zero.");
    }
    simplify();
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setNumerator(int num) {
    numerator = num;
    simplify();
}

void Fraction::setDenominator(int denom) {
    if (denom == 0) {
        throw invalid_argument("Denominator cannot be zero.");
    }
    denominator = denom;
    simplify();
}

Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(numerator * other.denominator + other.numerator * denominator,
                    denominator * other.denominator);
}

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(numerator * other.denominator - other.numerator * denominator,
                    denominator * other.denominator);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        throw invalid_argument("Division by zero is not allowed.");
    }
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator++(int) { 
    Fraction temp = *this;
    ++(*this);
    return temp;
}

Fraction& Fraction::operator--() { 
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator--(int) { 
    Fraction temp = *this;
    --(*this);
    return temp;
}

bool Fraction::operator==(const Fraction& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Fraction::operator>(const Fraction& other) const {
    return other < *this;
}

bool Fraction::operator<=(const Fraction& other) const {
    return !(other < *this);
}

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

void Fraction::display() const {
    cout << numerator << "/" << denominator;
}
