//CaloCell Class

#ifndef CALOCELL_HH
#define CALOCELL_HH

class CaloCell {
public:

/*
This class defines a single cell of the calorimeter. The calorimeter is composed of a set 
of such cells. The cell has a certain ID by which you can recognize it, an energy after an
event and it can have a cluster ID, which defines to what cluster it belongs during an
event.
*/
  CaloCell(double energy=0, int readoutID=0) : _e(energy), _id(readoutID) {}

  //Accessor functions
  double energy() const { return _e; }
  int readoutID() const { return _id ; }
  int readClusterID() const { return _clusterID ; }

  //Modfier functions
  void setEnergy(double energy) { _e = energy ; }
  void setReadoutID(int id) { _id = id ; }
  void setClusterID(int clusterID) { _clusterID = clusterID ; }

private:

  double _e ;
  int _id ;
  int _clusterID ;

} ;

#endif 