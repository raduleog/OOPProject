#pragma once

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
        bool operator==(const Sir<T>& sir) const; // Verifica daca doua siruri sunt identitice

        int size() const; // Returneaza dimensiunea sirului
        void print(std::ostream& out) const; // printeaza sirul
        
};