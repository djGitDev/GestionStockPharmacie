/*  AUTEUR(S):
    Abi Ayad mohemed djawad _ABIM14288800_
*/

#ifndef __FILE_H__
#define __FILE_H__

#include <iostream>
#include <cassert>

template <class T>
class File
{
private:
    struct Cellule
    {
        T element;
        Cellule *suivant;

        Cellule(const T &elem) : element(elem), suivant(nullptr) {}
    };

    Cellule *queue;

public:
    File() : queue(nullptr) {}

    ~File()
    {
        while (!estVide())
        {
            defiler();
        }
    }

    void enfiler(const T &element)
    {
        Cellule *nouvelleCellule = new Cellule(element);

        if (estVide())
        {
            queue = nouvelleCellule;
            queue->suivant = queue; // Pointe sur lui-même pour former une file circulaire
        }
        else
        {
            nouvelleCellule->suivant = queue->suivant;
            queue->suivant = nouvelleCellule;
            queue = nouvelleCellule;
        }
    }

    T defiler()
    {
        assert(!estVide() && "File vide");

        T element = queue->suivant->element;

        if (queue->suivant == queue) // File avec un seul élément
        {
            delete queue;
            queue = nullptr;
        }
        else
        {
            Cellule *temp = queue->suivant;
            queue->suivant = temp->suivant;
            delete temp;
        }

        return element;
    }

    T premier() const
    {
        assert(!estVide() && "File vide");

        return queue->suivant->element;
    }

    bool estVide() const
    {
        return queue == nullptr;
    }
};

#endif
