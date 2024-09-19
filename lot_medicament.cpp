/*  AUTEUR(S):
    Abi Ayad mohemed djawad _ABIM14288800_
*/


#include "lot_medicament.h"

LotMedicament::LotMedicament(std::string _nom,unsigned int _nb_boites){
  nom= _nom;
  nb_boites = _nb_boites;

}


LotMedicament::LotMedicament(std::string _nom,unsigned int _nb_boites,Date _date_expiration){
nom = _nom;
nb_boites = _nb_boites;
date_expiration = _date_expiration;
};


bool LotMedicament::operator ==(const LotMedicament &autre)const{
   return (nom.compare(autre.nom) == 0 && date_expiration == autre.date_expiration);
};

bool LotMedicament::operator >(const LotMedicament &autre)const{
   if(nom.compare(autre.nom) == 0){
      return (date_expiration > autre.date_expiration);
   }else{
      return nom.compare(autre.nom) > 0;
   }
};

bool LotMedicament::operator <(const LotMedicament &autre)const{
   if(nom.compare(autre.nom) == 0){
      return (date_expiration < autre.date_expiration);
   }else{
      return nom.compare(autre.nom) < 0;
   }
};

// std::ostream& operator << (std::ostream& os, LotMedicament& lot_medicament){
//   return os  << lot_medicament.nom << "  " << lot_medicament.nb_boites << "  " << lot_medicament.date_expiration << std::endl;
// };

std::ostream& operator<<(std::ostream& os, LotMedicament& lot_medicament) {
   Date  now = Date() ;  
    if (lot_medicament.date_expiration == now) {
      return  os << lot_medicament.nom << "  " << lot_medicament.nb_boites << std::endl;

    } else {
      return os  << lot_medicament.nom << "  " << lot_medicament.nb_boites << "  " << lot_medicament.date_expiration << std::endl;
    }

}