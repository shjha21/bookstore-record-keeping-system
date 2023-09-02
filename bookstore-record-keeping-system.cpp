
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iomanip>
using namespace std;

string EmployeeID;

class BookStore
{

    string Title,Author,BookId,Copy,Cost;
public:
    void Add(),Edit(),Delete(),Display(),HomePage(),SellBook(),UpdateStock(string,int),
ShowBusiness();
    void Business(string,string,string,int,int);
    int CheckSpace(string),CheckInteger(string),CheckId(string),CheckAuthor(string,string);

};

class Employee: public BookStore
{
    string EmployeeName,EmployeePassword,GetEmployeeId;
    static string EmployeeId;
public:
    Employee();
    void SignIn(),SignUp(),ForgotIDPassword();
    int EmployeeCheckId(string);

};

string Employee ::EmployeeId;

void BookStore :: Add()
{

    string Choice;

    cout<<"Do You want to add a book? \n\n";

    cout<<"\n\t\t\t(1) Yes                   ";
    cout<<"\n\t\t\t(2) No                    ";

    cout<<"\n\nEnter Your choice: ";
    getline(cin,Choice);

    try
    {
        if(Choice.length()>1)
            throw 6.0;
        else if(Choice.at(0)=='1')
        {
            try
            {
                cout<<"Note : Please Dont Use Space \n";
                cout<<"       You Can Use _(Under Score) instead of space \n";

                cout<<"\nEnter Book Id : ";
                getline(cin,BookId);
                int z=CheckId(BookId);
                if(z==1)
                {
                    cout<<"This ID already exists \n\n";
                    Add();
                }
                int a=CheckSpace(BookId);
                if(a==1)
                    throw 99;

                cout<<"\nEnter Book Name : ";
                getline(cin,Title);
                int b=CheckSpace(Title);
                if(b==1)
                    throw 99;

                cout<<"\nEnter Author Name : ";
                getline(cin,Author);
                int c=CheckSpace(Author);
                if(c==1)
                    throw 99;

                int m=CheckAuthor(Title,Author);

                if(m==1)
                {
                    cout<<"\nThis book and author already exist\n\n";
                    Add();
                }

                cout<<"\nEnter No of copies to be added : ";
                getline(cin,Copy);
                int e=CheckInteger(Copy);
                if(e==0)
                    throw 'x';

                cout<<"\nEnter Cost Of Book: ";
                getline(cin,Cost);
                int f=CheckInteger(Cost);
                if(f==0)
                    throw 'y';

                ofstream Write("BookStore.txt",ios::app);
                Write<<BookId<<"\t\t"<<Title<<"\t\t"<<Author<<"\t\t"<<Copy<<"\t\t"<<Cost<<endl;
                Write.close();

                cout<<"\nYour Book Is Succesfully Added \n\n";
                HomePage();

            }

            catch(int n)
            {
                cout<<"\n\nPlease Dont Use Space \n";
                cout<<"You Can Use _(Under Score) instead of space \n\n\n";
                Add();
            }

            catch(char f)
            {
                cout<<"\nPlease Input Integer Number \n\n";
                Add();
            }

        }

        else if(Choice.at(0)=='2')
            HomePage();
        else
            throw "gh";
    }

    catch(...)
    {
        cout<<"\nInvalid Input \n\n";
        Add();
    }

}

