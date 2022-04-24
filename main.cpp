#include <iostream>
#include "String.h"

using namespace std;

int main() {

	char* s1 = nullptr;

	String a("hello");
	String b = a;
	String c;

	cout << a + b << endl;

	cout << "first symbol 'l' in a: " << a.findfirstsym('l') << endl;

	b.setconststring("hello");
	s1 = b.getstring();

	c.setconststring("World;hello;hello");

	cout << "first word in c: " << c.findfirstword(s1) << endl;

	c.splitword(';');

}