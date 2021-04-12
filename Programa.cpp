#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <fstream>
#include <exception>
#include <chrono>
#include "Strukturos.h"
#include "Funkcijos.h"

std::vector<Studentas> studentai;
std::list<Studentas> studentaiList;
std::deque<Studentas> studentaiDeque;

std::vector<double> medianaCalcArr;
int m; // mokyniu sk,
int n; // nd, sk.

int main()
{

    bool irasymoMode = true;
    bool mediana = false;
    bool randomValues = false;
    bool isFailo = false;
    bool generuoti = false;
    bool analizuoti = false;

    std::cout << "Ar sugeneruoti duomenis? (y/n): ";
    std::string generuotiS;
    std::cin >> generuotiS;
    if (generuotiS == "y")
    {
        generuoti = true;
    }

    if (generuoti)
    {

        std::cout << "Kiek studentu sugeneruoti? (1-n):";
        std::cin >> m;
        if (std::cin.fail())
        {
            std::cerr << "netinkami duomenys, nutraukiama programa.";
            exit(1);
        }
        std::cout << "Kiek nd sugeneruoti? (1-n):";
        std::cin >> n;
        if (std::cin.fail())
        {
            std::cerr << "netinkami duomenys, nutraukiama programa.";
            exit(1);
        }

        //timer, failo sukurimas
        auto clock_start = std::chrono::system_clock::now();

        std::ofstream output("Studentai" + std::to_string(m) + ".txt");
        output << std::setw(25) << std::left << "Vardas" << std::setw(25) << std::left << "Pavarde";
        for (int i = 0; i < n; i++)
        {
            std::string nd = "ND" + std::to_string(i + 1);
            output << std::setw(15) << std::left << nd;
        }
        output << "Egz." << std::endl;
        for (int i = 0; i < m; i++)
        {
            std::string vard = "Vardenis" + std::to_string(i);
            std::string pavard = "Pavardenis" + std::to_string(i);
            output << std::setw(25) << std::left << vard << std::setw(25) << std::left << pavard;
            for (int a = 0; a < n; a++)
            {
                output << std::setw(15) << std::left << rand() % 10 + 1;
            }
            output << rand() % 10 + 1;
            if (i != m - 1)
                output << std::endl;
        }
        output.close();
        auto clock_now = std::chrono::system_clock::now();
        float currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
        std::cout << "Failas sugeneruotas per: " << currentTime / 1000000 << " S \n";
    }

    std::cout << "Ar analizuoti duomenis? (y/n): ";
    std::string analizuotiS;
    std::cin >> analizuotiS;
    if (analizuotiS == "y")
    {
        analizuoti = true;
    }

    if (analizuoti)
    {
        std::cout << "Naudoti vector(1), list(2), deque(3): ";
        std::string kaNaudot;
        std::cin >> kaNaudot;
        if(kaNaudot=="1")
        {
            Analizuoti(studentai,m,n);
        }
        else if(kaNaudot=="2")
        {
            AnalizuotiList(studentaiList,m,n);
        }
        else if(kaNaudot=="3")
        {
            AnalizuotiDeque(studentaiDeque,m,n);
        }
        else{
            std::cout << "Blogai pasirinkta.";
            exit(1);
        }
    }
    else //negeneruoti
    {
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
            try
            {
                if (input.fail())
                    throw "Nepavyko atidaryti failo";
            }
            catch (const char *e)
            {
                std::cerr << e << std::endl;
                exit(EXIT_FAILURE);
            }

            std::ofstream output("result.txt");

            File_Read(studentai, input, m, n);

            sort(studentai.begin(), studentai.end(), SortByVardas);
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
    }
    //end
    system("pause");
    return 0;
}