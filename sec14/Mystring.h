#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                     // Overloaded constructor
    Mystring(const Mystring &source);                    // Copy constructor
    Mystring( Mystring &&source);                         // Move constructor
    ~Mystring();                                                     // Destructor
    
    Mystring &operator=(const Mystring &rhs);     // Copy assignment
    Mystring &operator=(Mystring &&rhs);           // Move assignment
    
    void display() const;
    
    int get_length() const;                                      // getters
    const char *get_str() const;

    // Overloaded Operator Part
    bool operator==(const Mystring &rhs) const;

    bool operator!=(const Mystring &rhs) const;
    
    bool operator<(const Mystring &rhs) const;
    
    bool operator>(const Mystring &rhs) const;

    Mystring operator-() const;

    Mystring operator+(const Mystring &rhs) const;

    Mystring& operator+=(const Mystring &rhs);

    Mystring operator*(const int num) const;

    Mystring& operator*=(const int num);

    Mystring& operator++();  // pre-increment overloading
 
    Mystring operator++(int);  // post-inrement overloading
};

#endif // _MYSTRING_H_