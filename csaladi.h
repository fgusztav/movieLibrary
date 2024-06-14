#ifndef CSALADI_H
#define CSALADI_H


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "film.h"

#include "memtrace.h"
using namespace std;

///csaladi film tipusu szarmaztatott osztaly
class Csaladi: public Film
{
    int korhatar; //film korhatára
public:
    ///paraméter nélküli konstruktor
    Csaladi() : Film()
    {
        korhatar = 0;
    }
    ///paraméteres konstruktor
    Csaladi(string c, int h, int e, int korhat = 0) : Film(c, h, e)
    {
        korhatar = korhat;
    }
    ///másoló konstruktor
    Csaladi(const Csaladi& f) : Film(f.getCim(), f.getHossz(), f.getEv())
    {
        korhatar = f.getKorhatar();
    }

    ///visszaadja milyen tipusu Film, a megfelelő osztályok létrehozása érdekében
    int tipus() const
    {
        return 1;
    }

    ///visszaadja a film korhatárát
    int getKorhatar() const
    {
        return korhatar;
    };

    ///Kiírja a film adatait egy tetszőleges output streamre.
    void print(ostream& os) const
    {
        os << cim << '\t' << hossz << '\t' << ev << '\t' << korhatar << endl;
    };

    ///destruktor
    ~Csaladi() {}
};

#endif // CSALADI_H
