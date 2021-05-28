//#include "Vector.h"
#include<vector>
#include<list>
#include<deque>
#include"Strukturos.h"
bool SortByPazymys(Studentas stud1,Studentas stud2);
bool SortByVardas(Studentas stud1,Studentas stud2);
void NuskaitytiNM(int &n, int &m);
void Console_ZinomasSk(std::vector<Studentas> &studentai, bool mediana, int m, int n);
void Console_NezinomasSk(std::vector<Studentas> &studentai, bool mediana, int &m, int n);
void Console_Random(std::vector<Studentas> &studentai, bool mediana, int m, int n);
void File_Read(std::vector<Studentas> &studentai, std::ifstream &input, int &m, int& n);
void Analizuoti(std::vector<Studentas>& studentai, int &m, int &n);
void AnalizuotVectorStrat1(std::vector<Studentas>& studentai,std::vector<Studentas>& vykeliaiVec,std::vector<Studentas>& nevykeliaiVec);
void File_Read_List(std::list<Studentas> &studentai, std::ifstream &input, int &m, int& n);
void AnalizuotiList(std::list<Studentas>& studentai, int &m, int &n);
void AnalizuotiListStrat1(std::list<Studentas>& studentaiList,std::list<Studentas>& vykeliaiList,std::list<Studentas>& nevykeliaiList);
void File_Read_Deque(std::deque<Studentas> &studentai, std::ifstream &input, int &m, int& n);
void AnalizuotiDeque(std::deque<Studentas>& studentai, int &m, int &n);
void AnalizuotiDequeStrat1(std::deque<Studentas>& studentaiDeque,std::deque<Studentas>& vykeliaiDeque,std::deque<Studentas>& nevykeliaiDeque);
void AnalizuotVectorStrat2(std::vector<Studentas>& studentai, std::vector<Studentas>& nevykeliaiVec);
void AnalizuotiListStrat2(std::list<Studentas>& studentaiList,std::list<Studentas>& nevykeliaiList);
void AnalizuotiDequeStrat2(std::deque<Studentas>& studentaiDeque,std::deque<Studentas>& nevykeliaiDeque);