#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
using namespace std;


class screen
{
public:

    void welcome_screen();
    void login_screen();

};


class details
{
public:

    void room_details();
    void food_details();
    void about_us();

};


class tourist: public details
{
protected:
    int room_num;
    int staying_day;
    int number_of_person;
    string name;
    string address;
    string phone;

public:

    void home_page();
    void add_customer();
    void search_customer();
    void display_customer();
    void edit_customer();
    int check(int);
    void modify_customer(int);
    void delete_customer(int);

};

class generate_bill: public tourist
{
public:

    generate_bill();

};


void screen::welcome_screen()
{
    printf(" _______________________________________________________________________________________________________________\n");
    printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    printf("                          |      |  |----- |       +----+  +-----+  |\\    /|  |-----                        \n");
    printf("                          |      |  |      |       |    +  |     |  | \\  / |  |                             \n");
    printf("                          |  /\\  |  |----  |       |       |     |  |  \\/  |  |----                         \n");
    printf("                          | /  \\ |  |      |       |       |     |  |      |  |                             \n");
    printf("                          |/    \\|  |----- |-----  +-----  +-----+  |      |  |-----                        \n");
    printf(" +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf(" _______________________________________________________________________________________________________________\n\n");
    printf(" *****************************************||>> ROYAL BLUE HOTEL <<||********************************************\n");
    printf(" ===============================================================================================================\n\n");

    cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....";
    getch();
}


void screen::login_screen()
{
    system("cls");
    char username[20];
    char password[20];
    char user[20]="pranto";
    char pass[20]="******";

    printf(" _______________________________________________________________________________________________________________\n\n");
    printf(" *********************************||>> HOTEL MANAGEMENT SYSTEM APPLICATION <<||*********************************\n");
    printf(" ===============================================================================================================\n\n");
    printf("\n            ******************************  LOGIN FIRST  *********************************  ");
    again:
    printf("\n\n                 ENTER USERNAME: ");
    gets(username);
    printf("\n                 ENTER PASSWORD: ");
    gets(password);

    if(strcmp(username, "pranto")==0 && strcmp(password, "******")==0)
    {
        printf("\n\n\n\t\t\tWELCOME TO OUR BOOKING SYSTEM!!! LOGIN IS SUCCESSFUL!!!");
        printf("\n\n\n\t\t\t\t  Press any key to continue...");
    }
    else
    {
        printf("\n\n\t\t SORRY!!! LOGIN IS UNSUCESSFUL!!!\n");
        goto again;
    }
    getch();
}


void tourist::home_page()
{
    int choice;
    while(choice!=8)
    {
        system("cls");
        cout<<"\n\t\t\t\t*************************";
        cout<<"\n\t\t\t\t    *** HOME PAGE ***";
        cout<<"\n\t\t\t\t*************************";
        cout<<"\n\n\n\t\t\t1.Add Customer";
        cout<<"\n\t\t\t2.Search Customer Records";
        cout<<"\n\t\t\t3.Update Customer Records";
        cout<<"\n\t\t\t4.Room Details";
        cout<<"\n\t\t\t5.Food Details";
        cout<<"\n\t\t\t6.Calculate Bill";
        cout<<"\n\t\t\t7.About Us";
        cout<<"\n\t\t\t8.Exit";
        cout<<"\n\n\t\t\tEnter Your Choice: ";
        cin>>choice;

        switch(choice)
        {

        case 1:
            add_customer();
            break;

        case 2:
            search_customer();
            break;

        case 3:
            edit_customer();
            break;

        case 4:
            room_details();
            break;

        case 5:
            food_details();
            break;

        case 6:
            generate_bill();
            break;

        case 7:
            about_us();
            break;

        case 8:
            break;

        default:
            cout<<"\n\n\t\t\tWrong Choice!!!";
            cout<<"\n\t\t\tPress any key to continue...";
            getch();
        }
    }
}


void tourist::add_customer()
{
    system("cls");
    int r, f;
    ofstream fout("Record.txt",ios::app);

    cout<<"\nEnter Customer Detalis";
    cout<<"\n----------------------";
    cout<<"\nTotal Number of Rooms: 150";
    cout<<"\nRegular Suite Rooms (1 - 50)    PRICE-> 3000TK (Per Night}";
    cout<<"\nLuxury Suite Rooms (51 - 100)    PRICE-> 5000TK (Per Night}";
    cout<<"\nRoyal Suite Rooms (101 - 150)    PRICE-> 8000TK (Per Night}";
    cout <<"\n\nEnter The Room Number for Booking: ";
    cin>>r;

    f=check(r);

    if(f)
        cout<<"\nSorry!!! Room is already Booked!!! Please Try Another Room.";
    else
    {
        room_num=r;
        cout<<"Name: ";
        cin>>name;
        cout<<"Address: ";
        cin>>address;
        cout<<"Phone No: ";
        cin>>phone;

        fout.write((char*)this,sizeof(tourist));
        cout<<"\nCongrats!!! Room is Booked!!!";
    }

    cout<<"\nPress any key to continue...";
    getch();
    fout.close();
}


int tourist::check(int r)
{
    int f=0;

    ifstream fin("Record.txt",ios::in);

    while(!fin.eof())
    {
        fin.read((char*)this, sizeof(tourist));
        if(room_num==r)
        {
            f=1;
            break;
        }
    }

    fin.close();
    return(f);
}


void tourist::search_customer()
{
    system("cls");

    ifstream fin("Record.txt",ios::in);
    int r, f=0;

    cout<<"\nEnter Room Number for a particular Customer's details : ";
    cin>>r;

    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(tourist));
        if(room_num==r)
        {
            system("cls");
            cout<<"\nCustomer Details";
            cout<<"\n================";
            cout<<"\n\nRoom no: "<<room_num;
            cout<<"\nName: "<<name;
            cout<<"\nAddress: "<<address;
            cout<<"\nPhone no: "<<phone;
            f=1;
            break;
        }
    }

    if(f==0)
        cout<<"\nSorry Room Number Not found or It is Vacant!";

    cout<<"\n\nPress any key to continue...";
    getch();
    fin.close();
}


