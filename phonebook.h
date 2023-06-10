#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

namespace contact
{
    class phonebook
    {
        //Create the arrays for name and phone number
        char name[20],phoneNumber[11];

        


        public:
        void getData();
        void showdata();
        char * getName(){ return name;}
        char * getPhoneNumber(){return phoneNumber;}
        void update (char *newName, char *newPhonenumber)
         {
           strcpy(name, newName);
           strcpy(phoneNumber, newPhonenumber);
        }
        void newRecord();
        void display();
        //void display(char *name);
        //void searchName();
        //void updatePhoneNumber();
        //void deleteContact();
};

void phoneBook :: getData()
{
cout << "\n Enter Name: ";
       cin >> name;
       repeat:
       cout <<"Enter phone number: ";
       cin >> phoneNumber;


}

void phoneBook :: newRecord()
{
 bool found=false;
 char recordName[11];
 char recordPhoneNumber[20];

 getData();
 strcpy(recordName, name);
 strcpy(recordPhoneNumber, phoneNumber);

 //Add to file
 fstream file;

 file.open("phone.txt",ios::n | ios:: app | ios::binary);

 while file.read((char *)this, sizeof(*this))
 {
    if(strcmp(recordName, getPhoneNumber())==0)
    {
        found=true;
        break;
    }
 }
 
file.clear();
 //Close file
file.close();

 if (found ==true)
 {
    cout <<"\n This contact already exist \n";

 }
else
{
    file.open("phone.txt",ios::n | ios:: app | ios::binary);
    update(recordName,recordPhoneNumber);
    file.write((char *) this, sizeof(*this));
    cout<<"Record Added Succesfully\n";
    file.close();

}
}