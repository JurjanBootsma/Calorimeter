#include <iostream>
#include <fstream>
#include "Calorimeter.hh"
#include "CaloReader.hh"
#include "CaloReaderException.hh"
#include "CaloReco.hh"

/*
Example of using the calorimeter classes.
*/
int main() {
    const char* file = "data/calo.dat";
    CaloReader cr(file);
    cr.readEvent() ;
    cr.calo().dumpEvent() ;
    CaloReco rec(cr.calo()) ;
    rec.findClusters() ;
    rec.dumpClusters() ;

    cr.readEvent() ;
    cr.calo().dumpEvent() ;
    CaloReco rec2(cr.calo()) ;
    rec2.findClusters() ;
    rec2.dumpClusters() ;
    

    return 0 ;
}