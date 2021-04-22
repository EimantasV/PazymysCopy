#pragma once

#include<string>

//struct Studentas
class Studentas
{
    private:
    std::string vardas;
    std::string pavarde;
    double pazymiuSum;
    double medianos;
    double egzai;
    double galutinis;
    public:
    Studentas()
    {
     pazymiuSum=0;
     medianos=0;
     egzai=0;
     galutinis=0;
    }
    Studentas(std::string _vardas,std::string _pavarde,double _sum, double _mediana, double _egzas, double _galut)
    {
        vardas = _vardas;
        pavarde = _pavarde;
        pazymiuSum = _sum;
        medianos = _mediana;
        egzai = _egzas;
        galutinis = _galut;
    }
    std::string GetVardas()
    {
        return vardas;
    }
    std::string GetPavarde()
    {
        return pavarde;
    }
    double GetPazymiuSum()
    {
        return pazymiuSum;
    }
    double GetMediana()
    {
        return medianos;
    }
    double GetEgzas()
    {
        return egzai;
    }
    double GetGalutinis()
    {
        return galutinis;
    }

};