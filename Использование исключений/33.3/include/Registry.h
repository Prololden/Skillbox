#ifndef TASK_33_3_REGISTRY_H
#define TASK_33_3_REGISTRY_H
#include <iostream>
#include <vector>
#include "Data.h"

template <typename KeyType, typename ValueType>
class Registry
{
private:
    std::vector<Data<KeyType, ValueType>> base;

public:

    void add(Data<KeyType, ValueType> data);

    void add(KeyType key, ValueType value);

    void remove (KeyType key);

    void print();

    Data<KeyType, ValueType>* find (KeyType key);
};

template<typename KeyType, typename ValueType>
void Registry<KeyType, ValueType>::add(Data<KeyType, ValueType> data)
{
    base.push_back(data);
    std::cout << "Element \"" << data.key << " : " << data.value << "\" is added.\n";
}

template<typename KeyType, typename ValueType>
void Registry<KeyType, ValueType>::print()
{
    if (base.empty())
    {
        std::cout << "Registry base is empty.\n";
        return;
    }
    std::cout << "Registry base:\n";
    for (auto it = base.begin(); it != base.end(); ++it)
    {
        std::cout << "\t + " << it->key << " : " << it->value << "\n";
    }
}

template<typename KeyType, typename ValueType>
void Registry<KeyType, ValueType>::add(KeyType key, ValueType value)
{
    Data<KeyType, ValueType>* data = new Data<KeyType, ValueType>(key, value);
    this->base.push_back(*data);
    std::cout << "Element \"" << data->key << " : " << data->value << "\" is added.\n";
    delete data;
}

template<typename KeyType, typename ValueType>
void Registry<KeyType, ValueType>::remove(KeyType key)
{
    int removeCount {0};
    for (auto it = base.begin(); it != base.end();)
    {
        if (it->key == key)
        {
            std::cout << "Element \"" << it->key << " : " << it->value << "\" is removed.\n";
            it = base.erase(it);
            ++removeCount;
        }
        else
        {
            ++it;
        }
    }
    if (removeCount == 0)
        std::cout << "Key \"" << key << "\" is not found.\n";
}

template<typename KeyType, typename ValueType>
Data<KeyType, ValueType> *Registry<KeyType, ValueType>::find(KeyType key) {
    for (size_t i = 0; i < base.size(); ++i)
    {
        if (base[i].key == key) return &base[i];
    }
    std::cout << "Key is not found.\n";
    return nullptr;
}


#endif //TASK_33_3_REGISTRY_H