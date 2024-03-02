// Exercise 10: CaloReco class header file
// Author: Jurjan Bootsma

#ifndef CALORECO_HH
#define CALORECO_HH

#include "Calorimeter.hh"
#include "CaloCell.hh"
#include <iostream>

// Class that clusters cells with energy together
class CaloReco {
public: 

    CaloReco(Calorimeter& calo): _calo(&calo), _seedx(-1), _seedy(-1) {} // Constructor
    void findClusters() ; // Finds clusters and assings cluster IDs to them

private:

    // Data members
    Calorimeter* _calo ;
    int _seedx ; // Maximum energy cell x-position
    int _seedy ; // Maximum energy cell y-position

    // Private member functions
    CaloCell* findSeed() ; // Finds highest energy cell without cluster ID
    void growCluster(int ix, int iy, int clusid) ; // Grows cluster to neighbouring cells

} ;

#endif