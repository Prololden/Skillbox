#ifndef TASK_33_3_DATA_H
#define TASK_33_3_DATA_H
#include <iostream>

template <typename KeyType, typename ValueType>
struct Data
{
public:
    KeyType key;
    ValueType value;

    Data(){};
    Data(KeyType key, ValueType value) : key(key), value(value){};
};

#endif //TASK_33_3_DATA_H