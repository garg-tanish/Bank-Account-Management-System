// Title		: Bank Account Management System
// Language		: C++
// Made By      : Tanish Garg

#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <limits>

using namespace std;
int number;
char key;

class Bank_Account
{
    int Money_Deposit;
    char type;
    int ac_no;
    char name[70];

public:
    void report() const;
    int retMoney_Deposit() const;
    void create_Bank_Account();
    void dep(int);
    int retac_no() const;
    void Display_Account() const;
    void Updation();
    char rettype() const;
    void draw(int);
};

int check(int);

void Bank_Account::Updation()
{
    cout << "\n\tBank_Account No. : " << ac_no;
m:
    cout << "\n\tUpdation Bank_Account Holder Name\n";
    cout << "Warning! Pleases enter character not a number or anything else : ";
    cin.getline(name, 70);
    cin.ignore();
    int len = strlen(name);

    int count = 0;
    for (int i = 0; i <= len - 1; i++)
    {
        if (name[i] == 'a' || name[i] == 'b' || name[i] == 'c' || name[i] == 'd' || name[i] == 'e' || name[i] == 'f' || name[i] == 'g' || name[i] == 'h' || name[i] == 'i' || name[i] == 'j' || name[i] == 'k' || name[i] == 'l' || name[i] == 'm' || name[i] == 'n' || name[i] == 'o' || name[i] == 'p' || name[i] == 'q' || name[i] == 'r' || name[i] == 's' || name[i] == 't' || name[i] == 'u' || name[i] == 'v' || name[i] == 'w' || name[i] == 'x' || name[i] == 'y' || name[i] == 'z' || name[i] == ' ')
        {
            count++;
            if (count == len)
            {
                break;
            }
        }
        else
        {
            goto m;
        }
    }

    cout << "\n\tUpdation Type of Bank_Account\n";
    cout << "Warning! Pleases enter c/s not a number or anything else : ";
    while (!(cin >> key && key == 's' || key == 'S' || key == 'c' || key == 'C'))
    {
    }
    type = toupper(key);
}

void Bank_Account::create_Bank_Account()
{
    system("clear");
    int result, res = 0;
n:
    cout << "\tPlease Enter the Bank_Account Number\n";
    cout << "Warning! Pleases enter number not character or anything else : ";
    while (!(cin >> number))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.clear();
    cin.ignore(100, '\n');

    result = check(number);
    if (result == 1)
    {
        ac_no = number;
    m:
        cout << "\n\tEnter the Name of the Bank_Account holder\n";
        cout << "Warning! Pleases enter character not a number or anything else : ";
        cin.getline(name, 70);
        int len = strlen(name);

        int count = 0;
        for (int i = 0; i <= len - 1; i++)
        {
            if (name[i] == 'a' || name[i] == 'b' || name[i] == 'c' || name[i] == 'd' || name[i] == 'e' || name[i] == 'f' || name[i] == 'g' || name[i] == 'h' || name[i] == 'i' || name[i] == 'j' || name[i] == 'k' || name[i] == 'l' || name[i] == 'm' || name[i] == 'n' || name[i] == 'o' || name[i] == 'p' || name[i] == 'q' || name[i] == 'r' || name[i] == 's' || name[i] == 't' || name[i] == 'u' || name[i] == 'v' || name[i] == 'w' || name[i] == 'x' || name[i] == 'y' || name[i] == 'z' || name[i] == ' ')
            {
                count++;
                if (count == len)
                {
                    break;
                }
            }
            else
            {
                goto m;
            }
        }

        cout << "\n\tEnter Type of the Bank_Account\n";
        cout << "Warning! Pleases enter c/s not a number or anything else : ";
        while (!(cin >> key && key == 's' || key == 'S' || key == 'c' || key == 'C'))
        {
        }
        type = toupper(key);
        cout << "\n\tEnter The Starting Total-Money\n";
        cout << "Warning! Pleases enter number not character or anything else : ";
        while (!(cin >> number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        Money_Deposit = number;
        cout << "\n\n\n\tBank_Account Created....";
    }
}

void Bank_Account::Display_Account() const
{
    cout << "\n\tBank_Account No. : " << ac_no;
    cout << "\n\tBank_Account Holder Name : " << name;
    cout << "\n\tType of Bank_Account : " << type;
    cout << "\n\tBalance Total-Money : " << Money_Deposit;
}

int Bank_Account::retac_no() const
{
    return ac_no;
}

char Bank_Account::rettype() const
{
    return type;
}

void Bank_Account::report() const
{
    cout << setw(4) << ac_no << setw(14) << name << setw(14) << type << setw(15) << Money_Deposit << endl;
}

void Bank_Account::dep(int x)
{
    Money_Deposit += x;
}

void Bank_Account::draw(int x)
{
    Money_Deposit -= x;
}

int Bank_Account::retMoney_Deposit() const
{
    return Money_Deposit;
}

void write_Bank_Account();
void display_sp(int);
void display_all();
void delete_Bank_Account(int);
void Money_Deposit_withdraw(int, int);
void Updation_Bank_Account(int);

void write_Bank_Account()
{
    Bank_Account ac;
    ofstream outFile;
    outFile.open("Bank_Account.txt", ios::binary | ios::app);
    ac.create_Bank_Account();
    outFile.write(reinterpret_cast<char *>(&ac), sizeof(Bank_Account));
    outFile.close();
}

void delete_Bank_Account(int n)
{
    Bank_Account ac;
    ifstream inFile;
    ofstream outFile;
    inFile.open("Bank_Account.txt", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened !! Press any Key...";
        return;
    }
    outFile.open("Temp.txt", ios::binary);
    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Bank_Account)))
    {
        if (ac.retac_no() != n)
        {
            outFile.write(reinterpret_cast<char *>(&ac), sizeof(Bank_Account));
        }
    }
    inFile.close();
    outFile.close();
    remove("Bank_Account.txt");
    rename("Temp.txt", "Bank_Account.txt");
    cout << "\n\nRecord Deleted ..";
}

