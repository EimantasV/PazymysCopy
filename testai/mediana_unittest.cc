#include "../googletest/googletest/include/gtest/gtest.h"
#include "../Funkcijos.cpp"
#include <vector>

namespace {
    TEST(ProgramosTestai,Mediana)
    {
        std::vector<double> aibe {1,1,3,5,9,9};
        EXPECT_EQ(4.0, GautiMediana(aibe));
    }
}