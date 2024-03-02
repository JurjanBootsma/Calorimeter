// Exercise 10: Class CaloGrid
// Author: Jurjan Bootsma

#ifndef CALOGRID_HH
#define CALOGRID_HH

#include "CaloCell.hh"
#include <iostream>
using namespace std ;

// Class that holds the grid of the calorimeter
class CaloGrid {
public:

  CaloGrid(int size_x, int size_y) : _nx(size_x), _ny(size_y) { // Constructor
    _array = new CaloCell[_nx*_ny] ;
  }

  CaloGrid(const CaloGrid& other) : _nx(other._nx), _ny(other._ny) { // Copy constructor
    _array = new CaloCell[_nx*_ny] ;
    for(int i = 0 ; i<_nx*_ny ; i++) {
      _array[i] = other._array[i] ; // Copy all elements of array
    }
  }

  ~CaloGrid() { // Destructor
    delete[] _array ;
  }

  int const xSize() const { // x-size of grid accessor
    return _nx ;
  }

  int const ySize() const { // y-suze of grid accessor
    return _ny ;
  }
  
  // Gives pointer to cell of certain x- and y-position (const version)
  const CaloCell* cell(int x, int y) const { 
    return const_cast<CaloGrid*>(this)->cell(x,y) ; 
  }
  
  // Gives pointer to cell of certain x- and y-position (non-const version)
  CaloCell* cell(int x, int y) {
    if (x<0 || x>=_nx || y<0 || y>=_ny) return 0 ;
    return _array + x*_ny + y ;
  }
  

private:

  int _nx ;             // x-size
  int _ny ;             // y-size
  CaloCell* _array ;    // Array of CaloCells

} ;

#endif 