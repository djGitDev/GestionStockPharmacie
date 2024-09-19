/*  AUTEUR(S):
    Abi Ayad mohemed djawad _ABIM14288800_
*/

#if !defined(__DATE_H__)
#define __DATE_H__

#include <iostream>

class Date{
  public:
	Date();
	// � compl�ter
    bool operator ==(const Date& date) const;
    bool operator >(const Date& date) const;
    bool operator <(const Date& date) const;
    int operator - (const Date& date)const;
    bool estBissextile(int annee) const;
  private:

  int jour;
  int mois;
  int annee;

  friend std::ostream& operator << (std::ostream&, const Date& date);
  friend std::istream& operator >> (std::istream&, Date& date);
};

#endif
