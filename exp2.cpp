#include<iostream>
using namespace std;

class Complex {
public:
    int real;
    int imaginary;

    // Constructor
    Complex(int r = 0, int i = 0) {
        real = r;
        imaginary = i;
    }

    // Function to add two complex numbers
    Complex add(Complex c1, Complex c2) {
        Complex res;
        res.real = c1.real + c2.real;
        res.imaginary = c1.imaginary + c2.imaginary;
        return res;
    }
};

int main() {
    Complex c1(4, 7);
    Complex c2(3, 5); // Added second complex number

    cout << "Complex number 1: " << c1.real << " + i" << c1.imaginary << endl;
    cout << "Complex number 2: " << c2.real << " + i" << c2.imaginary << endl;

    Complex c3;
    c3 = c3.add(c1, c2); // Corrected function call

    cout << "Sum of complex numbers: " << c3.real << " + i" << c3.imaginary << endl;

    return 0;
}

