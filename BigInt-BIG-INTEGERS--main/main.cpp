#include "BigInt.h"

// Implementation of BigInt methods

void BigInt::removeLeadingZeros() {
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
}

BigInt::BigInt() {}

BigInt::BigInt(const std::string& num) {
    for (char c : num) {
        if (isdigit(c)) {
            digits.push_back(c - '0');
        }
    }
    std::reverse(digits.begin(), digits.end());
    removeLeadingZeros();
}

// Function to add two BigInts
BigInt BigInt::operator+(const BigInt& other) const {
    BigInt result;
    int carry = 0, sum;
    size_t maxLength = std::max(digits.size(), other.digits.size());

    for (size_t i = 0; i < maxLength || carry; ++i) {
        sum = carry;
        if (i < digits.size()) sum += digits[i];
        if (i < other.digits.size()) sum += other.digits[i];
        result.digits.push_back(sum % 10);
        carry = sum / 10;
    }

    return result;
}

// Function to subtract two BigInts
BigInt BigInt::operator-(const BigInt& other) const {
    // Assume the first number is larger than the second for simplicity
    BigInt result;
    int borrow = 0;

    for (size_t i = 0; i < digits.size(); ++i) {
        int sub = digits[i] - borrow;
        if (i < other.digits.size()) sub -= other.digits[i];

        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.digits.push_back(sub);
    }

    result.removeLeadingZeros();
    return result;
}

// Function to multiply two BigInts
BigInt BigInt::operator*(const BigInt& other) const {
    BigInt result;
    result.digits.resize(digits.size() + other.digits.size(), 0);

    for (size_t i = 0; i < digits.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < other.digits.size() || carry; ++j) {
            long long current = result.digits[i + j] + carry;
            if (j < other.digits.size()) {
                current += digits[i] * other.digits[j];
            }
            result.digits[i + j] = current % 10;
            carry = current / 10;
        }
    }

    result.removeLeadingZeros();
    return result;
}

// Function to divide two BigInts (only for simplicity)
BigInt BigInt::operator/(const BigInt& other) const {
    // Placeholder implementation, division can be complex
    return BigInt("0");
}

// Function to calculate factorial
BigInt BigInt::factorial(int n) {
    BigInt result("1");
    for (int i = 2; i <= n; ++i) {
        BigInt temp(std::to_string(i));
        result = result * temp;
    }
    return result;
}

// Function to calculate Catalan number
BigInt BigInt::catalan(int n) {
    BigInt num = factorial(2 * n);
    BigInt denom1 = factorial(n + 1);
    BigInt denom2 = factorial(n);
    return num / (denom1 * denom2);
}

// Function to display the BigInt
void BigInt::display() const {
    if (digits.empty()) {
        std::cout << "0";
        return;
    }
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        std::cout << *it;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    BigInt num1("1000000000000000000000000000000");
    BigInt num2("123456789012345678901234567890");

    BigInt sum = num1 + num2;
    std::cout << "Sum: ";
    sum.display(); // Display the result of addition

    BigInt difference = num1 - num2;
    std::cout << "Difference: ";
    difference.display(); // Display the result of subtraction

    BigInt product = num1 * num2;
    std::cout << "Product: ";
    product.display(); // Display the result of multiplication

    BigInt quotient = num1 / num2;
    std::cout << "Quotient: ";
    quotient.display(); // Placeholder for division

    int n = 10; // Example number for factorial and Catalan
    BigInt fact = BigInt::factorial(n);
    std::cout << "Factorial of " << n << " is: ";
    fact.display();

    BigInt cat = BigInt::catalan(n);
    std::cout << "Catalan number C(" << n << ") is: ";
    cat.display();

    return 0;
}