void BookStore :: Edit()
{

    string EditTitle,EditAuthor,EditBookId,EditCopy,EditCost;

    string Choice;

    cout<<"Do You Want To Edit book ? \n\n";

    cout<<"\n\t\t\t(1) Yes                   ";
    cout<<"\n\t\t\t(2) No                    ";

    cout<<"\n\nEnter Your choice: ";
    getline(cin,Choice);

    try
    {
        if(Choice.length()>1)
            throw 6.0;
        else if(Choice.at(0)=='1')
        {
            try
            {

                string EditId;
                cout<<"\nEnter Book ID : ";
                getline(cin,EditId);
                int y=CheckSpace(EditId);
                if(y==1)
                    throw 99;
                int Check=CheckId(EditId);
                if(Check==0)
                {
                    cout<<"\nSorry, no such ID exists \n";
                    Edit();
                }
                int a=CheckSpace(EditId);
                if(a==1)
                    throw 99;

                cout<<"Note : Please Dont Use Space \n";
                cout<<"       You Can Use _(Under Score) instead of space \n";

                cout<<"\nEnter New Book Id : ";
                getline(cin,EditBookId);
                int z=CheckId(EditBookId);
                if(z==1)
                {
                    cout<<"This ID already exists \n\n";
                    Edit();
                }
                int w=CheckSpace(EditBookId);
                if(w==1)
                    throw 99;

                cout<<"\nEnter New Book Name: ";
                getline(cin,EditTitle);
                int b=CheckSpace(EditTitle);
                if(b==1)
                    throw 99;

                cout<<"\nEnter New Author Name : ";
                getline(cin,EditAuthor);
                int c=CheckSpace(EditAuthor);
                if(c==1)
                    throw 99;


                cout<<"\nEnter No of copies to be added: ";
                getline(cin,EditCopy);
                int e=CheckInteger(EditCopy);
                if(e==0)
                    throw 'x';

                cout<<"\nEnter Cost Of Book: ";
                getline(cin,EditCost);
                int f=CheckInteger(EditCost);
                if(f==0)
                    throw 'y';


                ofstream Write("BookStore2.txt");
                ifstream Read("BookStore.txt");

                if(Read)
                {
                    while(Read>>BookId>>Title>>Author>>Copy>>Cost)
                    {
                        if(EditId==BookId)
                        {
                            Write<<EditBookId<<"\t\t"<<EditTitle<<"\t\t"<<EditAuthor<<"\t\t"<<EditCopy<<"\t\t"<<EditCost<<endl;
                            continue;
                        }

                        Write<<BookId<<"\t\t"<<Title<<"\t\t"<<Author<<"\t\t"<<Copy<<"\t\t"<<Cost<<endl;

                    }

                    Read.close();
                    Write.close();

                    remove("BookStore.txt");
                    rename("BookStore2.txt","BookStore.txt");
                }
                Read.close();
                Write.close();

                cout<<"\nYour Book Is Succesfully Edited \n\n";

                HomePage();

            }

            catch(int n)
            {
                cout<<"\n\nPlease Dont Use Space \n";
                cout<<"You Can Use _(Under Score) instead of space \n\n\n";
                Edit();
            }

            catch(char f)
            {
                cout<<"\nPlease Input Integer Number \n\n";
                Edit();
            }

        }

        else if(Choice.at(0)=='2')
            HomePage();
        else
            throw "gh";
    }

    catch(...)
    {
        cout<<"\nInvalid Input \n\n";
        Edit();
    }
}

void BookStore :: Delete()
{
    string Choice;

    cout<<"Do you want to delete a book? \n\n";

    cout<<"\n\t\t\t(1) Yes                   ";
    cout<<"\n\t\t\t(2) No                    ";

    cout<<"\n\nEnter Your choice: ";
    getline(cin,Choice);

    try
    {
        if(Choice.length()>1)
            throw 6.0;
        else if(Choice.at(0)=='1')
        {
            try
            {
                string EditId;
                cout<<"\nEnter Book ID: ";
                getline(cin,EditId);
                int y=CheckSpace(EditId);
                if(y==1)
                    throw 99;
                int Check=CheckId(EditId);
                if(Check==0)
                {
                    cout<<"\nSorry, no such ID exists\n";
                    Delete();
                }
                int a=CheckSpace(EditId);
                if(a==1)
                    throw 99;
                ofstream Write("BookStore2.txt");
                ifstream Read("BookStore.txt");

                if(Read)
                {
                    while(Read>>BookId>>Title>>Author>>Copy>>Cost)
                    {
                        if(EditId==BookId)
                        {
                            continue;
                        }

                        Write<<BookId<<"\t\t"<<Title<<"\t\t"<<Author<<"\t\t"<<Copy<<"\t\t"<<Cost<<endl;

                    }
                }
                else
                    cout<<"File Not Found";

                Read.close();
                Write.close();

                remove("BookStore.txt");
                rename("BookStore2.txt","BookStore.txt");

                cout<<"\nYour Book Is Succesfully Deleted \n\n";
                HomePage();

            }

            catch(int n)
            {
                cout<<"\n\nPlease Dont Use Space \n";
                cout<<"You Can Use _(Under Score) instead of space \n\n\n";
                Delete();
            }

            catch(char f)
            {
                cout<<"\nPlease Input Integer Number\n\n";
                Delete();
            }

        }

        else if(Choice.at(0)=='2')
            HomePage();
        else
            throw "gh";
    }

    catch(...)
    {
        cout<<"\nInvalid Input\n\n";
        Delete();
    }
}

