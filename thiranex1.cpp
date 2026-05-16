#include<iostream>
#include<fstream>
using namespace std;
class info
{
    public:
    void addstudent(int roll,string name,string dob,string fah,string mom)
    {
        ofstream infor("Information.txt",ios::app);
        infor<<roll<<","<<name<<","<<dob<<","<<fah<<","<<mom<<endl;
        infor.close();
        cout<<"Added sucessfully";
    }
    void Update(){
        ifstream file("Information.txt");
        ofstream temp("temp.txt");
        int sroll;
        cout<<"Enter student roll number: ";
        cin>>sroll;
        cin.ignore();
        string line;
        string data[5];
        bool found=false;
        while(getline(file,line))
        {
            string tempstr="";
            int i=0;
            for(char c:line)
            {
                if(c==',')
                {
                    data[i++]=tempstr;
                    tempstr="";
                }
                else
                {
                    tempstr+=c;
                }
            }
            data[i]=tempstr;
            if(stoi(data[0])==sroll)
            {
                found=true;
                cout<<"Enter student name: ";
                getline(cin,data[1]);
                cout<<"Enter Date of Birth: ";
                getline(cin,data[2]);
                cout<<"Enter student father name: ";
                getline(cin,data[3]);
                cout<<"Enter student mother name: ";
                getline(cin,data[4]);
            }
            temp<<data[0]<<","<<data[1]<<","<<data[2]<<","<<data[3]<<","<<data[4]<<endl;
        }
            file.close();
            temp.close();
            remove("Information.txt");
            rename("temp.txt","Information.txt");
            if(found)
            {
                cout<<"Updated successfully"<<endl;
            }
            else
            {
                cout<<"Roll number not found"<<endl;  
            }
    }
    void deleteinfo()
    {
        ifstream file("Information.txt");
        ofstream temp("temp.txt");
        int sroll;
        cout<<"Enter student roll number: ";
        cin>>sroll;
        cin.ignore();
        string line;
        string data[5];
        bool found=false;
        while(getline(file,line))
        {
            string tempstr="";
            int i=0;
            for(char c:line)
            {
                if(c==',')
                {
                    data[i++]=tempstr;
                    tempstr="";
                }
                else
                {
                    tempstr+=c;
                }
            }
            data[i]=tempstr;
            if(stoi(data[0])==sroll)
            {
                found=true;
                continue;
            }
            temp<<data[0]<<","<<data[1]<<","<<data[2]<<","<<data[3]<<","<<data[4]<<endl;
        }
            file.close();
            temp.close();
            remove("Information.txt");
            rename("temp.txt","Information.txt");
            if(found)
            {
                cout<<"deleted successfully"<<endl;
            }
            else
            {
                cout<<"Roll number not found"<<endl;  
            }
    }
    void display()
    {
        ifstream file("Information.txt");
        string line;
        string data[5];
        cout<<"----Students' Detail List----"<<endl;
        while(getline(file,line))
        {
            string tempstr="";
            int i=0;
            for(char c:line)
            {
                if(c==',')
                {
                    data[i++]=tempstr;
                    tempstr="";
                }
                else
                {
                    tempstr+=c;
                }
            }
            data[i]=tempstr;
            cout<<"Roll Number: "<<data[0]<<endl
            <<"Name: "<<data[1]<<endl
            <<"Date of Birth: "<<data[2]<<endl
            <<"Father Name: "<<data[3]<<endl
            <<"Mother Name: "<<data[4]<<endl;
        }
            file.close();
    }
};
int main()
{
    info s;
    while(1)
    {
        cout<<"1.Add Student Information"<<endl<<"2.Update Student Information"<<endl<<"3.delete Information"<<endl<<"4.display student information"<<endl<<"5.Exit"<<endl;
        int choice;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int roll;
                string name;
                string dob;
                string fah;
                string mom;
                cout<<"Enter student roll number: ";
                cin>>roll;
                cin.ignore();
                cout<<"Enter student name: ";
                getline(cin,name);
                cout<<"Enter Date of Birth: ";
                getline(cin,dob);
                cout<<"Enter student father name: ";
                getline(cin,fah);
                cout<<"Enter student mother name: ";
                getline(cin,mom);
                s.addstudent(roll,name,dob,fah,mom);
                break;
            }
            case 2:
            {
                s.Update();
                break;
            }
            case 3:
            {
                s.deleteinfo();
                break;
            }
            case 4:
            {
               s.display();
                break;
            }
            case 5:
            {
                cout<<endl<<"----Exiting----"<<endl;
                return 0;
            }
            default:
            {
                cout<<"Invalid choice"<<endl;
            }
        }
        
    }
}