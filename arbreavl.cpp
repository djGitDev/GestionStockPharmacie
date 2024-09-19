// /*  AUTEUR(S):
//     Abi Ayad mohemed djawad _ABIM14288800_
// */

// #include "arbreavl.h"

// template <class T>
// ArbreAvl<T>::ArbreAvl() : racine(nullptr), nbElements(0) {}

// template <class T>
// ArbreAvl<T>::~ArbreAvl()
// {
//     vider();
// }

// template <class T>
// void ArbreAvl<T>::vider()
// {
//     vider(racine);
//     racine= NULL;
//     nbElements = 0;
// }

// template <class T>
// void ArbreAvl<T>::vider(Noeud *noeud)
// {
//     if (noeud != nullptr)
//     {
//         vider(noeud->gauche);
//         vider(noeud->droite);
//         delete noeud;
//     }
//     return;
// }

// template <class T>
// void ArbreAvl<T>::inserer_arbre(Noeud* const &racine_autre)
// {
    
//     if (racine_autre == nullptr)
//     {
//         return;
//     }
//     inserer_arbre(racine_autre->gauche);
//     inserer(racine,racine_autre->contenu);
//     inserer_arbre(racine_autre->droite);
// }
// template <class T>
// void ArbreAvl<T>::inserer_arbre(const ArbreAvl<T> &arbre_autre){
//     inserer_arbre(arbre_autre.racine);
// }

// template <class T>
// bool ArbreAvl<T>::operator==(const ArbreAvl<T> &autre) const
// {
//     // À implémenter
//     return false;
// }

// template <class T>
// ArbreAvl<T> &ArbreAvl<T>::operator=(const ArbreAvl<T> &autre)
// {
//     // À implémenter
//     return *this;
// }

// template <class T>
// void ArbreAvl<T>::inserer(Noeud* &noeud,const T& element){
// if(noeud == NULL){
//     noeud = new Noeud(element);
// }else if(noeud->contenu > element){
//     if(noeud-> gauche == NULL){
//         noeud->gauche = new Noeud(element);
//         nbElements ++;
//     }else{
//         inserer(noeud->gauche,element);
//     }
// }else if(noeud->contenu < element){
//     if(noeud-> droite == NULL){
//         noeud->droite = new Noeud(element);
//         nbElements ++;

//     }else{
//         inserer(noeud->droite,element);
//     }
// }else{
//     noeud->contenu = element;
// }
// }
// template <class T>
// const T* ArbreAvl<T>::rechercher(const T& element)const{
//    return rechercher(racine,element);
    
// }


// template <class T>
// const T* ArbreAvl<T>::rechercher(Noeud* noeud,const T& element){
// if(noeud == NULL)
//     return NULL;
// if(noeud->contenu < element)
//     return racine->gauche.rechercher(element);
// if(noeud->contenu > element)
//     return racine->gauche.rechercher(element);
// return &(noeud->contenu);
// }



// template <class T>
// bool ArbreAvl<T>::contient(const T& element)const{
//    return rechercher(element) != NULL; 
// }

// template <class T>
// void ArbreAvl<T>::parcourirEnOrdre(Noeud* n, std::ostream &os) 
// {
//     if (n == nullptr)
//     {
//         return;
//     }
//     parcourirEnOrdre(n->gauche, os);
//     os << n->contenu ;
//     parcourirEnOrdre(n->droite, os);

// }

// template <class T>    
// void ArbreAvl<T>::parcourirEnOrdre(std::ostream &os)
// {
// parcourirEnOrdre(racine,os) ;       
// }
