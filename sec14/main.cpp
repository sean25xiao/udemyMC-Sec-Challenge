// Section 14
// Challenge
#include <iostream>
#include "Mystring.h"

using namespace std;

int main() {
    
    
    cout << boolalpha << endl;
    Mystring a {"frank"};  // overloaded constructor
    Mystring b {"frank"};  // overloaded constructor


    cout << (a==b) << endl;         // true
    cout << (a!=b) << endl;          // false
    
    b = "george";
    cout << (a==b) << endl;         // false
    cout << (a!=b) << endl;          // true

    cout << "===================" << endl;
    
    cout << (a<b) << endl;          // true
    cout << (a>b) << endl;           // false
    
    cout << "===================" << endl;

    b = "frank";
    cout << (a<b) << endl;          // false 
    cout << (a>b) << endl;           // false
    
    cout << "===================" << endl;
    
    Mystring s1 {"FRANK HI ARE YOU GOOD?"};
    s1 = -s1;       
    cout << s1 << endl;               // frank              

    s1 = s1 + "*****";
    cout << s1 << endl;               // frank*****       
    
    s1 += "=======";                        // frank*****-----
    cout << s1 << endl;

    cout << "===================" << endl;
    
    Mystring s2{"12345"};
    s1 = s2 * 3;
    cout << s1 << endl;              // 123451234512345
    
    Mystring s3{"abcdef"};  
    s3 *= 5;
    cout << s3 << endl;             // abcdefabcdefabcdefabcdefabcdef
    
    cout << "===================" << endl;

    Mystring s = "Frank";
    ++s;
    cout << s << endl;                  // FRANK
    
    s = -s; 
    cout << s << endl;                  // frank
    
    Mystring result;
    result = ++s;                           
    cout << s << endl;                  // FRANK
    cout << result << endl;           // FRANK
    
    s = "Frank";
    s++;
    cout << s << endl;                  // FRANK
    
    s = -s;
    cout << s << endl;                  // frank
    result = s++;
    cout << s << endl;                  // FRANK
    cout << result << endl;           // frank
    
    
    return 0;
}

