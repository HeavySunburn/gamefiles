#ifndef combat_hpp
#define combat_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <random>
#include <time.h>
#include "list.hpp"
#include "dlist.hpp"
#include "random.hpp"
using namespace std;


/*std::mt19937 generator (time(NULL));
int Rand(int l, int h)
{
    std::uniform_real_distribution<double> dis(l, h);

    return dis(generator);
}*/


class combat_menu{
public:
int lvl;
int monstlvl;
int xp;
string stats[5];
int statnums[5];
int monstatnums[5];
int combats;
int turn;
int dodging = Rand(0, 1);
int result;
string itemname[4];
string itemdesc[4];
int intemcount[4];
~combat_menu(){};
void combat_loader(string st[5],int sta[5],int lv,int x,int mst[5],int mlv,string in[4],string idesc[4],int itc[4]){
lvl  = lv;
monstlvl = mlv;
for (int i = 0; i < 5; i++)
    {
    monstatnums[i] = mst[i];
    stats[i] = st[i];
    statnums[i]  = sta[i];
    }
for (int i = 0; i < 4; i++)
    {
        itemname[i]=in[i];
        itemdesc[i]=idesc[i];
        intemcount[i]=itc[i];
    }
xp = x;
}
int Hp;
int MHp;
int bonusd = 0;
int Xpneed;
int xp2;
void combat_menu_func();
void combat();
void attack();
void magicattack();
void dodge();
void inventory();
void lvlup();
void lootdrop();
};

void combat_menu::combat_menu_func(){
    Hp = 100 + (10*lvl) + statnums[2];
    MHp = 100 + (10*monstlvl) + monstatnums[2];
    int Xpneed = 100 + (lvl*5);
    cout<<"Total Hp: "<<Hp<<"\n";
    cout<<"Total Monster Hp: "<<MHp<<"\n";
    cout<<"Current Xp: "<<xp<<"\n";
    cout<<"Total Xp needed to level up: "<<Xpneed<<"\n\n";
    cout<<"Player and Monster stats:\n\n";
    for(int i=0;i < 5;i++)
        {
            cout<<stats[i]<<" "<<statnums[i]<<"\t"<<stats[i]<<" "<<monstatnums[i]<<"\n";
        };
    };

void combat_menu::lvlup(){
cout<<"\nCongratz, you leveled up!\n";
lvl = lvl + 1;
cout<<"You HP has increased and a random stat has been increased by 1\n";
int j = Rand(1, 5);
statnums[j] = statnums[j] + 1;
cout<<"Your new stats are: lvl:"<<lvl<<" Total Hp: "<<Hp<<"\n";
for(int i=0;i < 5;i++)
        {
            cout<<stats[i]<<" "<<statnums[i]<<"\n";
        };
}

void combat_menu::attack(){
    int attack;
    if (dodging == 0)
        {
        if (turn == 1)

            {
                attack = 50+(10*statnums[0])+ bonusd;
                MHp = MHp - attack;
                cout<<"You hit for "<<attack<<"damage\n";
                cout<<"Monster Hp left:"<<MHp<<"\n";
                bonusd = 0;
            }
        else
            {
                attack = 50+(10*monstatnums[0]);
                Hp = Hp - attack;
                cout<<"Monster hit for "<<attack<<"damage\n";
                cout<<"Player Hp left:"<<Hp<<"\n";
            }
        }
    else if (dodging == 1)
    {
        if (turn == 1)
        {
         dodging = 0;
         cout<<"Monster dodged your attack\n";
        }
        else
        {
         dodging = 0;
         cout<<"You dodged the attack\n";
        }
    }

    if (Hp <= 0)
        {
        combats = 0;
        xp2 = 10 +monstlvl*5;
        Xpneed = Xpneed + xp2;
        cout<<"Removed xp:"<<xp2;
        xp = xp - xp2;
        result = 0;
        }
    else if (MHp <= 0)
        {
        combats = 0;
        xp2 = 10 +monstlvl*5;
        Xpneed = Xpneed - xp;
        result = 1;
        xp = xp + xp2;
        cout<<"Added xp:"<<xp2;
        cout<<"current Xp: "<<xp<<"\n";
        lootdrop();
        if (xp >= Xpneed)
            {
            lvlup();
            xp2 = 0;
            xp = 0;
            }
        }

};

void combat_menu::magicattack(){
   int magicattack;
   if (dodging == 0)
        {
        if (turn == 1)
            {
                magicattack = 50+(10*statnums[3])+bonusd;
                MHp = MHp - magicattack;
                cout<<"You cast for "<<magicattack<<"damage\n";
                cout<<"Monster Hp left:"<<MHp<<"\n";
                bonusd = 0;
            }
        else
            {
                magicattack = 50+(10*monstatnums[3]);
                Hp = Hp - magicattack;
                cout<<"Monster cast for "<<magicattack<<"damage\n";
                cout<<"Player Hp left:"<<Hp<<"\n";
            }
        }
         else if (dodging == 1)
        {
            if (turn == 1)
            {
            dodging = 0;
             cout<<"Monster dodged your spell\n";
            }
            else
            {
            dodging = 0;
             cout<<"You dodged the spell\n";
            }
        }


    if (Hp <= 0)
        {
        combats = 0;
        result = 0;
        xp2 = 10 +monstlvl*5;
        Xpneed = Xpneed + xp2;
        cout<<"Removed xp:"<<xp2;
        xp = xp - xp2;
        }
    else if (MHp <= 0)
        {
        combats = 0;
        xp2 = 10 +monstlvl*5;
        Xpneed = Xpneed - xp2;
        result = 1;
        xp = xp + xp2;
        cout<<"Added xp:"<<xp2;
        cout<<"current Xp: "<<xp<<"\n";
        lootdrop();
        if (xp >= Xpneed)
            {
            lvlup();
            xp2 = 0;
            xp = 0;
            }
        }
};

