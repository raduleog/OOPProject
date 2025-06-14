#include "src/Sir.h"

int main() {
    int arr1[] = {1, 2};
    int arr2[] = {1, 2, 3};
    int arr3[] = {1, 2, 9};
    int arr4[] = {7, 8, 9, 10};

    Sir<int> a(arr1, 2);
    Sir<int> b(arr2, 3);
    Sir<int> c(arr3, 3);
    Sir<int> d(arr4, 4);

    Sir<int> copiat;
    copiat = a;

    // Afisare initiala
    cout << "a: ";
    a.print();
    cout << "b: ";
    b.print();
    cout << "copiat: ";
    copiat.print();
    cout << "c: ";
    c.print();

    Sir<int> sFromInt = 99;  // test conversie int -> Sir<int>
    cout << "Sir dintr-un singur int: ";
    sFromInt.print();

    //Test operator ==
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

    //Test operator >, <, <=, >=
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
    if(a <= copiat){
        cout << "a este subsir\n";
    }

    //Test operator +
    cout << "\n[+] Concatenarea a+b: ";
    Sir<int> ab = a+b;
    ab.print();

    //Test operator -
    cout << "[-] Eliminare prefix a din b (b-a): ";
    Sir<int> bMinusa = b-a;
    bMinusa.print();

    //Test operator *
    cout << "[*] Intersectie pozitionala b*c: ";
    Sir<int> intersectie = b*c;
    intersectie.print();

    //Test operator <<
    cout << "\n[<<] Eliminare 2 elemente din fata lui d: ";
    Sir<int> dShiftLeft = d << 2;
    dShiftLeft.print();

    //Test operator >>
    cout << "[>>] Eliminare 2 elemente din spatele lui d: ";
    Sir<int> dShiftRight = d >> 2;
    dShiftRight.print();

    //Test conversie la T (doar daca nu e gol)
    try {
        int primul = static_cast<int>(a);
        cout << "\nConversie la int (din a): " << primul << endl;
    } catch (const std::out_of_range& e) {
        cout << "Exceptie: " << e.what() << endl;
    }

    return 0;
}