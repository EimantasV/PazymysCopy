#include<vector>
#include"Strukturos.h"
void NuskaitytiNM(int &n, int &m);
void Console_ZinomasSk(std::vector<Studentas> &studentai, bool mediana, int m, int n);
void Console_NezinomasSk(std::vector<Studentas> &studentai, bool mediana, int &m, int n);
void Console_Random(std::vector<Studentas> &studentai, bool mediana, int m, int n);
void File_Read(std::vector<Studentas> &studentai, std::ifstream &input, int &m, int n);