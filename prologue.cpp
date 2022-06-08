#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>
#include <random>
#include "random.hpp"
#include <windows.h>
using namespace std;

#include "saver.hpp"




class prologue{
public:
std::string stats[5] = {"strength","dexterity","endurance","intelligence","charisma"};
int statnums[5] = {0,0,0,0,0};
string charname;
bool firstencounter;
bool paladinon;
bool ashwoodquest;

~prologue(){};
int pointadder(int *avpoints,string *stats,int *statnums);
void intro();
void prologuepart1();
void vendor();
void ashwood();
};

int prologue::pointadder(int *avpoints,string *stats,int *statnums){
std::cout<<"You've selected "<<*stats<<",select amount of points you want to add/remove:";
std::cout<<"\nPress 7, to finish editing\n";
int pointcount;
std::cin >> pointcount;
if (pointcount > *avpoints){
        std::cout<<"Improper amount\n";
        pointcount = 0;
                            }
else *statnums = pointcount;
*avpoints = *avpoints - pointcount;
return *avpoints;
}

void prologue::intro(){
    Sleep(1000);
    cout<<"You wake up in a dark cave,hollow whispers are scratching at the back of your mind. You can only make out a few words,none of which are pleasant.\n";
    Sleep(2000);
    cout<<"Before you begin succumbing to the voices you realize you have no idea who or where you are\n";
    Sleep(2000);
    cout<<"For a brief moment you recall your name\nIt's.....\n It is.....\n";
        cin>>charname;
    cout<<charname<<"!\n";
    cout<<"It is "<<charname<<"! You exhale with relief\n";
    cout<<"You barely pick yourself up from the ground and inspect yourself\n";
    Sleep(1000);
    cout<<"You are dressed in old,tattered armor.On your left wrist is a peculiar metal cuff with a large circular piece of glass in the middle.\n";
    Sleep(1000);
    cout<<"You rub it, trying to clear the dust of it, when suddenly, it lights up and inscriptions appear on it:\n";
    Sleep(1000);
    cout<<"Welcome, awakened, please proceed further\n";


        int avpoints = 30;
        int avpoint;
        bool charloop = true;
        while(charloop == true){
        int pointsel;
        int pointcount;
        std::cout<<"Available runes: "<<avpoints<<"\n\n";
        for (int i = 0; i < 5; i++)
            {
            std::cout<<stats[i]<<" "<<statnums[i]<<"\n";
            }
        std::cout<<"\nWhat runes do you want to manipulate?";
        std::cout<<"\nPress 7, to finish\n";
        std::cin >> pointsel;
            switch (pointsel){
                case 1:{
                    avpoints = pointadder(&avpoints,&stats[0],&statnums[0]);
                       }
                break;
                case 2:{
                    avpoints = pointadder(&avpoints,&stats[1],&statnums[1]);
                       }
                break;
                case 3:{
                    avpoints = pointadder(&avpoints,&stats[2],&statnums[2]);
                       }
                break;
                case 4:{
                    avpoints = pointadder(&avpoints,&stats[3],&statnums[3]);
                       }
                break;
                case 5:{
                    avpoints = pointadder(&avpoints,&stats[4],&statnums[4]);
                       }
                break;
                case 7:{
                    charloop = false;
                    std::string names[3] = {"lvl","xp","profession"};
                    string itemname[4] ={"healsack","poison","smoke-bomb","magic-powder"};
                    string itemdesc[4] ={"+20HP","+50Damage","+100%dodge","+50Magic-damage"};
                    int itemcount[4] ={0,0,0,0};
                    int lvl = 1;
                    int xp = 0;
                    int profession = 0;
                    charactersave s1;
                    s1.charactersave_param(stats,statnums,charname);
                    statsave ss1;
                    ss1.statsave_param(names,lvl,xp,profession,charname,itemname,itemdesc,itemcount);
                    ss1.statsaver();
                        }
                break;
                };

        };
    cout<<"You feel a sudden rush of energy hit you,giving you enough strength to move on,despite this new rush of power, you somehow know that it won't lead to good things.\n";
    cout<<"You stop looking at you bracelet, brush yourself off and head for the nearest cave exit\n";
    Sleep(1000);
    cout<<"On your way out, you pull out an old sword from some corpse and keep heading towards the light.\n\n";
    Sleep(3000);
    cout<<"As you make it out of the cave,the blinding sun hits you and for a moment you are stunned from it.\n";
    Sleep(3000);
    cout<<"When you open your eyes,however,the world in front of you is nothing like what you expected it to be:\n";
    Sleep(3000);
    cout<<"\nThe sky is a desolate mixture of brown,red and orange, with smoke and ash going all the way to horizon.\n";
    cout<<"The wildlife is mostly dried up and gone, aside from some bushes and patches of bleak-red grass";
    cout<<"In the distance you see a pack of wild beasts, akin to dogs, but barely having any muscle and skin, wondering around looking for prey.\n";
    Sleep(3000);
    cout<<"\nThis world is on the razors edge of death.\n";
};

