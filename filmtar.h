#ifndef FILMTAR_H
#define FILMTAR_H

#include "film.h"
#include "csaladi.h"
#include "dokumentum.h"
#include <string.h>
#include <sstream>
#include <fstream>
#include <iostream>

#include "memtrace.h"
using namespace std;


class Filmtar
{
    int db = 0; //Filmtár mérete
    Film** filmek = nullptr; //tárolja a Film típusú objektumokra mutató pointereket
public:
    ///Paraméter nélküli konstruktor
    Filmtar() {};
    ///Tetszőleges ájlból beolvasó konstruktor
    Filmtar(const char* fajlnev)
    {
        beolvas(fajlnev);
    }
    ///Beolvassa a filmtárat egy adott fájlból. Paraméterként megadható a fájl neve.
    void beolvas(const char* fajlnev)
    {
        fstream adat;
        adat.open(fajlnev, fstream::in | fstream::out);
        if(adat.is_open())
        {
            string sor;
            while(getline(adat, sor))
            {
                unsigned char tipus = stoi(adatmezo(sor));

                string cim = adatmezo(sor);
                int hossz = stoi(adatmezo(sor));
                int ev = stoi(adatmezo(sor));

                switch(tipus)
                {
                case 1:
                {
                    int korhatar = stoi(adatmezo(sor));
                    Csaladi *cs = new Csaladi(cim, hossz, ev, korhatar);
                    hozzaad(cs);
                    break;
                }
                case 2:
                {
                    string leiras = adatmezo(sor);
                    Dokumentum *d = new Dokumentum(cim, hossz, ev, leiras);
                    hozzaad(d);
                    break;
                }

                default:
                {
                    Film *f = new Film(cim, hossz, ev);
                    hozzaad(f);
                }
                }
            }
        }
        adat.close();
    }
    ///Az adott nevű fájlba elmenti a Filmtárat, ugyanolyan formátumban mint ahogy beolvasta.
    void elment(const char* fajlnev)
    {
        fstream adat;
        adat.open(fajlnev, fstream::in | fstream::out);
        if (adat.is_open())
        {
            for (int i = 0; i < db; i++)
            {
                adat << filmek[i]->tipus() << '\t';
                any_print(adat, filmek[i]);
            }
        }
        adat.close();
    };
    ///eldonti melyik fajta filmet printeljen (type-casting hasznalataval)
    void any_print(std::ostream& os, Film* f)
    {
        switch(f->tipus())
        {
        case 1:
            ((Csaladi*) f)->print(os);
            break;
        case 2:
            ((Dokumentum*)f)->print(os);
            break;

        default:
            f->print(os);
        }
    }

    ///Adott output streamre kilistázza az összes filmet. A Film osztáylok print() fv.eit felhasználva.
    void list(std::ostream& os)
    {
        for (int i = 0; i < db; i++) any_print(os, filmek[i]);
    }

    ///Megadott szöveggel lehet keresni a Filmtarban, szintén Filmtarat ad vissza.
    Filmtar keres(char const *s)
    {
        Filmtar talalatok;
        for (int i = 0; i < db; i++)
        {
            if (filmek[i]->getCim().find(s) != string::npos) talalatok.hozzaad(filmek[i]);
        }
        return talalatok;
    };

    ///Film hozzáadása a filmtárhoz. Az objektumra mutató pointert kapja paraméterként.
    void hozzaad(Film* f)
    {
        Film** temp = new Film*[db+1];
        for (int i = 0; i < db; i++)
        {
            temp[i] = filmek[i];
        }
        temp[db] = f;
        db++;
        delete[] filmek;
        filmek = temp;
    };

    ///Film törlése a filmtárból. A hozzáadással azonos elven működik.
    void torol(Film* f)
    {
        Film** temp = new Film*[db-1];
        int idx = 0;
        for (int i = 0; i < db; i++)
        {
            if (filmek[i] != f) temp[idx++] = filmek[i];
        }
        db = idx;
        delete[] filmek;
        filmek = temp;
    }

    int size()
    {
        return db;
    }

    ///Ábécé sorrendbe rendezi a filmeket a címük alapján. Egy szimpla bubble sort.
    void rendez()
    {
        for (int i = db-1; i > 0; --i)
        {
            for (int k = 0; k < i; k++)
            {
                if (filmek[k]->getCim() > filmek[k+1]->getCim())
                {
                    Film* temp = filmek[k];
                    filmek[k] = filmek[k+1];
                    filmek[k+1] = temp;
                }
            }
        }
    }

    ///visszaadja a kapott string egy reszet (a '\t' elvalasztoig) es torli az eredetibol refernciaval
    string adatmezo(string& sor)
    {
        string adatmezo = sor.substr(0, sor.find('\t'));
        sor.erase(0, sor.find('\t') + 1);
        return adatmezo;
    }

    ///Adott indexu elemet adja vissza a filmek tombnek (operator overload)
    Film* operator[](int idx)
    {
        if (idx > db-1) return nullptr;
        return filmek[idx];
    }

    ///Destruktor
    ~Filmtar()
    {
        for (int i = 0; i < db; i++) delete filmek[i];
        delete[] filmek;
    };
};


#endif // FILMTAR_H
