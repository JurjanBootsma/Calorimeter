// Exercise 10: Calorimeter class header file
// Author: Jurjan Bootsma

#ifndef CALORIMETER_HH
#define CALORIMETER_HH

#include "CaloGrid.hh"
#include "Point.hh"
#include <iostream>
#include <fstream>

// Class that describes a calorimeter with a position and a grid of cells
class Calorimeter {
public:

  Calorimeter(int sizex, int sizey, Point position=Point(0,0,0)) : // Constructor
    _grid(sizex,sizey), _pos(position)
  {}

  // Accessors
  CaloGrid& grid() { return _grid ; }
  const CaloGrid& grid() const { return _grid ; }
  Point& position() { return _pos ; }
  const Point& position() const { return _pos ; }

  // Functions
  void dumpReadoutMap(std::ostream& os = std::cout) const ; // Print grid of IDs
  CaloCell* findCellByID(int id) ; // Return cell by entering ID
  void clear() ; // Set energy of every CaloCell in Calorimeter to 0
  void dumpEvent(std::ostream& os=cout) ; // Print energy cells in grid
  void dumpClusters(std::ostream& os=cout) ; // Print all the cluster IDs

private:

  CaloGrid _grid ;
  Point _pos ;


} ;

#endif 