void combat_menu::dodge(){
int dodgechance;
if (turn == 1)
    {
    dodgechance = 50+(10*statnums[1]);
    }
else if (turn == 0)
    {
    dodgechance = 50+(10*monstatnums[1]);
    }

cout<<"dodge chance is "<<dodgechance<<"%\n";
int dodger = Rand(1, 100);
if (dodger > dodgechance)
    {
        dodging = 0;
        cout<<"dodge unsuccessfull\n";
    }
else
    {
    dodging = 1;
    cout<<"dodge successfull\n";
    }
};

void combat_menu::inventory(){
int choice, element, position;
string desc;
int use;
double_llist dl;
cout<<"You check your pouch, to find the following items:"<<endl;
    for (int i = 0; i < 4; i++)
        {
            dl.create_list(itemname[i],intemcount[i],itemdesc[i]);
        };
        dl.display_dlist();
cout<<"What do you want to use?"<<endl;
cin>>use;
switch(use){
case 1:
    if(intemcount[0] > 0){
        cout<<"You used the healing sack contents to gain an additional 20Hp!"<<endl;
        Hp = Hp + 20;
        intemcount[0] = intemcount[0] - 1;
        dl.add_after(intemcount[0],itemname[0],1,itemdesc[0]);
        dl.deletenode(1);
    }
    else cout<<"You ran out\n"<<endl;
break;
case 2:
    if(intemcount[1] > 0){
        cout<<"You used the poison on your weapon to gain an additional 50 damage!"<<endl;
        bonusd = 50;
        intemcount[1] = intemcount[1] - 1;
        dl.add_after(intemcount[1],itemname[1],2,itemdesc[1]);
        dl.deletenode(2);
     }
    else cout<<"You ran out\n"<<endl;
break;
case 3:
    if(intemcount[2] > 0){
        cout<<"You used the smoke-bomb to try and dodge!"<<endl;
        dodging = 1;
        intemcount[2] = intemcount[2] - 1;
        dl.add_after(intemcount[2],itemname[2],3,itemdesc[2]);
        dl.deletenode(3);
    }
    else cout<<"You ran out\n"<<endl;
break;
case 4:
    if(intemcount[3] > 0){
    cout<<"You used the magic powder (cocaine) to gain an additional 50 damage!"<<endl;
    bonusd = 50;
    intemcount[3] = intemcount[3] - 1;
    dl.add_after(intemcount[3],itemname[3],4,itemdesc[3]);
    dl.deletenode(4);
    }
    else cout<<"You ran out\n"<<endl;
break;


}


};

void combat_menu::combat(){
    int combat_loop = 1;
    combats = 1;
    turn = 1;
    int action;
    MHp = 100 + (10*lvl) + monstatnums[2];
    Hp = 100 + (10*lvl) + statnums[2];
    Xpneed = 100 + (lvl*5);
    string actions[4]={"attack","magic attack","dodge","use inventory item"};
    while (combats == 1){
    if (turn == 1){
    cout<<"\nYour move,creep: \n";
    for (int i = 0; i < 4; i++)
    {
        cout<<actions[i]<<"\n";
    }
    cin>>action;
    while(combat_loop == 1){
                 switch(action){
                    case 1:{
                            attack();
                            turn = 0;
                            combat_loop = 0;

                            }
                    break;
                    case 2:{
                            magicattack();
                            turn = 0;
                            combat_loop = 0;

                            }
                    break;
                    case 3:{
                            dodge();
                            turn = 0;
                            combat_loop = 0;
                            }
                    break;
                    case 4:{
                            inventory();
                            turn = 0;
                            combat_loop = 0;
                            }
                            };

        };
    }
    else{
            int monsteraction = Rand(1, 3);
                if (monsteraction == 1)
                    {
                    attack();
                    turn = 1;
                    combat_loop = 1;

                    }
                else if (monsteraction == 2)
                    {
                    magicattack();
                    turn = 1;
                    combat_loop = 1;

                    }
                else
                    {
                    cout<<"Monster has attempted to dodge\n";
                    dodge();
                    turn = 1;
                    combat_loop = 1;

                    }
    }
        };
    };

void combat_menu::lootdrop(){

int loot = Rand(1,5);
switch(loot){
case 1:{
   cout<<"After looting the corpse you obtained: "<<itemname[0]<<endl;
   intemcount[0] = intemcount[0] + 1;
}
break;
case 2:{
   cout<<"After looting the corpse you obtained: "<<itemname[1]<<endl;
   intemcount[1] =  intemcount[1] + 1;
}
break;
case 3:{
   cout<<"After looting the corpse you obtained: "<<itemname[2]<<endl;
   intemcount[2] =  intemcount[2] + 1;
}
break;
case 4:{
   cout<<"After looting the corpse you obtained: "<<itemname[2]<<endl;
   intemcount[3] =  intemcount[3] + 1;
}
break;
case 5:{
    cout<<"You got lucky and found a full stash next to the monsters corpse"<<endl;
    for (int i = 0; i < 4; i++){
        intemcount[i] = intemcount[i] + 1;
    }
}
};
};


#endif