void BookStore :: Display()
{

    cout<<"\nId           Book Name               Author Name            Copy        Cost   \n";

    ifstream Read("BookStore.txt");

    if(Read)
    {
        while(Read>>BookId>>Title>>Author>>Copy>>Cost)
        {
            cout<<setiosflags(ios::left)<<setw(13)<<BookId<<setw(25)<<Title<<setw(22)<<Author<<setw(14)<<Copy<<setw(14)<<Cost<<endl;
        }
        Read.close();
    }
    Read.close();
    HomePage();
}

void BookStore :: HomePage()
{
    string Choice;

    while(1)
    {
        cout<<"\n\n\t\t\t ~~~~~~~~~Menu~~~~~~~~~~~~~~ ";
        cout<<"\n\t\t\t  (1) Sell Book              ";
        cout<<"\n\t\t\t  (2) Add Book               ";
        cout<<"\n\t\t\t  (3) Delete Book            ";
        cout<<"\n\t\t\t  (4) Edit Book              ";
        cout<<"\n\t\t\t  (5) Show All Book List     ";
        cout<<"\n\t\t\t  (6) Show My Sold List      ";
        cout<<"\n\t\t\t  (7) Logout                 ";

        cout<<"\n\nEnter Your choice : ";
        getline(cin,Choice);

        try
        {
            if(Choice.length()>1)
                throw 99;
            else if(Choice.at(0)=='1')
            {
                SellBook();
            }

            else if(Choice.at(0)=='2')
            {
                Add();
            }

            else if(Choice.at(0)=='3')
            {
                Delete();
            }

            else if(Choice.at(0)=='4')
            {
                Edit();
            }

            else if(Choice.at(0)=='5')
            {
                Display();
            }

            else if(Choice.at(0)=='6')
            {
                ShowBusiness();
            }

            else if(Choice.at(0)=='7')
            {
                cout<<"Logged Out Successfully \n\n";
                Employee();
            }

            else
            {
                throw 65;
            }
        }

        catch(...)
        {
            cout<<"Invalid Input \n\n";
        }
    }
}

int BookStore :: CheckSpace(string Check)
{
    int c=0;
    for(int i=0; i<Check.length(); i++)
    {
        if(Check.at(i)==' ')
            return 1;

    }
};

int BookStore :: CheckInteger(string Check)
{
    int f=0;
    for(int i=0; i<Check.length(); i++)
    {
        if(Check.at(i)>='1' && Check.at(i)<='9')
            f++;
    }

    if(f>=1)
        return 1;
    else
        return 0;
}

int BookStore :: CheckId(string ID)
{
    string CheckBookId;
    int c=0;
    ifstream Read("BookStore.txt");
    if(Read)
    {
        while(Read>>CheckBookId>>Title>>Author>>Copy>>Cost)
        {
            if(CheckBookId==ID)
            {
                c++;
            }

        }

        if(c>=1)
        {
            Read.close();
            return 1;
        }
        else
        {
            Read.close();
            return 0;
        }
    }
    else
    {
        Read.close();
        cout<<"File not found";
    }

    return 0;

}

Employee ::Employee()
{
    {
        string Choice;

        while(1)
        {
            cout<<"\n\n\t\t\t ~~~~~~~~~Menu~~~~~~~~~~~~~~~~ ";
            cout<<"\n\t\t\t  (1) Sign In                  ";
            cout<<"\n\t\t\t  (2) Sign Up                  ";
            cout<<"\n\t\t\t  (3) Exit                     ";

            cout<<"\n\nEnter Your choice : ";
            getline(cin,Choice);

            try
            {
                if(Choice.length()>1)
                    throw 99;
                else if(Choice.at(0)=='1')
                {
                    SignIn();
                }

                else if(Choice.at(0)=='2')
                {
                    SignUp();
                }

                else if(Choice.at(0)=='3')
                {
                    cout<<"Thanks For Using This Software \n\n";
                    exit(0);
                }

                else
                {
                    throw 65;
                }
            }

            catch(...)
            {
                cout<<"Invalid Input \n\n";

            }
        }
    }
}

