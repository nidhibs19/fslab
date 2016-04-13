#include<iostream>
#include<string>
using namespace std;
class Student{
string name;
string usn;
string branch;
string sem;
public:
Student(string iname,string iusn,string ibranch,int isem)
{
name=iname;
usn=iusn;
branch=ibranch;
sem=isem;
}
string pack()
{
string buffer;
ofstream myf(filename.c_str(),ios::app);
buffer= usn+"|"+name+"|"+sem+"|"+branch+"|";
buffer.resize(100,'$');
myf<<buffer<<endl;
myf.close();
}
bool match(string key,string val)
{
if(key==name)
return name==val;
if(key==usn)
return usn==val;
if(key==branch)
return branch==val;
if(key==sem)
return sem==val;
}
}
void Student :: unpack(string s)
{
stringstream ss;
ss<<s;
getline(ss,name,'|');
getline(ss,usn,'|');
getline(ss,branch,'|');
getline(ss,sem,'|');
}
class Node{
node *next;
int offset;
public:
friend class list;
Node(int ioffset)
{
offset=ioffset;
}
}
class List{
node *head;
public:
List()
{head=NULL;}
void insert(int offset)
{
node *temp=new node(offset);
temp->next=head;
head=temp;
}
void get()
{
int offset=head->offset;
if(head!=NULL){
offset=head->offset;
temp=head;
head=head->next;
delete temp;
return offset;
}
else return -1;
}
}
class FLR{
string fname;
List L;
public:
FLR(string ifname)
{
fname=ifname;
}
void writerec(string s)
{
int offset;
offset=L.get();
ofstream of(fname,ios::app);