int check(int n)
{
    Bank_Account ac;
    ifstream inFile;
    inFile.open("Bank_Account.txt", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened !! Press any Key...";
        return 0;
    }
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Bank_Account)))
    {
        if (ac.retac_no() == n)
        {
            cout << "account number already exist";
            return 0;
        }
    }
    inFile.close();
    return 1;
}

void display_sp(int n)
{
    Bank_Account ac;
    bool flag = false;
    ifstream inFile;
    inFile.open("Bank_Account.txt", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened !! Press any Key...";
        return;
    }
    cout << "\n\tBALANCE DETAILS\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Bank_Account)))
    {
        if (ac.retac_no() == n)
        {
            ac.Display_Account();
            flag = true;
        }
    }
    inFile.close();
    if (flag == false)
        cout << "\n\n\tBank_Account number does not exist";
}

void display_all()
{
    system("clear");
    Bank_Account ac;
    ifstream inFile;
    inFile.open("Bank_Account.txt", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened !! Press any Key...";
        return;
    }
    cout << "\n\n\t\tBank_Account HOLDER LIST\n\n";
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!========\n";
    cout << "A/c no.        NAME          Type        Balance\n";
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!========\n";
    while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Bank_Account)))
    {
        ac.report();
    }
    inFile.close();
}

