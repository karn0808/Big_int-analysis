#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class BigInt {
private:
    std::vector<int> digits;

    void removeLeadingZeros();

public:
    BigInt();
    BigInt(const std::string& num);

    BigInt operator+(const BigInt& other) const;
    BigInt operator-(const BigInt& other) const;
    BigInt operator*(const BigInt& other) const;
    BigInt operator/(const BigInt& other) const;
    static BigInt factorial(int n);
    static BigInt catalan(int n);
    void display() const;
};

#endif // BIGINT_H
