// Exercise 10: CaloReaderException Class
// Author: Jurjan Bootsma

#ifndef CALOREADEREXCEPTION_HH
#define CALOREADEREXCEPTION_HH

#include <string>
#include <iostream>
using namespace std ;

// Exception class that is thrown when file is not opened correctly
class CaloReaderException {
public:
    CaloReaderException(const char* file): _what(file) {} // Constructor
    const char* what() const { return _what.c_str() ; } // String of file that not opened

private:
    string _what ; // String of file

} ;

// The error message
inline ostream& operator<<(ostream& os, const CaloReaderException& cre) {
    return (os << "Reading error: file " << cre.what() <<  " not opened correctly" << endl);
}

#endif