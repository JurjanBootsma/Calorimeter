// Exercise 10: Calorimeter class functions
// Author: Jurjan Bootsma

#include <iostream>
#include "Calorimeter.hh"
using namespace std ;

// Print all the cells of the grid with their IDs
void Calorimeter::dumpReadoutMap(std::ostream& os) const {
    for (int yi = 0; yi < _grid.ySize(); yi++) { // Loop over y-direction
        os << endl;
            for (int xi = 0; xi <  _grid.xSize(); xi++) { // Loop over x-direction
                os << setw(5) << grid().cell(xi, yi)->readoutID() ; // Print IDs of cells
            }
    }
    os << endl ;
}

// Function that returns a cell by entering an ID
CaloCell* Calorimeter::findCellByID(int id) {
    // Loop over all cells
    for (int yi = 0; yi < _grid.ySize(); yi++) {
        for (int xi = 0; xi <  _grid.xSize(); xi++) {
            if (_grid.cell(xi, yi)->readoutID()==id) { // When ID is found, return cell
                return _grid.cell(xi, yi) ;
            }
        }
    }
    return 0 ; // If not found, return nullptr
}

// Function that sets the energy of every CaloCell object in the calorimeter to 0
void Calorimeter::clear() {
    // Loop over all cells
    for (int yi = 0; yi <  _grid.ySize(); yi++) {
        for (int xi = 0; xi <  _grid.xSize(); xi++) {
            _grid.cell(xi, yi)->setEnergy(0) ; // set energy to 0
        }
    }
}

// Print out energy of the cells with same layout as the IDs
void Calorimeter::dumpEvent(std::ostream& os) {
    for (int yi = 0; yi <  _grid.ySize(); yi++) {
        os << endl;
            for (int xi = 0; xi <  _grid.xSize(); xi++) {
                double energy = grid().cell(xi, yi)->energy() ;
                // Different symbols for different energies
                if (energy < 0.5) {
                    os << setw(5) << "." ;
                } else if (energy > 0.5 && energy < 2.0) {
                    os << setw(5) << "x" ;
                } else {
                    os << setw(5) << "X" ;
                }
            }
        os << endl ;
    }
    os << endl ;
}

// Print all of the cluster IDs in the grid
void Calorimeter::dumpClusters(std::ostream& os) {
    for (int yi = 0; yi < _grid.ySize(); yi++) {
        os << endl;
            for (int xi = 0; xi <  _grid.xSize(); xi++) {
                os << setw(5) << _grid.cell(xi,yi)->clusterID() ; // Print cluster ID
            }
            os << endl ;
    }
    os << endl ;    
}



