//Calorimeter Class

#ifndef CALORIMETER_HH
#define CALORIMETER_HH

#include "CaloGrid.hh"
#include "Point.hh"
#include <iomanip>

/*
This is the calorimeter class, with some functions.
*/
class Calorimeter {
public:

  Calorimeter(int sizex, int sizey, Point position=Point(0,0,0)) : 
    _grid(sizex,sizey), _pos(position)
  {}

  CaloGrid& grid() { return _grid ; }

  //Accessor Functions
  const CaloGrid& grid() const { return _grid ; }
  Point& position() { return _pos ; }
  const Point& position() const { return _pos ; }

  //Function to get the cell from a certain readout ID.
  CaloCell* findCellByID(int id) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
                if (grid().cell(i,j)->readoutID() == id) {
                    return grid().cell(i,j);
                }
            }
        }
    return 0;
  }

  //Function to set all energies to 0.
  void clear() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid().cell(i,j)->setEnergy(0) ;
            }
        }   
  }

  //Function to visualize the setup of the calorimeter.
  void dumpEvent(std::ostream& os=cout) {
    for (int i = 0; i < 10; i++) {
        os << std::endl ;
        for (int j = 0; j < 10; j++) {
            os << std::setw(3);
            if (grid().cell(i,j)->energy() < 0.5) {
                os << "." ;
            } else if (grid().cell(i,j)->energy() > 2) {
                os << "X" ;
            } else {
                os << "x" ;
            }

            }
        }
        os << std::endl << std::endl ;
  }

private:

  CaloGrid _grid ;
  Point _pos ;


} ;

#endif