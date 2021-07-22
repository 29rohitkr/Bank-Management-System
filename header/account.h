
using namespace std;

#ifndef ACCOUNT_H
#define ACCOUNT_H

struct birthDate{
        int day;
        int month;
        int year;
};
struct fullAddress
{
    string locality;
    string postOffice;
    string district;
    string state;
    long pinCode;
};

class Account
{
private:
    long accountNumber;
    string firstName;
    string lastName;
    string fullName;
    float balance;
    long phoneNumber;
    string emailId;
    int age;
    birthDate dob;
    fullAddress address;
    
    static long NextAccountNumber;

public:
    Account() {}
    Account(
        string fName,
        string lName,
        // birthDate dob,
        long pnNumber,
        string email,
        // string locality,
        // string postOffice,
        // string district,
        // string state,
        // long pinCode,
        float balance
        );
    long getAccNo();
    string getFirstName();
    string getLastName();
    string getFullName();
    long getphNumber();
    string getEmailId();
    // string getFullAddressP(); // for Printing on Screen
    // string getFullAddressF(); // for printing in file
    float getBalance();
    // birthDate getDob();
    // int getAge();

    void Deposit(float amount);
    void Withdraw(float amount);
    static void setLastAccountNumber(long accountNumber);
    static long getLastAccountNumber();

    // input output stream Overloading
    friend ofstream &operator<<(ofstream &ofs, Account &acc);
    friend ifstream &operator>>(ifstream &ifs, Account &acc);
    friend ostream &operator<<(ostream &out, Account &acc);
};
#endif