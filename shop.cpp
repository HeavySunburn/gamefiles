#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>
#include <random>
#include "random.hpp"
using namespace std;

class shopclass{
public:
string itemname[4];
string itemdesc[4];
int intemcount[4];
int pricerange[4];
int stock[4];
int cashpool;
// Stock should be randomly generated outside, then sent here, so that cheesing doesnt happen
void shop_param(string in[4],string idesc[4],int itc[4],int pri[4],int csh)
    {
        for (int i = 0; i < 4; i++)
            {
                itemname[i]=in[i];
                itemdesc[i]=idesc[i];
                intemcount[i]=itc[i];
                pricerange[i]=pri[i];
                stock[i]=Rand(1,5);

            }
        cashpool = csh;
    }
~shopclass(){};
void shop();
void choicer(int choice);
};

void shopclass::choicer(int choice){
    cout<<"You selected "<<itemname[choice-1]<<",please select count\n";
    int coun;
    cin>>coun;
    if (stock[choice-1] >= coun && pricerange[choice-1] <= cashpool)
        {
            stock[choice-1] =  stock[choice-1] - coun;
            intemcount[choice-1] = intemcount[choice-1] + coun;
            cashpool = cashpool - coun*pricerange[choice-1];
        }
    else cout<<"Invalid amount or cash count\n";
};

void shopclass::shop(){
bool loop = true;

cout<<"You have entered the shop, here you can buy items.\n";
while(loop == true){
    cout<<"\nYour balance is "<<cashpool<<".\n";
    cout<<"\n\tCurrent items for sale: \n";
    for (int i = 0; i < 4; i++)
            {
                cout<<"\n"<<i+1<<"."<<itemname[i]<<" ("<<itemdesc[i]<<") count: "<<stock[i]<<" cost: "<<pricerange[i];
            }
    cout<<"\n\nWhat would you like to purchase?\n";
    cout<<"Press 5 to finish\n";
    int choice;
    cin>>choice;
        switch (choice) {
            case 1: {
                choicer(choice);
            };
            break;
            case 2: {
                choicer(choice);
            };
            break;
            case 3: {
                choicer(choice);
            };
            break;
            case 4: {
                choicer(choice);
            };
            break;
            case 5: {
            cout<<endl;
            loop = false;
            }
            break;
        };
    };
};

int main(){
shopclass sh1;
int cashpool = 100;
int pricerange[4] = {10,20,60,30};
string itemname[4] = {"potion-of-healing","poison","smoke-bomb","magic-powder"};
string itemdesc[4] = {"+20HP","+50Damage","+100%dodge","+50Magic"};
int intemcount[4] = {1,2,3,4};
sh1.shop_param(itemname,itemdesc,intemcount,pricerange,cashpool);
sh1.shop();
    for (int i = 0; i < 4; i++)
        {
           intemcount[i]=sh1.intemcount[i];
           cout<<intemcount[i]<<" ";
        }

return 0;
}
