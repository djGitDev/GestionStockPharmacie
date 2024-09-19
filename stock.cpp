/*  AUTEUR(S):
    Abi Ayad mohemed djawad _ABIM14288800_
*/

#include "stock.h"
#include <assert.h>

Stock& Stock::operator+=(const Stock& autre)
{
    // � compl�ter.
    liste_medicaments.inserer_arbre(autre.liste_medicaments);
    return *this;
}

void Stock::ajouter_lot_medicaments(const LotMedicament& lot_medicaments){
    liste_medicaments.inserer(liste_medicaments.racine,lot_medicaments);
};


std::ostream& operator << (std::ostream& os, Stock& stock){
    stock.liste_medicaments.parcourirEnOrdre(os);
    return os;
}


bool Stock::modifier_lot(const Medicament &med){
  return modifier_lot(liste_medicaments.racine,med);

}


bool Stock::modifier_lot(ArbreAvl<LotMedicament>::Noeud *&racine, const Medicament &med) {
    if (racine == nullptr) {
        return false;
    }

    if (racine->gauche != nullptr) {
        return modifier_lot(racine->gauche, med);
    }

    if (racine->contenu.nom.compare(med.nom) == 0) {
        if (racine->contenu.nb_boites >= med.dose * med.repetitions) {
            racine->contenu.nb_boites -= med.dose * med.repetitions; 
            return true;
        }
    }

    if (racine->droite != nullptr) {
        return modifier_lot(racine->droite, med);
    }

    return false;
}

void Stock::vider() {
    if (liste_medicaments.racine != nullptr) {
        liste_medicaments.vider();
    } else {
        printf("Arbre vide");
    }
}

void Stock::ajouter_commande(const Medicament &med){

    ajouter_commande(liste_medicaments.racine,med);

}

void Stock::ajouter_commande(ArbreAvl<LotMedicament>::Noeud *&racine, const Medicament &med) {
    if(racine == NULL){
        racine = new ArbreAvl<LotMedicament>::Noeud(LotMedicament(med.nom,med.dose*med.repetitions));
    }else if(racine->contenu.nom.compare(med.nom) > 0){
        if(racine-> gauche == NULL){
            racine->gauche = new ArbreAvl<LotMedicament>::Noeud(LotMedicament(med.nom,med.dose*med.repetitions));
        }else{
            ajouter_commande(racine->gauche,med);
        }
    }else if(racine->contenu.nom.compare(med.nom) < 0){
        if(racine-> droite == NULL){
            racine->droite = new ArbreAvl<LotMedicament>::Noeud(LotMedicament(med.nom,med.dose*med.repetitions));
        }else{
            ajouter_commande(racine->droite,med);
        }
    }else{
        racine->contenu.nb_boites += med.dose* med.repetitions;
    }
}

