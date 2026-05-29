#include<iostream>
#include<vector>
using namespace std;
void display(vector<vector<char>>&choice)
{
    for(int i=0;i<3;i++)
    {
        cout<<" ";
        for(int j=0;j<3;j++)
        {
            cout<<" "<<choice[i][j]<<" ";
            if(j<2)
            {
                cout<<"|";
            }
        }
        cout<<endl;
        if(i<2)
        {
            cout<<"---|---|---"<<endl;
        }
    }
}
bool win(vector<vector<char>>&choice)
{
    if(choice[0][0]==choice[0][1] && choice[0][1]==choice[0][2])return true;
    if(choice[1][0]==choice[1][1] && choice[1][1]==choice[1][2])return true;
    if(choice[2][0]==choice[2][1] && choice[2][1]==choice[2][2])return true;
    if(choice[0][0]==choice[1][0] && choice[1][0]==choice[2][0])return true;
    if(choice[0][1]==choice[1][1] && choice[1][1]==choice[2][1])return true;
    if(choice[0][2]==choice[1][2] && choice[1][2]==choice[2][2])return true;
    if(choice[0][0]==choice[1][1] && choice[1][1]==choice[2][2])return true;
    if(choice[0][2]==choice[1][1] && choice[1][1]==choice[2][0])return true;
    return false;
    
}
bool draw(vector<vector<char>>&choice)
{
    int count=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(choice[i][j]=='X' || choice[i][j]=='O')
            {
                count++;
            }
        }
    }
    return (count==9);
}
bool check(char option,vector<vector<char>>&choice)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(choice[i][j]==option)
            {
                return true;
            }
        }
    }
    return false;
}
void fill(char option,vector<vector<char>>&choice,char currentplayer)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(choice[i][j]==option)
            {
                choice[i][j]=currentplayer;
                return;
            }
        }
    }
}
int main()
{
    vector<vector<char>>choice={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char currentplayer='X';
    while(true)
    {
    display(choice);
    char option;
    cout<<"Player "<<currentplayer<<" Enter position:";
    cin>>option;
    if(option<'1' || option>'9')
    {
        cout<<"Invalid choice"<<endl;
        continue;
    }
    if(check(option,choice))
    {
      fill(option,choice,currentplayer);
    }
    else
    {
        cout<<"Position already occupied"<<endl;
        continue;
    }
    if(win(choice))
    {
        cout<<currentplayer<<" won the match"<<endl;
        display(choice);
        return 0;
    }
    else if(draw(choice))
    {
        cout<<"Match draw"<<endl;
        display(choice);
        return 0;
    }
    if(currentplayer=='X')
    {
        currentplayer='O';
    }
    else
    {
        currentplayer='X';
    }
    
    }
}