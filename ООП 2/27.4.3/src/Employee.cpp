#include "../include/Employee.h"

int Employee::Count = 0;

int Employee::getId()
{
    return id;
}

void Employee::setId(const int id)
{
    this->id = id;
}

Employee::Employee() {
    ++Count;
    setId(Count);
}

int Employee::getIntFromCin(int min, int max)
{
    std::string buffer;
    std::getline(std::cin, buffer);
    int result = 0;
    try
    {
        result = std::stoi(buffer);
        if (result < min || result > max)
        {
            result = 0;
            throw -1;
        }
    }
    catch(int)
    {
        std::cerr << "Wrong number (not between " << min << " and " << max << ")!\n";
    }
    catch(...)
    {
        std::cerr << "Error while getting integer from input!\n";
    }
    return result;
}

std::string Employee::getTaskTypeString(TaskType taskType)
{
    switch (taskType)
    {
        case TASK_A:
            return "A";
        case TASK_B:
            return "B";
        case TASK_C:
            return "C";
        case NO_TASK:
            return "[no task]";
        default:
            return "[not defined]";
    }
}