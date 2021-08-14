#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
        std::cout << "Overloaded Constructor: Created Object" << std::endl;
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    std::cout << "Copy Assignment get called" << std::endl;
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    std::cout << "Move Assignment get called" << std::endl;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
int Mystring::get_length() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

// overloaded == operator
bool Mystring::operator==(const Mystring &rhs) const {
    if (std::strcmp(str, rhs.str) == 0)  // string matched
        return true;
    else
        return false;
}

// overloaded != operator
bool Mystring::operator!=(const Mystring &rhs) const {
    if (std::strcmp(str, rhs.str) == 0)  // string matched
        return false;
    else
        return true;
}

// overloaded > operator
bool Mystring::operator>(const Mystring &rhs) const {
    for (auto i = 0; i < strlen(str); i++) {
        if (str[i] == rhs.str[i]) {
            ; // do nothing, go to next iteration
        }
        else if (str[i] > rhs.str[i])
            return true;
        else
            return false;
    }

    return false;
}

// overloaded < operator
bool Mystring::operator<(const Mystring &rhs) const {
    for (auto i = 0; i < strlen(str); i++) {
        if (str[i] == rhs.str[i]) {
            ; // do nothing, go to next iteration
        }
        else if (str[i] < rhs.str[i])
            return true;
        else
            return false;
    }

    return false;
}

// overload - operator
Mystring Mystring::operator-() const {
    char* buff = new char[std::strlen(str)+1];
    strcpy(buff, str);  // str copy to buff
    for (auto i = 0; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Mystring tmp {buff};
    delete [] buff;
    return tmp;
}

// overload + operator
Mystring Mystring::operator+(const Mystring &rhs) const {
    auto buff_size = std::strlen(str) + std::strlen(rhs.str) + 1;
    char* buff = new char[buff_size];
    strcpy(buff, str);  // str copy to buff
    std::strcat(buff, rhs.str);
    Mystring tmp {buff};
    delete [] buff;
    return tmp;
}

// overload += operator
Mystring& Mystring::operator+=(const Mystring &rhs) {
    *this = *this + rhs.str;  // use the overloaded + operation
    return (*this);
}

// overload * operator
Mystring Mystring::operator*(const int num) const {
    Mystring tmp;
    for (int i = 0; i < num; i++) {
        tmp += *this;
    }
    return tmp;
}

// overload *= operator
Mystring& Mystring::operator*=(const int num) {
    *this = *this * num;
    return *this;
}

// overload ++ operator pre-increment
Mystring& Mystring::operator++() {  // pre-increment
    for (auto i = 0; i < std::strlen(this->str); i++)
        str[i] = std::toupper(str[i]);
    return *this;
}

// overload other ++ operator post-increment
Mystring Mystring::operator++(int) {
    Mystring temp {*this};   // make a copy
    operator++();     // call the pre-increment to increment self
    return temp;      // return old value
}