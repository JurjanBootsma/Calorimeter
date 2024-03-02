// Exercise 10: Main code
// Author: Jurjan Bootsma

#include <iostream>
#include "Calorimeter/Calorimeter.hh"
#include "Calorimeter/CaloReader.hh"
#include "Calorimeter/CaloReco.hh"
using namespace std ;

// Main code to test the calorimeter, its reading and its clustering
int main() {
    // Test if the calorimeter code was working on itself
    Calorimeter cm(20,10) ;
    cout << "x-position: " << cm.position().x() << endl ;
    cout << "Energy of cell [1,1]: " << cm.grid().cell(1,1)->energy() << endl << endl ;
    // It all works correctly

    CaloReader* reader = 0; // Define CaloReader pointer

    // Try exception when a wrong file is tried to be read
    try {
        reader = new CaloReader("wrong.dat") ;
    } catch (CaloReaderException cle) {
        cout << cle << endl ; // Gives indeed the error message
    }

    // Now try it for the correct file
    try {
        reader = new CaloReader("data/calo.dat") ;
    } catch (CaloReaderException cle) {
        cout << cle << endl ;
    }

    CaloReco rec(reader->calo()) ; // Create CaloReco for clustering

    // Show all the IDs in the grid, energies and clusters
    int event_num = 1 ; // Start at first event
    while(reader->readEvent()) {
        cout << "Event " << event_num << ":" << endl ;
        reader->calo().dumpReadoutMap() ; // Print IDs
        reader->calo().dumpEvent() ; // Print energies
        rec.findClusters() ;
        reader->calo().dumpClusters() ; // Print clusters
        event_num++ ;
    }

    delete reader ; // Delete the reader

}