#include "fraction.h"
#include <iostream>
#include <stdexcept>

using namespace std;


Fraction::Fraction() : numerator(0), denominator(1) {}


Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    if (denom == 0) {
        throw invalid_argument("Denominator cannot be zero.");
    }
}


int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}


void Fraction::setNumerator(int num) {
    numerator = num;
}

void Fraction::setDenominator(int denom) {
    if (denom == 0) {
        throw invalid_argument("Denominator cannot be zero.");
    }
    denominator = denom;
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
