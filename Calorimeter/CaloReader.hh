// Exercise 10: CaloReader Class header file
// Author: Jurjan Bootsma

#ifndef CALOREADER_HH
#define CALOREADER_HH

#include "Calorimeter.hh"
#include "CaloReaderException.hh"
#include <fstream>
#include <iostream>
using namespace std ;

// Class that can read a file with data of events and layout for a calorimeter
class CaloReader {
public:

    CaloReader(const char* input_file) ; // Constructor
    ~CaloReader() { delete _calo; } // Destructor

    Calorimeter& calo() { return *_calo; } // Accessor of the calorimeter
    bool readEvent() ; // Reads through file per event


private:

    Calorimeter* _calo ; // Calorimeter
    ifstream _file ; // The file that has to be read

} ;

#endif