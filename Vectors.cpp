#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

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
    int m;
    //string *vardas = new string[1000000];
    //string *pavarde = new string[1000000];
    int n;
    //double *pazymiuSum = new double[1000000];
    //double *medianos = new double[1000000];
    //double *egzai = new double [1000000];

    //double *medianaCalcArr = new double[100000]; // 1 zmogaus pazymiai skaiciuojant mediana

    vector<string> vardas;
    vector<string> pavarde;
    vector<double> pazymiuSum;
    vector<double> medianos;
    vector<double> egzai;
    vector<double> medianaCalcArr;

    bool irasymoMode = true;
    bool mediana = false;
    bool randomValues = false;

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
                string tempS;

                cout << "Iveskite varda: ";
                cin >> tempS;
                vardas.push_back(tempS);

                cout << "Iveskite pavarde: ";
                cin >> tempS;
                pavarde.push_back(tempS);

                pazymiuSum.push_back(0);
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
                    pazymiuSum[i] += temp;
                    if (mediana)
                    {
                        medianaCalcArr.push_back(temp);
                    }
                }
                if (mediana)
                {
                    sort(medianaCalcArr.begin(),medianaCalcArr.end());
                    if (n % 2 == 1)
                    {
                        medianos.push_back(medianaCalcArr[n / 2]);
                    }
                    else
                    {
                        medianos.push_back((medianaCalcArr[n / 2] + medianaCalcArr[n / 2 - 1]) / 2.0);
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

                    egzai.push_back(temp);
                    break;
                }
            }
        }

        else // nezinomas mokiniu ir nd sk.
        {
            for (int i = 0; true; i++) // :D
            {
                string tempS;
                cout << "Iveskite varda (parasykyte STOP, kad pereitumete prie rezultatu): ";
                cin >> tempS; // vardas[i];
                vardas.push_back(tempS);
                if (vardas[i] == "STOP")
                {
                    m = i;
                    break;
                }
                cout << "Iveskite pavarde: ";
                cin >> tempS; // pavarde[i];
                pavarde.push_back(tempS);

                pazymiuSum.push_back(0);
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
                    pazymiuSum[i] += temp;

                    if (mediana)
                    {
                        medianaCalcArr.push_back(temp);
                    }
                }
                if (mediana)
                {
                    sort(medianaCalcArr.begin(),medianaCalcArr.end());
                    if (a % 2 == 1)
                    {
                        medianos.push_back(medianaCalcArr[a / 2]);
                    }
                    else
                    {
                        medianos.push_back((medianaCalcArr[a / 2] + medianaCalcArr[a / 2 - 1]) / 2.0);
                    }
                }
                pazymiuSum[i] /= a;

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
                    egzai.push_back(temp);
                    break;
                }
            }
        }
    }
    else //random
    {
        for (int i = 0; i < m; i++)
        {
            string tempS;

            cout << "Iveskite varda: ";
            cin >> tempS;
            vardas.push_back(tempS);

            cout << "Iveskite pavarde: ";
            cin >> tempS;
            pavarde.push_back(tempS);

            pazymiuSum.push_back(0);
            medianaCalcArr.clear();
            for (int a = 0; a < n; a++)
            {
                int temp = rand() % 10 + 1;
                pazymiuSum[i] += temp;
                if (mediana)
                {
                    medianaCalcArr.push_back(temp);
                }
            }
            egzai.push_back(rand() % 10 + 1);
            if (mediana)
            {
                sort(medianaCalcArr.begin(),medianaCalcArr.end());
                if (n % 2 == 1)
                {
                    medianos.push_back(medianaCalcArr[n / 2]);
                }
                else
                {
                    medianos.push_back((medianaCalcArr[n / 2] + medianaCalcArr[n / 2 - 1]) / 2.0);
                }
            }
        }
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
                cout << setw(15) << left << vardas[i] << setw(15) << left << pavarde[i] << setw(21) << left << fixed << setprecision(2) << 0.4 * (pazymiuSum[i] / n) + 0.6 * egzai[i] << 0.4 * (medianos[i]) + 0.6 * egzai[i] << endl;
            }
        }
        else
        {
            cout << "Vardas         Pavarde        Galutinis(vid.)" << endl;
            cout << "=============================================" << endl;
            for (int i = 0; i < m; i++)
            {
                cout << setw(15) << left << vardas[i] << setw(15) << left << pavarde[i] << fixed << setprecision(2) << 0.4 * (pazymiuSum[i] / n) + 0.6 * egzai[i] << endl;
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
                cout << setw(15) << left << vardas[i] << setw(15) << left << pavarde[i] << setw(21) << left << fixed << setprecision(2) << 0.4 * (pazymiuSum[i]) + 0.6 * egzai[i] << 0.4 * (medianos[i]) + 0.6 * egzai[i] << endl;
            }
        }
        else
        {
            cout << "Vardas         Pavarde        Galutinis(vid.)" << endl;
            cout << "=============================================" << endl;
            for (int i = 0; i < m; i++)
            {
                cout << setw(15) << left << vardas[i] << setw(15) << left << pavarde[i] << fixed << setprecision(2) << 0.4 * (pazymiuSum[i]) + 0.6 * egzai[i] << endl;
            }
        }
    }

    //end
    system("pause");
    return 0;
}