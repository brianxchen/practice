#pragma once
#include "Common.h"

class Complex {
	public:
		double re;
		double im;
		Complex() {

		}
		Complex(double re, double im) {
			this->re = re;
			this->im = im;
		}
		string ToString() {
			return to_string(re) + " + " + to_string(im) + "i";
		}

		void add(const Complex& b) {
			re += b.re;
			im += b.im;
		}

		Complex operator+(const Complex& b) {
			Complex res;
			res.re = this->re + b.re;
			res.im = this->im + b.im;
			return res;
		}
};

/*
	Complex a(2.0, 5.0);
	Complex b(-1.0, 3.0);
	Complex c(2.0, 5.0);
	Complex d(-1.0, 3.0);
	cout << a.ToString();
	a.add(b);
	cout << a.ToString() << endl;


	Complex e = c + d;
	cout << e.ToString();

*/