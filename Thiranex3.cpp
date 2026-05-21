#include<iostream>
#include<vector>
using namespace std;
class Books{
    public:
    string title;
    int bookid;
    string author;
    string status;
    Books(string title,int bookid,string author)
    {
        this->title=title;
        this->bookid=bookid;
        this->author=author;
        status="available";
    }
};
class Members{
    public:
    string name;
    int id;
    vector<string> history;
    Members(string name,int id)
    {
        this->name=name;
        this->id=id;
    }
};
class info{
  private:
  vector<Books*>book;
  vector<Members*>member;
  public:
  void addbook()
  {
      cout<<"---Please Enter Book Details---"<<endl;
      string booktitle;
      int id;
      string authorname;
      cout<<"Enter Book Title: ";
      cin.ignore();
      getline(cin,booktitle);
      cout<<"Enter Book ID: ";
      cin>>id;
      cin.ignore();
      cout<<"Enter Author Name: ";
      getline(cin,authorname);
      for(Books *b:book)
      {
          if(b->bookid==id || b->title==booktitle)
          {
              cout<<"Book ID or Book already exist"<<endl;
              return;
          }
      }
      book.push_back(new Books(booktitle,id,authorname));
      cout<<"Book added successfully!"<<endl;
  }
  void addmem()
  {
      cout<<"---Please Enter Member Details---"<<endl;
      int memid;
      string memname;
      cout<<"Enter Member ID: ";
      cin>>memid;
      cin.ignore();
      cout<<"Enter Member Name: ";
      getline(cin,memname);
      for(Members *m:member)
      {
          if(m->id==memid || m->name==memname)
          {
              cout<<"Member ID or Member already exist"<<endl;
              return;
          }
      }
      member.push_back(new Members(memname,memid));
      cout<<"Member added successfully!"<<endl;
  }
  void search()
  {
    cout<<"1.Search By Title"<<endl;
    cout<<"2.Search By Author"<<endl;
    int choice;
    cout<<"Enter Your Choice: ";
    cin>>choice;
    if(choice==1)
    {
        bool found=false;
        string booktitle;
        cin.ignore();
        cout<<"Enter Book Title: ";
        getline(cin,booktitle);
        for(Books *b : book)
        {
            if(b->title==booktitle)
            {
                found=true;
                cout<<"Book Found"<<endl;
                cout<<"Book ID: "<<b->bookid<<endl;
                cout<<"Author: "<<b->author<<endl;
                cout<<"Status: "<<b->status<<endl;
                int op;
                cout<<"If you want to issue enter 1 or enter 0: ";
                cin>>op;
                if(op==1)
                {
                    if(b->status=="not_available")
                    {
                        cout<<"Book already issued"<<endl;
                        return;
                    }
                    bool memberfound=false;
                    int memid;
                    cout<<"Enter Member ID: ";
                    cin>>memid;
                    for(Members *m : member)
                    {
                        if(m->id==memid)
                        {
                            memberfound=true;
                            m->history.push_back(b->title);
                            b->status="not_available";
                            cout<<"Book issued successfully!"<<endl;
                            return;
                        }
                    }

                    if(!memberfound)
                    {
                        cout<<"Member does not exist"<<endl;
                        return;
                    }
                }
                else
                {
                    return;
                }
            }
        }
        if(!found)
        {
            cout<<"Book Not Found"<<endl;
        }
    }
    else if(choice==2)
    {
        bool found=false;
        string authorname;
        cin.ignore();
        cout<<"Enter Author Name: ";
        getline(cin,authorname);
        for(Books *b : book)
        {
            if(b->author==authorname)
            {
                found=true;
                cout<<"Book ID: "<<b->bookid<<endl;
                cout<<"Book Title: "<<b->title<<endl;
                cout<<"Status: "<<b->status<<endl<<endl;
            }
        }
        if(!found)
        {
            cout<<"No books found for this author"<<endl;
            return;
        }
        int id;
        cout<<"If you want to issue enter Book ID or enter 0: ";
        cin>>id;
        if(id==0)
        {
            return;
        }
        bool bookfound=false;
        for(Books *b : book)
        {
            if(b->bookid==id)
            {
                bookfound=true;
                if(b->status=="not_available")
                {
                    cout<<"Book already issued"<<endl;
                    return;
                }
                bool memberfound=false;
                int memid;
                cout<<"Enter Member ID: ";
                cin>>memid;
                for(Members *m : member)
                {
                    if(m->id==memid)
                    {
                        memberfound=true;
                        m->history.push_back(b->title);
                        b->status="not_available";
                        cout<<"Book issued successfully!"<<endl;
                        return;
                    }
                }
                if(!memberfound)
                {
                    cout<<"Member does not exist"<<endl;
                    return;
                }
            }
        }
        if(!bookfound)
        {
            cout<<"Book Not Found"<<endl;
        }
    }
    else
    {
        cout<<"Invalid choice"<<endl;
    }
  }
     void issue()
    {
    cin.ignore();
    string booktitle;
    cout<<"Enter Book Title: ";
    getline(cin,booktitle);
    string authorname;
    cout<<"Enter Author Name: ";
    getline(cin,authorname);
    int memid;
    cout<<"Enter Member ID: ";
    cin>>memid;
    bool found=false;
    for(Books *b : book)
    {
        if(b->title==booktitle && b->author==authorname)
        {
            found=true;
            if(b->status=="not_available")
            {
                cout<<"Book not available"<<endl;
                return;
            }
            bool memberfound=false;
            for(Members *m : member)
            {
                if(m->id==memid)
                {
                    memberfound=true;
                    m->history.push_back(booktitle);
                    b->status="not_available";
                    cout<<"Book issued successfully!"<<endl;
                    return;
                }
            }

            if(!memberfound)
            {
                cout<<"Member does not exist"<<endl;
                return;
            }
        }
    }

    if(!found)
    {
        cout<<"Book Not Found"<<endl;
    }
    }
    void retnbook()
    {
        int memid;
        cout<<"Enter Member id: ";
        cin>>memid;
        bool f=false;
        string booktitle;
        cout<<"Enter Book Title: ";
        cin.ignore();
        getline(cin,booktitle);
        for(Members *m: member)
        {
            if(m->id==memid)
            {
                f=true;
                bool issued=false;
                 for(int i=0;i<m->history.size();i++)
                {
                    if(m->history[i]==booktitle)
                    {
                        issued=true;
                        m->history.erase(m->history.begin()+i);
                        break;
                    }
                }
                if(!issued)
                  {
                    cout<<"This member did not issue this book"<<endl;
                    return;
                  }
            }
        }
        if(!f)
        {
            cout<<"Member not exist"<<endl;
            return;
        }
        bool found=false;
        for(Books *b: book)
        {
            if(b->title==booktitle)
            {
                found=true;
                b->status="available";
                cout<<"Book returned successfully!"<<endl;
                return;
            }
        }
        if(!found)
        {
            cout<<"Book not exist"<<endl;
            return;
        }
    }
    void history()
    {
        int memid;
        bool found=false;
        cout<<"Enter Member ID: ";
        cin>>memid;
        for(Members *m:member)
        {
            if(m->id==memid)
            {
                found=true;
                cout<<"Member ID: "<<m->id<<endl;
                cout<<"Member Name: "<<m->name<<endl;
                if(m->history.empty())
                  {
                     cout<<"No books issued"<<endl;
                  }
                else
                {
                cout<<"Books issued"<<endl;
                for(int i=0;i<m->history.size();i++)
                {
                    cout<<"->"<<m->history[i]<<endl;
                }
                }
            }
        }
        if(!found)
        {
            cout<<"Member not found"<<endl;
            return;
        }
    }
};
int main()
{
    info s;
    cout<<"========LIBRARY MANAGEMENT SYSTEM========"<<endl;
    while(1)
    {
        cout<<"1.Add Book Record"<<endl;
        cout<<"2.Add Member Record"<<endl;
        cout<<"3.Issue Book"<<endl;
        cout<<"4.Return Book"<<endl;
        cout<<"5.Search Book"<<endl;
        cout<<"6.history"<<endl;
        cout<<"7.Exit"<<endl;
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                s.addbook();
                break;
            }
            case 2:
            {
                s.addmem();
                break;
            }
            case 3:
            {
                s.issue();
                break;
            }
            case 4:
            {
                s.retnbook();
                break;
            }
            case 5:
            {
                s.search();
                break;
            }
            case 6:
            {
                s.history();
                break;
            }
            case 7:
            {
                cout<<"----Exiting---"<<endl;
                cout<<"---Thank You---"<<endl;
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