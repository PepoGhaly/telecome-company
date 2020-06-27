#include <iostream>
#include<string>
#include <ctime>
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
using namespace std;
struct date {
    int day, month, year;
};

struct line
{
    int mobile, pakge;
    double balance = 0;
    date start, renewal;
};
struct user
{
    long long ID;
    string name, email, password, adress;
    line phone[3];
    int num_of_phones = 0;
};
void recharge(double& balance) {
    double balance_recharge, cnt = 0;
    long long serial;
recharge:cout << "enter recharge serial" << endl;
    cin >> serial;
    cnt = 0;
    while (serial > 0) {
        serial /= 10;
        cnt++;
    }
    if (cnt == 14) {
        cout << "Enter Recharge amount \n";
        cin >> balance_recharge;
        balance += balance_recharge;
        cout << "Recharge successfully" << endl << "Your new balance is " << balance << "EGP \n";
    }
    else {
        cout << "Sreial invalid" << endl;
        goto recharge;
    }
}
bool pakage(double& balance, int& pakage, date& date) {
    cout << "select your Package:" << endl << "1: felx 25" << endl << "2: flex 30" << endl << "3: flex 50" << endl << "4: flex 100 \n";
    cin >> pakage;
    if (pakage == 1) {
        if (balance >= 25) {
            balance -= 25;
            time_t     rawtime;
            struct tm* timeinfo;
            time(&rawtime);
            timeinfo = localtime(&rawtime);
            date.day = timeinfo->tm_mday;
            date.month = (timeinfo->tm_mon) + 2;
            date.year = timeinfo->tm_year - 100;
            if (date.month == 13) {
                date.month = 1; date.year++;
            }
            cout << "your renewal date is " << date.day << "/" << date.month << "/" << date.year << endl;

            return 0;
        }
        else {
            return 1;
        }
    }
    else if (pakage == 2) {
        if (balance >= 30) {
            balance -= 30;
            time_t     rawtime;
            struct tm* timeinfo;
            time(&rawtime);
            timeinfo = localtime(&rawtime);
            date.day = timeinfo->tm_mday;
            date.month = (timeinfo->tm_mon) + 2;
            date.year = timeinfo->tm_year - 100;
            if (date.month == 13) {
                date.month = 1; date.year++;
            }
            cout << "your renewal date is " << date.day << "/" << date.month << "/" << date.year << endl;
            return 0;
        }
        else {
            return 1;
        }
    }
    else if (pakage == 3) {
        if (balance >= 50) {
            balance -= 50;
            time_t     rawtime;
            struct tm* timeinfo;
            time(&rawtime);
            timeinfo = localtime(&rawtime);
            date.day = timeinfo->tm_mday;
            date.month = (timeinfo->tm_mon) + 2;
            date.year = timeinfo->tm_year - 100;
            if (date.month == 13) {
                date.month = 1; date.year++;
            }
            cout << "your renewal date is " << date.day << "/" << date.month << "/" << date.year << endl;
            return 0;
        }
        else {
            return 1;
        }
    }
    else if (pakage == 4) {
        if (balance >= 100) {
            balance -= 100;
            time_t     rawtime;
            struct tm* timeinfo;
            time(&rawtime);
            timeinfo = localtime(&rawtime);
            date.day = timeinfo->tm_mday;
            date.month = (timeinfo->tm_mon) + 2;
            date.year = timeinfo->tm_year - 100;
            if (date.month == 13) {
                date.month = 1; date.year++;
            }
            cout << "your renewal date is " << date.day << "/" << date.month << "/" << date.year << endl;
            return 0;
        }
        else {
            return 1;
        }
    }
}
int main()
{
    user user[100];
    int user_select = 0, user_max = 1, phone_select = 0;
    string service;
    char ans;
start:cout << "Enter your ID:" << endl;
    cin >> user[user_select].ID;
    for (int i = 0; i < user_max; i++) {
        if (i == user_select) {
            continue;
        }
        if (user[i].ID == user[user_select].ID) {
            cout << "This ID is exists you can't Make two accounts\n";
            if (user[i].num_of_phones < 3) {
                cout << "Press 1 to add phone to your account\n";
                cin >> service;
                phone_select = i;
            }
            else {
                cout << "You can't have another phone number\n";
                goto start;
            }
        }
    }
    if (service[0] == '1') {
        goto phone;
    }
    else { phone_select = 0; }
    cout << "Enter your Name:" << endl;
    cin.ignore();
    getline(cin, user[user_select].name);
email:cout << "Enter your email:" << endl;
    cin >> user[user_select].email;
    for (int i = 0; i < user_max; i++) {
        if (i == user_select) {
            continue;
        }
        if (user[i].email == user[user_select].email) {
            cout << "Invalid this Email is exists you can't Make two accounts \n";
            goto email;
        }
    }
    cout << "Enter your Password:" << endl;
    cin >> user[user_select].password;
    cout << "Enter your Adress:" << endl;
    cin.ignore();
    getline(cin, user[user_select].adress);
    do {
    phone:cout << "Enter your Phone number:  +20";
        cin >> user[user_select].phone[phone_select].mobile;
        for (int i = 0; i < user_max; i++) {
            if (i == user_select) {
                continue;
            }
            for (int j = 0; j < 3; j++) {
                if (user[i].phone[phone_select].mobile == user[user_select].phone[j].mobile) {
                    cout << "Invalid this Phone is exists \n Please ";
                    goto phone;
                }
            }
        }
        user[user_select].num_of_phones++;
        time_t     rawtime;
        struct tm* timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        user[user_select].phone[phone_select].start.day = timeinfo->tm_mday;
        user[user_select].phone[phone_select].start.month = timeinfo->tm_mon + 1;
        user[user_select].phone[phone_select].start.year = timeinfo->tm_year - 100;
        if (user[user_select].phone[phone_select].start.month == 13) {
            user[user_select].phone[phone_select].start.month = 1;
            user[user_select].phone[phone_select].start.year++;
        }
        cout << "Do you have another number ?\n";
        cin >> ans;
        if (ans == 'Y' || ans == 'y') {
            phone_select++;
            if (user[user_select].num_of_phones >= 3) {
                cout << "You can't have more than 3 numbers" << endl;
                ans = 'n';
            }
            else
                goto phone;
        }
    } while (ans == 'Y' || ans == 'y');
    if (user[user_select].num_of_phones > 1) {
    phone_select:cout << "Choose which numer you want to make operation" << endl;
        for (int i = 0; i < user[user_select].num_of_phones; i++) {
            cout << i + 1 << ": +20" << user[user_select].phone[i].mobile << endl;
        }
        cin >> phone_select; phone_select--;
    }
    if (phone_select <= user[user_select].num_of_phones) {
        cout << "Your Balance is " << user[user_select].phone[phone_select].balance << "EGP \n";
        if (user[user_select].phone[phone_select].balance == 0) {
        recharge:cout << "Please recharge" << endl;
            recharge(user[user_select].phone[phone_select].balance);
        }
        if (pakage(user[user_select].phone[phone_select].balance, user[user_select].phone[phone_select].pakge, user[user_select].phone[phone_select].renewal) == 1) {
            cout << "your Balance is not enough";
            goto recharge;
        }
    operations:cout << "1: recharge \n2: change your pakage \n3: make a call \n4: send a message \n5: transfere Balance \n";
        cin >> service;
        if (service[0] == '1') {
            recharge(user[user_select].phone[phone_select].balance);
        }
        else if (service[0] == '2') {
            if (pakage(user[user_select].phone[phone_select].balance, user[user_select].phone[phone_select].pakge, user[user_select].phone[phone_select].renewal) == 1) {
                cout << "your Balance is not enough \n";
                goto recharge;
            }
        }
        else if (service[0] == '3') {
            int number;
            cout << "enter the number \n";
            cin >> number;
            user[user_select].phone[phone_select].balance -= 0.25;
            cout << "Successful call\n";
        }
        else if (service[0] == '4') {
            int number;
            cout << "enter the number \n";
            cin >> number;
            string message;
            cout << "enter message: \n";
            cin.ignore();
            getline(cin, message);
            user[user_select].phone[phone_select].balance -= 0.25;
        }
        else if (service[0] == '5') {
            int number, user_index, phone_index;
        num:cout << "enter the number  +20";
            cin >> number;
            bool found = 0;
            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 3; j++) {
                    if (user[i].phone[j].mobile == number) {
                        found = 1;
                        user_index = i;
                        phone_index = j;
                        break;
                    }
                }
            }
            if (found == 1) {
            amount:cout << "enter the amount \n";
                int amount;
                cin >> amount;
                if (amount < user[user_select].phone[phone_select].balance) {
                    user[user_select].phone[phone_select].balance -= amount;
                    user[user_index].phone[phone_index].balance += amount;
                    cout << "balance tarnsfered successfully \n";

                }
                else {
                    cout << "your balance is not enough please try again \n";
                    goto amount;
                }
            }
            else {
                cout << "the number is not found please try again \n";
                goto num;
            }

        }

    }
    else {
        cout << "invalid" << endl;
        goto phone_select;
    }
    cout << "Do you want to make another operation? Y/N \n";
    cin >> ans;
    if (ans == 'Y' || ans == 'y') {
        cout << "Same user??  Y/N \n";
        cin >> ans;
        if (ans == 'Y' || ans == 'y') {
            if (user[user_select].num_of_phones > 1) {
                cout << "select one \n";
                for (int i = 0; i < user[user_select].num_of_phones; i++) {
                    cout << i + 1 << ": +02" << user[user_select].phone[i].mobile << endl;
                }
                cin >> phone_select; phone_select--;
                goto operations;
            }
            else {
                phone_select = 0; goto operations;
            }
        }
        else {
            cout << "1: Create nwe user \n2: Use a saved user \n";
            cin >> service;
            if (service[0] == '1') {
                user_max++;
                user_select = user_max - 1;
                service = { "0" };
                goto start;
            }
            else {
            Username:cout << "Enter User Name: ";
                getline(cin, service);
                bool found = 0;
                for (int i = 0; i < user_max; i++) {
                    if (user[i].name == service) {
                        user_select = i;
                        found = 1;
                    }
                }
                if (found == 0) {
                    cout << "Invalid user name not found\n";
                    goto Username;
                }
            Pass:cout << "\nEnter Password:";
                getline(cin, service);
                cout << endl;
                if (service == user[user_select].password) {
                    cout << "select one \n";
                    for (int i = 0; i < user[user_select].num_of_phones; i++) {
                        cout << i + 1 << ": +20" << user[user_select].phone[i].mobile << endl;
                    }
                    cin >> phone_select; phone_select--;
                    goto operations;
                }
                else {
                    cout << "Invalid Password \n";
                    goto Pass;
                }
            }
        }
    }
    else {
        return 0;
    }
}