#pragma once

#include <iostream>

using namespace std;

class String
{

public:

    String();
    String(const char* s);
    String(const String&);
    ~String();

    int getlen();
    char* getstring();
    void setstring(char* s);
    void setconststring(const char* s);


    String& operator=(const String&);
    String& operator=(const char*);
    char& operator[](int i);

    friend bool operator<(const String& s1, const String& s2);
    friend bool operator>(const String& s1, const String& s2);
    friend bool operator==(const String& s1, const String& s2);
    friend ostream& operator<<(ostream& os, const String& s2);
    friend istream& operator>>(istream& is, String& s);
    friend String operator+(const String& s1, const String& s2);

    int findfirstsym(char c);
    int findfirstword(char* s);
    void splitword(char c);


protected:

    char* string;
    int len;
};