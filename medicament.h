/*  AUTEUR(S):
    Abi Ayad mohemed djawad _ABIM14288800_
*/

#if !defined(__MEDICAMENT_H__)
#define __MEDICAMENT_H__

#include "date.h"
#include <assert.h>
#include <string.h>
#include <iostream>
#include "lot_medicament.h"


enum class Status {
    OK,
    COMMANDE
};

class  Medicament{ 

      public :

      Medicament(std::string _nom, unsigned int _dose, unsigned int _repetitions,Status _status, Date _date_prescription)
             : nom(_nom), dose(_dose), repetitions(_repetitions),status(_status), date_prescription(_date_prescription) {}

      bool operator ==(const Medicament &autre)const;
            
      bool operator>(const Medicament &autre) const;

      bool operator<(const Medicament &autre) const;

      bool a_commander(const LotMedicament lot) const;     

      void modifier_status(const Status &_status);

      Status lire_status();
    

      private: 

      std::string nom;
      unsigned int dose ;
      unsigned int repetitions;
      Status status ;
      Date date_prescription;

      friend class Stock; 

      friend std::ostream& operator<<(std::ostream& os, const Medicament& med);
            
      
      
   };
   #endif