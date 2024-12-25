 #ifndef FRACTION_H
#define FRACTION_H

class Fraction {
private:
    int numerator;
    int denominator;
    void simplify(); 

public:
    Fraction(); 
    Fraction(int num, int denom); 

   
    int getNumerator() const;
    int getDenominator() const;

    
    void setNumerator(int num);
    void setDenominator(int denom);

    
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    Fraction& operator++();    
    Fraction operator++(int); 
    Fraction& operator--();    
    Fraction operator--(int); 

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

    
    void display() const;
};

#endif 