void Employee :: SignUp()
{
    try
    {
        cout<<"Enter ID: ";
        getline(cin,EmployeeId);
        int z=EmployeeCheckId(EmployeeId);
        if(z==1)
        {
            cout<<"This ID already exists \n";
            cout<<"\nPlease try again \n\n";
            Employee();
        }
        int a=CheckSpace(EmployeeId);
        if(a==1)
            throw 99;
        cout<<"Enter Name : ";
        getline(cin,EmployeeName);
        int b=CheckSpace(EmployeeName);
        if(b==1)
            throw 99;
        cout<<"Enter Password : ";
        getline(cin,EmployeePassword);
        int c=CheckSpace(EmployeePassword);
        if(c==1)
            throw 99;
    }
    catch(int a)
    {
        cout<<"\n\nPlease Dont Use Space \n";
        cout<<"You Can Use _(Under Score) instead of space \n";
        cout<<"\nPlease Try Again \n\n";
        Employee();
    }

    ofstream Write("login.txt",ios::app);
    Write<<EmployeeId<<"\t\t"<<EmployeeName<<"\t\t"<<EmployeePassword<<endl;
    cout<<"\nSign Up Success \n";
    Write.close();
    HomePage();
}

void Employee :: SignIn()
{

    string SignInId,SignInPassword;
    int c=0;
    try
    {
        cout<<"Enter Your ID  : ";
        getline(cin,EmployeeId);
        int a=CheckSpace(EmployeeId);
        if(a==1)
            throw 99;

        EmployeeID=EmployeeId;
        cout<<"Enter Password : ";
        getline(cin,EmployeePassword);
        int b=CheckSpace(EmployeePassword);
        if(b==1)
            throw 99;
    }
    catch(int a)
    {
        cout<<"\n\nPlease Dont Use Space \n";
        cout<<"You Can Use _(Under Score) instead of space \n";
        cout<<"Please Try Again \n\n";
        Employee();
    }

    ifstream Read("login.txt");

    if(Read)
    {
        while(Read>>SignInId>>EmployeeName>>SignInPassword)
        {
            if(EmployeeId==SignInId && EmployeePassword==SignInPassword)
            {
                cout<<"\nWelcome, Mr/Ms "<<EmployeeName<<". . ."<<endl;
                cout<<"You successfully signed in in your account \n\n";
                Read.close();
                HomePage();
                c++;
            }
        }
        if(c==0)
        {
            cout<<"\nYour Name or Password is wrong \n\n";
            Employee();
        }
        Read.close();
    }
    else
    {
        Read.close();
        cout<<"\nUser Not Found \n\n";
        Employee();
    }
}

int Employee ::EmployeeCheckId(string ID)
{
    ifstream Read("login.txt");
    if(Read)
    {
        string EmpLoyeeId;

        while(Read>>EmpLoyeeId>>EmployeeName>>EmployeePassword)
        {
            if(ID==EmpLoyeeId)
            {
                Read.close();
                return 1;
            }
        }
        Read.close();
        return 0;
    }
    else
    {
        Read.close();
        return 0;
    }

}

