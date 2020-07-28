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