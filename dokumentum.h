#ifndef DOKUMENTUM_H
#define DOKUMENTUM_H
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "film.h"

#include "memtrace.h"
using namespace std;

///dokumentum film tipusu szarmaztatott osztaly
class Dokumentum: public Film
{
    string leiras;
public:
    ///paraméter nélküli konstruktor
    Dokumentum () : Film()
    {
        leiras = "-";
    }
    ///paraméteres konstruktor
    Dokumentum(string c, int h, int e, string leir = "") : Film(c, h, e)
    {
        leiras = leir;
    }
    ///másoló konstruktor
    Dokumentum(const Dokumentum &f) : Film(f.getCim(), f.getHossz(), f.getEv())
    {
        leiras = f.getLeiras();
    }

    ///visszaadja milyen tipusu Film, a megfelelő osztályok létrehozása érdekében
    int tipus() const
    {
        return 2;
    }

    ///visszaadja a film leírását
    string getLeiras() const
    {
        return leiras;
    }

    ///Kiírja a film adatait egy tetszőleges output streamre.
    void print(ostream& os) const
    {
        os << cim << '\t' << hossz << '\t' << ev << '\t' << leiras << endl;
    };

    ///destruktor
    ~Dokumentum() {}

};

#endif // DOKUMENTUM_H
