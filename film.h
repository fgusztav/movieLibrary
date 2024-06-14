#ifndef FILM_H
#define FILM_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

#include "memtrace.h"
using namespace std;

class Film
{
protected:
    string cim; //A film címe.
    int hossz; //A film hossza másodpercben.
    int ev; //A film kiadásának éve.
public:
    ///paraméter nélküli konstruktor
    Film()
    {
        cim = "-";
        hossz = 0;
        ev = 0;
    }
    ///paraméteres konstruktor
    Film(string c, int h, int e)
    {
        cim = c;
        hossz = h;
        ev = e;
    }
    ///másoló konstruktor
    Film(const Film &f)
    {
        cim = f.getCim();
        hossz = f.getHossz();
        ev = f.getEv();
    }

    ///visszaadja milyen tipusu Film, a megfelelő osztályok létrehozása érdekében
    virtual int tipus() const
    {
        return 0;
    }
    ///visszaadja a film cimet
    string getCim() const
    {
        return cim;
    }
    ///visszaadja a film hosszát
    int getHossz() const
    {
        return hossz;
    }
    ///visszaadja a film kiadási évét
    int getEv() const
    {
        return ev;
    }

    ///Kiírja a film adatait egy tetszőleges output streamre.
    virtual void print(ostream& os)
    {
        os << cim << '\t' << hossz << '\t' << ev << endl;
    }
    ///destruktor
    virtual ~Film() {}
};


#endif // FILM_H
