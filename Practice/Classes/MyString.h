#pragma once
#include "Common.h"

class MyString {
	public:
		MyString(const char* pChar) {
			capacity = strlen(pChar) + 1;
			buffer = new char[capacity];
			memcpy(buffer, pChar, capacity);
		}
		MyString(int capacity) {
			this->capacity = capacity;
			buffer = new char[capacity];
		}
		char& operator[](int index) {
			if (index >= strlen(buffer)) {
				cout << "Array index out of bound, exiting";
				exit(0);
			}
			return buffer[index];
		}

		MyString operator+(const MyString& b) {
			int lenA = strlen(buffer);
			int lenB = strlen(b.buffer);
			int lenRes = lenA + lenB;
			MyString res(lenRes + 1);


			memcpy(res.buffer, buffer, lenA);
			memcpy(res.buffer + lenA, b.buffer, lenB);
			*(res.buffer + lenA + lenB) = 0;
			return res;
		}
		
		char* c_str() {
			return buffer;
		}
	private:
		char* buffer;
		int capacity;
};



/*
	TestString();

	MyString MyTestString( "abc");
	MyString MyTestString2("def");
	MyString TestString3 = MyTestString + MyTestString2;

	cout << MyTestString[0];

	printf("%s\n", MyTestString.c_str());

	printf("%s\n", TestString3.c_str());


*/