void Updation_Bank_Account(int n)
{
    bool found = false;
    Bank_Account ac;
    fstream File;
    File.open("Bank_Account.txt", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be opened !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(Bank_Account));
        if (ac.retac_no() == n)
        {
            ac.Display_Account();
            cout << "\n\n\tPlease Enter The New Details of Bank_Account" << endl;
            ac.Updation();
            int pos = (-1) * static_cast<int>(sizeof(Bank_Account));
            File.seekp(pos, ios::cur); // fncallat1353
            File.write(reinterpret_cast<char *>(&ac), sizeof(Bank_Account));
            cout << "\n\n\tRecord Updated....";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n\tRecord Not Found ";
}

void Money_Deposit_withdraw(int n, int option)
{
    int amt;
    bool found = false;
    Bank_Account ac;
    fstream File;
    File.open("Bank_Account.txt", ios::binary | ios::in | ios::out);
    if (!File)
    {
        cout << "File could not be opened !! Press any Key...";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&ac), sizeof(Bank_Account));
        if (ac.retac_no() == n)
        {
            ac.Display_Account();
            if (option == 1)
            {
                cout << "\n\n\tTO Money_Deposit Total-Money";
                cout << "\n\tWarning! Please Enter The Total-Money to be Money_Deposited: ";
                while (!(cin >> number))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.clear();
                cin.ignore(100, '\n');
                amt = number;
                ac.dep(amt);
            }
            if (option == 2)
            {
                cout << "\n\n\tTO WITHDRAW Total-Money";
                cout << "\n\tWarning! Please Enter The Total-Money to be withdraw: ";
                while (!(cin >> number))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cin.clear();
                cin.ignore(100, '\n');
                amt = number;
                int bal = ac.retMoney_Deposit() - amt;
                if (bal < 0)
                    cout << "Insufficience balance";
                else
                    ac.draw(amt);
            }
            int pos = (-1) * static_cast<int>(sizeof(ac));
            File.seekp(pos, ios::cur);
            File.write(reinterpret_cast<char *>(&ac), sizeof(Bank_Account));
            cout << "\n\n\tRecord Updated....";
            found = true;
        }
    }
    File.close();
    if (found == false)
        cout << "\n\n\tRecord Not Found ";
}

int main()
{
    char ch;
    int num;
    do
    {
        int number;
        system("clear");
        cout << "\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!\n\n";
        cout << "\t\tBANK MANAGEMENT SYSTEM\n";
        cout << "\n\t\t!!!!!!!!!!!!!!!!!!!!!!!\n\n";

        cout << "\t\t    ::MAIN MENU::\n";
        cout << "\n\t\t1. NEW Bank_Account";
        cout << "\n\t\t2. Money_Deposit Total-Money";
        cout << "\n\t\t3. WITHDRAW Total-Money";
        cout << "\n\t\t4. BALANCE ENQUIRY";
        cout << "\n\t\t5. ALL Bank_Account HOLDER LIST";
        cout << "\n\t\t6. CLOSE AN Bank_Account";
        cout << "\n\t\t7. Updation AN Bank_Account";
        cout << "\n\t\t8. EXIT";
        cout << "\n\n\t\tSelect Your Option (1-8): ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            write_Bank_Account();
            break;
        case '2':
            system("clear");
            cout << "\tEnter The Bank_Account Number\n";
            cout << "Warning! Pleases enter number not character or anything else : ";
            while (!(cin >> number))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.clear();
            cin.ignore(100, '\n');
            num = number;
            Money_Deposit_withdraw(num, 1);
            break;
        case '3':
            system("clear");
            cout << "\tEnter The Bank_Account Number\n";
            cout << "Warning! Pleases enter number not character or anything else : ";
            while (!(cin >> number))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.clear();
            cin.ignore(100, '\n');
            num = number;
            Money_Deposit_withdraw(num, 2);
            break;
        case '4':
            system("clear");
            cout << "\tEnter The Bank_Account Number\n";
            cout << "Warning! Pleases enter number not character or anything else : ";
            while (!(cin >> number))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.clear();
            cin.ignore(100, '\n');
            num = number;
            display_sp(num);
            break;
        case '5':
            display_all();
            break;
        case '6':
            system("clear");
            cout << "\tEnter The Bank_Account Number\n";
            cout << "Warning! Pleases enter number not character or anything else : ";
            while (!(cin >> number))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.clear();
            cin.ignore(100, '\n');
            num = number;
            delete_Bank_Account(num);
            break;
        case '7':
            system("clear");
            cout << "\tEnter The Bank_Account Number\n";
            cout << "Warning! Pleases enter number not character or anything else : ";
            while (!(cin >> number))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.clear();
            cin.ignore(100, '\n');
            num = number;
            Updation_Bank_Account(num);
            break;
        case '8':
            system("clear");
            break;
        default:
            cout << "wrong choice ";
        }
        cin.ignore();
        cin.get();
    } while (ch != '8');
    return 0;
}