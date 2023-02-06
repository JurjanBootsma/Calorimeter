//CaloReader Class

#ifndef CALOREADER_HH
#define CALOREADER_HH

#include <iostream>
#include <fstream>
#include "Calorimeter.hh"
#include "CaloReaderException.hh"

/*
This code let you read through events in the calorimeter.
*/
class CaloReader {
    private:
    Calorimeter* _calo ;
    std::ifstream _file ;

    public:
    //Read the file directly with initialization.
    CaloReader(const char* File): _file(File), _calo(0) {
        if (_file.fail()) {
            std::cout << CaloReaderException(File) << std::endl ;
        }
        std::string word;
        _file >> word ;
        if (word != "BEGIN_CALO_DEF") {
            std::cout << "READERROR: Does not read correctly." << std::endl ;
        }
        _file >> word ;
        if (word != "SIZE") {
            std::cout << "READERROR: Does not read correctly." << std::endl ;
        }
        int size_x ;
        int size_y ;
        _file >> size_x ;
        _file >> size_y ;
        _calo = new Calorimeter(size_x,size_y) ;

        int readoutID ;
        int pos_x ;
        int pos_y ;
        
        _file >> word ;
        while (word == "POSITION") {
                _file >> readoutID ;
                _file >> pos_x ;
                _file >> pos_y ;
                _file >> word ;
                (*_calo->grid().cell(pos_x,pos_y)).setReadoutID(readoutID) ;
            }

        if (word != "END_CALO_DEF") {
            std::cout << "READERROR: File not read correctly" << std::endl ;
        }

        }
    ~CaloReader() {}

    //Accessor function
    Calorimeter& calo() {return *_calo ;}
    
    //This function shows the layout of the calorimeter and the hits.
    void dumpReadoutMap(std::ostream& os = std::cout) {
        for (int i = 0; i < 10; i++) {
            os << std::endl ;
            for (int j = 0; j < 10; j++) {
                os << std::setw(3);
                os << calo().grid().cell(i,j)->readoutID() << " ";
            }
        }
        os << std::endl ;
    }

     //Let you read one event.
     bool readEvent() {
        if (_file.fail()) {
            return false ;
        }       
        _calo->clear() ; 
        
        std::string word;
        _file >> word ;
        if (word != "BEGIN_EVENT") {
            std::cout << "READERROR: Does not read correctly." << std::endl ;
            return false ;
        }
        _file >> word ;
        if (word != "ENERGY") {
            std::cout << "READERROR: Does not read correctly." << std::endl ;
            return false ;
        }

        int readoutID ;
        double energy ;

        while (word == "ENERGY") {
                _file >> readoutID ;
                _file >> energy ;
                _file >> word ;
                _calo->findCellByID(readoutID)->setEnergy(energy) ;
            }
        if (word != "END_EVENT") {
            std::cout << "READERROR: Does not read correctly." << std::endl ;
            return false ;
        }
        return true ;
     }

} ;

#endif