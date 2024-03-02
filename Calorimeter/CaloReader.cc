// Exercise 10: CaloReader Class functions
// Author: Jurjan Bootsma

#include "CaloReader.hh"

// Constructor. When object is created, the calorimeter grid is set correctly with all
// the cells given the correct readout ID.
CaloReader::CaloReader(const char* input_file): _calo(0), _file(input_file) {
         
    if (_file.fail()) {throw CaloReaderException(input_file);} // When file does not open
         
    string word ;
    _file>>word;
    // When file does not have the expected beginning
    if (word!="BEGIN_CALO_DEF") {throw CaloReaderException(input_file);} 

    _file>>word;
    if (word!="SIZE") {throw CaloReaderException(input_file);} // No SIZE in file

    int size_x, size_y ;
    _file >> size_x >> size_y; // x- and y-size of the grid
    _calo = new Calorimeter(size_x, size_y) ; // Create the calorimeter

    // Read in the cell mapping
    int readoutID, ix, iy ;
    _file >> word ;
    while (word=="POSITION") { // Keep going as long as we are looking at positions
        // Then read in readoutID, x- and y-position
        _file >> readoutID >> ix >> iy ;
        _calo->grid().cell(ix, iy)->setReadoutID(readoutID) ; // Set IDs
        _file >> word ;
    }
    if (word!="END_CALO_DEF"){throw CaloReaderException(input_file);} // No end header in file
}

bool CaloReader::readEvent() {
    if (_file.fail()) { return false ; } // Check if file is still okay for reading

    _calo->clear() ; // Every cell's energy to 0

    // Check if it starts reading an event
    string word ;
    _file >> word ;
    if (word!="BEGIN_EVENT") { return false ; }

    // Start reading the energies corresponding to a certain ID
    _file >> word ;
    int readoutID ;
    double energy ;
    while (word == "ENERGY") { // Keep going as long as there is data on the energy
        _file >> readoutID >> energy ;
        _calo->findCellByID(readoutID)->setEnergy(energy) ; // Set energy to right cell
        _file >> word ;
    }

    if (word!="END_EVENT") { return false ; } // Last check if read correctly
    
    return true ;
}