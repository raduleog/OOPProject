#pragma once

#include <iostream>
#include <stdexcept>
using namespace std;


template <typename T>
class Sir {
    private:
        T* data;
        int length;

    public:
        Sir();          // Constructorul default - creeaza un sir gol
        Sir(const T* arr, int len); // Creeaza un sir cu elementele lui arr
        Sir(const Sir<T>& sir); // Creeaza un sir nou cu aceeasi lungime si continut ca sir
        Sir(T elem); // conversie element -> sir de 1 element
        ~Sir(); // Elibereaza memoria

        Sir<T>& operator=(const Sir<T>& sir); // a = b -> copiaza continutul lui b in a
        operator T() const; // conversie la T (primul element)
        
        bool operator==(const Sir<T>& sir) const; // Verifica daca doua siruri sunt identice
        bool operator<(const Sir<T>& sir) const; 
        bool operator>(const Sir<T>& sir) const;
        bool operator<=(const Sir<T>& sir) const;
        bool operator>=(const Sir<T>& sir) const;
        Sir<T> operator+(const Sir<T>& sir) const; // Concateneaza două siruri
        Sir<T> operator-(const Sir<T>& sir) const; // verifica daca exista prefix intre doua siruri, si in caz afirmativ il elimina (întoarce şirul obţinut prin ştergerea şirului "scazator" din "descăzut", dacă "scăzătorul" este prefix al "descăzutului", altfel întoarce "descăzutul" neschimbat)
        Sir<T> operator*(const Sir<T>& sir) const; // întoarce şirul elementelor care ocupă aceeaşi poziţie şi coincid în cele două şiruri
        Sir<T> operator<<(int n) const; // elimina n elemente de la inceput
        Sir<T> operator>>(int n) const; // elimina n elemente de la sfarsit
        
        int size() const; // Returneaza dimensiunea sirului
        void print() const; // printeaza sirul
        
};

#include "Sir.cpp"
