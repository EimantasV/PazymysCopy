#include<iostream>
#include<iomanip>

using namespace std;

void NuskaitytiNM(int & n, int & m)
{
    cout << "Iveskite mokyniu sk.: ";
    while(true)
    {
        
        cin >> m;
        if(cin.fail())
        {
            cout << "Netinkamas simbolis. (Naudokite skaitmenis). Pakartokite: "<<endl; 
            cin.clear();
            cin.ignore();
            continue;
        }
        if(m<0)
        {
            cout << "Netinkamas skaicius. (galimi skaiciai nuo 0 iki +infinity). Pakartokite: "<<endl; 
            continue;
        }
        break;
    }
    cout << "Iveskite nd sk.: ";
    while(true)
    {
        
        cin >> n;
        if(cin.fail())
        {
            cout << "Netinkamas simbolis. (Naudokite skaitmenis). Pakartokite: "<<endl; 
            cin.clear();
            cin.ignore();
            continue;
        }
        if(n<1)
        {
            cout << "Netinkamas skaicius. (galimi skaiciai nuo 1 iki +infinity). Pakartokite: "<<endl; 
            continue;
        }
        break;
    }
}

int main()
{
    int m;
    string *vardas = new string[1000000];
    string *pavarde = new string[1000000];
    int n;
    double *pazymiuSum = new double[1000000];
    double *medianos = new double[1000000];
    double *egzai = new double [1000000];

    double *medianaCalcArr = new double[100000];

    bool irasymoMode = true;
    bool mediana = false;
    bool randomValues = false;

    cout << "Ar zinote mokiniu ir nd sk.? (y/n): ";
    string yn;
    cin >>yn;

    cout << "Ar norite, kad galutinis rezultatas butu ir su mediana suskaiciuotas? (y/n): ";
    string yn2;
    cin >>yn2;
    if(yn2=="y")
    {
        mediana=true;
    }

    if(yn =="y")
    {
        cout << "Ar norite atsitiktinai sugeneruotu reiksmiu? (y/n): ";
        string yn3;
        cin >>yn3;
        if(yn3=="y")
        {
            randomValues=true;
        }
        NuskaitytiNM(n,m);
    }
    else 
    {
        cout << "Nezinomas mokiniu ir nd sk."<<endl;
        irasymoMode=false;
    }



    
    //Nuskaityti
    if(!randomValues)
    {
        if(irasymoMode) // zinomas mokiniu ir nd sk.
        {
            for(int i =0;i<m;i++)
            {
                cout << "Iveskite varda: ";
                cin >> vardas[i];
                cout << "Iveskite pavarde: ";
                cin >> pavarde[i];
                pazymiuSum[i] = 0;
                
                for(int a = 0;a<n;a++)
                {
                    int temp;
                    cout << "Iveskite nd pazymi: ";
                    cin >> temp;
                    if(cin.fail())
                    {
                        cout << "Netinkamas pazymys. (Naudokite skaitmenis). Pakartokite: ";
                        a--;
                        cin.clear();
                        cin.ignore();
                        continue;
                    }
                    if(temp <1 || temp >10) 
                    {
                        cout << "Netinkamas pazymys. (skaicius nuo 1 iki 10), Pakartokite: ";
                        a--;
                        continue;
                    }
                    pazymiuSum[i] +=temp;
                    if(mediana)
                    {
                        medianaCalcArr[a]=temp;
                    }
                }
                if(mediana)
                {
                    if(n%2==1)
                    {
                        medianos[i] = medianaCalcArr[n/2];
                    }
                    else
                    {
                        medianos[i] = (medianaCalcArr[n/2]+medianaCalcArr[n/2-1])/2.0;
                    }
                }
                while (true)
                {
                    cout << "Iveskite egzamino pazymi: ";
                    cin>> egzai[i];
                    if(cin.fail())
                    {
                        cout << "Netinkamas pazymys. (Naudokite skaitmenis). Pakartokite: ";
                        
                        cin.clear();
                        cin.ignore();
                        continue;
                    }
                    if(egzai[i] <1 || egzai[i] >10) 
                    {
                        cout << "Netinkamas pazymys. (skaicius nuo 1 iki 10), Pakartokite: ";
                        continue;
                    }
                    break;
                }
            }
        }

        else // nezinomas mokiniu ir nd sk.
        {
            for(int i =0;i<1000000;i++)
            {
                cout << "Iveskite varda (parasykyte STOP, kad pereitumete prie rezultatu): ";
                cin >> vardas[i];
                if(vardas[i]=="STOP")
                {
                    m = i;
                    break;
                }
                cout << "Iveskite pavarde: ";
                cin >> pavarde[i];
                pazymiuSum[i] = 0;
                int a;
                for(a=0;a<1000000;a++)
                {
                    int temp;
                    cout << "Iveskite nd pazymi (parasykite 1 betkoki simboli (ne skaiciu), kad pereitumete prie egzamino rez.): ";
                    cin >> temp;
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        break;
                    }
                    if(temp <1 || temp >10) 
                    {
                        cout << "Netinkamas pazymys. (skaicius nuo 1 iki 10), Pakartokite: ";
                        continue;
                    }
                    pazymiuSum[i] +=temp;
                    
                    if(mediana)
                    {
                        medianaCalcArr[a]=temp;
                    }
                }
                if(mediana)
                {
                    if(a%2==1)
                    {
                        medianos[i] = medianaCalcArr[a/2];
                    }
                    else
                    {
                        medianos[i] = (medianaCalcArr[a/2]+medianaCalcArr[a/2-1])/2.0;
                    }
                }
                pazymiuSum[i]/=a;


                while (true)
                {
                    cout << "Iveskite egzamino pazymi: ";
                    cin>> egzai[i];
                    
                    if(cin.fail())
                    {
                        cout << "Netinkamas pazymys. (Naudokite skaitmenis). Pakartokite: ";
                        
                        cin.clear();
                        cin.ignore();
                        continue;
                    }
                    if(egzai[i] <1 || egzai[i] >10) 
                    {
                        cout << "Netinkamas pazymys. (skaicius nuo 1 iki 10), Pakartokite: ";
                        continue;
                    }
                    break;
                }
            }
        }
    }
    else //random
    {
        for(int i =0;i<m;i++)
        {
            vardas[i] = "Vardenis"+to_string(i);
            pavarde[i] = "Pavardenis"+to_string(i);
            for(int a = 0;a<n;a++)
            {
                int temp = rand()%10+1;
                pazymiuSum[i] += temp;
                if(mediana)
                {
                    medianaCalcArr[a]=temp;
                }
            }
            egzai[i] =rand()%10+1;
            if(mediana)
            {
                if(n%2==1)
                {
                    medianos[i] = medianaCalcArr[n/2];
                }
                else
                {
                    medianos[i] = (medianaCalcArr[n/2]+medianaCalcArr[n/2-1])/2.0;
                }
            }
        }
    }



    //Print
    cout <<endl;
    if(irasymoMode)
    {
        if(mediana)
        {
            cout << "Vardas         Pavarde        Galutinis(vid.)      Galutinis(med.)"<<endl;
            cout << "=================================================================="<<endl;
            for(int i =0;i<m;i++)
            {
                cout << setw(15) << left << vardas[i] << setw(15) << left <<  pavarde[i] << setw(21) << left<<fixed<<setprecision(2)  << 0.4*(pazymiuSum[i]/n)+0.6*egzai[i] << 0.4*(medianos[i])+0.6*egzai[i]<< endl;
            }
        }
        else
        {
            cout << "Vardas         Pavarde        Galutinis(vid.)"<<endl;
            cout << "============================================="<<endl;
            for(int i =0;i<m;i++)
            {
                cout << setw(15) << left << vardas[i] << setw(15) << left <<  pavarde[i] << fixed<<setprecision(2)  << 0.4*(pazymiuSum[i]/n)+0.6*egzai[i]<< endl;
            }
        }
    }
    else
    {   
        if(mediana)
        {
            cout << "Vardas         Pavarde        Galutinis(vid.)      Galutinis(med.)"<<endl;
            cout << "=================================================================="<<endl;
            for(int i =0;i<m;i++)
            {
                cout << setw(15) << left << vardas[i] << setw(15) << left <<  pavarde[i] << setw(21) << left<<fixed<<setprecision(2)  << 0.4*(pazymiuSum[i])+0.6*egzai[i] << 0.4*(medianos[i])+0.6*egzai[i]<< endl;
            }
        }
        else
        {
            cout << "Vardas         Pavarde        Galutinis(vid.)"<<endl;
            cout << "============================================="<<endl;
            for(int i =0;i<m;i++)
            {
                cout << setw(15) << left << vardas[i] << setw(15) << left <<  pavarde[i] <<fixed<<setprecision(2)  << 0.4*(pazymiuSum[i])+0.6*egzai[i]<< endl;
            }
        }
    }
    
    
    
    
    //end
    system("pause");
    return 0;
}