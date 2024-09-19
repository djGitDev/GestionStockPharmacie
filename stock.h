/*  AUTEUR(S):
    Abi Ayad mohemed djawad _ABIM14288800_
*/
#if !defined(__STOCK_H__)
#define __STOCK_H__

#include <iostream>
#include "arbreavl.h"
#include"medicament.h"

#include"lot_medicament.h"
#include<string.h>

class Stock{
  public:
	Stock& operator+=(const Stock& autre);
  void ajouter_lot_medicaments(const LotMedicament& lot_medicaments);

  bool modifier_lot(const Medicament &med);


  // bool modifier_lot(ArbreAvl<LotMedicament>::Noeud *&racine, const Medicament &med);
  void vider();
  void ajouter_commande(const Medicament& med);
  void ajouter_commande(ArbreAvl<LotMedicament>::Noeud *&racine, const Medicament &med);


  private:
     ArbreAvl<LotMedicament> liste_medicaments;

  bool modifier_lot(ArbreAvl<LotMedicament>::Noeud *&racine, const Medicament &med);
  friend std::ostream& operator << (std::ostream&, Stock&);

};

#endif