void prologue::prologuepart1(){
    firstencounter = true;
    bool prologuepart1loop = true;
    cout<<"\nThe cave you have left was on top of a hill and you can vaguely make out 3 things to which you can go to:\n\n";
    while (prologuepart1loop == true){
    cout<<"Where do you want to go?\n";
    cout<<"1.A decrepit slanted hut with light coming from the inside.\n2.What appears to be a husk of some sort of large walking machine.\n";
    cout<<"3.An abandoned village.\n";
    cout<<"Which do you chose to go to?\n";
    int p1choice;
    cin>>p1choice;
    switch (p1choice){
        case 1:
        vendor();
        break;

    };
    };
}

void prologue::vendor(){
if (firstencounter == true)
    {
        cout<<"You reach the hut and are at the doorstep. Do you want to knock first? (Y/N)\n";
        string ynchoice;
        cin>>ynchoice;
            if (ynchoice == "y" || "yes")
                {
                    cout<<"You knock on the door 3 times and hear some noise coming from the inside\n";
                    Sleep(1000);
                    cout<<"A skinny pale man cautiously opens the door.\n";
                    cout<<"'Who are you and what do you want?', he asks firmly\n";
                    cout<<"\nWhat do you reply?\n";
                    cout<<"1.I'm "<<charname<<", who are you?\n";
                    cout<<"2.It doesn't matter who I am,prepare to die\n";
                    int diachoice;
                    cin>>diachoice;
                    switch (diachoice)
                        {
                        case 1:
                            cout<<"\nAlright,"<<charname<<"I'm Haldor,the last living person here,since you're not one of the scourged,we can talk\n";
                            cout<<"I can barter with you and fix your gear,but until I can trust you,that's all I will do.\n";
                            firstencounter = false;
                        break;
                        case 2:
                            cout<<"\nThe man quickly pulls out a dagger from behind his back and lunges forward\n";
                            /*combat menu goes here*/
                        break;
                       };
                }
                else
                {
                    cout<<"You kick in the door, only to find that the inhabitant was already charging at you\n";
                    /* combat menu goes here*/
                };

        }
    else
        {
            bool dialogueloop = true;
            cout<<"You reach the hut and meet with Haldor\n";
            while (dialogueloop == true)
            {
                cout<<"'What do you want this time?', he asks\n";
                cout<<"1.I want to trade.\n";
                cout<<"2.I need information.\n";
                cout<<"3.Nothing,just stopping by.\n";
                int diachoice;
                cin>>diachoice;
                    switch (diachoice)
                    {
                        case 1:
                        /*shop goes here*/
                        break;
                        case 2:
                                cout<<"'Information about what?'\n";
                                cout<<"The scourge\n";
                                cout<<"This area\n";
                                cout<<"Do you need any help with something\n";
                                cin>>diachoice;
                                    switch (diachoice){
                                        case 1:
                                            cout<<"The scourge is the sickness that devoured everything until the horizon, no one knows where it came from.\n";
                                            cout<<"Everyone who fought it has lost and there is nothing you can but survive here\n";
                                        break;
                                        case 2:
                                            cout<<"This area used to be called the Vinefields, because of the fruitvine farms that were here, now it's a wasteland\n";
                                            cout<<"The village nearby is Ashwood,the residents are scourged, so they will try to kill you on sight\n";
                                            cout<<"The machine nearby was a Paladin, one of the weapons the old ones used to fight the sickness with,as you can see, they lost\n";
                                        break;
                                        case 3:
                                            cout<<"Yes I do, I need the powerstone from Ashwood's refinery to provide heat and light for the winter,";
                                            cout<<"without it I don't know how long I will be able to hold to life here.\n";
                                            break;
                                                        };
                        break;
                        case 3:
                            dialogueloop = false;
                        break;
                    };
            };
        };
};

void prologue::ashwood(){












}


int main(){
prologue p1;
p1.intro();
p1.prologuepart1();
return 0;
};