void BookStore ::SellBook()
{
    string Title,Author;
    int quantity,Cost,c=0,stock;
    try
    {
        cout<<"Note : Please Dont Use Space \n";
        cout<<"       You Can Use _(Under Score) instead of space \n";

        cout<<"\nEnter Book Name : ";
        getline(cin,Title);
        int b=CheckSpace(Title);
        if(b==1)
            throw 99;

        cout<<"\nEnter Author Name : ";
        getline(cin,Author);
        int c=CheckSpace(Author);
        if(c==1)
            throw 99;

    }

    catch(int n)
    {
        cout<<"\n\nPlease Dont Use Space \n";
        cout<<"You Can Use _(Under Score) instead of space \nPlease Try again \n\n";
        HomePage();
    }

    ifstream Read("BookStore.txt");
    if(Read)
    {
        while(Read>>BookId>>Title>>Author>>stock>>Cost)
        {
            if(Title==Title && Author==Author)
            {
                c++;
                cout<<"\nYes, We have "<<stock<<" copies of it "<<endl<<"Cost of each book is : "<<Cost<<"Re"<<endl;
                cout<<endl<<"How many books do you need ? : ";
                cin>>quantity;
                cin.ignore();
                if(quantity<=stock)
                {
                    int Pay=quantity*Cost;

                    cout<<"\nYou need to pay "<<Pay<<"Re\n\n"<<endl;

                    Read.close();
                    
                    cout<<"Do You Want to Sell ???";

                    string Choice;

                    cout<<"\n\t\t\t  (1) Yes                    ";
                    cout<<"\n\t\t\t  (2) No                     ";

                    cout<<"\n\nEnter Your choice : ";
                    getline(cin,Choice);

                    try
                    {
                        if(Choice.length()>1)
                            throw 6.0;
                        else if(Choice.at(0)=='1')
                        {
                            Business(BookId,Title,Author,quantity,Pay);
                            UpdateStock(BookId,quantity);
                            HomePage();

                        }

                        else if(Choice.at(0)=='2')
                        {
                            HomePage();
                        }

                        else
                            throw "gh";
                    }

                    catch(...)
                    {
                        cout<<"\nInvalid Input \n\n";
                        Delete();
                    }

                    c++;

                    HomePage();

                }
                else
                {
                    cout<<"Sorry, required copies are not currently in stock\n";
                    Read.close();
                    HomePage();
                }
            }

        }
        if(c==0)
        {
            cout<<"Sorry, this book is not currently available\n";
        }
    }
    else
    {
        Read.close();
        cout<<"Sorry, File not found\n";
    }

}

void BookStore ::UpdateStock(string ID,int quantity)
{

    ofstream Write("BookStore2.txt");
    ifstream Read("BookStore.txt");

    int stock,Count;
    if(Read)
    {
        while(Read>>BookId>>Title>>Author>>stock>>Cost)
        {
            if(ID==BookId)
            {
                Count=stock-quantity;
                stock=Count;
            }
            Write<<BookId<<"\t\t"<<Title<<"\t\t"<<Author<<"\t\t"<<stock<<"\t\t"<<Cost<<endl;
        }

        Read.close();
        Write.close();

        remove("BookStore.txt");
        rename("BookStore2.txt","BookStore.txt");
    }
    else
    {
        Read.close();
        Write.close();
    }
}

void BookStore ::Business(string Bookid,string Title,string Author,int COPY,int Money)
{
    char ID[10]= {0};
    int c=0;
    for(int i=0; i<EmployeeID.length(); i++)
    {
        ID[i]=EmployeeID[i];
    }

    strcat(ID,".txt");

    ofstream Write(ID,ios::app);
    Write<<BookId<<"\t\t"<<Title<<"\t\t"<<Author<<"\t\t"<<COPY<<"\t\t"<<Money<<endl;
    Write.close();
}

void BookStore :: ShowBusiness()
{
    cout<<" Id           Book Name               Author Name            Copy        Cost   \n";

    int a=EmployeeID.length();
    int c=0;
    char ID2[20]= {0};
    for(int i=0; i<a; i++)
    {
        ID2[i]=EmployeeID[i];
    }
    strcat(ID2,".txt");

    ifstream Read(ID2);
    if(Read)
    {
        if(Read.is_open())
        {
            while(Read>>BookId>>Title>>Author>>Copy>>Cost)
            {
                cout<<setiosflags(ios::left)<<setw(13)<<BookId<<setw(25)<<Title<<setw(22)<<Author<<setw(14)<<Copy<<setw(14)<<Cost<<endl;
            }
            Read.close();
        }
        else
        {
            Read.close();
            cout<<"Error Opening\n";

        }
    }
    else
    {
        Read.close();
        cout<<"File Not found\n";

    }
    HomePage();
}

int BookStore::CheckAuthor(string Title,string Author)
{
    ifstream Read("BookStore.txt");
    if(Read)
    {
        string CheckTitle,CheckAuthor,stock,Cost,CheckBookId;
        while(Read>>CheckBookId>>CheckTitle>>CheckAuthor>>stock>>Cost)
        {
            if(CheckTitle==Title && CheckAuthor==Author)
            {
                Read.close();
                return 1;
            }
        }
        Read.close();
        return 0;
    }
    else
    {
        Read.close();
        return 0;
    }

}

int main()
{
    Employee EmployeeObject;
    return 0;
}




