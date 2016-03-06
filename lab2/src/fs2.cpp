#include<iostream>
#include <string>
#include<fstream>
using namespace std;
class Student {
    string usn;
    string  name;
    string branch;
    string sem;
public:
    void read();
    void pack(string filename);
    void search(string,string);
    void unpack(ifstream &);
    void unpack(string);
    void modify();
    };
    Student s;
    int main()
{
    int ch;
    //fstream f;
    Student s;
    string fname,key;
    while(1)
    {
    cout<<"1.insert 2.search 3.delete 4.modify\n";
    cout<<"enter your choice";
    cin>>ch;

         switch(ch)
        {
        case 1:
            s.read();
            cout<<"enter filename ";
            cin >> fname;
            s.pack(fname);
            break;
        case 2:
            cout<<"Enter the USN to be searched\n";
            cin>>key;
            cout<<"enter filename ";
            cin >> fname;
            s.search(key,fname);
            break;
        case 3:
            //s.modify;
            break;
        case 4:
            s.unpack(fname);
            break;

            }
        }
}
void Student::read(){
    cout<<"enter name"<<endl;
    cin>>name;
    cout<<"enter usn"<<endl;
    cin>>usn;
    cout<<"enter branch"<<endl;
    cin>>branch;
    cout<<"enter sem"<<endl;
    cin>>sem;
}
void Student::pack(string filename){
    string buffer;
    ofstream myf(filename.c_str(),ios::app);
    buffer= usn+"|"+name+"|"+sem+"|"+branch+"|";
    buffer.resize(100,'$');
    myf<<buffer<<endl;
    myf.close();

}
void Student::unpack(string filename)
{
    string temp;
    ifstream myf(filename.c_str());
    getline(myf,usn,'|');
    getline(myf,name,'|');
    getline(myf,branch,'|');
    getline(myf,sem,'$');
    getline(myf,temp);
    myf.close();
}
void Student::unpack(ifstream &myf)
{
    string temp;
    getline(myf,usn,'|');
    getline(myf,name,'|');
    getline(myf,branch,'|');
    getline(myf,sem,'$');
    getline(myf,temp);
}
void Student::search(string key,string fname)
{
    Student s[10];
    int i=0,count=0,ch;

    ifstream myf(fname.c_str());
    //cout<<myf;
    while(!myf.eof())
    {
    cout<<"In search\n";
    s[i].unpack(myf);
    if(key==s[i].usn)
    {
                cout<<"record found\n";
                cout<<s[i].usn<<"\t"<<s[i].name;
                break;
    }
    i++;
    }


    myf.close();
}
void Student::modify()
{
	string search_usn;
	string ch_name,ch_usn,ch_sem;
	int count;
	int search_flag=-1,modify_flag=-1,i=0,choice;
	cout<<"Enter the USN to be modified"<<endl;
	cin>>search_usn;
	fp.open("input.txt",ios::in);	
	while(fp)
	{
		s[i].unpack();
		i++;
	}
	fp.close();
	count=i;
	for(i=0;i<count;i++)
	{
		if(s[i].usn==search_usn)
		{
			search_flag=i;
			break;
		}
	}
	if(search_flag==-1)
	{
	cout<<"Record not found"<<endl;
	exit(1);
	}
	else
	{
		cout<<"Record found:"<<endl;
		s[search_flag].display();
	}
	cout<<"Do you wish to modify the record?"<<endl;
	cout<<"Press 1 to modify"<<endl<<"Press 0 to exit"<<endl;
	cin>>modify_flag;
	if(modify_flag)
	{
		cout<<"Enter the field to be changed"<<endl;
		cout<<"1.Name\n2.USN\n3.Semester"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: cout<<"Enter the Name"<<endl;
				cin>>ch_name;
				s[search_flag].name=ch_name;
				break;
			case 2:cout<<"Enter the USN"<<endl;
				cin>>ch_usn;
				s[search_flag].usn=ch_usn;
				break;
			case 3:cout<<"Enter the semester"<<endl;
				cin>>ch_usn;
				s[search_flag].sem=ch_sem;
				break;	
			default:cout<<"Wrong input"<<endl;	
		}
	}
	fp.open("input.txt",ios::out);
	s[search_flag].pack();
	fp.close();
	cout<<endl<<endl;
}
