#ifndef dlist_hpp
#define dlist_hpp

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <string>
using namespace std;

struct node
{
    int info;
    string name;
    string descrip;
    struct node *next;
    struct node *prev;
}*start;
/*
Class Declaration
*/
class double_llist
{
public:
    void create_list(string name,int value,string descri);
    void add_begin(int value,string name,string descri);
    void add_after(int value,string name, int position,string descri);
    void delete_element(int value);
    void search_element(int value);
    void display_dlist();
    void count();
    void reverse();
    void deletenode(int nodenum);
double_llist()
{
start = NULL;
}
};


void double_llist::create_list(string name,int value,string descri)
{
struct node *s, *temp;
temp = new(struct node);
temp->descrip = descri;
temp->name = name;
temp->info = value;
temp->next = NULL;
if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
else
    {
        s = start;
        while (s->next != NULL)
        s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}
void double_llist::add_begin(int value,string name,string descri)
{
if (start == NULL)
    {
    cout<<"First Create the list."<<endl;
    return;
    }
struct node *temp;
temp = new(struct node);
temp->prev = NULL;
temp->descrip = descri;
temp->name = name;
temp->info = value;
temp->next = start;
start->prev = temp;
start = temp;
cout<<"Element Inserted"<<endl;
}
/*
Insertion of element at a particular position
*/
void double_llist::add_after(int value,string name, int pos,string descri)
{
    if (start == NULL)
    {
    cout<<"First Create the list."<<endl;
    return;
    }
struct node *tmp, *q;
int i;
q = start;
for (i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == NULL)
    {
cout<<"There are less than ";
cout<<pos<<" elements."<<endl;
return;
}
}
tmp = new(struct node);
tmp->descrip = descri;
tmp->name = name;
tmp->info = value;
    if (q->next == NULL)
        {
            q->next = tmp;
            tmp->next = NULL;
            tmp->prev = q;
        }
    else
        {
            tmp->next = q->next;
            tmp->next->prev = tmp;
            q->next = tmp;
            tmp->prev = q;
        }
cout<<"Element Inserted"<<endl;
}

/*
Deletion of element from the list
 */
void double_llist::delete_element(int value)
{
struct node *tmp, *q;
/*first element deletion*/
if (start->info == value)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        cout<<"Element Deleted"<<endl;
        free(tmp);
        return;
    }
q = start;
while (q->next->next != NULL)
    {
        /*Element deleted in between*/
        if (q->next->info == value)
    {
tmp = q->next;
q->next = tmp->next;
tmp->next->prev = q;
cout<<"Element Deleted"<<endl;
free(tmp);
return;
}
q = q->next;
}
/*last element deleted*/
    if (q->next->info == value)
        {
            tmp = q->next;
            free(tmp);
            q->next = NULL;
            cout<<"Element Deleted"<<endl;
            return;
        }
    cout<<"Element "<<value<<" not found"<<endl;
}

/*
* Display elements of Doubly Link List
*/
void double_llist::display_dlist()
{
        struct node *q;
        if (start == NULL)
    {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }
    q = start;
    cout<<"The Doubly Link List is :"<<endl;
    while (q != NULL)
        {
            cout<<q->name<<": "<<q->descrip<<" "<<q->info<<endl;
            q = q->next;
        }
//cout<<"NULL"<<endl;
}

/*
268 * Number of elements in Doubly Link List
269 */
void double_llist::count()
{
struct node *q = start;
int cnt = 0;
while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
cout<<"Number of elements are: "<<cnt<<endl;
}

/*
283 * Reverse Doubly Link List
284 */
void double_llist::reverse()
{
    struct node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    start = p1;
    cout<<"List Reversed"<<endl;
}

void double_llist::deletenode(int nodenum){
node *temp = new node();
node *temp1 = new node();
temp1 = start;
temp = start;
int cnt = 0;

while (temp1 != NULL)
    {
       temp1 = temp1->next;
       cnt++;
    }
if(nodenum == cnt){
   for(int i = 1; i < nodenum-1; i++)
        {
            temp = temp->next;
        }
    node* lastNode = temp->next;
    temp->next = NULL;
    free(lastNode);
}
else if(nodenum > cnt){
    cout<<"The number you selected is bigger than the list length"<<endl;
}
else if(nodenum == 1 && cnt > 0){
    start = temp->next;
    delete temp;
}
else if(nodenum < cnt){
    for(int i = 1; i < nodenum-1; i++)
        {
            temp = temp->next;
        }
    node *del = temp->next;
    temp->next = del->next;
    node *nextn = del->next;
    nextn->prev = temp;
    free(del);
}
};
#endif
/*int main()
{
int choice, element, position;
string name,desc;
double_llist dl;

dl.create_list("Cumsock",1,"used");
dl.create_list("Pinata",1,"broken");
dl.create_list("Fly swatter",2,"sticky");
dl.create_list("uhhhm",2,"ughhhh");
dl.create_list("something",3,"not useful");

while (1)
{
    cout<<endl<<"----------------------------"<<endl;
    cout<<endl<<"Operations on Doubly linked list"<<endl;
    cout<<endl<<"----------------------------"<<endl;
    cout<<"1.Create Node"<<endl;
    cout<<"2.Add at beginning"<<endl;
    cout<<"3.Add after position"<<endl;
    cout<<"4.Delete"<<endl;
    cout<<"5.Display"<<endl;
    cout<<"6.Count"<<endl;
    cout<<"7.Reverse"<<endl;
    cout<<"8.Quit"<<endl;
    cout<<"9.Delete specific node"<<endl;
    cout<<"10.Replace specific node with new contents"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
switch ( choice )
{
case 1:
    cout<<"Insert the new element count: ";
    cin>>element;
    cout<<"Enter the element name: ";
    cin>>name;
    cout<<"Enter the element description: ";
    cin>>desc;
    dl.create_list(name,element,desc);
    cout<<endl;
break;
case 2:
    cout<<"Insert the new element count: ";
    cin>>element;
    cout<<"Enter the element name: ";
    cin>>name;
    cout<<"Enter the element description: ";
    cin>>desc;
    dl.add_begin(element,name,desc);
    cout<<endl;
break;
case 3:
    cout<<"Insert Element after position: ";
    cin>>position;
    cout<<"Insert the new element count: ";
    cin>>element;
    cout<<"Insert Element name: ";
    cin>>name;
    cout<<"Enter the element description: ";
    cin>>desc;
    dl.add_after(element,name,position,desc);
    cout<<endl;
break;
case 4:
    if (start == NULL)
    {
    cout<<"List empty,nothing to delete"<<endl;
break;
}
    cout<<"Enter the element for deletion: ";
    cin>>element;
    dl.delete_element(element);
    cout<<endl;
break;
case 5:
    dl.display_dlist();
    cout<<endl;
break;
case 6:
    dl.count();
break;
case 7:
    if (start == NULL)
    {
    cout<<"List empty,nothing to reverse"<<endl;
break;
}
    dl.reverse();
    cout<<endl;
break;
case 8:
    exit(1);
break;
case 9:
    cout<<"Insert Node number for deletion: ";
    cin>>position;
    dl.deletenode(position);
    cout<<endl;
break;
case 10:
    cout<<"Insert element position which you want to replace: ";
    cin>>position;
    cout<<"Insert the new element count: ";
    cin>>element;
    cout<<"Insert Element name: ";
    cin>>name;
    cout<<"Enter the element description: ";
    cin>>desc;
    dl.add_after(element,name,position,desc);
    dl.deletenode(position);
break;
default:
    cout<<"Wrong choice"<<endl;
}
}
return 0;
}*/









