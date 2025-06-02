#include "Sir.h"

// Constructorul default
template <typename T>
Sir<T>::Sir() {
    data = nullptr; // gol
    length = 0;
}

// Constructorul de date
template <typename T>
Sir<T>::Sir(const T* arr, int len){
    length = len;
    data = new T[length];

    for (int i = 0; i < length; i++)
        data[i] = arr[i];
}

// Copiere -> a = b
template <typename T>
Sir<T>::Sir(const Sir<T>& sir){
    length = sir.length;
    data = new T[length];

    for (int i = 0; i < length; i++)
        data[i] = sir.data[i];
}

// Destructor (free)
template <typename T>
Sir<T>::~Sir(){
    delete[] data; // eliberam memoria alocata
}

// Operatorul =
template <typename T>
Sir<T>& Sir<T>::operator=(const Sir<T>& sir){
    if (this != &sir){ // rezolv auto-atribuirea (a = a)
        delete[] data; // eliberez datele existente
        length = sir.length;
        data = new T[length]; // aloc memorie
        for (int i = 0; i < length; i++)
            data[i] = sir.data[i];  // copiez elementele
    }

    return *this;
}

// Conversie catre T (ex. int, char)
template <typename T>
Sir<T>::operator T() const{
    if (length == 0){
        throw std::out_of_range("Sirul este gol");
    }
    return data[0]; // intoarce primul element
}

// Operatorul == 
template <typename T>
bool Sir<T>::operator==(const Sir<T>& sir) const{
    if (length != sir.length)
        return false;
    
    for (int i = 0; i < sir.length; i++){
        if (data[i] != sir.data[i])
         return false;
    }
    return true;
}

// Operatorul <
template <typename T>
bool Sir<T>::operator<(const Sir<T>& sir) const{
    if (length >= sir.length)  // Daca lungimea lui a > lungimea lui b, 
        return false;          // nu poate fi subsir

    for (int i = 0; i < length; i++){
        if (data[i] != sir.data[i]){   // verific element cu element
            return false;
        }
    }
    return true;
}

// Operatorul <= 
template <typename T>
bool Sir<T>::operator<=(const Sir<T>& sir) const{
    if (length > sir.length)  // Daca lungimea lui a > lungimea lui b, 
        return false;          // nu poate fi subsir

    for (int i = 0; i < length; i++){
        if (data[i] != sir.data[i]){   // verific element cu element
            return false;
        }
    }
    return true;
}

// Pentru > si >= ma voi folosi de operatorii definiti mai sus
template <typename T>
bool Sir<T>::operator>(const Sir<T>& sir) const{
    if (sir < *this)
        return true;

    return false;
}

template <typename T>
bool Sir<T>::operator>=(const Sir<T>& sir) const{
    if (sir <= *this)
        return true;

    return false;
}
// Size
template <typename T>
int Sir<T>::size() const {
    return length;
}

// PRINT
template <typename T>
void Sir<T>::print() const {
    std::cout << "[";
    for (int i = 0; i < length; ++i) {
        std::cout << data[i];
        if (i < length - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}