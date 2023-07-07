#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main ()
{
    int choice;
    string phone, email, keyword, identifier, ip, name;

    cout<< "Enter:\n1 for phone number validation\n2 for email validation\n3 for identifier validation \n4 for IP validation\n5 for name validation \n6 to exit: ";
    cin>> choice;

    switch(choice)
    {
    case 1:
        cout<< "\nEnter phone number: ";
        cin>> phone;

        if (regex_match (phone, regex("(\\+977)?[9][6-9]\\d{8}") ))
            cout << "Valid phone number";
        else
            cout<< "Not a valid phone number";
        break;

    case 2:
        cout<< "\nEnter email address: ";
        cin>> email;

        if (regex_match (email, regex("^([a-zA-Z0-9_\\-\\.]+)@([a-zA-Z0-9_\\-]+)(\\.[a-zA-Z]{2,5}){1,2}$") ))
            cout << "Valid email address";
        else
            cout<< "Not a valid email address";
        break;

    case 3:
        cout<< "\nEnter identifier: ";
        cin>> identifier;

        if (regex_match (identifier, regex("^([a-zA-Z_$][a-zA-Z\\d_$]*)$")))
            cout << "Valid Identifier";
        else
            cout<< "Not a valid identifier";
        break;

    case 4:
        cout<< "\nEnter ip address: ";
        cin>> ip;

        if (regex_match (ip, regex("^\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1}$")))
            cout << "Valid IP address";
        else
            cout<< "Not a valid IP address";
        break;

    case 5:
        cout<< "\nEnter name: ";
        cin>> name;

        if (regex_match (name, regex("^[A-Z][a-z]*([\s-][A-Z][a-z]*)*$")))
            cout << "Valid Name";
        else
            cout<< "Not a valid Name";
        break;

    case 6:
        exit(0);
    default:
        exit(0);
    }

    return 0;
}


