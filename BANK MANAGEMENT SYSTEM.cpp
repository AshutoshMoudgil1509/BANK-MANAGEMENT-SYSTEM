#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
class Bank{
    protected:
    const string mIFSC;
    const string mbranchName;
    const string mAddress;
    const int mbranchCode;

    public:
    Bank() : mIFSC("IFC12345XYZ"), mbranchName("ROPAR"), mAddress(" COLLEGE ROAD , RUPNAGAR(PUNJAB)"), mbranchCode(1234) {}
};
class Account : public Bank{
    protected:
    unsigned long long mAccountNumber;
    string mAccountHolderName;
    int mBalance;
    int mPin;
    public:
    Account( const string &name,int balance,int pin, unsigned long long accountNumber):
    mAccountHolderName(name),mBalance(balance),mPin(pin),mAccountNumber(accountNumber){}
    void createAccount( const string &name){
        if (name.empty()) {
        cout << "Error: Account holder name cannot be empty.\n";
        return;
        }
        if (name.length() > 50) {  
        cout << "Warning: The account holder name is unusually large. Please consider shortening it.\n";
        }
        mAccountHolderName = name;

        srand(time(0));
        int min = 1000;
        int max = 9999;
        mPin = min + rand() % (max - min + 1);

        unsigned long long Min = 10000000000ULL;
        unsigned long long Max = 99999999999ULL;
        mAccountNumber = Min + (rand() * (RAND_MAX + 1ULL) + rand()) % (Max - Min + 1);

        cout<<"ACCOUNT CREATED SUCCESSFULLY.\n";
    }
    void deposit(){
        int balance ;
        cout<<"HOW MUCH MONEY WANT TO DEPOSIT.\n";
        cin>>balance;
        if(balance == 0){
            cout<<"Deposit 0 money.\n";
            return;
        }
        if (balance < 0) {
            cout << "Invalid deposit amount.\n";
            return;
        }
        if(balance > 10000000){
            cout<<"Warning: You are depositing a very large amount. Please double-check the amount.\n";
            return ;
        }
        mBalance += balance;
        cout<<"MONEY DEPOSITED SUCCESSFULLY.\n";
    }
    void withdrawal(){
        int mWithdrawal;
        cout<<"HOW MUCH MONEY WANT TO WITHDRAWAL.\n";
        cin>>mWithdrawal;
        if (mWithdrawal < 0) {
            cout << "Invalid withdrawal amount.\n";
            return;
        }
        if (mWithdrawal> mBalance) {
            cout << "INSUFFICIENT BALANCE.\n";
        } 
        if(mWithdrawal > 600000){
            cout<<"Warning. You are withdrawing a very large amount. Please double-check the amount.\n";
            return;
        }
        else {
            mBalance -= mWithdrawal;
            cout << "MONEY WITHDRAWN SUCCESSFULLY.\n";
        }
    }
    int checkBalance(){
        int currentBalance = mBalance;
        cout<<"CURRENT BALANCE : "<<currentBalance<<endl;
        return currentBalance;
    }
    void updateAccHolderName (string &name){
        string newName;
        cout<<"Enter the New Account Holder Name.\n";
        getline(cin >> ws, newName);
        if (name.empty()) {
        cout << "Error: Account holder name cannot be empty.\n";
        return;
        }
        if (name.length() > 50) {  
        cout << "Warning: The account holder name is unusually large. Please consider shortening it.\n";
        return;
        }
        mAccountHolderName = newName;
        cout<<"Account Holder Name updated.\n";
    }
    void updatePin(int pin){
        int newPin;
        cout<<"Enter the New Pin.\n";
        cin>>newPin;
        if(newPin == 0000){
            cout<<"Pin is too Weak.TRY AGAIN.\n";
            return ;
        }
        mPin= newPin;
        cout<<"Pin Updated.\n";
    }
    int checkPin(){
        cout<<"Your Pin."<<mPin<<endl;
        return mPin;
    }
    void updateDetails(string name,int pin){
        int choice1;
        do{
            cout<<"1.Update Account Holder Name.\n2.Update Pin.\n";
            cout<<"3.EXIT.\n";
            cout<<"Enter the Choice.\n";
            cin>>choice1;
            switch(choice1){
                case 1:
                updateAccHolderName(name);
                break;
                case 2:
                updatePin(pin);
                break;
                case 3:
                cout<<"EXIT.\n";
                break;
                default:
                cout<<"Invalid Choice.Pleasa try again.\n";
            }
        }while(choice1 != 3);
    }
    void checkDetails(){
        cout<<"YOUR BANK DETAILS.\n";
        cout<<"IFSC : "<<mIFSC<<endl;
        cout<<"BRANCH : "<<mbranchName<<endl;
        cout<<"BRANCH CODE : "<<mbranchCode<<endl;
        cout<<"ACCOUNT NUMBER : "<<mAccountNumber<<endl;
        cout<<"ACCOUNT HOLDER NUMBER : "<<mAccountHolderName<<endl;
        cout<<"ADDRESS : "<<mAddress<<endl;
    }

};

int main(){
    Account bank("Unknown",0,0,0);
    int pin ,balance;
    unsigned long long accountNumber;
    string name;
    int choice;
    do{
        cout<<"\n...BANK MANAGEMENT SYSTEM...\n";
        cout<<"1.CREATE ACCOUNT.\n";
        cout<<"2.DEPOSIT MONEY.\n";
        cout<<"3.WITHDRAWAL MONEY.\n";
        cout<<"4.CHECK BALANCE.\n";
        cout<<"5.UPDATE DETAILS.\n";
        cout<<"6.CHECK DETAILS.\n";
        cout<<"7.CHECK PIN.\n";
        cout<<"8.EXIT.\n";
        cout<<"Enter The Choice.\n ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter the Name.\n";
            getline(cin >> ws, name);
            bank.createAccount(name);
            break;
            case 2:
            bank.deposit();
            break;
            case 3:
            bank.withdrawal();
            break;
            case 4:
            bank.checkBalance();
            break;
            case 5:
            bank.updateDetails(name,pin);
            break;
            case 6:
            bank.checkDetails();
            break;
            case 7:
            bank.checkPin();
            break;
            case 8:
            cout<<"EXITING PROGRAM..\n";
            break;
            default:
            cout<<"Invalid choice.Please try again.\n";
        }
    }while(choice != 8);
    return 0;
}