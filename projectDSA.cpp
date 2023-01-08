//START

#include<bits/stdc++.h>
using namespace std;
//implementing a node class
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

//implementing the logNode
class logNode
{
    public:
    string name;
    long long int number;
    string td;

    logNode(string name,long long int number,string td)
    {
        this->name= name;
        this->number=number;
        this->td=td;
    }
};

//implementing the phonebook
class phonebook
{
    public:
    map<string,node*> list;
    vector<logNode*> callLog;

    //constructor
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
    
    bool checkExistence(string name)
    {
        if(list.find(name)!=list.end())
        {
            cout<<"Contact already exists! Do you want to update it? [y/n]\n";
            char x;
            cin>>x;
            if(x=='y') update(name);
            return true;
        }
        return false;
    }

    void add(string name,long long int number,string email)
    {
        node * n= new node(number,email);
        list[name]=n;
        return;
    }

    void displayAll()
    {
        cout<<"Total Contacts : "<<list.size()<<endl<<endl;
        map<string,node*> ::iterator it= list.begin();
        for(;it!=list.end();++it)
        {
            cout<<it->first<<" :"<<endl;
            cout<<"Number(s) : " <<endl;
            for(int i=0;i<it->second->numbers.size();i++) cout<<it->second->numbers[i]<<endl;
            cout<<"Email : "<<it->second->email<<endl<<endl;
        }
    }

    void displayByKey(string key)
    {
        cout<<endl<<"The searched contact is: \n";
        cout<<key<<" :"<<endl;
        cout<<"Number(s) : " <<endl;
        for(int i=0;i<list[key]->numbers.size();i++) cout<<list[key]->numbers[i]<<endl;
        cout<<"Email : "<<list[key]->email<<endl<<endl;
        return;
    }

    string getKeyByEmail(string email)
    {
        string key="";
        for(auto it=list.begin();it!=list.end();it++)
            {
                if(it->second->email==email)
                {
                    key = it->first;
                    break;
                }
            }
        return key;
    }

    string getKeyByNumber(long long int number)
    {
        string key="";
         for(auto it=list.begin();it!=list.end();it++)
            {
                for(auto i=0;i<it->second->numbers.size();it++)
                {
                    if(it->second->numbers[i]==number)
                    {
                        key = it->first;
                        break;
                    }
                }
            }
            return key;
    }

    void search()
    {
        cout<<"*************Enter the number corresponding to your choice*************"<<endl<<endl;
        cout<<"1: Search by name."<<endl;
        cout<<"2: Search by email."<<endl;
        cout<<"3: Search by number(s)."<<endl;
        cout<<endl;

        int x;
        cin>>x;
        cin.ignore();
        switch(x)
        {
            case(1):
            {
                cout<<"Enter the name: \n";
                string n;
                getline(cin,n);
                if(list.find(n)==list.end())
                {
                    cout<<"Contact does not exist!"<<endl;
                    return;
                }
                displayByKey(n);
                break;
            }

            case(2):
            {
                cout<<"Enter the email: \n";
                string n;
                getline(cin,n);
                string key=getKeyByEmail(n);
                if(key=="") 
                {
                    cout<<"Contact does not exist!"<<endl;
                    return;
                }
                displayByKey(key);
                break;
            }

            case(3):
            {
                cout<<"Enter the number: \n";
                long long int num;
                cin>>num;
                string key=getKeyByNumber(num);
                if(key=="") 
                {
                    cout<<"Contact does not exist!"<<endl;
                    return;
                }
                displayByKey(key);
                break;
            }
        }
    }

    void deleteByKey(string key)
    {
        list.erase(key);
        return;
    }

    void del()
    {
        cout<<"*************Enter the number corresponding to your choice*************"<<endl<<endl;
        cout<<"1: Delete by name."<<endl;
        cout<<"2: Delete by email."<<endl;
        cout<<"3: Delete by number(s)."<<endl;
        cout<<endl;

        int x;
        cin>>x;
        cin.ignore();
        switch(x)
        {
            case(1):
            {
                cout<<"Enter the name: \n";
                string n;
                getline(cin,n);
                if(list.find(n)==list.end())
                {
                    cout<<"Contact does not exist!"<<endl;
                    return;
                }
                deleteByKey(n);
                break;
            }

            case(2):
            {
                cout<<"Enter the email: \n";
                string n;
                getline(cin,n);
                string key=getKeyByEmail(n);
                if(key=="") 
                {
                    cout<<"Contact does not exist!"<<endl;
                    return;
                }
                deleteByKey(key);
                break;
            }

            case(3):
            {
                cout<<"Enter the number: \n";
                long long int num;
                cin>>num;
                string key=getKeyByNumber(num);
                if(key=="") 
                {
                    cout<<"Contact does not exist!"<<endl;
                    return;
                }
                deleteByKey(key);
                break;

            }
        }
    }

