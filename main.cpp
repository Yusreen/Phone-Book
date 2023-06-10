#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include "phonebook.h"

using namespace std;
using namespace contact;
int main()
{
    phoneBook rec;
    int choice;

    while(1)
    {
        char nm[20];
        cout<<"\n*****Phone Book -Developed by CPPSECRETS *****\n";
        cout<<"1) Add New Record\n";
        cout<<"2) Display All Records\n";
        cout<<"3) Search Telephone No.\n";
        cout<<"4) Search Person Name\n";
        cout<<"5) Update Telephone No.\n";
        cout<<"6) Delete a record \n";
        cout<<"7) Exit\n";
        cout<<"Choose your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1 : rec.newrecord();
                 break;

            case 2 :  rec.display();
              break;

            case 3 :rec.searchpname();
                    break;
                    

            case 4 :
            cout<<"\n\nEnter Name : ";
            cin>>nm;
            rec.display(nm);
            break;

            case 5 :rec.updatetelno();
                 break;

           case 6:   rec.deleterec();
                    break;

           case 7:  exit(1);

           default:
                cout<<"Invalid Option!!"<<endl;

        }

    }


return 0;
}