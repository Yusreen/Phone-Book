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
        void showData();
        char * getName(){ return name;}
        char * getPhoneNumber(){return phoneNumber;}
        void update (char *newName, char *newPhonenumber)
         {
           strcpy(name, newName);
           strcpy(phoneNumber, newPhonenumber);
        }
        void newRecord();
        void display();
        void display(char *name);
        //void searchName();
        //void deleteContact();
};

void phonebook :: getData()
{
cout << "\n Enter Name: ";
       cin >> name;
       repeat:
       cout <<"Enter phone number: ";
       cin >> phoneNumber;


}
void phonebook :: showData()
{
    cout<<"\n";
    cout<<setw(20)<<name;
    cout<<setw(15)<<phoneNumber;
   
}

void phonebook :: newRecord()
{
 bool found=false;
 char recordName[11];
 char recordPhoneNumber[20];

 getData();
 strcpy(recordName, name);
 strcpy(recordPhoneNumber, phoneNumber);

 //Add to file
 fstream file;

 file.open("phone.txt",ios::in | ios:: app | ios::binary);

 while (file.read((char *)this, sizeof(*this)))
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
    file.open("phone.txt", ios:: app | ios::binary);
    update(recordName,recordPhoneNumber);
    file.write((char *) this, sizeof(*this));
    cout<<"Record Added Succesfully\n";
    file.close();

}
}//  end of newRecord

void phonebook::display()
{
   fstream file;
   file.open("phone.txt",ios::ate | ios::in | ios::out | ios::binary);
   file.seekg(0,ios:: beg);
   cout <<"The records are : \n";

   while(file)
   {
    file.read((char*)this, sizeof(*this));
    if(!file.eof())
       showData();
   }
   file.clear();
   file.close();
}

void phonebook :: display(char *name)
{
    char c;
    char number[11];
     bool found=false;

     fstream file;
     file.open("phone.txt",ios::ate | ios::in | ios::out | ios::binary);
     file.seekg(0,ios:: beg);

      while(file.read((char *) this, sizeof(*this)))
     {
         if(strcmp(name,getName())==0)            
        {
            found=true;
            showData();
        } 
     }
     file.clear();
     if(found ==false)
     {
        cout<<"\n\n---Record Not found---\n";
     }
     file.close();
}
}