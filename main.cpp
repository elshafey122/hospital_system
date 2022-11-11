#include <iostream>
using namespace std;

const int max_spec=20;
const int max_patien=5;
struct hospital_system
{
    string names[max_spec][max_patien];
    int states[max_spec][max_patien];
    int added[max_spec]={0};

    void Add_patient()
    {
    int spec;
    cout<<"Enter specialization, name, statis: ";//0 0 1
    cin>>spec;
    cin>>names[spec-1][added[spec-1]];
    cin>>states[spec-1][added[spec-1]];

    string x=names[spec-1][added[spec-1]];
    int y=states[spec-1][added[spec-1]];

    if(y==1)
    {
        for(int i=added[spec-1];i>0;i--)
        {
            names[spec-1][i]=names[spec-1][i-1];
            states[spec-1][i]=states[spec-1][i-1];
        }
        names[spec-1][0]=x;
        states[spec-1][0]=y;
    }
    added[spec-1]++;
    if((added[spec-1])>5)
    {
        cout<<"sorry we cannot add more patients in this specialization "<<endl;
        added[spec-1]--;
    }
}

void Print_patients()
{
    int check=0;
    for(int i=0;i<20;i++)
    {
        if(added[i]==0)
        {
            continue;
        }
        cout<<"there are "<<added[i]<<" patients in specialization "<<i+1<<endl;
        check=1;
        for(int k=0;k<added[i];k++)
        {
            cout<<names[i][k]<<" ";
            if(states[i][k]==0)
            {
                 cout<<"regular"<<endl;
            }
            else if(states[i][k]==1)
            {
                 cout<<"Urgent"<<endl;
            }
        }
        cout<<endl;
    }
    if(check==0)
    {
        cout<<"there is no patients in hospital now"<<endl;
    }
}

void next_patient()
{
   cout<<"enter specialization: ";
   int spec;
   cin>>spec;
   if(added[spec-1]==0)
   {
       cout<<"No patient at this moment. have rest, dr "<<endl;
   }
   else
   {
       cout<<names[spec-1][0]<<" please go with the dr"<<endl;
       for(int i=0;i<added[spec-1]-1;i++)
        {
            names[spec-1][i]=names[spec-1][i+1];
            states[spec-1][i]=states[spec-1][i+1];
        }
        added[spec-1]--;
   }
}

void run()
{
    int choice=-1;
    while(choice=-1)
    {
        cout<<"Enter your choice:"<<endl;
        cout<<"1) Add new patient"<<endl;
        cout<<"2) Print all patients"<<endl;
        cout<<"3) Get next patient"<<endl;
        cout<<"4) Exit"<<endl;
        cin>>choice;
        if(choice>=1&&choice<=4)
        {
            if(choice==1)
            {
                Add_patient();
            }
            else if(choice==2)
            {
                Print_patients();
            }
            else if(choice==3)
            {
                next_patient();
            }
            else if(choice==4)
            {
                cout<<"thanks"<<endl;
                break;
            }
        }
        else
        {
            cout<<"invalid input enter value between [1:4]"<<endl;
        }
    }
}

};

int main()
{
    hospital_system h1=hospital_system();
    h1.run();

    hospital_system h2;
    h1.run();

    return 0;
}
