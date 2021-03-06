#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <exception>
#include "Strukturos.h"
#include "Funkcijos.h"



std::vector<Studentas> studentai;
std::vector<double> medianaCalcArr;
int m; // mokyniu sk,
int n; // nd, sk.

int main()
{

    bool irasymoMode = true;
    bool mediana = false;
    bool randomValues = false;
    bool isFailo = false;

    std::cout << "Ar nuskaityti duomenys is failo? (y/n): ";
    std::string arIsFailo;
    std::cin >> arIsFailo;
    if (arIsFailo == "y")
    {
        isFailo = true;
    }
    if (!isFailo)
    {
        std::cout << "Ar zinote mokiniu ir nd sk.? (y/n): ";
        std::string yn;
        std::cin >> yn;

        std::cout << "Ar norite, kad galutinis rezultatas butu ir su mediana suskaiciuotas? (y/n): ";
        std::string yn2;
        std::cin >> yn2;
        if (yn2 == "y")
        {
            mediana = true;
        }

        if (yn == "y")
        {
            std::cout << "Ar norite atsitiktinai sugeneruotu reiksmiu? (y/n): ";
            std::string yn3;
            std::cin >> yn3;
            if (yn3 == "y")
            {
                randomValues = true;
            }
            NuskaitytiNM(n, m);
        }
        else
        {
            std::cout << "Nezinomas mokiniu ir nd sk." << std::endl;
            irasymoMode = false;
        }

        //Nuskaityti
        if (!randomValues)
        {
            if (irasymoMode) // zinomas mokiniu ir nd sk.
            {
                Console_ZinomasSk(studentai, mediana, m, n);
            }

            else // nezinomas mokiniu ir nd sk.
            {
                Console_NezinomasSk(studentai, mediana, m, n);
            }
        }
        else if (randomValues) //random
        {
            Console_Random(studentai, mediana, m, n);
        }
    }
    else if (isFailo)
    {

        std::string failoName;
        std::cout << "Failo pavadinimas: ";
        std::cin >> failoName;
        
        std::ifstream input(failoName);
        try{
            if(input.fail()) throw "Nepavyko atidaryti failo"; 
        }catch(const char * e){
            std::cerr << e << std::endl;
            exit(EXIT_FAILURE);
        }

        std::ofstream output("result.txt");

        File_Read(studentai,input,m,n);

        sort(studentai.begin(), studentai.end());
        output << "Vardas         Pavarde        Galutinis(vid.)      Galutinis(med.)" << std::endl;
        output << "==================================================================" << std::endl;
        for (int i = 0; i < m; i++)
        {
            output << std::setw(15) << std::left << studentai[i].vardas << std::setw(15) << std::left << studentai[i].pavarde << std::setw(21) << std::left << std::fixed << std::setprecision(2) << 0.4 * (studentai[i].pazymiuSum) + 0.6 * studentai[i].egzai << 0.4 * (studentai[i].medianos) + 0.6 * studentai[i].egzai << std::endl;
        }
        input.close();
        output.close();
        system("pause");
        return 0;
    }

    //Print
    std::cout << std::endl;
    if (irasymoMode)
    {
        if (mediana)
        {
            std::cout << "Vardas         Pavarde        Galutinis(vid.)      Galutinis(med.)" << std::endl;
            std::cout << "==================================================================" << std::endl;
            for (int i = 0; i < m; i++)
            {
                std::cout << std::setw(15) << std::left << studentai[i].vardas << std::setw(15) << std::left << studentai[i].pavarde << std::setw(21) << std::left << std::fixed << std::setprecision(2) << 0.4 * (studentai[i].pazymiuSum / n) + 0.6 * studentai[i].egzai << 0.4 * (studentai[i].medianos) + 0.6 * studentai[i].egzai << std::endl;
            }
        }
        else
        {
            std::cout << "Vardas         Pavarde        Galutinis(vid.)" << std::endl;
            std::cout << "=============================================" << std::endl;
            for (int i = 0; i < m; i++)
            {
                std::cout << std::setw(15) << std::left << studentai[i].vardas << std::setw(15) << std::left << studentai[i].pavarde << std::fixed << std::setprecision(2) << 0.4 * (studentai[i].pazymiuSum / n) + 0.6 * studentai[i].egzai << std::endl;
            }
        }
    }
    else
    {
        if (mediana)
        {
            std::cout << "Vardas         Pavarde        Galutinis(vid.)      Galutinis(med.)" << std::endl;
            std::cout << "==================================================================" << std::endl;
            for (int i = 0; i < m; i++)
            {
                std::cout << std::setw(15) << std::left << studentai[i].vardas << std::setw(15) << std::left << studentai[i].pavarde << std::setw(21) << std::left << std::fixed << std::setprecision(2) << 0.4 * (studentai[i].pazymiuSum) + 0.6 * studentai[i].egzai << 0.4 * (studentai[i].medianos) + 0.6 * studentai[i].egzai << std::endl;
            }
        }
        else
        {
            std::cout << "Vardas         Pavarde        Galutinis(vid.)" << std::endl;
            std::cout << "=============================================" << std::endl;
            for (int i = 0; i < m; i++)
            {
                std::cout << std::setw(15) << std::left << studentai[i].vardas << std::setw(15) << std::left << studentai[i].pavarde << std::fixed << std::setprecision(2) << 0.4 * (studentai[i].pazymiuSum) + 0.6 * studentai[i].egzai << std::endl;
            }
        }
    }

    //end
    system("pause");
    return 0;
}