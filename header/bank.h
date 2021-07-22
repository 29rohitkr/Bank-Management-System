using namespace std;
#include "account.h"
#ifndef BANK_H
#define BANK_H
class Bank
{
private:
    map<long, Account> accounts;

public:
    Bank();
    Account OpenAccount(
        string fName,
        string lName,
        // birthDate dob,
        long phNumber,
        string emailiD,
        // string locality,
        // string postOffice,
        // string district,
        // string state,
        // long pinCode,
        float balance);
    Account BalanceEnquiry(long accountNumber);
    Account Deposit(long accountNumber, float amount);
    Account Withdraw(long accountNumber, float amount);
    void CloseAccount(long accountNumber);
    void ShowAllAccount();
    ~Bank();
};

#endif
