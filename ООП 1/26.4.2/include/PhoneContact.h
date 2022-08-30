#ifndef TASK_26_2_PHONECONTACT_H
#define TASK_26_2_PHONECONTACT_H

#include <iostream>


class PhoneContact {
    std::string number;
    std::string name;

public:
    PhoneContact(std::string& name, std::string& number);

    static bool isNumberCorrect(const std::string& n);


    void call();


    void sms(std::string& message);


    std::string getNumber() const;


    std::string getName() const;


    void setNumber(const std::string& newNumber);


    void setName(const std::string& newName);


    bool isEqual(const std::string& nameOrNumber);
};

#endif //TASK_26_2_PHONECONTACT_H