#include "filmtar.h"

#include "memtrace.h"
using namespace std;

int main()
{
    ///Film osztaly mukodesenek tesztelese:
    //parameter nelkuli konstruktor
    Film f1;
    if(f1.getCim() != "-") throw ("Hibas cim");
    if(f1.getHossz() != 0) throw ("Hibas hossz");
    if(f1.getEv() != 0) throw ("Hibas ev");

    //parameteres kosntruktor
    Film f2("Matrix", 444, 2000);
    if(f2.getCim() != "Matrix") throw ("Hibas cim");
    if(f2.getHossz() != 444) throw ("Hibas hossz");
    if(f2.getEv() != 2000) throw ("Hibas ev");

    //masolo konstruktor
    Film f3(f2);
    if(f3.getCim() != "Matrix") throw ("Hibas cim");
    if(f3.getHossz() != 444) throw ("Hibas hossz");
    if(f3.getEv() != 2000) throw ("Hibas ev");

    ///Csaladi szarmaztatott osztaly mukodesenek tesztelese:
    //parameter nelkuli konstruktor
    Csaladi f4;
    if(f4.getCim() != "-") throw ("Hibas cim");
    if(f4.getHossz() != 0) throw ("Hibas hossz");
    if(f4.getEv() != 0) throw ("Hibas ev");

    //parameteres kosntruktor
    Csaladi f5("Matrix", 444, 2000, 16);
    if(f5.getCim() != "Matrix") throw ("Hibas cim");
    if(f5.getHossz() != 444) throw ("Hibas hossz");
    if(f5.getEv() != 2000) throw ("Hibas ev");
    if(f5.getKorhatar() != 16) throw ("Hibas korhatar");

    //masolo konstruktor
    Csaladi f6(f5);
    if(f6.getCim() != "Matrix") throw ("Hibas cim");
    if(f6.getHossz() != 444) throw ("Hibas hossz");
    if(f6.getEv() != 2000) throw ("Hibas ev");
    if(f6.getKorhatar() != 16) throw ("Hibas korhatar");

    ///Dokumentum szarmaztatott osztaly mukodesenek tesztelese:
    //parameter nelkuli konstruktor
    Dokumentum f7;
    if(f7.getCim() != "-") throw ("Hibas cim");
    if(f7.getHossz() != 0) throw ("Hibas hossz");
    if(f7.getEv() != 0) throw ("Hibas ev");

    //parameteres kosntruktor
    Dokumentum f8("Matrix", 444, 2000, "Filmrol szolo szoveg.");
    if(f8.getCim() != "Matrix") throw ("Hibas cim");
    if(f8.getHossz() != 444) throw ("Hibas hossz");
    if(f8.getEv() != 2000) throw ("Hibas ev");
    if(f8.getLeiras() != "Filmrol szolo szoveg.") throw ("Hibas leiras");

    //masolo konstruktor
    Dokumentum f9(f8);
    if(f8.getCim() != "Matrix") throw ("Hibas cim");
    if(f8.getHossz() != 444) throw ("Hibas hossz");
    if(f8.getEv() != 2000) throw ("Hibas ev");
    if(f8.getLeiras() != "Filmrol szolo szoveg.") throw ("Hibas leiras");


    ///Filmtar tesztelese
    ///fajlbol beolvasas es konstruktor teszt
    Filmtar Netflix("filmtar.txt");

    ///kilistazas teszt
    Netflix.list(cout);

    ///rendezes
    Netflix.rendez();
    cout << "Rendezes utan:" << endl;
    Netflix.list(cout);

    ///hozzaadas teszt
    Dokumentum* f10 = new Dokumentum();
    Netflix.hozzaad(f10);

    int tempsize = Netflix.size();
    if (Netflix[tempsize-1]->getCim() != "-") throw("Hibas hozzaadas");

    ///fajlba mentes teszt
    Netflix.elment("filmtar.txt");
    Filmtar Netflix2("filmtar.txt");
    for (int i = 0; i < tempsize; i++)
    {
        if (Netflix[0]->getCim() != Netflix2[0]->getCim())
        {
            throw("Hibas mentes");
        }
    }
    return 0;

}
