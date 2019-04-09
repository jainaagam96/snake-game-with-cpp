#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<windows.h>
void pos(int);
bool check();
int pr=2,pc=2,r1,c1,c,length=1;
int po[100],poo[100];
char a[28][40]={' '};
using namespace std;
int prev;
int score;
bool draw(int r,int c,int n)
{
    int i;
    cout<<"score is: "<<score<<endl;
    pos(n);
    if(check()==false)
    {
        system("cls");
        cout<<"game over..."<<endl;
        cout<<"score is: "<<score<<endl;
        return false;
    }
    a[r][c]='#';
    a[pr][pc]='O';
            for(i=length;i>1;i-=1)
            {
                a[po[i]][poo[i]]='o';
            }
    int j;
    for(i=0;i<41;i++)
        cout<<"-";
    cout<<endl;
    for(i=0;i<28;i++)
    {
        cout<<"|";
        for(j=0;j<40;j++)
        {
            cout<<a[i][j];
        }
        cout<<"|\n";
    }
    for(i=0;i<41;i++)
        cout<<"-";
        cout<<endl;
         for(i=length;i>1;i-=1)
            {
                a[po[i]][poo[i]]=' ';
            }
        if(r==pr&&c==pc)
        {
            length+=1;
            score+=1;
           a[r][c]=' ';
           srand(time(NULL));
            r1=rand()%(27);
            srand(time(NULL));
            c1=rand()%(39);
        }
        a[pr][pc]=' ';
        system("cls");
        return true;
}
void pos(int n)
{
   switch(n)
        {
        case 8:

            for(int i=length;i>1;i-=1)
            {
                po[i]=po[i-1];
                poo[i]=poo[i-1];
            }
               po[1]=pr;
                poo[1]=pc;
                if(prev==2&&length>1)
                {
                    pr++;
                    break;
                }
            pr--;
            prev=8;
            break;
        case 2:
           for(int i=length;i>1;i-=1)
            {
                po[i]=po[i-1];
                poo[i]=poo[i-1];
            }
               po[1]=pr;
                poo[1]=pc;
                if(prev==8&&length>1)
                {
                    pr--;
                    break;
                }
            pr++;
            prev=2;
            break;
        case 4:
             for(int i=length;i>1;i-=1)
             {
                po[i]=po[i-1];
                poo[i]=poo[i-1];
             }
               po[1]=pr;
                poo[1]=pc;
                if(prev==6&&length>1)
                {
                    pc++;
                    break;
                }
            pc--;
            prev=4;
            break;
        case 6:
            for(int i=length;i>1;i-=1)
            {
                po[i]=po[i-1];
                poo[i]=poo[i-1];
            }
               po[1]=pr;
                poo[1]=pc;
                  if(prev==4&&length>1)
                  {
                      pc--;
                    break;
                  }
            pc++;
            prev=6;
            break;
        default:
            if(prev==8)
            {
                for(int i=length;i>1;i-=1)
                {
                    po[i]=po[i-1];
                    poo[i]=poo[i-1];
                }
                po[1]=pr;
                poo[1]=pc;
                pr--;
                break;
            }
                if(prev==2)
                {
                    for(int i=length;i>1;i-=1)
                    {
                        po[i]=po[i-1];
                        poo[i]=poo[i-1];
                    }
                        po[1]=pr;
                        poo[1]=pc;
                        pr++;
                        break;
                }

                if(prev==4)
                {
                    for(int i=length;i>1;i-=1)
                    {
                        po[i]=po[i-1];
                        poo[i]=poo[i-1];
                    }
                    po[1]=pr;
                    poo[1]=pc;
                    pc--;
                    break;
                }

                if(prev==6||prev==0)
                {
                    for(int i=length;i>1;i-=1)
                    {
                        po[i]=po[i-1];
                        poo[i]=poo[i-1];
                    }
                        po[1]=pr;
                        poo[1]=pc;
                    pc++;
                    break;
                }
            break;
        }
}
bool check()
{
    for(int i=length;i>1;i-=1)
    {
       if(po[i]==pr && poo[i]==pc)
        return false;
    }
    if(pr>27||pr<0)
        return false;
    if(pc>39||pc<0)
        return false;
    return true;
}
int main()
{
    cout<<"instructions:   enter 8 for up,2 for down ,4for left and 6 for right\n";
    cout<<"Loding...\n";
    int r,c,x;
    srand(time(NULL));
    r=rand()%(27);
    srand(time(NULL));
    c=rand()%(39);
    r1=r;
    c1=c;
    Sleep(1000);
    while(1)
    {
        int n;
        if(_kbhit())
        {
            n=_getch();
            n=n-48;
            x=draw(r1,c1,n);
        }
        else
        {
            n=0;
            x=draw(r1,c1,n);
        }
        if(x==false)
            break;
    }
return 0;
}
