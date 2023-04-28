
/* ATM Interface.
Data members: Name, acc no., type of acc, balance
Member func: assign initial values, deposit amount, withdraw after checking balance,
display name and balance
 */
#include <iostream>
using namespace std;

class customer
{
private:
    int account_number;
    string account_type;
    int balance;
    int deposit;
    int withdrawal;

public:
    string customer_name;
    void amount(); // assigning initial values
    void deposit_amount();
    void withdraw(); // to withdraw an amount after checking the balance
    void getinfo();  // to display name and balance
    void viewinfo();
};

void customer ::getinfo()
{
    cout << "Enter name: " << endl;
    cin >> customer_name;
    cout << "Enter account number: " << endl;
    cin >> account_number;
    cout << "Enter account type: savings/personal" << endl;
    cin >> account_type;
    cout << "Enter current bank balance: " << endl;
    cin >> balance;
}

void customer ::deposit_amount()
{
    cout << "Enter amount to be deposited: " << endl;
    cin >> deposit;
    balance = balance + deposit;
    cout << "Balance: " << balance << endl;
}

void customer ::withdraw()
{
    cout << "Enter amount to be withdrawn: " << endl;
    cin >> withdrawal;
    try
    {
        // if (withdrawal > 30000)
        //   throw('a');
        if (withdrawal > balance)
            throw(1);
        balance = balance - withdrawal;
        cout << "Amount successfully withdrawn!" << endl;
        cout << "Balance: " << balance << endl;
    }
    catch (int e)
    {
        cout << "Insufficient funds :(" << endl;
    }
    // catch (char a)
    //{
    //   cout << "Withdraw limit for this account is Rs 30,000. Please enter amount less than Rs 30,000." << endl;
    //}
}

void customer ::amount()
{
    cout << "Current balance in your bank account: " << balance << endl;
}
void customer ::viewinfo()
{
    cout << "Your Good name: " << customer_name << endl;
    cout << "Account number: " << account_number << endl;
    cout << "Account type: " << account_type << endl;
    cout << "Bank balance: " << balance << endl;
}
int main()
{
    int x;
    customer sample;
    sample.getinfo();
    do
    {
        cout << "You can do the following things; Enter the appropriate number: " << endl;
        cout << "1) Deposit amount" << endl;
        cout << "2) Withdraw amount" << endl;
        cout << "3) Check current bank balance" << endl;
        cout << "4) View bank details" << endl;
        cout << "5) Quit" << endl;
        cout << "Enter your option: " << endl;
        cin >> x;
        switch (x)
        {
        case 1:
            sample.deposit_amount();
            break;

        case 2:
            sample.withdraw();
            break;

        case 3:
            sample.amount();
            break;

        case 4:
            sample.viewinfo();
            break;

        case 5:
            break;
        }

    } while (x != 5);
    return 0;
}
