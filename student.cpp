#include <iostream>
#include <string.h>
#define SIZE 10
using namespace std;
class student{
           public: char name[10];
              char USN[10];
              char dept_name[4];
              char gender;
              float sgpa;
            public:void getdetails()
             {
                 cout<<"NAME:"<<endl;
                 cin>>name;
                 cout<<"USN:"<<endl;
                 cin>>USN;
                 cout<<"GENDER:"<<endl;
                 cin>>gender;
                 cout<<"DEPARTMENT"<<endl;
                 cin>>dept_name;
                 cout<<"SGPA:"<<endl;
                 cin>>sgpa;
             }
              void put_details()
             {
                 cout<<"NAME:"<<name<<"\t"<<"USN:"<<USN<<"\t"<<"GENDER:"<<gender<<"\t"<<"DEPARTMENT:"<<dept_name<<"SGPA:"<<sgpa<<endl;
             }
            int put_details(char dept[4])
             {
              if(strcmp(dept,dept_name)==0)
              {
                 cout<<"NAME:"<<name<<"\t"<<"USN:"<<USN<<"\t"<<"GENDER:"<<gender<<"\t"<<"DEPARTMENT:"<<dept_name<<"SGPA:"<<sgpa<<endl;
                 return 1;
              }
              else
                return 0;
             }
             };

             bool isawarded(student s)
             {
                 if(s.sgpa==10)
                    return true;
                 else
                    return false;
             }

int main()
{
    student s[SIZE];
    int i=0,j,k, n=0,ctr=0;
    int ch;
    char d[4];
    char choice1;
    do{
        cout<<"----------MENU----------"<<endl;
        cout<<"1:ENTER STUDENT DETAILS "<<" "<<"2:DISPLAY ALL STUDENT DETAILS "<<endl;
        cout<<"3:ENTER PARTICULAR DEPARTMENT TO DISPLAY THE DETAILS "<<"4.DISPLAY DETAILS OF STUDENTS TO BE AWARDED "<<"5:END"<<endl;
        cin>>ch;
        switch(ch)
        {
          case 1:
                 do{
                 s[i++].getdetails();
                 cout<<"DO YOU WANT TO ENTER DETAILS OF ANOTHER STUDENT(y/n)"<<endl;
                 cin>>choice1;
                 }while(choice1=='y'||choice1=='Y');
                 break;
          case 2:for(j=0;j<i;j++)
                    s[j].put_details();
                 break;
          case 3:cout<<"ENTER DEPARTMENT NAME"<<endl;
                 cin>>d;
                 for(j=0;j<i;j++)
                 {
                     k=s[j].put_details(d);
                     if(k==1)
                        ctr++;
                 }
                 if(ctr==0)
                 cout<<"NO STUDENT OF THIS DEPARTMENT\n";
                 break;

            case 4:cout<<"STUDENTS TO BE AWARDED ARE:\n";
                    for(j=0;j<i;j++)
                    {
                        if(isawarded(s[j]))
                        {
                             s[j].put_details();
                             ctr++;
                        }
                    }
                    if(ctr==0)
                    cout<<"NO STUDENTS ARE ELIGIBLE FOR GETTING AWARDED\n";
                    break;
            case 5:cout<<"END OF PROGRAM\n";
                    break;
           default:cout<<"PLEASE ENTER A VALID CHOICE"<<endl;
               break;
        }
        }while(ch!=5);
        return 0;
    }


