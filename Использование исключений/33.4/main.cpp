#include <iostream>

template <typename T>
double getAverage(T* array, int length)
{
    double result {0};
    for (int i = 0; i < length; ++i)
    {
        result += *(array + i);
    }
    result /= length;
    return result;
}

template <typename T>
void getFromCin(T* array, int length)
{
    std::cout << "Please enter value (1 per line):\n";
    std::string input;
    for (int i = 0; i < length; ++i)
    {
        std::getline(std::cin, input);
        try
        {
            if (std::is_same<T, int>())
            {
                *(array + i) = std::stoi(input);
            }
            else if (std::is_same<T, float>())
            {
                *(array + i) = std::stof(input);
            }
            else if (std::is_same<T, double>())
            {
                *(array + i) = std::stod(input);
            }
            else
            {
                std::cin >> *(array + i);
            }
        }
        catch (...)
        {
            std::cerr << "Type is not supported. Please use int, float or double types.\n";
        }
    }
}

int main()
{
    int arrayInteger[5] {0};
    int length {5};
    double average {0};

    std::cout << "Please enter 5 integer values:\n";
    getFromCin(arrayInteger, length);
    average = getAverage(arrayInteger, length);
    std::cout << "Average is: " << average << "\n";

    double arrayDouble[5]{0};
    std::cout << "Please enter 5 double values:\n";
    getFromCin(arrayDouble, length);
    average = getAverage(arrayDouble, length);
    std::cout << "Average is: " << average << "\n";

    return 0;
}