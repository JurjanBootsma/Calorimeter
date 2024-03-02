// Exercise 10: CaloReco class functions
// Author: Jurjan Bootsma

#include "CaloReco.hh"

// Function that finds clusters and assigns cluster IDs to them
void CaloReco::findClusters() {
    // Start by setting all clusterIDs to 0
    for (int yi = 0; yi < _calo->grid().ySize(); yi++) {
        for (int xi = 0; xi < _calo->grid().xSize(); xi++) {
            _calo->grid().cell(xi,yi)->setClusterID(0) ;
        }
    }

    CaloCell* SeedCell = CaloReco::findSeed() ; // Find cell of highest energy
    int clusid = 1 ; // Start with cluster ID 1
    while (SeedCell!=0) { // As long as no null pointer (so as long as there is a cell)
        growCluster(_seedx, _seedy, clusid) ; // Grow cluster for that cell
        clusid++ ; // New cluster ID for possible new cluster
        SeedCell = CaloReco::findSeed() ;
    }
}

// Function that finds the cell with the highest energy without a cluster ID
CaloCell* CaloReco::findSeed() {
    double energy_high = 0 ; // Start at lowest energy
    CaloCell* SeedCell = 0; // Cell starts as null pointer
    _seedx = -1 ; _seedy = -1 ; // So that no old values are stored
    for (int yi = 0; yi < _calo->grid().ySize(); yi++) {
        for (int xi = 0; xi < _calo->grid().xSize(); xi++) {
            // Check which cell has highest energy and has no cluster yet
            if ((_calo->grid().cell(xi,yi)->energy())>energy_high && (_calo->grid().cell(xi,yi)->clusterID())==0) {
                energy_high = _calo->grid().cell(xi,yi)->energy() ;
                SeedCell = _calo->grid().cell(xi,yi) ;
                // Maximum positions
                _seedx = xi ;
                _seedy = yi ;
            }
        }
    }
    return SeedCell ;
}

// Function that finds cells next to the highest energy cell and assigns a cluster to them
// if they have an energy > 0
void CaloReco::growCluster(int ix, int iy, int clusid) {
    CaloCell* growCell = _calo->grid().cell(ix,iy) ; // Cell in the middle
    growCell->setClusterID(clusid) ; // Assign the cluster id

    // Loop over all neighbouring cells
    for (int y_neigh = -1; y_neigh<=1; y_neigh++) {
        for (int x_neigh = -1; x_neigh<=1; x_neigh++) {
            // Cell has to be within grid
            if (ix+x_neigh >= 0 && ix+x_neigh < _calo->grid().xSize() && iy+y_neigh >= 0 && iy+y_neigh < _calo->grid().ySize()) {
                // Cell needs energy higher than 0 and no cluster ye
                if ((growCell+y_neigh+(_calo->grid().ySize())*x_neigh)->energy()>0 && (growCell+y_neigh+(_calo->grid().ySize()*x_neigh))->clusterID()==0) {
                    CaloReco::growCluster(ix+x_neigh, iy+y_neigh, clusid) ;
                }
            }
        }
    }
}