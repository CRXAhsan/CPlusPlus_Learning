#include<iostream>
using namespace std;



class Room
{
    public:
        void store()
        {
            cout<<"You have Selected Cold Rooms For Your Vegetables.\n";
            cout<<"Cold Rooms Rent is 2000 Rs per meter\n";
            cout<<"Enter Length and width for area you want to need for your Vegetables.\n";
            cin>>length>>Width;
            area = length * Width;
            cout<<"Your total area is "<<area;
            rent = area * 2000;
            cout<<"You total rent per day is : "<<rent;
            cout<<"\n";
        }
    private:
        int rent;
        int area;
        int length;
        int Width;
};

class Hall
{
    public:
        void store()
        {
            cout<<"You have Selected Hall For Your Vegetables.\n";
            cout<<"Hall Rent is 1000 Rs per meter\n";
            cout<<"Enter Length and width for area you want to need for your Vegetables.\n";
            cin>>length>>Width;
            area = length * Width;
            cout<<"Your total area is "<<area;
            rent = area * 1000;
            cout<<"You total rent per day is : "<<rent;
            cout<<"\n";
        }
    private:
        int rent;
        int area;
        int length;
        int Width;
};

class Transport
{
    public:
        void Carry()
        {

        }
    protected:
        int weight;
        int capacity;
        int speed;
    
};

class LandTransport : public Transport
{
    public:
        void LandCarry()
        {
            cout<<"land transport take your goods in 7 days.\n";
            
        }
    private:
};

class SeaTransport : public Transport
{
    public:
        void SeaCarry()
        {
            cout<<"Sea transport take your goods in 12 days.\n";
        }
    private:
};

class AirTransport : public Transport
{
    public:
        void AirCarry()
        {
            cout<<"Air transport take your goods in 3 days.\n";
        }
    private:
};

class Continenet : public LandTransport, public SeaTransport, public AirTransport
{
    public:
        
    private:
        string name;
        string NoOfCountries;
        string BusinessType;
        int transportType;
};

class Asia :public Continenet
{
    public:
    void tradePloicy()
        {
            cout<<"**** Asia have Some trade Policies ****\n";
            cout<<"You have To Send the Vacinated Vegetables\n";
            cout<<"also these vagetables are fresh and have an expiry date.\n";
        }
        void menu()
        {
            cout<<"#### You have Choosen Asia ####\n";
            tradePloicy();
            cout<<"Transport services available \n";
            cout<<"1. land transport\n";
            cout<<"2. Sea transport\n";
            switch (choice)
            {
            case 1:
                LandCarry();
                break;
            
            case 2:
                SeaCarry();
                break;
            }

        }
    private:
    int choice;
};

class Africa :public Continenet
{
    public:
        void tradePloicy()
        {
            cout<<"**** Africa have Some trade Policies ****\n";
            cout<<"You have To Send the Vacinated Vegetables\n";
            cout<<"also these vagetables are fresh and have an expiry date.\n";
        }
        void menu()
        {
            
            cout<<"#### You have Choosen Africa ####\n";
            tradePloicy();
            cout<<"Transport services available \n";
            cout<<"1. land transport\n";
            cout<<"2. Sea transport\n";
            switch (choice)
            {
            case 1:
                LandCarry();
                break;
            
            case 2:
                SeaCarry();
                break;
            }

        }
    private:
    int choice;
};

class Europe :public Continenet
{
    public:
    void tradePloicy()
        {
            cout<<"**** Europe have Some trade Policies ****\n";
            cout<<"You have To Send the Vacinated Vegetables\n";
            cout<<"also these vagetables are fresh and have an expiry date.\n";
        }
        void menu()
        {
            cout<<"#### You have Choosen Europe ####\n";
            tradePloicy();
            cout<<"Transport services available \n";
            cout<<"1. Air transport\n";
            cout<<"2. Sea transport\n";
            switch (choice)
            {
            case 1:
                AirCarry();
                break;
            
            case 2:
                SeaCarry();
                break;
            }

        }
    private:
    int choice;

};

class Company
{
    public:
        Company()
        {
            r = new Room();
            h = new Hall();
        }

        void take_order()
        {
            cout<<"Enter Your Company Name.\n";
            cin>>comp_name;
            cout<<"Enter Your Registration no.\n";
            cin>>registeration_no;
            cout<<"Enter Your Business Type.\n";
            cin>>business_type;
            cout<<"Enter your Order.\n";
            cin>>order;
        }

        void Export()
        {
            cout<<"Company Name: "<<comp_name;
            cout<<"\nRegistration No: "<<registeration_no;
            cout<<"\nBusiness Type: "<<business_type;
            cout<<"\nOrder Amount: "<<order;
            cout<<"\n";
        }

        void Profit_report()
        {
            
        }

        void CountryWiseSaleReport()
        {
            
        }

        void ContinentWiseSaleReport()
        {
            
        }

        void FinancialStatement()
        {

        }

        void Menu()
        {
            cout<<"##### Welcome to Maju Food Internationals #####\n\n";
            take_order();
            cout<<"\nWhich type of room You want for your vegetables.\n";
            cout<<"1. Cold rooms\n";
            cout<<"2. Halls\n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                r->store();
                break;
            
            case 2:
            h->store();
                break;
            }
            cout<<"Select your Continent.\n";
            cout<<"1. Asia\n";
            cout<<"2. Europe\n";
            cout<<"3. Africa\n";
            cin>>choice;
            switch (choice)
            {
            case 1:
                asia->menu();
                break;
            
            case 2:
                eur->menu();
                break;

            case 3:
                afr->menu();
                break;
            }
          
        }

    private:
        string comp_name;
        string registeration_no;
        string business_type;
        int order;
        int choice;
        Room* r;
        Hall* h;
        Asia* asia;
        Africa* afr;
        Europe* eur;
};


int main()
{
    Company c;
    c.Menu();
}