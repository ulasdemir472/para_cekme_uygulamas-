#include <iostream>

using namespace std;

class Account
{
private:
    string username;
    int password,balance;
public:
    void set_username(string un)
    {
        username = un;
    }
    void set_password(int pw)
    {
        password = pw;
    }
    void set_balance(int ba)
    {
        balance = ba;
    }

    string get_username()
    {
        return username;
    }
    int get_password()
    {
        return password;
    }
    int get_balance()
    {
        return balance;
    }

    Account(string u,int p,int b)
    {
        username = u;
        password = p;
        balance = b;
    }

};

class Choice
{
public:
    void Para_Cekme(Account account)
    {
        int amount;
        cout<<"Enter amount of money you would like to withdraw : ";
        cin>>amount;
        account.set_balance(account.get_balance()-amount);
        cout<<"Hesabinizda kalan para : "<<account.get_balance();

    }
};

class Login:public Choice
{
public:

    void password_check(Account account)
    {
        int enter_password;
        cout<<"Enter password: ";
        cin>>enter_password;
        if(enter_password==account.get_password())
        {
            cout<<"Giris basarili."<<endl;
            Para_Cekme(account);
        }
        else{
            cout<<"Giris basarisiz.";

        }
    }

};



int main()
{
    Login login;
    Choice choice;
    Account account1("ulas",1111,800);
    Account account2("Peter Parker",9876,12);
    Account account3("Tony Stark",1234,1000000);

    string enter_username;
    Account Accounts[3]={account1,account2,account3};

    cout<<"Enter username: ";
    getline(cin,enter_username);
    for(int i=0;i<3;i++)
    {
        Account temp=Accounts[i];
        if(enter_username==temp.get_username())
        {
            login.password_check(temp);

        }
        else{
            continue;
        }
    }

    return 0;
}
