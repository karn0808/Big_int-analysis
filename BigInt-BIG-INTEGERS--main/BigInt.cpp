#include "BigInt.h"
#include <algorithm>

// Helper constructor to set value and sign
BigInt::BigInt(const std::string& val) : value(val), isNegative(false) {
    if (val[0] == '-') {
        isNegative = true;
        value = val.substr(1);
    }
}

// Default and int constructor
BigInt::BigInt() : value("0"), isNegative(false) {}
BigInt::BigInt(int val) : value(std::to_string(abs(val))), isNegative(val < 0) {}

// Helper function for addition
BigInt BigInt::add(const BigInt& other) const {
    std::string result;
    int carry = 0;

    // Align lengths by padding the shorter string with leading zeros
    std::string a = this->value;
    std::string b = other.value;
    while (a.size() < b.size()) a.insert(a.begin(), '0');
    while (b.size() < a.size()) b.insert(b.begin(), '0');

    for (int i = a.size() - 1; i >= 0; --i) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result.insert(result.begin(), (sum % 10) + '0');
        carry = sum / 10;
    }
    if (carry) result.insert(result.begin(), carry + '0');
    return BigInt(result);
}

// Other helper operations (to be fully implemented)
BigInt BigInt::subtract(const BigInt& other) const {
    // Implement subtraction logic
    return BigInt();
}

BigInt BigInt::multiply(const BigInt& other) const {
    // Implement multiplication logic
    return BigInt();
}

BigInt BigInt::divide(const BigInt& other) const {
    // Implement division logic
    return BigInt();
}

BigInt BigInt::modulus(const BigInt& other) const {
    // Implement modulus logic
    return BigInt();
}

// Operator overloads
BigInt BigInt::operator+(const BigInt& other) const { return add(other); }
BigInt BigInt::operator-(const BigInt& other) const { return subtract(other); }
BigInt BigInt::operator*(const BigInt& other) const { return multiply(other); }
BigInt BigInt::operator/(const BigInt& other) const { return divide(other); }
BigInt BigInt::operator%(const BigInt& other) const { return modulus(other); }

std::ostream& operator<<(std::ostream& os, const BigInt& bigInt) {
    if (bigInt.isNegative && bigInt.value != "0") os << '-';
    os << bigInt.value;
    return os;
}
