#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <exception>
#include <chrono>
#include <iomanip>
#include <list>
#include <deque>
#include "Strukturos.h"

bool SortByPazymys(Studentas stud1, Studentas stud2)
{
    return stud1.GetGalutinis() > stud2.GetGalutinis();
}
bool SortByVardas(Studentas stud1, Studentas stud2)
{
    return stud1.GetVardas() < stud2.GetVardas();
}

void NuskaitytiNM(int &n, int &m)
{
    std::cout << "Iveskite mokiniu sk.: ";
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
    
        std::string vardasTemp;
        std::string pavardeTemp;
        double pazymiuSumTemp;
        double egzasTemp;
        double medianaTemp;
        double galutinisTemp;

    for (int i = 0; i < m; i++)
    {
        //studentai.push_back(Studentas());
        std::string tempS;

        std::cout << "Iveskite varda: ";
        std::cin >> vardasTemp;

        std::cout << "Iveskite pavarde: ";
        std::cin >> pavardeTemp;

        pazymiuSumTemp = 0;
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
            pazymiuSumTemp += temp;

            if (mediana)
            {
                medianaCalcArr.push_back(temp);
            }
        }
        if (mediana)
        {
            medianaTemp = GautiMediana(medianaCalcArr);
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

            egzasTemp = temp;
            break;
        }
        Studentas tempStud(vardasTemp,pavardeTemp,pazymiuSumTemp,medianaTemp,egzasTemp,galutinisTemp);
        studentai.push_back(tempStud);
    }
}

void Console_NezinomasSk(std::vector<Studentas> &studentai, bool mediana, int &m, int n)
{
    std::vector<double> medianaCalcArr;

    std::string vardasTemp;
    std::string pavardeTemp;
    double pazymiuSumTemp;
    double egzasTemp;
    double medianaTemp;
    double galutinisTemp;


    for (int i = 0; true; i++) // :D
    {
        //studentai.push_back(Studentas());
        //std::string tempS;
        std::cout << "Iveskite varda (parasykyte STOP, kad pereitumete prie rezultatu): ";
        std::cin >> vardasTemp; // vardas[i];
        
        if (vardasTemp == "STOP")
        {
            m = i;
            break;
        }
        std::cout << "Iveskite pavarde: ";
        std::cin >> pavardeTemp; // pavarde[i];

        pazymiuSumTemp = 0;
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
            pazymiuSumTemp += temp;

            if (mediana)
            {
                medianaCalcArr.push_back(temp);
            }
        }
        if (mediana)
        {
            medianaTemp = GautiMediana(medianaCalcArr);
        }
        pazymiuSumTemp /= a;

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
            egzasTemp = temp;
            break;
        }
        studentai.push_back(Studentas(vardasTemp,pavardeTemp,pazymiuSumTemp,medianaTemp,egzasTemp,galutinisTemp));
    }
}

void Console_Random(std::vector<Studentas> &studentai, bool mediana, int m, int n)
{
    std::vector<double> medianaCalcArr;

    std::string vardasTemp;
    std::string pavardeTemp;
    double pazymiuSumTemp;
    double egzasTemp;
    double medianaTemp;
    double galutinisTemp;

    for (int i = 0; i < m; i++)
    {


        std::cout << "Iveskite varda: ";
        std::cin >> vardasTemp;


        std::cout << "Iveskite pavarde: ";
        std::cin >> pavardeTemp;


        pazymiuSumTemp = 0;
        medianaCalcArr.clear();
        for (int a = 0; a < n; a++)
        {
            int temp = rand() % 10 + 1;
            pazymiuSumTemp += temp;
            if (mediana)
            {
                medianaCalcArr.push_back(temp);
            }
        }
        egzasTemp = rand() % 10 + 1;
        if (mediana)
        {
            medianaTemp = GautiMediana(medianaCalcArr);
        }

        studentai.push_back(Studentas(vardasTemp,pavardeTemp,pazymiuSumTemp,medianaTemp,egzasTemp,galutinisTemp));
    }
}

