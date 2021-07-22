#include <bits/stdc++.h>
#include "../header/bank.h"
#include "../header/account.h"
#include "../header/main.h"
#include "../header/error.h"

using namespace std;

// ofstream &operator<<(ofstream &ofs, birthDate &dob)
// {
//     ofs << dob.day << dob.month << dob.year << endl;
//     return ofs;
// }
ofstream &operator<<(ofstream &ofs, Account &acc)
{
    ofs << acc.getAccNo() << endl;
    ofs << acc.getFullName() << endl;
    ofs << acc.getphNumber() << endl;
    ofs << acc.getEmailId() << endl;
    // ofs << acc.getDob() << endl;
    // ofs << acc.getFullAddressF() << endl;
    ofs << acc.getBalance() << endl;
    return ofs;
}

ifstream &operator>>(ifstream &ifs, Account &acc)
{
    ifs >> acc.accountNumber;
    ifs >> acc.firstName >> acc.lastName;
    acc.fullName = acc.firstName + " " + acc.lastName;
    ifs >> acc.phoneNumber;
    ifs >> acc.emailId;
    // ifs >> acc.dob.day >> acc.dob.month >> acc.dob.year;
    // ifs >> acc.address.locality >> acc.address.postOffice >> acc.address.district >> acc.address.state >> 
    // acc.address.pinCode;
    //ifs >> 
    ifs >> acc.balance;
    return ifs;
}
ostream &operator<<(ostream &out, Account &acc)
{
    out << "\tAccount Number : " << acc.getAccNo() << endl;
    out << "\tFull Name      : " << acc.getFullName() << endl;
    out << "\tPhone Number   : " << acc.getphNumber() << endl;
    out << "\tEmail Id       : " << acc.getEmailId() << endl;
    //out << "\tD.O.B          : " << acc.getDob() << endl;
    //out << "\tFull Address   : " << acc.getFullAddressP() << endl;
    out << "\tBalance        : " << acc.getBalance() << endl;
    return out;
}

// ostream &operator<<(ostream &out, birthDate dob){
//     out << dob.day << "/";
//     out << dob.month << "/";
//     out << dob.year << endl;
//     return out;
// }
//out << "\tFirst Name     : " << acc.getFirstName() << endl;
//out << "\tLast Name      : " << acc.getLastName() << endl;
//out << "\tDate of Birth  : " <<


int main()
{
    Bank b;
    Account acc;

    int choice = 0;
    string fName = "", lName = "";
    long phNumber;
    string emailId;
    long accountNumber;
    float balance;
    float amount;
    // string locality = "";
    // string postOffice = "";
    // string district = "";
    // string state = "";
    // birthDate dob = {00 , 00, 0000};
    // long pinCode = 123456;

    cout << "\t****** BANKING SYSTEM ******" << endl;
    do{
        cout << "\n\t| Select One Option below |";
        cout << "\n\t| 1. Open An Account.     |";
        cout << "\n\t| 2. Balance Enquiry.     |";
        cout << "\n\t| 3. Deposit.             |";
        cout << "\n\t| 4. Withdraw.            |";
        cout << "\n\t| 5. Close An Account.    |";
        cout << "\n\t| 6. Show All Accounts.   |";
        cout << "\n\t| 7. Quit.                |";
        cout << "\n Enter Your Choice :  ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter First Name : ";
                cin >> fName;
                cout << "Enter Last Name  : ";
                cin >> lName;
                // cout << "Enter Date of birth (dd mm yyyy) : ";
                // cin >> dob.day >> dob.month >> dob.year;
                cout << "Enter your Phone Number : +91-";
                cin >> phNumber;
                cout << "Enter yout Email Id : ";
                cin >> emailId;
                // cout << "Enter Your Address : " ;
                // cin >> locality >> postOffice >> district >> state >> pinCode;
                cout << "Enter Initial Balance : ";
                cin >> balance;
                
                // acc = b.OpenAccount(fName, lName, dob, phNumber, emailId, locality,
                // postOffice, district, state, pinCode, balance);
                acc = b.OpenAccount(fName, lName, phNumber, emailId, balance);
                cout << endl << "Congratulation Account is Created." <<endl;
                cout << acc;
                break;
            case 2:
                cout << "Enter Account Number : ";
                cin >> accountNumber;
                acc = b.BalanceEnquiry(accountNumber);
                cout << "Your Account Details " << endl;
                cout << acc;
                break;
            case 3:
                cout << "Enter Account Number : ";
                cin >> accountNumber;
                cout << "Enter Balance : ";
                cin >> amount;
                acc = b.Deposit(accountNumber, amount);
                cout << endl << "Amount is Deposited." <<endl;
                cout << acc;
                break;
            case 4:
                cout << "Enter Account Number : ";
                cin >> accountNumber;
                cout << "Enter Balance : ";
                cin >> amount;
                acc = b.Withdraw(accountNumber, amount);
                cout << endl <<"Amount Withdrawn" <<endl;
                cout << acc;
                break;
            case 5:
                cout << "Enter Account Number :";
                cin >> accountNumber;
                b.CloseAccount(accountNumber);
                cout << endl << "Account is closed"<<endl;
                //cout << acc;
                break;
            case 6:
                b.ShowAllAccount();
                break;
            case 7: break;

            default:
                cout << "\nEnter Correct Choice, Try Again!";
                exit(0);          
            
        }
        
    }while( choice != 7);
    return 0;
}
