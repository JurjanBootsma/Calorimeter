// Exercise 10: CaloCell class
// Author: Jurjan Bootsma

#ifndef CALOCELL_HH
#define CALOCELL_HH

// Class that describes a cell in a calorimeter, with an energy, ID and cluster ID
class CaloCell {
public:

  CaloCell(double energy=0, int readoutID=0) : _e(energy), _id(readoutID) {} // Constructor

  // Accessors
  double energy() const { return _e; }
  int readoutID() const { return _id ; }
  int clusterID() const { return _clusterID ; }

  // Modifiers
  void setEnergy(double energy) { _e = energy ; }
  void setReadoutID(int id) { _id = id ; }
  void setClusterID(int clusterID) { _clusterID = clusterID ; }

private:

  double _e ; // Energy
  int _id ; // Readout ID
  int _clusterID ; // Cluster ID

} ;

#endif 