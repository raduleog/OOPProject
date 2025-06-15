# 📘 Proiect POO – Clasa Template `Sir<T>`

## 🔍 Descriere

Acest proiect implementează o clasă template generică `Sir<T>`, care reprezintă un șir de elemente (similar unui vector). Clasa oferă funcționalități extinse prin suprascrierea operatorilor pentru:
- comparație (`==`, `<`, `<=`, `>`, `>=`)
- concatenare (`+`)
- ștergere prefix (`-`)
- intersecție pozițională (`*`)
- ștergeri din capătul stâng sau drept (`<<`, `>>`)
- conversii implicite

Proiectul este împărțit în 3 module: definiția clasei, implementarea funcționalităților și testarea acestora.

---

## 📁 Structura fișierelor

```
/project-root
├── src/
│   ├── Sir.h         # Definirea clasei template și a operatorilor
│   ├── Sir.cpp       # Implementarea tuturor metodelor și operatorilor
├── main.cpp          # Cod de testare manuală
├── README.md         # Documentația proiectului
└── .gitignore        # Fișiere excluse din git
```

---

## 🧠 Funcționalități implementate

### ✅ Constructori
- Constructor default (șir gol)
- Constructor cu vector și lungime
- Copy constructor
- Operator `=`
- Destructor

### ⚙️ Operatorii implementați

| Operator   | Descriere |
|------------|-----------|
| `==`       | Verifică egalitatea a două șiruri |
| `<`, `<=`  | Verifică dacă un șir este subșir (strict/nestrict) al altuia |
| `>`, `>=`  | Verifică dacă un șir este suprașir (strict/nestrict) al altuia |
| `+`        | Concatenează două șiruri |
| `-`        | Elimină prefixul dacă există |
| `*`        | Returnează elementele comune aflate pe aceleași poziții |
| `<< n`     | Elimină primele `n` elemente din șir |
| `>> n`     | Elimină ultimele `n` elemente din șir |
| `(T)`      | Conversie la primul element din șir sau excepție dacă e gol |

---

## ▶️ Compilare și rulare

### 🔧 Compilare
Este necesar un compilator C++ instalat (`g++`, `clang++` etc). Apoi:

```bash
g++ -o test main.cpp
./test
```

### 🧪 Exemple de rulare

- Compararea a două șiruri
- Testarea operatorilor de concatenare, ștergere și intersecție
- Testarea conversiei și a operatorilor de deplasare

---

## 👥 Autori și contribuții

| Nume                 | Responsabilități principale                                                                                              |
|----------------------|--------------------------------------------------------------------------------------------------------------------------|
| Radu Leog            | Definirea clasei `Sir<T>`, operatori de comparație, conversii                                                            |
| Robert-Valentin Pufu | Operatorii binari: `+`, `-`, `*`                                                                                         |
| Alexandru-Mihai Zob  | Operatorii de deplasare `<<`, `>>`, management memorie, conversie `Sir(T)`, testare (main.cpp), documentație (README.md) |

---

## 🛠 Informații adiționale

- Proiectul poate fi extins cu funcționalități suplimentare (sortare, acces indexat etc.).
- Respectă principiile programării orientate pe obiecte: **encapsulare**, **modularitate**, **operator overloading**.

---