/*  AUTEUR(S):
    Abi Ayad mohemed djawad _ABIM14288800_
*/

#if !defined(__LOTMEDICAMENT_H__)
#define __LOTMEDICAMENT_H__

#include "date.h"
#include <assert.h>
#include <string.h>

class LotMedicament{

  public :

  LotMedicament(std::string nom, unsigned int nb_boites,Date date_expiration);
  LotMedicament(std::string nom,unsigned int nb_boites);


  bool operator ==(const LotMedicament &autre)const;
  bool operator >(const LotMedicament &autre)const;
  bool operator <(const LotMedicament &autre)const;
  friend std::ostream& operator << (std::ostream&, LotMedicament&);

  //  private :

   std::string nom;
   unsigned int nb_boites;
   Date date_expiration; 

  //  friend class Medicament; 
   friend class Stock; 

};
































#endif