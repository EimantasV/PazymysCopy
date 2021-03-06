#pragma once

#include<string>
struct Studentas
{
    std::string vardas;
    std::string pavarde;
    double pazymiuSum;
    double medianos;
    double egzai;
    bool operator<(Studentas stud)
    {
        return vardas < stud.vardas;
    }
};