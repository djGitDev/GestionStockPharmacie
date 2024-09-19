/*  AUTEUR(S):
    Abi Ayad mohemed djawad _ABIM14288800_
*/


#include "prescription.h"




void Prescription::ajouter_medicament(const Medicament& medicament){
    medicaments.enfiler(medicament);
};



std::ostream& operator << (std::ostream& os, Prescription& prescription){
     while (!prescription.medicaments.estVide())
        {
            os << prescription.medicaments.defiler() ;
        }
    return os;
}

