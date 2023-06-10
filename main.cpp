#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include "phonebook.h"

using namespace std;
using namespace contact;
int main()
{
  phonebook rec;
  int choice;

    while(1)
    {
        char nm[20];
        cout<<"\n*****Yusreen's Phone Book *****\n";
        cout<<"1) Add New Record\n";
        cout<<"2) Display all the Records\n";
        cout <<"3) Search a contact by name \n";
        cout<<"4) Exit\n";

      
        cin>>choice;
        switch(choice)
        {
            case 1 : rec.newRecord();
                 break;

            case 2: rec.display();
                  break;

            case 3:
            cout <<"\n Enter the name: ";
            cin >> nm;
            rec.display(nm);
            break;

            case 4:
            exit(1);

             default:
             cout<<"Invalid Option!"<<endl;
        }
    }
}