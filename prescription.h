/*  AUTEUR(S):
    Abi Ayad mohemed djawad _ABIM14288800_
*/

#if !defined(__PRESCRIPTION_H__)
#define __PRESCRIPTION_H__

#include "date.h"
#include <assert.h>
#include <string.h>
#include <iostream>
#include "file.h"
#include "medicament.h"



class Prescription{

  public :

  void ajouter_medicament(const Medicament& medicament);
  friend std::ostream& operator << (std::ostream&, Prescription&);

   private :

   File<Medicament> medicaments;
   
   friend std::ostream& operator << (std::ostream&, Prescription&);

};

#endif





