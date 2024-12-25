#include "fraction.h"
#include <iostream>

using namespace std;

int main() {
    Fraction f1(3, 4);  // 3/4
    Fraction f2(2, 5);  // 2/5

    cout << "Fraction 1: ";
    f1.display();
    cout << "\nFraction 2: ";
    f2.display();
    cout << "\n";

    // Addition
    Fraction sum = f1 + f2;
    cout << "Sum: ";
    sum.display();
    cout << "\n";

    // Subtraction
    Fraction diff = f1 - f2;
    cout << "Difference: ";
    diff.display();
    cout << "\n";

    // Multiplication
    Fraction prod = f1 * f2;
    cout << "Product: ";
    prod.display();
    cout << "\n";

    // Division
    Fraction div = f1 / f2;
    cout << "Quotient: ";
    div.display();
    cout << "\n";

    // Increment and Decrement
    cout << "Fraction 1 after prefix increment: ";
    (++f1).display();
    cout << "\n";

    cout << "Fraction 1 after postfix increment: ";
    (f1++).display();
    cout << " (original value)\n";
    f1.display();
    cout << " (after increment)\n";

    // Comparison
    cout << "Is Fraction 1 == Fraction 2? " << (f1 == f2 ? "Yes" : "No") << "\n";
    cout << "Is Fraction 1 != Fraction 2? " << (f1 != f2 ? "Yes" : "No") << "\n";
    cout << "Is Fraction 1 < Fraction 2? " << (f1 < f2 ? "Yes" : "No") << "\n";
    cout << "Is Fraction 1 > Fraction 2? " << (f1 > f2 ? "Yes" : "No") << "\n";

    return 0;
}
