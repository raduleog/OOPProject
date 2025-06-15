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

// Constructor care creează un șir cu un singur element, egal cu cel dat.
// Permite conversia implicită de la un tip de bază (ex. int, char) la Sir<T>.
template <typename T>
Sir<T>::Sir(T elem) {
    length = 1;
    data = new T[1];
    data[0] = elem;
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

// Operatorul + concatenare
template <typename T>
Sir<T> Sir<T>::operator+(const Sir<T>& sir) const {
    int newLength = length + sir.length;
    T* newData = new T[newLength];

    // Copiez elementele din primul sir
    for (int i = 0; i < length; i++) {
        newData[i] = data[i];
    }

    // Copiez elementele din al doilea sir
    for (int i = 0; i < sir.length; i++) {
        newData[length + i] = sir.data[i];
    }

    Sir<T> result(newData, newLength);
    delete[] newData; // Eliberez memoria temporară
    return result;
}

// Operatorul * întoarce şirul elementelor care ocupă aceeaşi poziţie şi coincid în cele două şiruri

template <typename T>
Sir<T> Sir<T>::operator*(const Sir<T>& sir) const {
    int minLength = (length < sir.length) ? length : sir.length; //aflam lungimea celui mai mic sir folosind o comparatie simpla cu operator ternar
    T* commonData = new T[minLength]; // stocam temporar elementele comune intr un vector de lungimea min length aflata anterior
    int commonCount = 0; //counter pentru elemente comune

//parcurgem si comparam sirurile si stocam elementele comune
    for (int i = 0; i < minLength; i++) {
        if (data[i] == sir.data[i]) {
            commonData[commonCount++] = data[i];
        }
    }
    // rezultatul apartine unui sir cu
    Sir<T> result(commonData, commonCount);
    delete[] commonData; 
    return result;
}


//Operatorul - elimina prefixul, daca exista
template <typename T>
Sir<T> Sir<T>::operator-(const Sir<T>& sir) const {
    if (sir.length > length) //pentru a fi prefix, sirul trebuie sa aiba o lungime mai mica 
        return *this;
    
    for (int i = 0; i < sir.length; ++i) // parcurgem elementele
    {
    if (data[i] != sir.data[i]) //este prefix daca nu contine elemente diferite
     return *this; 
    }

    int newLength = length - sir.length; // câte elemente rămân după eliminarea prefixului
    T* newData = new T[newLength];

    for (int i = 0; i < newLength; ++i) //parcurgem elementele ramase dupa prefix
    {
        newData[i] = data[sir.length + i]; // pentru "eliminare", începem de la poziția imediat după prefix
    }
    Sir<T> result(newData, newLength); //noul sir
    delete[] newData;
    return result; // Returnăm noul șir
}

//Operatorul << elimina n elemente de la inceputul sirului
template <typename T>
Sir<T> Sir<T>::operator<<(int n) const {
    if(n >= length){
        return Sir<T>(); //returneaza un sir gol in cazul in care numar de elemente care trebuie sterse sunt mai multe decat numarul de elemente din sir
    }
    int newLength = length - n; // cate elemente raman dupa eliminarea primelor n elemente
    T* newData = new T[newLength];

    for(int i = 0; i < newLength; ++i){
        newData[i] = data[n+i];
    }

    Sir<T> result(newData, newLength); // noul sir
    delete[] newData; // eliberare memorie
    return result;
}

//Operatorul >> elimina n elemente de la sfarsitul sirului
template <typename T>
Sir<T> Sir<T>::operator>>(int n) const {
    if(n >= length){
        return Sir<T>();  //returneaza un sir gol in cazul in care numar de elemente care trebuie sterse sunt mai multe decat numarul de elemente din sir
    }
    int newLength = length - n; // cate elemente raman dupa eliminarea ultimelor n elemente
    T* newData = new T[newLength];

    for(int i = 0; i < newLength; ++i){
        newData[i] = data[i];
    }

    Sir<T> result(newData, newLength); // noul sir
    delete[] newData; //eliberare memorie
    return result;
}