#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Studentas
{
    string vardas;
    string pavarde;
    double pazymiuSum;
    double medianos;
    double egzai;
    bool operator<(Studentas stud)
    {
        return vardas < stud.vardas;
    }
};
vector<Studentas> studentai;
int m; // mokyniu sk,
int n; // nd, sk.
void NuskaitytiNM(int &n, int &m)
{
    cout << "Iveskite mokyniu sk.: ";
    while (true)
    {

        cin >> m;
        if (cin.fail())
        {
            cout << "Netinkamas simbolis. (Naudokite skaitmenis). Pakartokite: " << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        if (m < 0)
        {
            cout << "Netinkamas skaicius. (galimi skaiciai nuo 0 iki +infinity). Pakartokite: " << endl;
            continue;
        }
        break;
    }
    cout << "Iveskite nd sk.: ";
    while (true)
    {

        cin >> n;
        if (cin.fail())
        {
            cout << "Netinkamas simbolis. (Naudokite skaitmenis). Pakartokite: " << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        if (n < 1)
        {
            cout << "Netinkamas skaicius. (galimi skaiciai nuo 1 iki +infinity). Pakartokite: " << endl;
            continue;
        }
        break;
    }
}

int main()
{

    vector<double> medianaCalcArr;

    bool irasymoMode = true;
    bool mediana = false;
    bool randomValues = false;
    bool isFailo = false;

    cout << "Ar nuskaityti duomenys is failo? (y/n): ";
    string arIsFailo;
    cin >> arIsFailo;
    if (arIsFailo == "y")
    {
        isFailo = true;
    }
    if (!isFailo)
    {
        cout << "Ar zinote mokiniu ir nd sk.? (y/n): ";
        string yn;
        cin >> yn;

        cout << "Ar norite, kad galutinis rezultatas butu ir su mediana suskaiciuotas? (y/n): ";
        string yn2;
        cin >> yn2;
        if (yn2 == "y")
        {
            mediana = true;
        }

        if (yn == "y")
        {
            cout << "Ar norite atsitiktinai sugeneruotu reiksmiu? (y/n): ";
            string yn3;
            cin >> yn3;
            if (yn3 == "y")
            {
                randomValues = true;
            }
            NuskaitytiNM(n, m);
        }
        else
        {
            cout << "Nezinomas mokiniu ir nd sk." << endl;
            irasymoMode = false;
        }

        //Nuskaityti
        if (!randomValues)
        {
            if (irasymoMode) // zinomas mokiniu ir nd sk.
            {
                for (int i = 0; i < m; i++)
                {
                    studentai.push_back(Studentas());
                    string tempS;

                    cout << "Iveskite varda: ";
                    cin >> tempS;
                    studentai[i].vardas = tempS;

                    cout << "Iveskite pavarde: ";
                    cin >> tempS;
                    studentai[i].pavarde = tempS;

                    studentai[i].pazymiuSum = 0;
                    //pazymiuSum[i] = 0;

                    medianaCalcArr.clear();
                    for (int a = 0; a < n; a++)
                    {
                        int temp;
                        cout << "Iveskite nd pazymi: ";
                        cin >> temp;
                        if (cin.fail())
                        {
                            cout << "Netinkamas pazymys. (Naudokite skaitmenis). Pakartokite: ";
                            a--;
                            cin.clear();
                            cin.ignore();
                            continue;
                        }
                        if (temp < 1 || temp > 10)
                        {
                            cout << "Netinkamas pazymys. (skaicius nuo 1 iki 10), Pakartokite: ";
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
                        sort(medianaCalcArr.begin(), medianaCalcArr.end());
                        if (n % 2 == 1)
                        {
                            studentai[i].medianos = medianaCalcArr[n / 2];
                        }
                        else
                        {
                            studentai[i].medianos = (medianaCalcArr[n / 2] + medianaCalcArr[n / 2 - 1]) / 2.0;
                        }
                    }
                    while (true)
                    {
                        double temp;
                        cout << "Iveskite egzamino pazymi: ";
                        cin >> temp; //egzai[i];

                        if (cin.fail())
                        {
                            cout << "Netinkamas pazymys. (Naudokite skaitmenis). Pakartokite: ";

                            cin.clear();
                            cin.ignore();
                            continue;
                        }
                        if (temp < 1 || temp > 10)
                        {
                            cout << "Netinkamas pazymys. (skaicius nuo 1 iki 10), Pakartokite: ";
                            continue;
                        }

                        studentai[i].egzai = temp;
                        break;
                    }
                }
            }

            else // nezinomas mokiniu ir nd sk.
            {
                for (int i = 0; true; i++) // :D
                {
                    studentai.push_back(Studentas());
                    string tempS;
                    cout << "Iveskite varda (parasykyte STOP, kad pereitumete prie rezultatu): ";
                    cin >> tempS; // vardas[i];
                    studentai[i].vardas = tempS;
                    if (studentai[i].vardas == "STOP")
                    {
                        m = i;
                        break;
                    }
                    cout << "Iveskite pavarde: ";
                    cin >> tempS; // pavarde[i];
                    studentai[i].pavarde = tempS;

                    studentai[i].pazymiuSum = 0;
                    //pazymiuSum[i] = 0;

                    medianaCalcArr.clear();

                    int a;
                    for (a = 0; true; a++)
                    {
                        int temp;
                        cout << "Iveskite nd pazymi (parasykite 1 betkoki simboli (ne skaiciu), kad pereitumete prie egzamino rez.): ";
                        cin >> temp;
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore();
                            break;
                        }
                        if (temp < 1 || temp > 10)
                        {
                            cout << "Netinkamas pazymys. (skaicius nuo 1 iki 10), Pakartokite: ";
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
                        sort(medianaCalcArr.begin(), medianaCalcArr.end());
                        if (a % 2 == 1)
                        {
                            studentai[i].medianos = medianaCalcArr[a / 2];
                        }
                        else
                        {
                            studentai[i].medianos = (medianaCalcArr[a / 2] + medianaCalcArr[a / 2 - 1]) / 2.0;
                        }
                    }
                    studentai[i].pazymiuSum /= a;

                    while (true)
                    {
                        cout << "Iveskite egzamino pazymi: ";
                        double temp;

                        cin >> temp; // egzai[i];

                        if (cin.fail())
                        {
                            cout << "Netinkamas pazymys. (Naudokite skaitmenis). Pakartokite: ";

                            cin.clear();
                            cin.ignore();
                            continue;
                        }
                        if (temp < 1 || temp > 10)
                        {
                            cout << "Netinkamas pazymys. (skaicius nuo 1 iki 10), Pakartokite: ";
                            continue;
                        }
                        studentai[i].egzai = temp;
                        break;
                    }
                }
            }
        }
        else if (randomValues) //random
        {
            for (int i = 0; i < m; i++)
            {
                studentai.push_back(Studentas());
                string tempS;

                cout << "Iveskite varda: ";
                cin >> tempS;
                studentai[i].vardas = tempS;

                cout << "Iveskite pavarde: ";
                cin >> tempS;
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
                    sort(medianaCalcArr.begin(), medianaCalcArr.end());
                    if (n % 2 == 1)
                    {
                        studentai[i].medianos = medianaCalcArr[n / 2];
                    }
                    else
                    {
                        studentai[i].medianos = (medianaCalcArr[n / 2] + medianaCalcArr[n / 2 - 1]) / 2.0;
                    }
                }
            }
        }
    }
    else if (isFailo)
    {

        string failoName;
        cout << "Failo pavadinimas: ";
        cin >> failoName;
        ifstream input(failoName);
        ofstream output("result.txt");

        string temp;
        for (int i = 0; i < 1000; i++) //1000 nd limit
        {
            input >> temp;
            if (temp == "Egz." || temp == "Egzaminas")
            {
                n = i - 2;
                break;
            }
        }

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

            sort(medianaCalcArr.begin(), medianaCalcArr.end());
            if (n % 2 == 1)
            {
                studentai[m].medianos = medianaCalcArr[n / 2];
            }
            else
            {
                studentai[m].medianos = (medianaCalcArr[n / 2] + medianaCalcArr[n / 2 - 1]) / 2.0;
            }

        }

        sort(studentai.begin(),studentai.end());
        output << "Vardas         Pavarde        Galutinis(vid.)      Galutinis(med.)" << endl;
        output << "==================================================================" << endl;
        for (int i = 0; i < m; i++)
        {
            output << setw(15) << left << studentai[i].vardas << setw(15) << left << studentai[i].pavarde << setw(21) << left << fixed << setprecision(2) << 0.4 * (studentai[i].pazymiuSum) + 0.6 * studentai[i].egzai << 0.4 * (studentai[i].medianos) + 0.6 * studentai[i].egzai << endl;
        }
        system("pause");
        return 0;
    }

    //Print
    cout << endl;
    if (irasymoMode)
    {
        if (mediana)
        {
            cout << "Vardas         Pavarde        Galutinis(vid.)      Galutinis(med.)" << endl;
            cout << "==================================================================" << endl;
            for (int i = 0; i < m; i++)
            {
                cout << setw(15) << left << studentai[i].vardas << setw(15) << left << studentai[i].pavarde << setw(21) << left << fixed << setprecision(2) << 0.4 * (studentai[i].pazymiuSum / n) + 0.6 * studentai[i].egzai << 0.4 * (studentai[i].medianos) + 0.6 * studentai[i].egzai << endl;
            }
        }
        else
        {
            cout << "Vardas         Pavarde        Galutinis(vid.)" << endl;
            cout << "=============================================" << endl;
            for (int i = 0; i < m; i++)
            {
                cout << setw(15) << left << studentai[i].vardas << setw(15) << left << studentai[i].pavarde << fixed << setprecision(2) << 0.4 * (studentai[i].pazymiuSum / n) + 0.6 * studentai[i].egzai << endl;
            }
        }
    }
    else
    {
        if (mediana)
        {
            cout << "Vardas         Pavarde        Galutinis(vid.)      Galutinis(med.)" << endl;
            cout << "==================================================================" << endl;
            for (int i = 0; i < m; i++)
            {
                cout << setw(15) << left << studentai[i].vardas << setw(15) << left << studentai[i].pavarde << setw(21) << left << fixed << setprecision(2) << 0.4 * (studentai[i].pazymiuSum) + 0.6 * studentai[i].egzai << 0.4 * (studentai[i].medianos) + 0.6 * studentai[i].egzai << endl;
            }
        }
        else
        {
            cout << "Vardas         Pavarde        Galutinis(vid.)" << endl;
            cout << "=============================================" << endl;
            for (int i = 0; i < m; i++)
            {
                cout << setw(15) << left << studentai[i].vardas << setw(15) << left << studentai[i].pavarde << fixed << setprecision(2) << 0.4 * (studentai[i].pazymiuSum) + 0.6 * studentai[i].egzai << endl;
            }
        }
    }

    //end
    system("pause");
    return 0;
}