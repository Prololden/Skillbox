#ifndef TASK_26_2_PHONE_H
#define TASK_26_2_PHONE_H

#include "PhoneContact.h"
#include <iostream>
#include <vector>


class Phone {
private:
    std::vector<PhoneContact> contactList {};
public:

    void add(std::string name, std::string number);

    void call(std::string nameOrNumber);


    void sms(std::string& nameOrNumber, std::string& message);

    void contacts();

    bool contactListIsEmpty()
    {
        return contactList.empty();
    }
};

#endif //TASK_26_2_PHONE_H