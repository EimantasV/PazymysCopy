#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Strukturos.h"

void NuskaitytiNM(int &n, int &m)
{
    std::cout << "Iveskite mokyniu sk.: ";
    while (true)
    {

        std::cin >> m;
        if (std::cin.fail())
        {
            std::cout << "Netinkamas simbolis. (Naudokite skaitmenis). Pakartokite: " << std::endl;
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        if (m < 0)
        {
            std::cout << "Netinkamas skaicius. (galimi skaiciai nuo 0 iki +infinity). Pakartokite: " << std::endl;
            continue;
        }
        break;
    }
    std::cout << "Iveskite nd sk.: ";
    while (true)
    {

        std::cin >> n;
        if (std::cin.fail())
        {
            std::cout << "Netinkamas simbolis. (Naudokite skaitmenis). Pakartokite: " << std::endl;
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        if (n < 1)
        {
            std::cout << "Netinkamas skaicius. (galimi skaiciai nuo 1 iki +infinity). Pakartokite: " << std::endl;
            continue;
        }
        break;
    }
}

double GautiMediana(std::vector<double> &medianaCalcArr)
{
    int n = medianaCalcArr.size();
    sort(medianaCalcArr.begin(), medianaCalcArr.end());
    if (n % 2 == 1)
    {
        return medianaCalcArr[n / 2];
    }
    else
    {
        return (medianaCalcArr[n / 2] + medianaCalcArr[n / 2 - 1]) / 2.0;
    }
}

void Console_ZinomasSk(std::vector<Studentas> &studentai, bool mediana, int m, int n)
{
    std::vector<double> medianaCalcArr;
    for (int i = 0; i < m; i++)
    {
        studentai.push_back(Studentas());
        std::string tempS;

        std::cout << "Iveskite varda: ";
        std::cin >> tempS;
        studentai[i].vardas = tempS;

        std::cout << "Iveskite pavarde: ";
        std::cin >> tempS;
        studentai[i].pavarde = tempS;

        studentai[i].pazymiuSum = 0;
        //pazymiuSum[i] = 0;

        medianaCalcArr.clear();
        for (int a = 0; a < n; a++)
        {
            int temp;
            std::cout << "Iveskite nd pazymi: ";
            std::cin >> temp;
            if (std::cin.fail())
            {
                std::cout << "Netinkamas pazymys. (Naudokite skaitmenis). Pakartokite: ";
                a--;
                std::cin.clear();
                std::cin.ignore();
                continue;
            }
            if (temp < 1 || temp > 10)
            {
                std::cout << "Netinkamas pazymys. (skaicius nuo 1 iki 10), Pakartokite: ";
                a--;
                continue;
            }
            studentai[i].pazymiuSum += temp;

            if (mediana)
            {
                medianaCalcArr.push_back(temp);
            }
        }
        if (mediana)
        {
            studentai[i].medianos = GautiMediana(medianaCalcArr);
        }
        while (true)
        {
            double temp;
            std::cout << "Iveskite egzamino pazymi: ";
            std::cin >> temp; //egzai[i];

            if (std::cin.fail())
            {
                std::cout << "Netinkamas pazymys. (Naudokite skaitmenis). Pakartokite: ";

                std::cin.clear();
                std::cin.ignore();
                continue;
            }
            if (temp < 1 || temp > 10)
            {
                std::cout << "Netinkamas pazymys. (skaicius nuo 1 iki 10), Pakartokite: ";
                continue;
            }

            studentai[i].egzai = temp;
            break;
        }
    }
}

void Console_NezinomasSk(std::vector<Studentas> &studentai, bool mediana, int &m, int n)
{
    std::vector<double> medianaCalcArr;
    for (int i = 0; true; i++) // :D
    {
        studentai.push_back(Studentas());
        std::string tempS;
        std::cout << "Iveskite varda (parasykyte STOP, kad pereitumete prie rezultatu): ";
        std::cin >> tempS; // vardas[i];
        studentai[i].vardas = tempS;
        if (studentai[i].vardas == "STOP")
        {
            m = i;
            break;
        }
        std::cout << "Iveskite pavarde: ";
        std::cin >> tempS; // pavarde[i];
        studentai[i].pavarde = tempS;

        studentai[i].pazymiuSum = 0;
        //pazymiuSum[i] = 0;

        medianaCalcArr.clear();

        int a;
        for (a = 0; true; a++)
        {
            int temp;
            std::cout << "Iveskite nd pazymi (parasykite 1 betkoki simboli (ne skaiciu), kad pereitumete prie egzamino rez.): ";
            std::cin >> temp;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore();
                break;
            }
            if (temp < 1 || temp > 10)
            {
                std::cout << "Netinkamas pazymys. (skaicius nuo 1 iki 10), Pakartokite: ";
                continue;
            }
            studentai[i].pazymiuSum += temp;

            if (mediana)
            {
                medianaCalcArr.push_back(temp);
            }
        }
        if (mediana)
        {
            studentai[i].medianos = GautiMediana(medianaCalcArr);
        }
        studentai[i].pazymiuSum /= a;

        while (true)
        {
            std::cout << "Iveskite egzamino pazymi: ";
            double temp;

            std::cin >> temp; // egzai[i];

            if (std::cin.fail())
            {
                std::cout << "Netinkamas pazymys. (Naudokite skaitmenis). Pakartokite: ";

                std::cin.clear();
                std::cin.ignore();
                continue;
            }
            if (temp < 1 || temp > 10)
            {
                std::cout << "Netinkamas pazymys. (skaicius nuo 1 iki 10), Pakartokite: ";
                continue;
            }
            studentai[i].egzai = temp;
            break;
        }
    }
}

void Console_Random(std::vector<Studentas> &studentai, bool mediana, int m, int n)
{
    std::vector<double> medianaCalcArr;
    for (int i = 0; i < m; i++)
    {
        studentai.push_back(Studentas());
        std::string tempS;

        std::cout << "Iveskite varda: ";
        std::cin >> tempS;
        studentai[i].vardas = tempS;

        std::cout << "Iveskite pavarde: ";
        std::cin >> tempS;
        studentai[i].pavarde = tempS;

        studentai[i].pazymiuSum = 0;
        medianaCalcArr.clear();
        for (int a = 0; a < n; a++)
        {
            int temp = rand() % 10 + 1;
            studentai[i].pazymiuSum += temp;
            if (mediana)
            {
                medianaCalcArr.push_back(temp);
            }
        }
        studentai[i].egzai = rand() % 10 + 1;
        if (mediana)
        {
            studentai[i].medianos = GautiMediana(medianaCalcArr);
        }
    }
}

void File_Read(std::vector<Studentas> &studentai, std::ifstream &input, int &m, int n)
{
    std::string temp;
    for (int i = 0; i < 1000; i++) //1000 nd limit
    {
        input >> temp;
        if (temp == "Egz." || temp == "Egzaminas")
        {
            n = i - 2;
            break;
        }
    }

    std::vector<double> medianaCalcArr;
    for (m = 0; !input.eof(); m++) // m - mokyniai global
    {
        studentai.push_back(Studentas());
        input >> studentai[m].vardas;
        input >> studentai[m].pavarde;
        int tempNd;

        studentai[m].pazymiuSum = 0;
        medianaCalcArr.clear();
        for (int a = 0; a < n; a++)
        {
            input >> tempNd;
            studentai[m].pazymiuSum += tempNd;
            medianaCalcArr.push_back(tempNd);
        }
        studentai[m].pazymiuSum /= n;
        input >> studentai[m].egzai;

        studentai[m].medianos = GautiMediana(medianaCalcArr);
    }
}