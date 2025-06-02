#pragma once

#include <iostream>
#include <stdexcept>
#include "Sir.cpp"

template <typename T>
class Sir {
    private:
        T* data;
        int length;

    public:
        Sir();          // Constructorul default - creeaza un sir gol
        Sir(const T* arr, int len); // Creeaza un sir cu elementele lui arr
        Sir(const Sir<T>& sir); // Creeaza un sir nou cu aceeasi lungime si continut ca sir
        ~Sir(); // Elibereaza memoria

        Sir<T>& operator=(const Sir<T>& sir); // a = b -> copiaza continutul lui b in a
        operator T() const; // conversie la T (primul element)
        
        bool operator==(const Sir<T>& sir) const; // Verifica daca doua siruri sunt identitice
        bool operator<(const Sir<T>& sir) const; 
        bool operator<(const Sir<T>& sir) const;
        bool operator<=(const Sir<T>& sir) const;
        bool operator>=(const Sir<T>& sir) const;
        
        int size() const; // Returneaza dimensiunea sirului
        void print() const; // printeaza sirul
        
};