void File_Read(std::vector<Studentas> &studentai, std::ifstream &input, int &m, int& n)
{
    std::string temp;
    m=0;
    for (int i = 0; i < 1000; i++) //1000 nd limit
    {

        input >> temp;

        if (temp == "Egz." || temp == "Egzaminas")
        {
            n = i - 2;
            break;
        }
        if (i == 999)
        {
            try
            {
                throw "per daug nd (>=1000) arba nerastas 'Egz.' 'Egzaminas'";
            }
            catch (const char *e)
            {
                std::cerr << e << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    try
    {
        std::vector<double> medianaCalcArr;
        
        std::string vardasTemp;
        std::string pavardeTemp;
        double pazymiuSumTemp;
        double egzasTemp;
        double medianaTemp;
        double galutinisTemp;

        while(!input.eof()) // m - mokiniai global
        {
            m++;
            input >> vardasTemp;
            input >> pavardeTemp;
            int tempNd;

            pazymiuSumTemp = 0;
            medianaCalcArr.clear();
            for (int a = 0; a < n; a++)
            {
                input >> tempNd;
                pazymiuSumTemp += tempNd;
                medianaCalcArr.push_back(tempNd);
            }
            pazymiuSumTemp /= n;
            input >> egzasTemp;

            medianaTemp = GautiMediana(medianaCalcArr);

            galutinisTemp = (0.4 * pazymiuSumTemp + 0.6 * egzasTemp);

            
                    Studentas tempStud(vardasTemp,pavardeTemp,pazymiuSumTemp,medianaTemp,egzasTemp,galutinisTemp);
        studentai.push_back(tempStud);
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Analizuoti(std::vector<Studentas>& studentai, int &m, int &n)
{
    std::string fileName;
    std::cout << "Failo pavadinimas: ";
    std::cin >> fileName;

    //timer, failo sukurimas
    auto clock_startTotal = std::chrono::system_clock::now();
    auto clock_start = std::chrono::system_clock::now();

    //failo nuskaitymas
    clock_start = std::chrono::system_clock::now();
    std::ifstream input(fileName);
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
    File_Read(studentai, input, m, n);
    input.close();
    auto clock_now = std::chrono::system_clock::now();
    float currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Failas nuskaitytas per: " << currentTime / 1000000 << " S \n";

    //failo rikiavimas
    clock_start = std::chrono::system_clock::now();
    sort(studentai.begin(), studentai.end(), SortByPazymys);

    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Studentai surikuoti pagal rezultatus per: " << currentTime / 1000000 << " S \n";

    //studentu atskirimas i dvi kategorijas Vykeliai ir Nevykeliai
    clock_start = std::chrono::system_clock::now();
    std::vector<Studentas>::iterator pirmasNevykes;

    for (std::vector<Studentas>::iterator it = studentai.begin() ; it != studentai.end(); it++)
    {
        if ((0.4 * (*it).GetPazymiuSum() + 0.6 * (*it).GetEgzas()) < 5.0)
        {
            pirmasNevykes = it;
            break;
        }
    }

    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Studentai atskirti pagal rezultatus per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    std::ofstream output("Vykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (std::vector<Studentas>::iterator it = studentai.begin() ; it != pirmasNevykes; it++)
    {
        output << std::setw(25) << std::left << (*it).GetVardas() << std::setw(25) << std::left << (*it).GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << 0.4 * ((*it).GetPazymiuSum()) + 0.6 * (*it).GetEgzas() << 0.4 * ((*it).GetMediana()) + 0.6 * (*it).GetEgzas() << std::endl;
    }

    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Vykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    output.open("Nevykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (std::vector<Studentas>::iterator it = pirmasNevykes ; it != studentai.end(); it++)
    {
        output << std::setw(25) << std::left << (*it).GetVardas() << std::setw(25) << std::left << (*it).GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << 0.4 * ((*it).GetPazymiuSum()) + 0.6 * (*it).GetEgzas() << 0.4 * ((*it).GetMediana()) + 0.6 * (*it).GetEgzas() << std::endl;
    }
    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Nevykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_startTotal).count());
    std::cout << "Uzduotis atlikta per: " << currentTime / 1000000 << " S \n";
}

void AnalizuotiVectorStrat1(std::vector<Studentas>& studentai,std::vector<Studentas>& vykeliaiVec,std::vector<Studentas>& nevykeliaiVec)
{
    int m, n;
    std::string fileName;
    std::cout << "Failo pavadinimas: ";
    std::cin >> fileName;

    //timer, failo sukurimas
    auto clock_startTotal = std::chrono::system_clock::now();
    auto clock_start = std::chrono::system_clock::now();

    //failo nuskaitymas
    clock_start = std::chrono::system_clock::now();
    std::ifstream input(fileName);
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
    File_Read(studentai, input, m, n);
    input.close();
    auto clock_now = std::chrono::system_clock::now();
    float currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Failas nuskaitytas per: " << currentTime / 1000000 << " S \n";

    //rusiavimas
    clock_start = std::chrono::system_clock::now();

    int countV = std::count_if(studentai.begin(),studentai.end(),[](Studentas x){return x.GetGalutinis()>=5;});
    vykeliaiVec.resize(countV);
    nevykeliaiVec.resize(m-countV);

    std::copy_if (studentai.begin(), studentai.end(), vykeliaiVec.begin(), [](Studentas x){return x.GetGalutinis()>=5;});
    std::copy_if (studentai.begin(), studentai.end(), nevykeliaiVec.begin(), [](Studentas x){return x.GetGalutinis()<5;});


    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Studentai atskirti pagal rezultatus per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    std::ofstream output("Vykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (std::vector<Studentas>::iterator it = vykeliaiVec.begin() ; it != vykeliaiVec.end(); it++)
    {
        output << std::setw(25) << std::left << (*it).GetVardas() << std::setw(25) << std::left << (*it).GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << (*it).GetGalutinis() << 0.4 * ((*it).GetMediana()) + 0.6 * (*it).GetEgzas() << std::endl;
    }

    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Vykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    output.open("Nevykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (std::vector<Studentas>::iterator it = nevykeliaiVec.begin() ; it != nevykeliaiVec.end(); it++)
    {
        output << std::setw(25) << std::left << (*it).GetVardas() << std::setw(25) << std::left << (*it).GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << (*it).GetGalutinis() << 0.4 * ((*it).GetMediana()) + 0.6 * (*it).GetEgzas() << std::endl;
    }
    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Nevykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_startTotal).count());
    std::cout << "Uzduotis atlikta per: " << currentTime / 1000000 << " S \n";
}
void AnalizuotiVectorStrat2(std::vector<Studentas>& studentai, std::vector<Studentas>& nevykeliaiVec)
{
    int m, n;
    std::string fileName;
    std::cout << "Failo pavadinimas: ";
    std::cin >> fileName;

    //timer, failo sukurimas
    auto clock_startTotal = std::chrono::system_clock::now();
    auto clock_start = std::chrono::system_clock::now();

    //failo nuskaitymas
    clock_start = std::chrono::system_clock::now();
    std::ifstream input(fileName);
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
    File_Read(studentai, input, m, n);
    input.close();
    auto clock_now = std::chrono::system_clock::now();
    float currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Failas nuskaitytas per: " << currentTime / 1000000 << " S \n";

    //rusiavimas
    clock_start = std::chrono::system_clock::now();

    int countV = std::count_if(studentai.begin(),studentai.end(),[](Studentas x){return x.GetGalutinis()<5;});
    nevykeliaiVec.resize(countV);

    std::copy_if (studentai.begin(), studentai.end(), nevykeliaiVec.begin(), [](Studentas x){return x.GetGalutinis()<5;});
    studentai.erase(std::remove_if(studentai.begin(),studentai.end(),[](Studentas x){return x.GetGalutinis()<5;}),studentai.end());


    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Studentai atskirti pagal rezultatus per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    std::ofstream output("Vykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (auto & i : studentai)
    {
        output << std::setw(25) << std::left << i.GetVardas() << std::setw(25) << std::left << i.GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << i.GetGalutinis() << 0.4 * (i.GetMediana()) + 0.6 * i.GetEgzas() << std::endl;
    }

    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Vykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    output.open("Nevykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (auto & i : nevykeliaiVec)
    {
        output << std::setw(25) << std::left << i.GetVardas() << std::setw(25) << std::left << i.GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << i.GetGalutinis() << 0.4 * (i.GetMediana()) + 0.6 * i.GetEgzas() << std::endl;
    }
    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Nevykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_startTotal).count());
    std::cout << "Uzduotis atlikta per: " << currentTime / 1000000 << " S \n";
}

void File_Read_List(std::list<Studentas> &studentai, std::ifstream &input, int &m, int& n)
{
    m=0;
    std::string temp;

    for (int i = 0; i < 1000; i++) //1000 nd limit
    {

        input >> temp;

        if (temp == "Egz." || temp == "Egzaminas")
        {
            n = i - 2;
            break;
        }
        if (i == 999)
        {
            try
            {
                throw "per daug nd (>=1000) arba nerastas 'Egz.' 'Egzaminas'";
            }
            catch (const char *e)
            {
                std::cerr << e << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    try
    {
        std::vector<double> medianaCalcArr;

        std::string vardasTemp;
        std::string pavardeTemp;
        double pazymiuSumTemp;
        double egzasTemp;
        double medianaTemp;
        double galutinisTemp;

        while(!input.eof()) // m - mokiniai global
        {
            m++;
            input >> vardasTemp;
            input >> pavardeTemp;
            int tempNd;

            pazymiuSumTemp = 0;
            medianaCalcArr.clear();
            for (int a = 0; a < n; a++)
            {
                input >> tempNd;
                pazymiuSumTemp += tempNd;
                medianaCalcArr.push_back(tempNd);
            }
            pazymiuSumTemp /= n;
            input >> egzasTemp;

            medianaTemp = GautiMediana(medianaCalcArr);

            galutinisTemp = (0.4 * pazymiuSumTemp + 0.6 * egzasTemp);

            
                    Studentas tempStud(vardasTemp,pavardeTemp,pazymiuSumTemp,medianaTemp,egzasTemp,galutinisTemp);
        studentai.push_back(tempStud);
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void AnalizuotiList(std::list<Studentas>& studentai, int &m, int &n)
{
    std::string fileName;
    std::cout << "Failo pavadinimas: ";
    std::cin >> fileName;

    //timer, failo sukurimas
    auto clock_startTotal = std::chrono::system_clock::now();
    auto clock_start = std::chrono::system_clock::now();

    //failo nuskaitymas
    clock_start = std::chrono::system_clock::now();
    std::ifstream input(fileName);
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
    File_Read_List(studentai, input, m, n);
    input.close();
    auto clock_now = std::chrono::system_clock::now();
    float currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Failas nuskaitytas per: " << currentTime / 1000000 << " S \n";

    //failo rikiavimas
    clock_start = std::chrono::system_clock::now();
    studentai.sort(SortByPazymys);

    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Studentai surikuoti pagal rezultatus per: " << currentTime / 1000000 << " S \n";

    //studentu atskirimas i dvi kategorijas Vykeliai ir Nevykeliai
    clock_start = std::chrono::system_clock::now();
    std::list<Studentas>::iterator pirmasNevykes;

    for (std::list<Studentas>::iterator it = studentai.begin() ; it != studentai.end(); it++)
    {
        if ((0.4 * (*it).GetPazymiuSum() + 0.6 * (*it).GetEgzas()) < 5.0)
        {
            pirmasNevykes = it;
            break;
        }
    }

    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Studentai atskirti pagal rezultatus per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    std::ofstream output("Vykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (std::list<Studentas>::iterator it = studentai.begin() ; it != pirmasNevykes; it++)
    {
        output << std::setw(25) << std::left << (*it).GetVardas() << std::setw(25) << std::left << (*it).GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << 0.4 * ((*it).GetPazymiuSum()) + 0.6 * (*it).GetEgzas() << 0.4 * ((*it).GetMediana()) + 0.6 * (*it).GetEgzas() << std::endl;
    }

    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Vykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    output.open("Nevykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (std::list<Studentas>::iterator it = pirmasNevykes ; it != studentai.end(); it++)
    {
        output << std::setw(25) << std::left << (*it).GetVardas() << std::setw(25) << std::left << (*it).GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << 0.4 * ((*it).GetPazymiuSum()) + 0.6 * (*it).GetEgzas() << 0.4 * ((*it).GetMediana()) + 0.6 * (*it).GetEgzas() << std::endl;
    }
    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Nevykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_startTotal).count());
    std::cout << "Uzduotis atlikta per: " << currentTime / 1000000 << " S \n";
}

void AnalizuotiListStrat1(std::list<Studentas>& studentaiList,std::list<Studentas>& vykeliaiList,std::list<Studentas>& nevykeliaiList)
{
    int m, n;
    std::string fileName;
    std::cout << "Failo pavadinimas: ";
    std::cin >> fileName;

    //timer, failo sukurimas
    auto clock_startTotal = std::chrono::system_clock::now();
    auto clock_start = std::chrono::system_clock::now();

    //failo nuskaitymas
    clock_start = std::chrono::system_clock::now();
    std::ifstream input(fileName);
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
    File_Read_List(studentaiList, input, m, n);
    input.close();
    auto clock_now = std::chrono::system_clock::now();
    float currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Failas nuskaitytas per: " << currentTime / 1000000 << " S \n";

    //rusiavimas
    clock_start = std::chrono::system_clock::now();

    int countV = std::count_if(studentaiList.begin(),studentaiList.end(),[](Studentas x){return x.GetGalutinis()>=5;});
    vykeliaiList.resize(countV);
    nevykeliaiList.resize(m-countV);

    std::copy_if (studentaiList.begin(), studentaiList.end(), vykeliaiList.begin(), [](Studentas x){return x.GetGalutinis()>=5;});
    std::copy_if (studentaiList.begin(), studentaiList.end(), nevykeliaiList.begin(), [](Studentas x){return x.GetGalutinis()<5;});


    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Studentai atskirti pagal rezultatus per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    std::ofstream output("Vykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (auto & i : vykeliaiList)
    {
        output << std::setw(25) << std::left << i.GetVardas() << std::setw(25) << std::left << i.GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << i.GetGalutinis() << 0.4 * (i.GetMediana()) + 0.6 * i.GetEgzas() << std::endl;
    }

    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Vykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    output.open("Nevykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (auto & i : nevykeliaiList)
    {
        output << std::setw(25) << std::left << i.GetVardas() << std::setw(25) << std::left << i.GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << i.GetGalutinis() << 0.4 * (i.GetMediana()) + 0.6 * i.GetEgzas() << std::endl;
    }
    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Nevykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_startTotal).count());
    std::cout << "Uzduotis atlikta per: " << currentTime / 1000000 << " S \n";
}

void AnalizuotiListStrat2(std::list<Studentas>& studentaiList,std::list<Studentas>& nevykeliaiList)
{
    int m, n;
    std::string fileName;
    std::cout << "Failo pavadinimas: ";
    std::cin >> fileName;

    //timer, failo sukurimas
    auto clock_startTotal = std::chrono::system_clock::now();
    auto clock_start = std::chrono::system_clock::now();

    //failo nuskaitymas
    clock_start = std::chrono::system_clock::now();
    std::ifstream input(fileName);
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
    File_Read_List(studentaiList, input, m, n);
    input.close();
    auto clock_now = std::chrono::system_clock::now();
    float currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Failas nuskaitytas per: " << currentTime / 1000000 << " S \n";

    //rusiavimas
    clock_start = std::chrono::system_clock::now();

    int countV = std::count_if(studentaiList.begin(),studentaiList.end(),[](Studentas x){return x.GetGalutinis()<5;});
    nevykeliaiList.resize(countV);

    std::copy_if (studentaiList.begin(), studentaiList.end(), nevykeliaiList.begin(), [](Studentas x){return x.GetGalutinis()<5;});
    studentaiList.erase(std::remove_if(studentaiList.begin(),studentaiList.end(),[](Studentas x){return x.GetGalutinis()<5;}),studentaiList.end());


    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Studentai atskirti pagal rezultatus per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    std::ofstream output("Vykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (auto & i : studentaiList)
    {
        output << std::setw(25) << std::left << i.GetVardas() << std::setw(25) << std::left << i.GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << i.GetGalutinis() << 0.4 * (i.GetMediana()) + 0.6 * i.GetEgzas() << std::endl;
    }

    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Vykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    output.open("Nevykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (auto & i : nevykeliaiList)
    {
        output << std::setw(25) << std::left << i.GetVardas() << std::setw(25) << std::left << i.GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << i.GetGalutinis() << 0.4 * (i.GetMediana()) + 0.6 * i.GetEgzas() << std::endl;
    }
    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Nevykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_startTotal).count());
    std::cout << "Uzduotis atlikta per: " << currentTime / 1000000 << " S \n";
}

void File_Read_Deque(std::deque<Studentas> &studentai, std::ifstream &input, int &m, int& n)
{
    m=0;
    std::string temp;

    for (int i = 0; i < 1000; i++) //1000 nd limit
    {

        input >> temp;

        if (temp == "Egz." || temp == "Egzaminas")
        {
            n = i - 2;
            break;
        }
        if (i == 999)
        {
            try
            {
                throw "per daug nd (>=1000) arba nerastas 'Egz.' 'Egzaminas'";
            }
            catch (const char *e)
            {
                std::cerr << e << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }

    try
    {
        std::vector<double> medianaCalcArr;

        std::string vardasTemp;
        std::string pavardeTemp;
        double pazymiuSumTemp;
        double egzasTemp;
        double medianaTemp;
        double galutinisTemp;

        while(!input.eof()) // m - mokiniai global
        {
            m++;
            input >> vardasTemp;
            input >> pavardeTemp;
            int tempNd;

            pazymiuSumTemp = 0;
            medianaCalcArr.clear();
            for (int a = 0; a < n; a++)
            {
                input >> tempNd;
                pazymiuSumTemp += tempNd;
                medianaCalcArr.push_back(tempNd);
            }
            pazymiuSumTemp /= n;
            input >> egzasTemp;

            medianaTemp = GautiMediana(medianaCalcArr);

            galutinisTemp = (0.4 * pazymiuSumTemp + 0.6 * egzasTemp);

            
                    Studentas tempStud(vardasTemp,pavardeTemp,pazymiuSumTemp,medianaTemp,egzasTemp,galutinisTemp);
        studentai.push_back(tempStud);
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void AnalizuotiDeque(std::deque<Studentas>& studentai, int &m, int &n)
{
    
    std::string fileName;
    std::cout << "Failo pavadinimas: ";
    std::cin >> fileName;

    //timer, failo sukurimas
    auto clock_startTotal = std::chrono::system_clock::now();
    auto clock_start = std::chrono::system_clock::now();

    //failo nuskaitymas
    clock_start = std::chrono::system_clock::now();
    std::ifstream input(fileName);
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
    File_Read_Deque(studentai, input, m, n);
    input.close();
    auto clock_now = std::chrono::system_clock::now();
    float currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Failas nuskaitytas per: " << currentTime / 1000000 << " S \n";

    //failo rikiavimas
    clock_start = std::chrono::system_clock::now();
    sort(studentai.begin(),studentai.end(), SortByPazymys);

    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Studentai surikuoti pagal rezultatus per: " << currentTime / 1000000 << " S \n";

    //studentu atskirimas i dvi kategorijas Vykeliai ir Nevykeliai
    clock_start = std::chrono::system_clock::now();
    std::deque<Studentas>::iterator pirmasNevykes;

    for (std::deque<Studentas>::iterator it = studentai.begin() ; it != studentai.end(); it++)
    {
        if ((0.4 * (*it).GetPazymiuSum() + 0.6 * (*it).GetEgzas()) < 5.0)
        {
            pirmasNevykes = it;
            break;
        }
    }

    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Studentai atskirti pagal rezultatus per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    std::ofstream output("Vykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (std::deque<Studentas>::iterator it = studentai.begin() ; it != pirmasNevykes; it++)
    {
        output << std::setw(25) << std::left << (*it).GetVardas() << std::setw(25) << std::left << (*it).GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << 0.4 * ((*it).GetPazymiuSum()) + 0.6 * (*it).GetEgzas() << 0.4 * ((*it).GetMediana()) + 0.6 * (*it).GetEgzas() << std::endl;
    }

    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Vykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    output.open("Nevykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (std::deque<Studentas>::iterator it = pirmasNevykes ; it != studentai.end(); it++)
    {
        output << std::setw(25) << std::left << (*it).GetVardas() << std::setw(25) << std::left << (*it).GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << 0.4 * ((*it).GetPazymiuSum()) + 0.6 * (*it).GetEgzas() << 0.4 * ((*it).GetMediana()) + 0.6 * (*it).GetEgzas() << std::endl;
    }
    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Nevykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_startTotal).count());
    std::cout << "Uzduotis atlikta per: " << currentTime / 1000000 << " S \n";
}

void AnalizuotiDequeStrat1(std::deque<Studentas>& studentaiDeque,std::deque<Studentas>& vykeliaiDeque,std::deque<Studentas>& nevykeliaiDeque)
{
    int m, n;
    std::string fileName;
    std::cout << "Failo pavadinimas: ";
    std::cin >> fileName;

    //timer, failo sukurimas
    auto clock_startTotal = std::chrono::system_clock::now();
    auto clock_start = std::chrono::system_clock::now();

    //failo nuskaitymas
    clock_start = std::chrono::system_clock::now();
    std::ifstream input(fileName);
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
    File_Read_Deque(studentaiDeque, input, m, n);
    input.close();
    auto clock_now = std::chrono::system_clock::now();
    float currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Failas nuskaitytas per: " << currentTime / 1000000 << " S \n";

    //rusiavimas
    clock_start = std::chrono::system_clock::now();

    int countV = std::count_if(studentaiDeque.begin(),studentaiDeque.end(),[](Studentas x){return x.GetGalutinis()>=5;});
    vykeliaiDeque.resize(countV);
    nevykeliaiDeque.resize(m-countV);

    std::copy_if (studentaiDeque.begin(), studentaiDeque.end(), vykeliaiDeque.begin(), [](Studentas x){return x.GetGalutinis()>=5;});
    std::copy_if (studentaiDeque.begin(), studentaiDeque.end(), nevykeliaiDeque.begin(), [](Studentas x){return x.GetGalutinis()<5;});


    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Studentai atskirti pagal rezultatus per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    std::ofstream output("Vykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (auto & i : vykeliaiDeque)
    {
        output << std::setw(25) << std::left << i.GetVardas() << std::setw(25) << std::left << i.GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << i.GetGalutinis() << 0.4 * (i.GetMediana()) + 0.6 * i.GetEgzas() << std::endl;
    }

    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Vykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    output.open("Nevykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (auto & i : nevykeliaiDeque)
    {
        output << std::setw(25) << std::left << i.GetVardas() << std::setw(25) << std::left << i.GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << i.GetGalutinis() << 0.4 * (i.GetMediana()) + 0.6 * i.GetEgzas() << std::endl;
    }
    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Nevykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_startTotal).count());
    std::cout << "Uzduotis atlikta per: " << currentTime / 1000000 << " S \n";
}
void AnalizuotiDequeStrat2(std::deque<Studentas>& studentaiDeque,std::deque<Studentas>& nevykeliaiDeque)
{
    int m, n;
    std::string fileName;
    std::cout << "Failo pavadinimas: ";
    std::cin >> fileName;

    //timer, failo sukurimas
    auto clock_startTotal = std::chrono::system_clock::now();
    auto clock_start = std::chrono::system_clock::now();

    //failo nuskaitymas
    clock_start = std::chrono::system_clock::now();
    std::ifstream input(fileName);
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
    File_Read_Deque(studentaiDeque, input, m, n);
    input.close();
    auto clock_now = std::chrono::system_clock::now();
    float currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Failas nuskaitytas per: " << currentTime / 1000000 << " S \n";

    //rusiavimas
    clock_start = std::chrono::system_clock::now();


    int countV = std::count_if(studentaiDeque.begin(),studentaiDeque.end(),[](Studentas x){return x.GetGalutinis()<5;});
    nevykeliaiDeque.resize(countV);

    std::copy_if (studentaiDeque.begin(), studentaiDeque.end(), nevykeliaiDeque.begin(), [](Studentas x){return x.GetGalutinis()<5;});
    studentaiDeque.erase(std::remove_if(studentaiDeque.begin(),studentaiDeque.end(),[](Studentas x){return x.GetGalutinis()<5;}),studentaiDeque.end());


    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Studentai atskirti pagal rezultatus per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    std::ofstream output("Vykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (auto & i : studentaiDeque)
    {
        output << std::setw(25) << std::left << i.GetVardas() << std::setw(25) << std::left << i.GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << i.GetGalutinis() << 0.4 * (i.GetMediana()) + 0.6 * i.GetEgzas() << std::endl;
    }

    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Vykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    //studentu surasymas i failus
    clock_start = std::chrono::system_clock::now();
    output.open("Nevykeliai.txt");
    output << "Vardas                   Pavarde                  Galutinis(vid.)      Galutinis(med.)" << std::endl;
    output << "======================================================================================" << std::endl;
    for (auto & i : nevykeliaiDeque)
    {
        output << std::setw(25) << std::left << i.GetVardas() << std::setw(25) << std::left << i.GetPavarde() << std::setw(21) << std::left << std::fixed << std::setprecision(2) << i.GetGalutinis() << 0.4 * (i.GetMediana()) + 0.6 * i.GetEgzas() << std::endl;
    }
    output.close();
    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_start).count());
    std::cout << "Nevykeliai surasyti i faila per: " << currentTime / 1000000 << " S \n";

    clock_now = std::chrono::system_clock::now();
    currentTime = float(std::chrono::duration_cast<std::chrono::microseconds>(clock_now - clock_startTotal).count());
    std::cout << "Uzduotis atlikta per: " << currentTime / 1000000 << " S \n";
}