void tourist::display_customer()
{
    system("cls");

    ifstream fin("Record.txt",ios::in);
    cout<<"\nList Of Rooms Allotted";
    cout<<"\n======================\n";

    while(!fin.eof())
    {
		fin.read((char*)this,sizeof(tourist));
		cout<<"\nRoom no: "<<room_num;
        cout<<"\nName: "<<name;
		cout<<"\nAddress: "<<address;
		cout<<"\nPhone No: "<<phone;
		cout<<"\n****************************\n";
	}

    getch();
    fin.close();

}


generate_bill::generate_bill()
{
    system("cls");

    int room;
    cout<<"\nTotal Number of Rooms: 150\n";
    cout<<"\nRegular Suite Rooms  (1 - 50)    PRICE-> 3000TK (Per Night}";
    cout<<"\nLuxury Suite Rooms (51 - 100)    PRICE-> 5000TK (Per Night}";
    cout<<"\nRoyal Suite Rooms (101 - 150)    PRICE-> 8000TK (Per Night}";
    cout<<"\n\nEnter Room Number: " ;
    cin>>room;

    cout<<"\nEnter Number of Night for Stay: ";
    cin>>staying_day;

    printf("\n\n*** Welcome to our Restuarant System ***\n");
    printf("----------------------------------------");
    printf("\n1.  Breakfast                     250  TK ");
    printf("\n2.  Lunch                         500  TK ");
    printf("\n3.  Snakes                        250  TK ");
    printf("\n4.  Dinner                        500  TK ");
    printf("\n5.  Total Cost (Per Night)       1500  TK ");

    cout<<"\n\nNumber of Person for Food: ";
    cin>>number_of_person;

    if(room>=1 && room<=50)
        cout<<"\nTotal Bill: "<<3000*staying_day+1500*number_of_person*staying_day<<endl;

    else if(room>=51 && room<=100)
        cout<<"\nTotal Bill: "<<5000*staying_day+1500*number_of_person*staying_day<<endl;

    else if(room>=101 && room<=150)
        cout<<"\nTotal Bill: "<<8000*staying_day+1500*number_of_person*staying_day<<endl;

    printf("\n\n***THANK YOU***\n\n");
    printf("Press any key to continue...");
    getch();
}

void details::room_details()
{
    system("cls");

    int type;
    cout<<"\nTotal Number of Rooms: 150\n";
    cout<<"\n1. Regular Suite Rooms  (1 - 50)    PRICE-> 3000TK (Per Night}";
    cout<<"\n2. Luxury Suite Rooms (51 - 100)    PRICE-> 5000TK (Per Night}";
    cout<<"\n3. Royal Suite Rooms (101 - 150)    PRICE-> 8000TK (Per Night}";

    cout<<"\n\nChoose Comfort Suite Option for Details: ";
    cin>>type;
    printf("\n\n###################################################################\n\n");

    if(type==1)
    {
        printf("Regular Suite Rooms: \n");
        printf("\n>>> One big room with single bed.");
        printf("\n>>> One bathroom");
        printf("\n>>> Fully air conditioned");
        printf("\n>>> Refrigerator");
        printf("\n>>> TV");
        printf("\n>>> Dressing table");
        printf("\n\nPRICE-> 3000TK (Per Night}\n\n");
        getch();
    }
    else if(type==2)
    {
        printf("Luxury Suite Rooms: \n");
        printf("\n>>> Two big room with double bed.");
        printf("\n>>> Two bathroom");
        printf("\n>>> Fully air conditioned");
        printf("\n>>> Refrigerator");
        printf("\n>>> TV");
        printf("\n>>> Dressing table");
        printf("\n\nPRICE-> 5000TK (Per Night}\n\n");
        getch();
    }
    else if(type==3)
    {
        printf("Royal Suite Rooms: \n");
        printf("\n>>> Three big room with two bed.");
        printf("\n>>> Two bathroom");
        printf("\n>>> Fully air conditioned");
        printf("\n>>> Refrigerator");
        printf("\n>>> TV");
        printf("\n>>> Dressing table");
        printf("\n>>> Big balcony");
        printf("\n>>> Kitchen");
        printf("\n\nPRICE-> 8000TK (Per Night}\n\n");
        getch();
    }
    else
    {
        printf("Wrong Choose");
        getch();
    }
    cout<<"\n\nPress any key to continue...";
    getch();
}


