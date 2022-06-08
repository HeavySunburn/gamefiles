#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>

#include "combat.hpp"
#include "saver.hpp"
#include "loader.hpp"
#include "professions.hpp"
#include "list.hpp"
#include <random>
using namespace std;



int pointadder(int *avpoints,string *stats,int *statnums){
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

main() {
statsave ss1;
statload sl1;
characterload cc1;
combat_menu cm1;
mage m1;
berserker b1;
warrior w1;
thief t1;

std::string charnam;
string monstn;
std::string stats[5] = {"strength","dexterity","endurance","intelligence","charisma"};
std::string names[3] = {"lvl","xp","profession"};
string itemname[4] ={"healsack","poison","smoke-bomb","magic-powder"};
string itemdesc[4] ={"+20HP","+50Damage","+100%dodge","+50Magic-damage"};
int itemcount[4] ={0,0,0,0};
int statnums[5] = {0,0,0,0,0};
int mstatnum[5] = {0,0,0,0,0};
int xp = 0;
int lvl = 1;
int monstlvl = 1;
int prof = 0;
int outloop = 1;
int charloop = 1;
string result;
int record  = 0;
TsingleList sl;
lst_el * p;


while(outloop == 1){
std::cout<<"\nMenu loaded, please select action:\n";
std::cout<<"1.Load character\n";
std::cout<<"2.Load monster\n";
std::cout<<"3.Create character\n";
std::cout<<"4.Add profession to loaded character\n";
std::cout<<"5.Generate 5 random monsters\n";
std::cout<<"6.Display current loaded hero stats\n";
std::cout<<"7.Display current loaded monster stats\n";
std::cout<<"8.Combat sim between the loaded monsters\n";
std::cout<<"9.Combat history log\n";

int num;
std::cin >> num;
if (num == 1)
    {
        std::cout<<"Please type character name: ";
        statnums[prof-1] = statnums[prof-1] - 2;
        std::cin >> charnam;
        cc1.characterload_param(charnam);
        cc1.charload_display();
        sl1.statload_param(charnam);
        sl1.statloader();
        lvl = sl1.lvl;
        xp =  sl1.xp;
        prof = sl1.prof;
        if (prof == 1)
            {
                b1.bersekering(cc1);
            }
        else if (prof == 2)
            {
                t1.thiefing(cc1);
            }
        else if (prof == 3)
            {
                w1.warrioring(cc1);
            }
        else if (prof == 4)
            {
                m1.maging(cc1);
            };
        for (int i = 0; i < 5; i++)
            {
            stats[i] = cc1.stats[i];
            statnums[i] = cc1.statnums[i];
        }
        for (int i = 0; i < 4; i++)
            {
            itemname[i] = sl1.itemname[i];
            itemdesc[i] = sl1.itemdesc[i];
            itemcount[i] = sl1.intemcount[i];
            }

    }
else if (num == 2){
        std::cout<<"Please type monster name: ";
        std::cin >> monstn;
        monsterload ml1(monstn);
        for (int i = 0; i < 5; i++)
            {
            stats[i] = ml1.stats[i];
            mstatnum[i] = ml1.statnums[i];
            }
        std::cout <<"\n";
    }
else if (num == 3){
        std::string stats[5] = {"strength","dexterity","endurance","intelligence","charisma"};
        int statnums[5] = {0,0,0,0,0};
        int avpoints = 30;
        int avpoint;
        while(charloop == 1){
        int pointsel;
        int pointcount;
        std::cout<<"Available points: "<<avpoints<<"\n\n";
        for (int i = 0; i < 5; i++)
            {
            std::cout<<stats[i]<<" "<<statnums[i]<<"\n";
            }
        std::cout<<"\nWhat points do you want to edit?";
        std::cout<<"\nPress 7, to finish editing\n";
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
                charloop = 0;
                /*outloop = 0;*/
                std::cout<<"Please type character name: ";
                std::cin >> charnam;
                saver* s1 = new charactersave(stats,statnums,charnam);
                s1->charsave_display();
                ss1.statsave_param(names,lvl,xp,prof,charnam,itemname,itemdesc,itemcount);
                ss1.statsaver();
                   }
            break;
            }
            };
}
else if (num == 4){
        string classes[4] = {"Berserker","thief","warrior","mage"};
        std::string stats[5] = {"strength","dexterity","endurance","intelligence","charisma"};
        std::cout <<"Available classes: \n";
        for (int i = 0; i < 4; i++)
            {
            std::cout << classes[i] <<", adds +2 "<<stats[i]<<" points \n";
            }
        std::cout <<"\n";
        std::cout <<"Which do you want to pick?\n";
        int classloop = 0;
        int classsel;
        std::cin >> classsel;
        while(classloop == 0){
            switch(classsel){
            case 1:
                b1.bersekering(cc1);
                prof = 1;
                classloop = 1;
            break;
            case 2:
                t1.thiefing(cc1);
                prof = 2;
                classloop = 1;
            break;
            case 3:
                w1.warrioring(cc1);
                prof = 3;
                classloop = 1;
            break;
            case 4:
                m1.maging(cc1);
                prof = 4;
                classloop = 1;
            break;
            default:
                std::cout <<"It's between 1 and 4\n";
                classloop = 1;
            break;
                            }
                            };
        ss1.statsave_param(names,lvl,xp,prof,charnam,itemname,itemdesc,itemcount);
        ss1.statsaver();
        std::cout <<"\n";
}
else if (num == 1234){
    statnums[prof-1] = statnums[prof-1] - 2;
    std::cout <<"Pools closed due to Aids\n";
    saver* s1 = new charactersave(stats,statnums,charnam);
    s1->charsave_display();
    ss1.statsave_param(names,lvl,xp,prof,charnam,itemname,itemdesc,itemcount);
    ss1.statsaver();
    outloop = 0;
}
else if (num == 5)
    {
    string monstname[5] = {"Cyclops","Centaur","Sphinx","Skeleton","Wraith"};

    for (int i =0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
             mstatnum[j] = rand() % 10 + 1;
            }
            saver* s1 = new charactersave(stats,mstatnum,monstname[i]);
            s1->charsave_display();

        }

    for (int i =0; i < 5; i++)
        {
        monsterload ml1(monstname[i]);
        std::cout <<"\nThe name of the monster is: "<<monstname[i]<<"\n";
        for (int j = 0; j < 5; j++)
            {
             stats[j] = ml1.stats[j];
             mstatnum[j] = ml1.statnums[j];
             std::cout <<stats[j]<<" "<<mstatnum[j]<<"\n";
            }
        }
}
else if (num == 6){
    for (int i = 0; i < 5; i++)
        {
        stats[i] = cc1.stats[i];
        statnums[i] = cc1.statnums[i];
        std::cout << stats[i] <<" "<<statnums[i]<<"\n";
        }
    std::cout <<"\n";
}
else if (num == 7){
    for (int i = 0; i < 5; i++)
        {
        /*stats[i] = ml1.stats[i];
        mstatnum[i] = ml1.statnums[i];*/
        std::cout << stats[i] <<" "<<mstatnum[i]<<"\n";
        }
    std::cout <<"\n";
}
else if (num == 8){
        cm1.combat_loader(stats,statnums,lvl,xp,mstatnum,monstlvl,itemname,itemdesc,itemcount);
        cm1.combat_menu_func();
        cm1.combat();
            for (int i = 0; i < 5; i++)
                {
                    statnums[i] = cm1.statnums[i];
                }
                for (int i = 0; i < 4; i++)
        {
        itemname[i] = cm1.itemname[i];
        itemdesc[i] = cm1.itemdesc[i];
        itemcount[i] = cm1.intemcount[i];
        }
        /*int xp2 = cm1.xp2;*/
        xp = cm1.xp;
        /*int xp3 = xp + xp2;*/
        lvl = cm1.lvl;
        if (cm1.result == 0)
    {
        result = "defeat";
    }
        else result = "victory";
        cout<<"\nBattle outcome is: "<<result<<"\n";
        record = record + 1;
        /*statnums[prof-1] = statnums[prof-1] - 2;*/
        saver* s1 = new charactersave(stats,statnums,charnam);
        s1->charsave_display();
        ss1.statsave_param(names,lvl,xp,prof,charnam,itemname,itemdesc,itemcount);
        ss1.statsaver();
        p = new lst_el;
        p->key = record;
        p->name = result;
        sl.push_tail(p);
            if (record >= 11)
                {
                /*record = 0;
                while(sl.size()) sl.rmHead();
                cout << "Empty list: "; sl.showElements();
                cout << endl << endl;*/
                sl.rmHead();
                }
}
else if (num == 9){
    cout << "Now there should be "<< sl.size() <<" elements in the list: "; sl.showElements(); cout << endl;
    cout << "Program also displays single fields of the elements\n";
    cout << "Keys: "; sl.showKeys(); cout << endl;
    cout << "Names: "; sl.showNames(); cout << endl;
}
else std::cout<<"\nIt's a choice between 1 and 9!\nTry again,without being stupid.\n\n";
}
return 0;
}


