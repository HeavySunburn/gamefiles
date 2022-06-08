#ifndef list_hpp
#define list_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>
#include <random>
using namespace std;

//Element declaration
struct lst_el{
    lst_el * next;
    int key;
    string name;

};
//definition of sinly listed list class
class TsingleList{
    lst_el * head, * tail;
    int cnt;
public:
    TsingleList()
    {
    head = tail = NULL;
    cnt = 0;
    }

~TsingleList(){
    lst_el * el;
while(head)
    {
    el = head->next;
    delete head;
    head = el;
    }
            }
//Method returning list size
unsigned size(){
return cnt;
}

//Method adding an element at the front of the list
lst_el * push_head(lst_el * el){
el->next = head;
head = el;
if(!tail) tail = head;
cnt++;
return head;
}
//Method adding an element at the end of the list
lst_el * push_tail(lst_el * el){
if(tail) tail->next = el;
el->next = NULL;
tail = el;
if(!head) head = tail;
cnt++;
 return tail;
}
//Method adding an element (el1) after an element (el2)
lst_el * insert(lst_el * el1, lst_el * el2){
el1->next = el2->next;
el2->next = el1;
if(!(el1->next)) tail = el1;
cnt++;
return el1;
}
//Method deleting the first element of the list
lst_el * rmHead(){
lst_el * el;
if(head){
el = head;
head = head->next;
if(!head) tail = NULL;
cnt--;
return el;
}
else return NULL;
}
//Method deleting the last element of the list
lst_el * rmTail(){
lst_el * el;
if(tail){
el = tail;
if(el == head) head = tail = NULL;
else{
tail = head;
while(tail->next != el) tail = tail->next;
tail->next = NULL;
}
cnt--;
return el;
}
else return NULL;
}
//Method deleting the el element of the list
lst_el * erase(lst_el * el){
lst_el * el1;

if(el == head) return rmHead();
else{el1 = head;
while(el1->next != el) el1 = el1->next;
el1->next = el->next;
if(!(el1->next)) tail = el1;
cnt--;
return el;
}
}

//Method returns nth element of the list
lst_el * index(int n){
lst_el * el;

if((!n) || (n > cnt)) return NULL;
else if(n == cnt) return tail;
else{
el = head;
while(--n) el = el->next;
return el;
 }
 }
//Methods used to display data stored in the list
void showKeys(){
lst_el * el;
if(!head) cout << "List is empty." << endl;
else{
el = head;
while(el){
cout << el->key << " ";
el = el->next;
}
cout << endl;
}
}
void showNames(){
lst_el * el;
if(!head) cout << "List is empty." << endl;
else{
el = head;
while(el){
cout << el->name << " ";
el = el->next;
}
cout << endl;
}
}
void showElements(){
lst_el * el;
if(!head) cout << "List is empty." << endl;
else{
el = head;
while(el){
cout << "Name: " << el->name << ", key: " << el->key <<";";
el = el->next;
}
cout << endl;
}
}
};

#endif




