#include "../include/Phone.h"

void Phone::add(std::string name, std::string number)
{
    if (!PhoneContact::isNumberCorrect(number))
    {
        std::cerr << "New number has incorrect format.\n";
        return;
    }

    if (!contactList.empty())
    {
        for (PhoneContact& c : contactList)
        {
            if (c.isEqual(name))
            {
                std::cout << "Name " << name
                          << " is already registered in contact list.\nUpdate number for it (yes / no)?\n";
                std::string answer;
                std::getline(std::cin, answer);
                if (answer == "yes")
                {
                    c.setNumber(number);
                }
                return;
            }
            else if (c.isEqual(number))
            {
                std::cout << "Number +7" << number
                          << " is already registered for the name " << c.getName()
                          << ".\n Update the name? (yes / no)\n";
                std::string answer;
                std::getline(std::cin, answer);
                if (answer == "yes")
                {
                    c.setName(name);
                }
                return;
            }
        }
    }
    auto* contact = new PhoneContact(name, number);
    contactList.push_back(*contact);
    std::cout << "Contact is added to contact list: " << name << ", +7" << number << "\n";
    delete contact;
    contact = nullptr;
}

void Phone::contacts()
{
    if (contactList.empty())
    {
        std::cout << "\t - No contacts in the list\n";
    }
    else
    {
        for (PhoneContact& c : contactList)
        {
            std::cout << "\t - " << c.getName() << " : +7" << c.getNumber() << "\n";
        }
    }
}

void Phone::call(std::string nameOrNumber) {
    for (PhoneContact& c : contactList)
    {
        if (c.isEqual(nameOrNumber))
        {
            c.call();
            return;
        }
        std::cout << "Such name or number is not found in contact list.\n";
    }
}

void Phone::sms(std::string& nameOrNumber, std::string& message)
{
    for (PhoneContact& c : contactList)
    {
        if (c.isEqual(nameOrNumber))
        {
            c.sms(message);
            return;
        }
        std::cout << "Such name or number is not found in contact list.\n";
    }
}