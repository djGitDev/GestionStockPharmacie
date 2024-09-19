/*  AUTEUR(S):
    Abi Ayad mohemed djawad _ABIM14288800_
*/
#include "date.h"
#include <cstdio>
#include <iomanip>
#include <assert.h>
#include <ctime>

//Date sans argument: initialise une date avec les donn�es de la date actuelle
Date::Date(){
	time_t now = time(0);
	tm* dt = localtime(&now);
	annee = 1900 + dt->tm_year;
	mois = 1+dt->tm_mon;
	jour = dt->tm_mday;

}

bool Date::operator ==(const Date& d) const {
    return (jour == d.jour && mois == d.mois && annee == d.annee);
}

bool Date::operator >(const Date& d) const {
    if (*this == d )return false;
    if (annee > d.annee) return true;
    if (annee < d.annee) return false;
    if (mois > d.mois) return true;
    if (mois < d.mois) return false;
    return jour > d.jour;
}

bool Date::operator <(const Date& d) const{
    if (*this == d )return false;
    if (annee < d.annee) return true;
    if (annee > d.annee) return false;
    if (mois < d.mois) return true;
    if (mois > d.mois) return false;
    return jour < d.jour;
}

bool Date::estBissextile(int annee) const {
    return (annee % 4 == 0 && (annee % 100 != 0 || annee % 400 == 0));
}
int Date::operator - (const Date& d) const {
    
    const int joursParMois[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int jours1 = jour;
    for (int i = 1; i < mois; ++i) {
        jours1 += joursParMois[i];
    }
     if(estBissextile(annee)&& mois > 2)
         jours1 ++;
     jours1 += (annee - 1) * 365 + (annee - 1) / 4 - (annee - 1) / 100 + (annee - 1) / 400;
    // jours1 += (annee - 1) / 4 - (annee - 1) / 100 + (annee - 1) / 400;

    int jours2 = d.jour;
    for (int i = 1; i < d.mois; ++i) {
        jours2 += joursParMois[i];
    }
     if(estBissextile(d.annee)&& d.mois > 2)
         jours2 ++;
     jours2 += (d.annee - 1) * 365 + (d.annee - 1) / 4 - (d.annee - 1) / 100 + (d.annee - 1) / 400;
    // jours2 += (d.annee - 1) / 4 - (d.annee - 1) / 100 + (d.annee - 1) / 400;

    return jours1 - jours2 ;
}

std::ostream& operator << (std::ostream& os, const Date& d){
    int a=d.annee, m=d.mois, j=d.jour; // <<=== utilisez le param�tre d au lieu de 2024-06-07
    char chaine[40];
    sprintf(chaine, "%04d-%02d-%02d", a, m, j);
    os << chaine;
    return os;
}

std::istream& operator >> (std::istream& is, Date& d){
    int a=0, m=0, j=0;
    char t1=0,t2=0;
    is >> a >> t1 >> m >> t2 >> j;
    assert(t1=='-');
    assert(t2=='-');
    // � compl�ter: transf�rez les valeur a,m,j dans l'objet d.
    d.annee = a;
    d.mois = m;
    d.jour = j ;
    return is;
}



