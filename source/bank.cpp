#include <iostream>
#include <map>
#include <fstream>
#include "../header/account.h"
#include "../header/bank.h"
#include "../header/error.h"
#include "../header/main.h"

using namespace std;


Bank::Bank()
{
    Account account;

    streampos begin, end;
    ifstream infile("bank.data", ios::binary);
    begin = infile.tellg();
    infile.seekg(0, ios::end);
    end = infile.tellg();
    infile.close();
    int fileSize = end - begin;
    //ifstream infile;
    if (fileSize > 1)
    {
        infile.open("bank.data");

        while (!infile.eof())
        {
            infile >> account;
            accounts.insert(pair<long, Account>(account.getAccNo(), account));
        }
        Account::setLastAccountNumber(account.getAccNo());
    }
    else
    {
        return;
    }
    infile.close();
}
//======================================================================

Account Bank::OpenAccount(
    string fName,
    string lName,
    // birthDate dob,
    long phNumber,
    string email,
    // string locality,
    // string postOffice,
    // string district,
    // string state,
    // long pinCode,
    float balance)
{
    ofstream outfile;
    //Account account(fName, lName, dob, phNumber, email, locality, postOffice, district, state, pinCode, 
    //balance);

    Account account(fName, lName, phNumber, email, balance);
    accounts.insert(pair<long, Account>(account.getAccNo(), account));
    outfile.open("bank.data", std::ios::trunc);

    map<long, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        outfile << itr->second;
    }
    outfile.close();
    return account;
}

//====================================================================

Account Bank::BalanceEnquiry(long accountNumber)
{
    map<long, Account>::iterator itr = accounts.find(accountNumber);
    return itr->second;
}
//====================================================================

Account Bank::Deposit(long accountNumber, float amount)
{
    map<long, Account>::iterator itr = accounts.find(accountNumber);
    itr->second.Deposit(amount);
    return itr->second;
}

//==================================================================
Account Bank::Withdraw(long accountNumber, float amount)
{
    map<long, Account>::iterator itr = accounts.find(accountNumber);
    itr->second.Withdraw(amount);
    return itr->second;
}

//=================================================================

void Bank::CloseAccount(long accountNumber)
{
    map<long, Account>::iterator itr = accounts.find(accountNumber);
    cout << "Accounts Deleted " << endl
         << itr->second;
    accounts.erase(accountNumber);
}
//==================================================================
void Bank::ShowAllAccount()
{
    streampos begin, end;
    ifstream infile("bank.data", ios::binary);
    begin = infile.tellg();
    infile.seekg(0, ios::end);
    end = infile.tellg();
    int fileSize = end - begin;
    if (fileSize < 1)
    {
        cout << "File Is Empty";
        return;
    }
    map<long, Account>::iterator itr;

    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        cout << "Account : " << itr->first << endl;
        cout << itr->second << endl;
        cout << "==================================\n";
    }
}
//===========================================================================

Bank::~Bank()
{
    ofstream outfile;
    outfile.open("bank.data", std::ios::trunc);
    map<long, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        outfile << itr->second;
    }
    outfile.close();
}