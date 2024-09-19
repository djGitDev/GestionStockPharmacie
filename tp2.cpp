/*
  INF3105 - Structures de donn�es et algorithmes
  Hiver 2020.
  TP2
*/
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <limits>
#include "arbreavl.h"
#include "lot_medicament.h"
#include "date.h"
#include "stock.h"
#include "prescription.h"
#include "medicament.h"



using namespace std;

int tp2(istream& entree){
    Date maintenant;
    Stock stock;
    Stock commande;
    Stock approvisionnement;
    int num_presc = 0;

    // Prescription prescription;
    while(entree){
        string typecommande;
        entree >> typecommande;
        if(!entree) break; // d�tection fin ==> sortie

        if(typecommande=="PRESCRIPTION"){
                Prescription prescription;
            num_presc ++;            
            char deuxpoints=0;
            entree >> deuxpoints;
            assert(deuxpoints==':');
            string nomMed;
            entree >> nomMed;
            while(entree && nomMed!=";"){
            	int dose;
            	int rep;
            	entree >> dose >> rep;
                Medicament med(nomMed,dose,rep,Status::OK,maintenant);
                med.modifier_status((stock.modifier_lot(med))? Status::OK : Status::COMMANDE);
                if(med.lire_status() == Status::COMMANDE)
                commande.ajouter_commande(med);

                // med.status = (stock.liste_medicaments.contient(med) && !med.a_commander(stock.liste_medicaments.rechercher(med)))? Status::OK : Status::COMMANDE;
                prescription.ajouter_medicament(med);
            	// � compl�ter ****
            	entree >> nomMed;
            }

            // � compl�ter *****
            cout << "PRESCRIPTION " << num_presc << std::endl << prescription;
        }else if(typecommande=="APPROV"){
        	string nomMed;
        	char deuxpoints=0;
        	entree >> deuxpoints;
        	assert(deuxpoints==':');
        	entree >> nomMed;
        	while(entree && nomMed!=";"){
        		int quantite;
        		Date dateexpiration;
        		entree >> quantite >> dateexpiration;
                LotMedicament lot(nomMed,quantite,dateexpiration);
                approvisionnement.ajouter_lot_medicaments(lot);

        		// � compl�ter
        		entree >> nomMed;
        	}
            stock+= approvisionnement;

            approvisionnement.vider();


        	// � compl�ter
        	cout << "APPROV OK";
        }else if(typecommande=="STOCK"){

        	char pointvirgule=0;
            entree >> pointvirgule;
            assert(pointvirgule==';');
            // � compl�ter
            cout << "STOCK " << maintenant << std::endl;
            cout << stock ;
        }else if(typecommande=="DATE"){
        	char pointvirgule=0;
        	entree >> maintenant >> pointvirgule;
        	assert(pointvirgule==';');
        	// � compl�ter
        	cout << maintenant << " COMMANDE"<< std::endl;
            cout <<  commande;
        }else{
            cout << "Transaction '" << typecommande << "' invalide!" << endl;
            return 2;
        }
        cout << endl;
        entree >> ws; // force la lecture d'un espace blanc.
    }
    return 0;
}
// syntaxe d'appel : ./tp2 [nomfichier.txt]
int main(int argc, const char** argv){
    // Gestion de l'entr�e :
    //  - lecture depuis un fichier si un argument est sp�cifi�;
    //  - sinon, lecture depuis std::cin.
    if(argc>1){
         std::ifstream entree_fichier(argv[1]);
         if(entree_fichier.fail()){
             std::cerr << "Erreur d'ouverture du fichier '" << argv[1] << "'" << std::endl;
             return 1;
         }
         return tp2(entree_fichier);
    }else
         return tp2(std::cin);

    return 0;
}




