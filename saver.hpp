#ifndef saver_hpp
#define saver_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <random>
#include <time.h>
using namespace std;


class saver{
    public:
        std::string stats[5];
        int statnums[5];
        std::string charname;
        virtual ~saver(){};
        virtual void charsave_display()=0;
};

class charactersave: public saver{
public:
    charactersave(std::string s[5],int st[5],std::string ch)
    {
        for (int i = 0; i < 5; i++)
        {
        stats[i] = s[i];
        statnums[i] = st[i];
        charname = ch;
        }
    }
    ~charactersave(){};
void charsave_display()
{
    std::fstream file;
    std::string txt = ".txt";
    std::string filename = charname+txt;
    ofstream (filename.c_str());
    file.open( filename.c_str(), ios::in | ios::out );
        if( file.good() == true )
            {
            std::cout << "Character saved succesfully\n" << endl;
            for (int i = 0; i < 5; i++)
            file << stats[i]<<" "<<statnums[i]<<"\n";
            }
        else std::cout << "Unable to save\n" << std::endl;
            file.close();
};
};

class statsave{
public:
string names[3];
int lvl;
int xp;
int prof;
string itemname[4];
string itemdesc[4];
int intemcount[4];
string statsname;
void statsave_param(string n[3],int lv,int x,int pro,string f,string in[4],string idesc[4],int itc[4])
    {
        for (int i = 0; i < 4; i++)
        {
            itemname[i]=in[i];
            itemdesc[i]=idesc[i];
            intemcount[i]=itc[i];
        }

        for (int i = 0; i < 3; i++)
        {
            names[i]=n[i];
        }

        lvl=lv;
        xp=x;
        prof=pro;
        statsname = f;
    }
~statsave(){};
void statsaver(){
std::fstream file;
std::string txt = "stats.txt";
std::string filename = statsname+txt;
ofstream (filename.c_str());
file.open( filename.c_str(), ios::in | ios::out );
if( file.good() == true )
    {
        std::cout << "stats saved succesfully\n" << endl;
        /*file << names[0]<<" "<<monstlvl<<"\n";*/
        file << names[0]<<" "<<lvl<<"\n";
        file << names[1]<<" "<<xp<<"\n";
        file << names[2]<<" "<<prof<<"\n";
        for (int i = 0; i < 4; i++)
            {
                file <<itemname[i]<<" "<<itemdesc[i]<<" "<<intemcount[i]<<endl;
            }
    }
else std::cout << "Unable to save\n" << std::endl;
file.close();
}
};

class monstersave: public saver{
public:
monstersave(string stats[5],string monstname,int statnum[5]){
charactersave(stats,statnum,monstname);
charsave_display();
}
};

#endif
