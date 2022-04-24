#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

using namespace std;

String::String()
{
    len = 0;
    string = new char[1];
    string[0] = '\0';
}

String::String(const char* s)
{
    len = strlen(s);
    string = new char[len + 1];
    strcpy(string, s);
}

String::String(const String& s)
{
    len = s.len;
    string = new char[len + 1];
    strcpy(string, s.string);
}

String::~String()
{
    delete[] string;
}

int String::getlen()
{
    return len;
}

char* String::getstring()
{
    return string;
}

void String::setstring(char* s)
{
    if (s == nullptr)
        throw "Error";

    if (string != nullptr)
    {
        delete[] string;
        len = 0;
    }

    len = strlen(s);
    string = new char[len + 1];
    string[len] = '\0';

    for (int i = 0; i < len; i++)
    {
        string[i] = s[i];
    }
}

void String::setconststring(const char* s)
{
    if (s == nullptr)
        throw "Error";

    if (string != nullptr)
    {
        delete[] string;
        len = 0;
    }

    len = strlen(s);
    string = new char[len + 1];
    string[len] = '\0';

    for (int i = 0; i < len; i++)
    {
        string[i] = s[i];
    }
}

String& String::operator=(const String& s)
{
    if (this == &s)
        return *this;
    delete[] string;
    len = s.len;
    string = new char[len + 1];
    strcpy(string, s.string);
    return *this;
}

String& String::operator=(const char* s)
{
    delete[] string;
    len = strlen(s);
    string = new char[len + 1];
    strcpy(string, s);
    return *this;
}

char& String::operator[](int i)
{
    return string[i];
}

int String::findfirstsym(char c)
{
    if (string == nullptr) 
        return -1;

    for (int i = 0; i < len; i++)
    {
        if (string[i] == c)
            return i;
    }
    return -1;
 }

int String::findfirstword(char* s)
{
    int flag;
    if (s == nullptr) 
        return -1;

    for (int i = 0; i < strlen(string); i++)
    {
        if (s[0] == string[i])
        {
            flag = 1;
            for (int j = 1; j < strlen(s); j++)
            {
                if (s[j] != string[i + j]) flag = 0;
            }

            if (flag == 1) return i;
        }

    }

    return -1;
}

bool operator<(const String& s1, const String& s2)
{
    return (strcmp(s1.string, s2.string) < 0);
}

bool operator>(const String& s1, const String& s2)
{
    return s2 < s1;
}

bool operator==(const String& s1, const String& s2)
{
    return (strcmp(s1.string, s2.string) == 0);
}


ostream& operator<<(ostream& os, const String& s)
{
    os << s.string;
    return os;
}

String operator+(const String& s1, const String& s2)
{
    String _temp;                         // временный объект
    delete[] _temp.string;                   // стираем строку, выделенную в конструкторе по умолчанию
    _temp.len = s1.len + s2.len;        // вычисляем длину будущей строки
    _temp.string = new char[_temp.len + 1];  // выделяем место под новую строку + нулевой символ

    strcpy(_temp.string, s1.string);
    strcpy(_temp.string + s1.len, s2.string); // собственно, сцепляем и сохраняем в новый объект

    return _temp;
}

istream& operator>>(istream& is, String& s)
{
    char temp[80];
    is.get(temp, 80);
    if (is)
        s = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

void String::splitword(char c)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] != c)
        {
            cout << string[i];
        }

        else
            cout << '\n';
    }
}
