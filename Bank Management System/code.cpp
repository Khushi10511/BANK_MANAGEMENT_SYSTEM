#include <iostream>
#include <iomanip>
using namespace std;
struct bank
{
    long accno;
    string name;
    double balance;

} arr[100];
void createAccount(int i)
{
    cin.ignore(1, '\n');
    cout << "Enter Account Holder's Name: ";
    getline(cin, arr[i].name);
    cout << "Enter Account Number: ";
    cin >> arr[i].accno;
    cout << "Enter Initial Balance: $";
    cin >> arr[i].balance;
    cout << "Account created successfully." << endl;
}
void deposit(int n)
{
    long s;
    int i, flag = 0;
    cout << "\nEnter the account no :";
    cin >> s;
    for (int j = 1; j <= n; j++)
    {
        if (arr[j].accno == s)
        {
            i = j;
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "\nAccount not found!!";
    else
    {
        double d;
        cout << "\nEnter the amount of money you want to deposit :";
        cin >> d;
        arr[i].balance += d;
        cout << fixed << setprecision(2);
        cout << "\nThe new balance is :" << arr[i].balance;
    }
}
void withdraw(int n)
{
    long s;
    int i, flag = 0;
    cout << "\nEnter the account no :";
    cin >> s;
    for (int j = 1; j <= n; j++)
    {
        if (arr[j].accno == s)
        {
            i = j;
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "\nAccount not found!!";
    else
    {
        double d;
        cout << "\nEnter the amount of money you want to withdraw :";
        cin >> d;
        if (arr[i].balance < d)
            cout << "\nInsufficient Balance!!!";
        else
        {
            arr[i].balance -= d;
            cout << fixed << setprecision(2);
            cout << "\nThe new balance is :" << arr[i].balance;
        }
    }
}
void close(int n)
{
    long s;
    int i, flag = 0;
    cout << "\nEnter the account no :";
    cin >> s;
    for (int j = 1; j <= n; j++)
    {
        if (arr[j].accno == s)
        {
            i = j;
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "\nAccount not found!!";
    else
    {
        arr[i].accno = 0;
        arr[i].name = " ";
        arr[i].balance = 0.0;
        cout << "\nAccount deleted successfully!!";
    }
}
void balance(int n)
{
    long s;
    int i, flag = 0;
    cout << "\nEnter the account no :";
    cin >> s;
    for (int j = 1; j <= n; j++)
    {
        if (arr[j].accno == s)
        {
            i = j;
            flag = 1;
        }
    }
    if (flag == 0)
        cout << "\nAccount not found!!";
    else
    {
        cout << "\nAccount no :" << arr[i].accno;
        cout << "\nAccount holder :" << arr[i].name;
        cout << fixed << setprecision(2);
        cout << "\nAccount Balance :" << arr[i].balance;
    }
}

int main()
{
    int choice, n = 0;
    cout << "\n\n\t\t....................BANKING SYSTEM MENU.........................." << endl;
    while (true)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Close Account" << endl;
        cout << "5. Balance Enquiry" << endl;
        cout << "6. Exit" << endl;
        cout << "-------------------------------------------------------------------------------------------------------\n"
             << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
            n++;
        switch (choice)
        {
        case 1:
            createAccount(n);
            break;
        case 2:
            deposit(n);
            break;
        case 3:
            withdraw(n);
            break;
        case 4:
            close(n);
            break;
        case 5:
            balance(n);
            break;
        case 6:
            return 0;
            break;
        default:
            cout << "\nInvalid choice!!!!";
        }
    }
    return 1;
}
