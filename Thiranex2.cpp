#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
class info
{
    public:
    bool checkacc(string acc,int password)
    {
        bool found=false;
        ifstream check("Information.txt");
        string line;
        vector<string> data(4);

       while(getline(check,line))
        {
           string tempstr="";
           int i=0;
           for(char c : line)
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
            if(acc==data[0] && data[2]==to_string(password))
            { 
             found=true;
            }
        }
           check.close();
           return found;
    }
       void add(string acc,string name,int password,int amount)
       {
           ifstream check("Information.txt");
           string line;
           vector<string> data(4);
           while(getline(check,line))
           {
             string tempstr="";
             int i=0;
             for(char c : line)
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
            if(acc==data[0])
            { 
             cout<<"Account number already exists"<<endl;
             check.close();
             return;
            }
        }
           check.close();
           ofstream information("Information.txt",ios::app);
           information<<acc<<","<<name<<","<<password<<","<<amount<<endl;
           information.close();
           cout<<"-----Thank you for trusting our digital banking service-----"<<endl;
       }
       void withdraw(string acc,int password,int with)
       {
            if(with<=0)
            {
              cout<<"Invalid withdrawal amount"<<endl;
              return;
            }
           int money=0;
           int i=0;
           ifstream infor("Information.txt");
          if(!infor)
          {
            cout<<"File could not be opened"<<endl;
            return;
          }
           ofstream temp("temp.txt");
           bool found=false;
           vector<string>data(4);
           string line;
           while(getline(infor,line))
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
               if(acc==data[0] && password==stoi(data[2]) && stoi(data[3])>=with)
               {
                   found=true;
                   int amt=stoi(data[3])-with;
                   data[3]=to_string(amt);
               }
               else if(acc==data[0] && password==stoi(data[2]) && stoi(data[3])<with)
               {
                   while(1)
                   {
                    if(stoi(data[3])<with) 
                    {
                      cout<<"Low Balance please enter a valid amount: ";
                      cin>>money;
                      if(money<=0)
                      {
                          cout<<"Invalid amount"<<endl;
                          continue;
                      }
                        with=money;
                    }
                    else if(stoi(data[3])>=with)
                    {
                       found=true;
                       int amt=stoi(data[3])-with;
                       data[3]=to_string(amt);
                       with=money;
                       break;
                    }
                   }
                   
               }
                temp<<data[0]<<","<<data[1]<<","<<data[2]<<","<<data[3]<<endl;                   
           }
           infor.close();
           temp.close();
           remove("Information.txt");
           rename("temp.txt","Information.txt");
           if(found)
           {
               cout<<"Amount withdrawn successfully!"<<endl;
           }
           else
           {
               cout<<"Account number or password is wrong....please try again"<<endl;
           }
       }
       void deposit(string acc,int password,int dept)
       {
                 if(dept<=0)
                 {
                  cout<<"Invalid amount"<<endl;
                  return;
                 }
           int i=0;
           ifstream infor("Information.txt");
           if(!infor){
              cout<<"File could not be opened"<<endl;
              return;
            }
           ofstream temp("temp.txt");
           bool found=false;
           vector<string>data(4);
           string line;
           while(getline(infor,line))
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
               if(acc==data[0] && password==stoi(data[2]))
               {
                   found=true;
                   int amt=stoi(data[3])+dept;
                   data[3]=to_string(amt);
               }
                temp<<data[0]<<","<<data[1]<<","<<data[2]<<","<<data[3]<<endl;                   
           }
           infor.close();
           temp.close();
           remove("Information.txt");
           rename("temp.txt","Information.txt");
           if(found)
           {
               cout<<"Amount deposited successfully!"<<endl;
           }
           else
           {
               cout<<"Account number or password is wrong....please try again"<<endl;
           }
       }
       void balance(string acc,int password)
       {
           int i=0;
           ifstream infor("Information.txt");
           if(!infor){
              cout<<"File could not be opened"<<endl;
              return;
            }
           bool found=false;
           vector<string>data(4);
           string line;
           while(getline(infor,line))
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
               if(acc==data[0] && password==stoi(data[2]))
               {
                   found=true;
                   cout<<"Account Number: "<<data[0]<<endl;
                   cout<<"User Name: "<<data[1]<<endl;
                   cout<<"Account Balance: "<<data[3]<<endl;
               }
           }
           infor.close();
           if(!found)
           {
               cout<<"Account number or password is wrong....please try again"<<endl;
           }
       }
};
int main()
{
    cout<<"===========WELCOME TO NET BANKING==========="<<endl;
    info s;
    while(true)
    {
        cout<<"If You are a New_User enter option 1"<<endl;
        cout<<"If You are an Old_User enter option 2"<<endl;
        cout<<"To Cancel Request enter option 3"<<endl;
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                string acc;
                string name;
                int password;
                int check;
                cout<<"Enter Account Number: ";
                cin>>acc;
                cin.ignore();
                cout<<"Enter User Name: ";
                getline(cin,name);
                while(1)
                {
                cout<<"Enter Four Digit Pin: ";
                cin>>password;
                  if(password < 1000 || password > 9999)
                  {
                    cout<<"Please enter exactly 4 digits"<<endl;
                    continue;
                  }
                cout<<"Confirm your Pin: ";
                cin>>check;
                if(check!=password)
                   {
                    cout<<"Pin does not match.Try again"<<endl;
                   }
                else if(check==password)
                  {
                    break;
                  }
                }
                int amount;
                int f;
                cout<<"If want to deposit amount press 1 or if you don't want to deposit amount press 0: ";
                cin>>f;
                if(f==1)
                {
                   cout<<"Enter amount to be deposited: ";
                   cin>>amount;
                   if(amount<=0)
                   {
                     cout<<"Invalid deposit amount"<<endl;
                     break;
                    }
                   s.add(acc,name,password,amount);
                }
                else
                {
                    s.add(acc,name,password,0);
                }
                break;
            }
            case 2:
            {
              bool exit=false; 
              while(!exit){
               cout<<"1.Withdraw"<<endl;
               cout<<"2.Deposit"<<endl;
               cout<<"3.Check Balance"<<endl;
               cout<<"4.Exit"<<endl;
               int option;
               cout<<"Enter your request: ";
               cin>>option;
               switch(option)
               {
                   case 1:
                   {
                     string acc;
                     cout<<"Enter account number: ";
                     cin>>acc;
                     int password;
                     cout<<"Enter Pin: ";
                     cin>>password;
                     if(s.checkacc(acc,password))
                     {
                     int with;
                     cout<<"Enter amount to be withdrawn: ";
                     cin>>with;
                     s.withdraw(acc,password,with);
                     }
                     else
                     {
                         cout<<"Account number or Password is wrong"<<endl;
                     }
                     break;
                   }
                   case 2:
                   {
                        string acc;
                        cout<<"Enter account number: ";
                        cin>>acc;
                        int password;
                        cout<<"Enter Pin: ";
                        cin>>password;
                        if(s.checkacc(acc,password))
                        {
                          int dept;
                          cout<<"Enter amount to be deposited: ";
                          cin>>dept;
                          s.deposit(acc,password,dept);
                        }
                        else
                        {
                          cout<<"Account number or Password is wrong"<<endl;
                        }   
                        break;
                   }
                   case 3:
                   {
                       string acc;
                       cout<<"Enter Account Number: ";
                       cin>>acc;
                       int password;
                       cout<<"Enter Pin: ";
                       cin>>password;
                       if(s.checkacc(acc,password))
                        {
                          s.balance(acc,password);
                        }
                        else
                        {
                          cout<<"Account number or Password is wrong"<<endl;
                        }  
                       break;
                   }
                   case 4:
                   {
                       cout<<"---Exiting---"<<endl;
                       exit=true;
                       break;
                   }
                   default:
                   {
                       cout<<"Invalid choice"<<endl;
                   }
                   
               }
               }
               break;
            }
            case 3:
            {
                cout<<"===========Thank You==========="<<endl;
                return 0;
            }
            default:
            {
                cout<<"Invalid choice"<<endl;
                break;
                
            }
        }
    }
}