/*  AUTEUR(S):
    Abi Ayad mohemed djawad _ABIM14288800_
*/


#include "medicament.h" 
  
 
std::ostream& operator<<(std::ostream& os, const Medicament& med){
    os << med.nom << " " << med.dose << " " << med.repetitions << " " << ((med.status == Status::OK) ? "OK" : "COMMANDE")  <<std::endl;
    return os;
}
  
bool Medicament::operator ==(const Medicament &autre)const{
    return (nom.compare(autre.nom) == 0 && dose*repetitions == autre.dose* autre.repetitions 
             && date_prescription == autre.date_prescription);
};

bool Medicament::operator >(const Medicament &autre)const{
    if(nom.compare(autre.nom) == 0){
        return (dose*repetitions > autre.dose* autre.repetitions);
    }else{
        return nom.compare(autre.nom) > 0;
    }
};

bool Medicament::operator<(const Medicament &autre) const {
        if(nom.compare(autre.nom) == 0){
        return (dose*repetitions < autre.dose* autre.repetitions);
    }else{
        return nom.compare(autre.nom) < 0;
    }
};

bool Medicament::a_commander(const LotMedicament lot)const{
    return (lot.nb_boites < dose * repetitions); 
}

void Medicament::modifier_status(const Status &_status){
   status = _status;

}

Status Medicament::lire_status(){
  return status; 

}
