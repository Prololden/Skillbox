#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>
#include <filesystem>

template <typename T>
void printVector(const std::vector<T>& vector)
{
    for (const auto& i: vector)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main()
{
    //Task 1:
    std::cout << "--- Task 1 ---\n";
    for (auto i : {1, 2, 3, 4, 5})
    {
        std::cout << i << " ";
    }
    std::cout << "\n";


    //Task 2:
    std::cout << "--- Task 2 ---\n";
    std::vector<int> numberVector {1, 2, 3, 4, 2, 4, 5, 7, 6, 8, 6};
    std::cout << "Input vector:\n";
    printVector(numberVector);

    //Lambda:
    auto getUnique = [](std::vector<int>& v)->std::unique_ptr<std::vector<int>>
    {
        auto valuesSet = new std::unordered_set<int>();
        auto result = std::make_unique<std::vector<int>>();
        for (auto &i : v) {
            if (valuesSet->insert(i).second)
                result->push_back(i);
            else
                std::cout << "Number " << i << " is repeated.\n";
        }
        return result;
    };

    auto uniqueVector = getUnique(numberVector);
    std::cout << "Unique elements vector:\n";
    printVector(*uniqueVector);

    //Task 3:
    std::cout << "--- Task 3 ---\n";
    auto getFilesWithExtension = [](const std::filesystem::path& path, const std::string& extension)->std::unique_ptr<std::vector<std::filesystem::path>>
    {
        std::cout << "Getting filenames with extension " << extension << " in path " << path << "...\n";
        auto result = std::make_unique<std::vector<std::filesystem::path>>();
        auto* paths = new std::filesystem::recursive_directory_iterator(path);
        for(const auto& p: *paths)
        {
            if (p.is_regular_file())
            {
                if (p.path().extension().compare(extension) == 0)
                {
                    result->push_back(p.path().filename());
                }
            }
        }
        return result;
    };
    std::filesystem::path path = "C:\\TestDir";
    std::string extension = ".txt";
    try
    {
        auto fileNames = getFilesWithExtension(path, extension);
        std::cout << "File names in "<< path  << " with extension "<< extension << ":\n";
        printVector(*fileNames);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what();
    }

    return 0;
}