void details::food_details()
{
    system("cls");

    printf("\n\n*** Welcome to our Restuarant System ***\n");
    printf("----------------------------------------");
    printf("\n1.  Breakfast                     250  TK ");
    printf("\n2.  Lunch                         500  TK ");
    printf("\n3.  Snakes                        250  TK ");
    printf("\n4.  Dinner                        500  TK ");
    printf("\n5.  Total Cost (Per Night)       1500  TK ");

    printf("\n\n\t***THANK YOU***\n\n");
    printf("Press any key to continue...");
    getch();
}

void details::about_us()
{
    system("cls");

    printf("\nWELCOME TO ROYAL BLUE HOTEL");
    printf("\n\nCONTACT US");
    printf("\n\nADDRESS:  Airport Road, Dhaka Cantonment, Dhaka-1206\n");
    printf("\nPHONE:  +8801730089139\n\t+8801766666530\n");
    printf("\nHOTLINE:  2466\n");
    printf("\nEMAIL: royalblue@hotelbd.com\n");
    printf("\n\n\***THANK YOU FOR VISITING OUR APPLICATION***\n\n");
    printf("Press any key to continue...");
    getch();
}

void tourist::edit_customer()
{

    system("cls");

    int chc, r;
    cout<<"\nUPDATE PAGE";
    cout<<"\n===========\n";
    cout<<"\n1. Modify Customer Record";
    cout<<"\n2. Delete Customer Record";
    cout<<"\nEnter your choice: ";
    cin>>chc;
    system("cls");

    switch(chc)
    {

    case 1:
        cout<<"\nEnter Room Number: " ;
        cin>>r;
        modify_customer(r);
        break;

    case 2:
        cout<<"\nEnter Room Number: " ;
        cin>>r;
        delete_customer(r);
        break;

    case 3:
        display_customer();
        break;

    default:
        cout<<"\nWrong Choice!!!";
    }

    cout<<"\nPress any key to continue...";
    getch();
}


void tourist::modify_customer(int r)
{
    long pos, f=0;

    fstream file("Record.txt",ios::in|ios::out|ios::binary);

    while(!file.eof())
    {
        pos=file.tellg();
        file.read((char*)this,sizeof(tourist));

        if(room_num==r)
        {
            cout<<"\nEnter New Details";
            cout<<"\n=================";
            cout<<"\nNew Name: ";
            cin>>name;
            cout<<"New Address: ";
            cin>>address;
            cout<<"New Phone No: ";
            cin>>phone;
            file.seekg(pos);
            file.write((char*)this,sizeof(tourist));
            cout<<"\nCongrats!!! Record is Modified!!!";
            f=1;
            break;
        }
    }
    if(f==0)
        cout<<"\nSorry Room Number Not found or It is Vacant!!!";

    file.close();
}

void tourist::delete_customer(int r)
{
    int f=0;
    char ch;
    ifstream fin("Record.txt",ios::in);
    ofstream fout("temp.txt",ios::out);

    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(tourist));
        if(room_num==r)
        {
            cout<<"\nName: "<<name;
            cout<<"\nAddress: "<<address;
            cout<<"\nPone No: "<<phone;
            cout<<"\n\nDo you want to Delete this Record( y / n ): ";
            cin>>ch;

            if(ch=='n')
                fout.write((char*)this,sizeof(tourist));
            f=1;
        }
        else
            fout.write((char*)this,sizeof(tourist));
    }

    fin.close();
    fout.close();

    if(f==0)
        cout<<"\nSorry Room Number Not found or It is Vacant!!!";

    else
    {
        remove("Record.txt");
        rename("temp.txt","Record.txt");
    }
}



int main()
{
    screen s;
    tourist t;

    s.welcome_screen();

    s.login_screen();

    t.home_page();

    return 0;
}
