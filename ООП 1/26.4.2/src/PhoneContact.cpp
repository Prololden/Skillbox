#include "../include/PhoneContact.h"

PhoneContact::PhoneContact(std::string& name, std::string& number)
{
    isNumberCorrect(number) ? this->number = number : this->number = "0000000000";
    this->name = name;
    std::cout << "New contact is created:\n";
    std::cout << "\t - name: " << name << "\n";
    std::cout << "\t - number: +7" << number << "\n";
}

bool PhoneContact::isNumberCorrect(const std::string& n)
{
    bool numberIsCorrect = true;
    if (n.length() == 10)
    {
        for (char c : n)
        {
            if (c < '0' || c > '9')
            {
                numberIsCorrect = false;
                break;
            }
        }
    }
    else
    {
        numberIsCorrect = false;
    }
    return numberIsCorrect;
}

void PhoneContact::call()
{
    std::cout << "---------------------------------\n";
    std::cout << "CALL: " << name << " : +7" << number << "\n";
    std::cout << "---------------------------------\n";
}

void PhoneContact::sms(std::string& message)
{
    std::cout << "---------------------------------\n";
    std::cout << "SMS: " << name << " : +7" << number << "\n";
    std::cout << message << "\n";
    std::cout << "---------------------------------\n";
}

std::string PhoneContact::getNumber() const
{
    return number;
}

std::string PhoneContact::getName() const
{
    return name;
}

void PhoneContact::setNumber(const std::string& newNumber)
{
    if (isNumberCorrect(newNumber))
    {
        this->number = newNumber;
        std::cout << "New number for " << name << " is +7" << number << "\n";
    }
    else
    {
        std::cerr << "New number has incorrect format.\n";
    }
}

void PhoneContact::setName(const std::string &newName)
{
    this->name = newName;
    std::cout << "New name for number +7" << number << " is " << name << "\n";
}

bool PhoneContact::isEqual(const std::string &nameOrNumber) {
    return (name == nameOrNumber || number == nameOrNumber);
}