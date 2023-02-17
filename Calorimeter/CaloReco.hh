//CaloReco Class

#ifndef CALORECO_HH
#define CALORECO_HH

#include "Calorimeter.hh"
#include "Point.hh"
#include <iostream>

/*
This function groups the hits in an event.
*/
class CaloReco {
    public:

        CaloReco(Calorimeter& calo) : _calo(&calo) {}

        //Find the hit with the most energy.
        CaloCell* findSeed() {
            double energy_max ;
            CaloCell* cell_max ;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                        if (_calo->grid().cell(i,j)->energy() > energy_max && _calo->grid().cell(i,j)->readClusterID() == 0) {
                            cell_max = _calo->grid().cell(i,j) ;
                            energy_max = cell_max->energy() ;
                            _pos_max = Point(i,j,0);
                        }
                    }
                }
                return cell_max ;
            }

        //Grow the cluster to more cells with non-zero energies.
        void growCluster(int ix, int iy, int clusid) {
            _calo->grid().cell(ix,iy)->setClusterID(clusid) ;


            for (int i = ix-1; i <= ix+1; i++) {
                for (int j = iy-1; j <= iy+1; j++) {
                    if (j < 0) {
                        continue ;
                    }
                    else if (j > 9) {
                        continue ;
                    }
                    else if (i < 0) {
                        continue ;
                    }
                    else if (i > 9) {
                        continue ;
                    }
                    else {
                        if (_calo->grid().cell(i,j)->energy()>0 && _calo->grid().cell(i,j)->readClusterID()==0) {
                            _calo->grid().cell(i,j)->setClusterID(clusid) ;
                            growCluster(i,j,clusid) ;
                        }
                    }
                }
            }
        }

        //Find hit-clusters.
        void findClusters() {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    _calo->grid().cell(i,j)->setClusterID(0) ;
                    }
                }

            
            int clusid = 0 ;
            CaloCell* cell_max ;
            for (clusid = 1; true; clusid++) {
                std::cout << "" << std::endl;
                cell_max = findSeed() ;
            
                if (cell_max->energy() < 0.000001) {
                    break ;
                }
                int x_max; int y_max ;
                x_max = _pos_max.x() ;
                y_max = _pos_max.y() ;
        
                growCluster(x_max,y_max,clusid) ;
            }
        }

        void dumpClusters(std::ostream& os=cout) {
            for (int i = 0; i < 10; i++) {
                os << std::endl ;
                for (int j = 0; j < 10; j++) {
                    os << std::setw(3);
                    os << _calo->grid().cell(i,j)->readClusterID();
                    }
                }
                os << std::endl << std::endl ;
                }

    private:

        Calorimeter* _calo ;
        Point _pos_max ;

} ;

#endif 
