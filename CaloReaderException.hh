//CaloReaderException Class

#ifndef CALOREADEREXCEPTION_HH
#define CALOREADEREXCEPTION_HH

#include <string>

/*
This expection class is thrown in CaloReader when the file cannot be openend
correctly.
*/
class CaloReaderException {
    private:
    std::string _what ;

    public:
    CaloReaderException(const char* What) : _what(What) {}
    const char* what() {return _what.c_str();}

} ;

//Global so that this can be printed in main.
std::ostream& operator<<(std::ostream& os, const CaloReaderException& cre) {
  return (os << "CaloReaderException: This file cannot be opened.") ;
}

#endif