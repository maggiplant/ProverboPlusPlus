// Necesas por uzado de std::ifstream
#include <fstream>
// Necesas por uzado de std::cout kaj std::endl
#include <iostream>
// Por uzi vektorojn
#include <vector>
// Por generi hazardan valoron bazita je la nuna tempo
#include <time.h>
// Por shanghigi argv al entjero
#include <cstdlib>
// Por subteni kompiladon je Vindozo en Visual Studio
#include <string>

int main(int argc, char *argv[])
{
    // Malfermi proverbaro.txt per ifstream
    std::ifstream dosiero;
    dosiero.open("proverbaro.txt");

    // Kiom da liniojn enhavas la tekstdosiero?
    int kiomDaLinioj = 0;

    // Chi tiu tekstocheno estas nur por meti la enhavon de proverbaro.txt en dosieroVekt linio post linio
    std::string linio;
    // La dosiera vektoro mem
    std::vector<std::string> dosieroVekt;
    while (getline(dosiero, linio))
    {
        kiomDaLinioj++;
        dosieroVekt.push_back(linio);
    }
    // Fermi la dosieron
    dosiero.close();

    // Pravalorizi la hazardciferan generilon kun la aktuala tempo kiel 'semo'
    srand(time(NULL));

    // Chi tiu seo estas por ekscii, kiom da proverbojn la uzanto demandis. La programo supozas unu se la uzanto ne konigas
    int kiomDaProverboj;
    if (argv[1] != NULL)
    {
        kiomDaProverboj = atoi(argv[1]);
    }
    else
    {
        kiomDaProverboj = 1;
    }

    // En chi tiu por-iteracio, hazardan valoron estas elektita per rand() kaj per ghi, hazardan proverbon el dosieroVekt estas elektita.
    // La por-iteracio rulas ghis la maksimuma valoro de kiomDaProverboj estas atingita. 
    for (int i = 0; i < kiomDaProverboj; i++)
    {
        int hazarda = rand() % kiomDaLinioj + 1;
        std::cout << dosieroVekt.at(hazarda) << std::endl;
    }

    return 0;
}