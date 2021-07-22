#include <iostream>
#include "../header/account.h"
#include "../header/error.h"
#include "../header/main.h"
using namespace std;
//  Account Class Methods Defination

long Account::NextAccountNumber = 0;

long Account::getAccNo() { 
    return this->accountNumber; 
}

string Account::getFirstName() 
{ 
    return this->firstName; 
}

string Account::getLastName() 
{
    return this->lastName;
}

string Account::getFullName()
{
    return this->fullName;
}

long Account::getphNumber()
{
    return this->phoneNumber;
}

string Account::getEmailId()
{
    return this->emailId;
}
// string Account::getFullAddressP()
// {
//     string address_ = address.locality + ", " + address.postOffice + ",\n\t\t\t " + address.district + ", " + address.state + 
//     ", " + to_string(address.pinCode);
//     return address_;
// }
// string Account::getFullAddressF()
// {
//     string address_ = address.locality + " " + address.postOffice + " " + address.district + " " + address.state +
//                       " " + to_string(address.pinCode);
//     return address_;
// }

// birthDate Account::getDob(){
//     return this->dob;
// }
float Account::getBalance()
{ 
    return this->balance;
}
// int Account::getAge()
// {
//     // statement to get today date and subtract dob date from it.
// }

Account::Account(
    string fName,
    string lName,
    // birthDate dob,
    long phNumber,
    string email,
    /*string locality,
    string postOffice,
    string district,
    string state,
    long pinCode,*/
    float balance)
{
    NextAccountNumber++;
    this->accountNumber = NextAccountNumber;
    this->firstName = fName;
    this->lastName = lName;
    this->fullName = fName + " " + lName;
    // this->dob.day = dob.day;
    // this->dob.month = dob.month;
    // this->dob.year = dob.year;
    this->phoneNumber = phNumber;
    this->emailId = email;
    // this->address.locality = locality;
    // this->address.postOffice = postOffice;
    // this->address.district = district;
    // this->address.state = state;
    // this->address.pinCode = pinCode;
    this->balance = balance;
}

void Account::Deposit(float amount)
{
    balance += amount;
}

void Account::Withdraw(float amount)
{
    if ((this->balance) - (amount) < minBalance)
    {
        throw InsufficientFund();
    }
    balance -= amount;
}

void Account::setLastAccountNumber(long accountNumber)
{
    NextAccountNumber = accountNumber;
}

long Account::getLastAccountNumber()
{
    return NextAccountNumber;
}
