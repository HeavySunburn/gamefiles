#ifndef random_cpp
#define random_cpp

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>
using namespace std;





std::mt19937 generator (time(NULL));
int Rand(int l, int h)
{
    std::uniform_real_distribution<double> dis(l, h);

    return dis(generator);
}



#endif
