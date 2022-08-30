#include <iostream>
#include "include/Phone.h"

int main() {
    std::cout << "Phone simulation is started\n";
    Phone phone;
    std::cout << "\t- Phone is initialized\n";
    std::cout << "---------------------------\n";
    std::string cmd;
    do
    {
        std::cout << "Please enter the command (call, add, sms, contacts, exit):\n";
        std::getline(std::cin, cmd);
        if (cmd == "add")
        {
            std::cout << "--- Adding new contact ---\n";
            std::cout << "\t - Please enter the name: ";
            std::string name;
            std::getline(std::cin, name);
            std::cout << "\t - Please enter the number: +7";
            std::string number;
            std::getline(std::cin, number);

            phone.add(name, number);
        }
        else if (cmd == "call")
        {
            if (phone.contactListIsEmpty())
            {
                std::cout << "No contacts in the list. Please add any contact.\n";
                continue;
            }
            std::cout << "--- Calling the contact ---\n";
            std::cout << "\t - Please enter the name or number (after +7): ";
            std::string nameOrNumber;
            std::getline(std::cin, nameOrNumber);
            phone.call(nameOrNumber);
        }
        else if (cmd == "sms")
        {
            if (phone.contactListIsEmpty())
            {
                std::cout << "No contacts in the list. Please add any contact.\n";
                continue;
            }
            std::cout << "--- Sending sms to the contact ---\n";
            std::cout << "\t - Please enter the name or number (after +7): ";
            std::string nameOrNumber;
            std::getline(std::cin, nameOrNumber);
            std::cout << "\t - Please enter the message: ";
            std::string message;
            std::getline(std::cin, message);
            phone.sms(nameOrNumber, message);
        }
        else if (cmd == "contacts")
        {
            if (phone.contactListIsEmpty())
            {
                std::cout << "No contacts in the list. Please add any contact.\n";
                continue;
            }
            std::cout << "--- Contacts ---\n";
            phone.contacts();

        }
        else if (cmd != "exit")
        {
            std::cerr << "Bad command, please try again.\n";
        }
    } while (cmd != "exit");
    std::cout << "--- Exit the program ---\n";
    std::cout << "Program is finished.\n";
    return 0;
}