    void update(string originalName)
    {
        cout<<"*************Enter the number corresponding to your choice*************"<<endl<<endl;
        cout<<"1: Change name."<<endl;
        cout<<"2: Change email."<<endl;
        cout<<"3: Change number."<<endl;
        cout<<"4: Add a new number."<<endl<<endl;
        int n; 
        cin>>n;
        cin.ignore();
        switch(n)
        {
            case(1):
            {
                cout<<"Enter new name: \n";
                string newName; 
                getline(cin,newName);
                list[newName]=list[originalName];
                list.erase(originalName);
                break;
            }

            case(2):
            {
                cout<<"Enter new email: \n";
                string newEmail; 
                getline(cin,newEmail);
                list[originalName]->email=newEmail;
                break;
            }

            case(3):
            {
                cout<<"Enter new number: \n";
                long long int newNumber; 
                cin>>newNumber;
                list[originalName]->numbers[0]=newNumber;
                break;
            }

            case(4):
            {
                cout<<"Enter new number: \n";
                long long int newNumber; 
                cin>>newNumber;
                list[originalName]->numbers.push_back(newNumber);
                break;
            }
        }
    }

    void callByKey(string key)
    {
        time_t my_time = time(NULL);
        string x=ctime(&my_time);
        logNode * n= new logNode(key,list[key]->numbers[0],x);
        callLog.push_back(n);
        return;
    }

    void callRandom(long long int num)
    {   
        time_t my_time = time(NULL);
        string x=ctime(&my_time);
        logNode * n= new logNode("Unknown",num,x);
        callLog.push_back(n);
        return;
    }

    void call()
    {
        cout<<"*************Enter the number corresponding to your choice*************"<<endl<<endl;
        cout<<"1: Call by name."<<endl;
        cout<<"2: Call by email."<<endl;
        cout<<"3: Call by number(s)."<<endl;
        cout<<"4: Call random number."<<endl;
        cout<<endl;

        int x;
        cin>>x;
        cin.ignore();
        switch(x)
        {
            case(1):
            {
                cout<<"Enter the name: \n";
                string n;
                getline(cin,n);
                if(list.find(n)==list.end())
                {
                    cout<<"Contact does not exist!"<<endl;
                    return;
                }
                callByKey(n);
                break;
            }

            case(2):
            {
                cout<<"Enter the email: \n";
                string n;
                getline(cin,n);
                string key=getKeyByEmail(n);
                if(key=="") 
                {
                    cout<<"Contact does not exist!"<<endl;
                    return;
                }
                callByKey(key);
                break;
            }

            case(3):
            {
                cout<<"Enter the number: \n";
                long long int num;
                cin>>num;
                string key=getKeyByNumber(num);
                if(key=="") 
                {
                    cout<<"Contact does not exist!"<<endl;
                    return;
                }
                callByKey(key);
                break;

            }

            case(4):
            {
                cout<<"Enter the number: \n";
                long long int num;
                cin>>num;
                callRandom(num);
                break;
            }
        }
    }

    void displayCallLog()
    {
        int size=callLog.size();
        if(size==0){
            cout<<"No recent calls!"<<endl;
            return;
        }
        cout<<"Recents: \n\n";
        for(int i=size-1;i>=0;i--)
        {
            cout<<size-i<<": "<<callLog[i]->name<<endl;
            cout<<"Number: "<<callLog[i]->number<<endl;
            cout<<"Time and Date: "<<callLog[i]->td<<endl;
        }
        return;
    }

    void clearLog()
    {
        callLog.clear();
        cout<<"Log Cleared Sucessfully!"<<endl;
        return;
    }

};



int main()
    {
    phonebook contacts;
    char c='y';
    while(c=='y')
    {
    cout<<endl<<"*************Enter the number corresponding to your choice*************"<<endl<<endl;
    cout<<"1: Search a Contact."<<endl;
    cout<<"2: Display all Contacts."<<endl;
    cout<<"3: Add a new Contact."<<endl;
    cout<<"4: Delete a Contact."<<endl;
    cout<<"5: Update a Contact."<<endl;
    cout<<"6: Make a call."<<endl;
    cout<<"7: Display Call log."<<endl;
    cout<<"8: Clear Call Log."<<endl<<endl;
    
    int n;
    cin>>n;
    cin.ignore();
    switch(n)
    {
        case(1):
        {
            contacts.search();
            cout<<"Search sucessfull!"<<endl;
            break;
        }

        case(2):
        {
            cout<<endl<<"Contacts: "<<endl<<endl;
            contacts.displayAll();
            cout<<endl;
            break;
        }

        case(3):
        {
            cout<<endl<<"Enter the name: "<<endl;
            string name; 
            getline(cin,name);
            bool x= contacts.checkExistence(name);
            if(x==true) break;
            cout<<"Enter the contact number: \n";
            long long int number; 
            cin>>number;
            cout<<"Enter the email: \n";
            string email;
            cin>>email;
            contacts.add(name,number,email);
            cout<<"Contact sucessfully added!"<<endl;
            break;
        }

        case(4):
        {
            contacts.del();
            cout<<"Contact deleted sucessfully!"<<endl;
            break;
        }

        case(5):
        {
            cout<<endl<<"Enter the name: \n";
            string name; 
            getline(cin,name);
            contacts.update(name);
            cout<<"Contact sucessfully updated!"<<endl;
            break;
        }

        case(6):
        {
            contacts.call();
            cout<<"Call made sucessfully!"<<endl;
            break;
        }

        case(7):
        {
            contacts.displayCallLog();
            cout<<endl;
            break;
        }

        case(8):
        {
            contacts.clearLog();
            cout<<"Call Log cleared!"<<endl;
            break;
        }
    }

    cout<<endl<<"Do you want to continue? [y/n] "<<endl;
    cin>>c;
    }
    return 0;
    }
//END
