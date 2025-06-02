#include "src/Sir.h"

int main() {
    int arr1[] = {1, 2};
    int arr2[] = {1, 2, 3};

    Sir<int> a(arr1, 2);
    Sir<int> b(arr2, 3);

    Sir<int> copiat;
    copiat = a;

    // Sir<int> gol;

    // int intreg = gol;

    a.print();
    b.print();
    copiat.print();
    if (a == b){
        cout<<"Sirurile a si b sunt egale\n";
    }
    else{
        cout<<"Sirurile a si b sunt diferite\n";
    }
    if (a == copiat){
        cout<<"Sirurile a si c sunt egale\n";
    }
    else{
        cout<<"Sirurile a si c sunt diferite\n";
    }

    if (a > b){
        cout<<"a este suprasir strict\n";
    }
    if (a < b){
        cout<<"a este subsir strict\n";
    }
    if (b > a){
        cout<<"b este suprasir strict\n";
    }
    if (copiat >= a){
        cout<<"c este suprasir\n";
    }

}