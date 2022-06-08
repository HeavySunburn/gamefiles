#ifndef loader_hpp
#define loader_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <random>
#include <time.h>
using namespace std;


class characterload{
std::string charactername;
public:
void characterload_param(std::string characternam)
    {
    charactername = characternam;
    }
std::string stats[5];
int statnums[5];
~characterload(){};
void charload_display();
};

void characterload::charload_display(){
std::fstream file;
std::string txt = ".txt";
std::string filename = charactername+txt;
file.open( filename.c_str(), std::ios::in | std::ios::out );
if( file.good() == true )
    {
        std::cout << "Load successful\n" << std::endl;
        for (int i = 0; i < 5; i++)
        {
        (file >> stats[i]>> statnums[i]);
        std::cout << statnums[i] <<" "<<stats[i]<<"\n";
        }
    }
else std::cout << "Load unsuccessful\n" << std::endl;
file.close();
};

class monsterload: public characterload{
public:
monsterload(string monstname){
characterload_param(monstname);
charload_display();
}
};

class statload{
public:
string statloadn;
string statnames[3];
string itemname[4];
string itemdesc[4];
int intemcount[4];
int lvl;
int xp;
int prof;
void statload_param(std::string c)
    {
    statloadn = c;
    }
~statload(){};
void statloader(){
std::fstream file;
std::string txt = "stats.txt";
std::string filename = statloadn+txt;
file.open( filename.c_str(), std::ios::in | std::ios::out );
if( file.good() == true )
    {
        std::cout << "Load successful\n" << std::endl;
        (file >> statnames[0]>>lvl);
        (file >> statnames[1]>>xp);
        (file >> statnames[2]>>prof);
        for (int i = 0; i < 4; i++)
        {
        (file >> itemname[i]>> itemdesc[i]>> intemcount[i]);
        std::cout << itemname[i] <<" "<<itemdesc[i]<<" "<<intemcount[i]<<"\n";
        }
        std::cout << statnames[0] <<" "<<lvl<<"\n";
        std::cout << statnames[1] <<" "<<xp<<"\n";
        std::cout << statnames[2] <<" "<<prof<<"\n";
    }
else std::cout << "Load unsuccessful\n" << std::endl;
file.close();
};
};

#endif
