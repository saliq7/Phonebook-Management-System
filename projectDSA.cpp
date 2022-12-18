#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    vector<long long int> numbers;
    string email;
    public:
    node(long long int number,string email)
    {
       numbers.push_back(number); 
       this ->email=email;
    }
};

class phonebook
{
    public:
    map<string,node*> list;

    phonebook()
    {
        node * n=new node(7780849120,"saliqgowhar.211ee250@nitk.edu.in");
        list["Saliq Gowhar"]=n;
        n=new node(9140371872,"aditisingh.211ai004@nitk.edu.in");
        list["Aditi Singh"]=n;
        n=new node(9569601457,"ashutosh.211ai008@nitk.edu.in");
        list["Ashutosh Gupta"]=n;
        n=new node(8700931594,"shrmabhav.211ai011@nitk.edu.in");
        list["Bhavya"]=n;
        n=new node(8712709640,"katakamritvik.211ai022@nitk.edu.in");
        list["K Ritvik"]=n;
    }
    //Operations
    void add(string name,long long int number,string email)
    {
        if(list.find(name)!=list.end())
        {
            cout<<"Contact already exists!"<<endl;
            return;
        }
        node * n= new node(number,email);
        list[name]=n;
        return;
    }

    void displayAll()
    {
        map<string,node*> ::iterator it= list.begin();
        for(;it!=list.end();++it)
        {
            cout<<it->first<<" :"<<endl;
            cout<<"Number(s) : ";
            for(int i=0;i<it->second->numbers.size();i++) cout<<it->second->numbers[i]<<endl;
            cout<<"Email : "<<it->second->email<<endl<<endl;
        }
    }

};



int main()
    {
    phonebook contacts;
    cout<<endl<<"*************Enter the number corresponding to your choice*************"<<endl<<endl;
    cout<<"1: Search a Contact."<<endl;
    cout<<"2: Display all Contacts."<<endl;
    cout<<"3: Add a new Contact."<<endl;
    cout<<"4: Delete a Contact."<<endl;
    cout<<"5: Update a Contact."<<endl<<endl;
    
    int n;
    cin>>n;
    switch(n)
    {
        case(2):
        {
            cout<<endl<<"Contacts: "<<endl<<endl;
            contacts.displayAll();
            break;
        }
        case(3):
        {
            cout<<"Enter the name: "<<endl;
            string name; cin>>name;
            cout<<"Enter the contact number: \n";
            long long int number; cin>>number;
            cout<<"Enter the email: \n";
            string email;cin>>email;
            contacts.add(name,number,email);
            cout<<"Contact sucessfully added!"<<endl;
            break;
        }
    }
    return 0;
    }