#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<unistd.h>
#include<sstream>
#include<string>
using namespace std;
class student{
	string name;
	string usn;
	string branch;
	string sem;
public:
student(string iname,string iusn,string ibranch,string isem)
    {
    	name=iname;
    	usn=iusn;
    	branch=ibranch;
    	sem=isem;
    }
string pack(int n)
    {
    	string s;
    	s=name+"|"+usn+"|"+branch+"|"+sem;
    	s.resize(n,'$');
    	return s;
    }
bool match(string key,string value)
{
    	if(key=="name")
    	return name==value;
    	else if(key=="usn")
    	return usn==value;
    	else if(key=="branch")
    	return branch==value;
    	else if(key=="sem")
    	return sem==value;
}
};
student unpack(string s)
{
    	stringstream ss;
    	ss<<s;
    	string name,usn,branch,sem;
    	getline(ss,name,'|');
   	getline(ss,usn,'|');
   	getline(ss,branch,'|');
    	getline(ss,sem,'|');
    	return student(name,usn,branch,sem);
}
class node
{
    	node *next;
    	int offset;
	public:
    	friend class list;
    	node(int ioffset)
	{
    	offset=ioffset;
	}	
};
class list{
   	node *head;
	public:
	list()
	{
	head=NULL;
	}
	int insert(int offset)
	{
		node *temp=new node(offset);
    		temp->next=head;
    		head=temp;
	}
int get()
{
    	int offset;
    	if(head!=NULL)
    	{
    	offset=head->offset;
    	node *temp=head;
    	head=head->next;
    	delete temp;
    	return offset;
    	}
    	else
    	return -1;
	}	
};
class FLRfile
{
	string fname;
	list L;
	int n;
	public:
	FLRfile(string ifname,int in)
	{
	fname=ifname;
	n=in;
	}

	void writerecord(string s)
	{
	 	int offset=L.get();
    		if(offset>=0)
    		{
    		ofstream of(fname.c_str(),ios::in|ios::out);
    		of.seekp(offset,ios::beg);
    	    	of.write(s.c_str(),n);
    		of.close();
    		}
      		else {
        	ofstream of(fname.c_str(),ios::out|ios::app);
        	of.write(s.c_str(),n);
    		of.close();
    		}
	}	

void deleterecord(string key,string value)
{
    	char buff[n+2];
    	buff[n]='$';
    	buff[n+1] = '\0';
    	fstream of1(fname.c_str(),ios::in|ios::out);
    	int offset;
    	while(!of1.eof())
    	{
    	int offset=of1.tellg();
    	of1.read(buff,n);
    	student s = unpack(buff);
    	if(s.match(key,value))
    	{
    	of1.seekp(offset);
    	L.insert(offset);
    	of1.write("\n",1);
    	break;
    	}
	}
	of1.close();
}
};

int main()
{
	student s1("nidhi","054","ise","6");
	student s2("nikhil","056","ise","6");
	student s3("manju","045","ise","6");
	FLRfile f("out2.txt",50);
	f.writerecord(s1.pack(50));
	f.writerecord(s2.pack(50));
	f.writerecord(s3.pack(50));
	f.writerecord(s3.pack(50));
	f.deleterecord("name","nidhi");
	return 0;
}
