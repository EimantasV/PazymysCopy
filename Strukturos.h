#pragma once

#include<string>

class Zmogus {
protected:
    std::string vardas;
    std::string pavarde;
    
public:
    virtual ~Zmogus() = 0;
    std::string GetVardas() const { return vardas; }
    std::string GetPavarde() const { return pavarde; }
    void setVardas(std::string vardas) { Zmogus::vardas = vardas; }
    void setPavarde(std::string pavarde) { Zmogus::pavarde = pavarde; }
};

inline Zmogus::~Zmogus() {
}


//struct Studentas
class Studentas : public Zmogus
{
    private:
    //std::string vardas;
    //std::string pavarde;
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
    std::string GetVardas() const
    {
        return vardas;
    }
    std::string GetPavarde() const
    {
        return pavarde;
    }
    double GetPazymiuSum() const
    {
        return pazymiuSum;
    }
    double GetMediana() const
    {
        return medianos;
    }
    double GetEgzas() const
    {
        return egzai;
    }
    double GetGalutinis() const
    {
        return galutinis;
    }

    Studentas (const Studentas& other) :  medianos(other.GetMediana()), egzai(other.GetEgzas()) , galutinis(other.GetGalutinis()){vardas = other.GetVardas();pavarde= other.GetPavarde();}; // copy
    
    Studentas& operator=( const Studentas& other) // set
    {
        if(&other == this) return *this;

        vardas = other.GetVardas();
        pavarde = other.GetPavarde();
        medianos = other.GetMediana();
        egzai = other.GetEgzas();
        galutinis = other.GetGalutinis();
        return *this;
    }
    ~Studentas(){} // destroy

};