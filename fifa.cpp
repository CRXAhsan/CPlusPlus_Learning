#include<iostream>
using namespace std;

class Teams
{
    public:
        string team[4];
        string name[4][11];// first bracket for teams associated and another for players name
        // constructor for initializing the values of teams
        Teams()
        {
            // loop for initializing the values of data variable team[4];
            for(int i=0; i<4; i++)
            {
                team[i]="team";
            }

            // loop for initializing the values of data variable name[4][11];
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                {    
                    name[i][j]="name";
                }
            }
        }

        // setter func for set the user define values to teams
        void setTeams()
        {
            for(int j=0; j<4; j++) // loop for describing specific team
            {
                cout<<"Enter Team "<<j+1<<" Name : ";
                cin>>team[j];
                cout<<"Enter Players Name \n";            
                for(int k=0; k<11; k++) // loop for players name input along with specific team
                {
                    cout<<"No."<<k+1<<" ";
                    cin>>name[j][k];
                }
            }
        }

        // getter func use to display the record of teams
        void getTeams()
        {
            for(int j=0; j<4; j++) // loop for describing specific team
            {
                cout<<"Team "<<j+1<<" Name : "<<team[j]<<"\n";
                cout<<"Players Name \n";
                for(int k=0; k<11; k++) // loop for players name input along with specific team
                {
                    cout<<"No."<<k+1<<" "<<name[j][k]<<"\n";
                }
            }            
        }

        
};

class Venue
{
    public:
        string venue[3];

        Venue()
        {
            // loop for initializing the values of data variable venue[3];
            for(int i=0; i<3; i++)
            {
                venue[i]="venue";
            }
        }
        // seter for set the user defined venues
        void setVenue()
        {
            cout<<"Enter Venues "<<endl;
            for(int i=0; i<3; i++)
            {
                cout<<"Venue "<<i+1<<" : ";
                cin>>venue[i];
            }
        }
        // geter for display what user has entered
        void getVenue()
        {
            for(int i=0; i<3; i++)
            {
                cout<<"Venue "<<i+1<<" : "<<venue[i]<<"\n";
            }
        }
};

class Matches
{
    private:
        Teams *t1;
        Venue *v1;
        
    
    public:
        Matches(Teams *t, Venue *v)
        {
            t1=t;
            v1=v;
        }
        // random func for generatring a number from total teams
        void setMatch()
        {
            t1->setTeams();
            v1->setVenue();
        }
        void getMatch()
        {
            cout<<"*************Total Teams With Their Players*************\n";
            t1->getTeams();
            cout<<"********************************************************\n\n";
            cout<<"**********************Total Venues**********************\n";
            v1->getVenue();
            cout<<"********************************************************\n\n";
            cout<<"**********************Total Matches*********************\n";
            for (int j=0; j<3; j++)
            {
                if (j==0)
                {
                    cout<<"Match "<<j+1<<" : "<<t1->team[j]<<"  V/S  "<<t1->team[j+1]<<"\n";
                }
                else if (j==1)
                {
                    cout<<"Match "<<j+1<<" : "<<t1->team[j+1]<<"  V/S  "<<t1->team[j+2]<<"\n";
                }
                else if (j==2)
                {
                    cout<<"Final Match "<<j+1<<" : "<<t1->team[j-2]<<"  V/S  "<<t1->team[j]<<"\n";
                }
            }
            cout<<"********************************************************\n\n";
            cout<<"**********************Score of Teams********************\n";
            cout<<"Teams    Score\n";
            for (int i=2; i>=0; i--)
            {
                if (i==2)
                {
                    cout<<"  "<<t1->team[i-2]<<"       "<<i<<"\n";
                }
                else if (i==1)
                {
                    cout<<"  "<<t1->team[i+1]<<"       "<<i<<"\n";
                }
                else if (i==0)
                {
                    cout<<"  "<<t1->team[i+1]<<"       "<<i<<"\n";
                    cout<<"  "<<t1->team[i+3]<<"       "<<i<<"\n";
                }
            }
            cout<<"********************************************************\n\n";

            cout<<"***********************Match Winner*********************\n";
            cout<<"\t"<<t1->team[0]<<"\n";
            cout<<"Here is your trophee...\n";
            cout<<"   ********* \n";
            cout<<"    *     *  \n";
            cout<<"     *   *   \n";
            cout<<"      ***    \n";
            cout<<"       *     \n";
            cout<<"       *     \n";
            cout<<"   **********\n\n";
            cout<<"********************************************************\n\n";
        }

};

class Winner
{
    private:
        Matches *m1;
    public:
        Winner(Matches *m)
        {
            m1=m;
        }
        void setWinner()
        {
            m1->setMatch();
        }
        void getWinner()
        {
            m1->getMatch();
            
        }
};

int main()
{
    
    Teams t2;
    Venue v2;
    Matches m2(&t2 , &v2);
    Winner win(&m2);
    win.setWinner();
    win.getWinner();
}