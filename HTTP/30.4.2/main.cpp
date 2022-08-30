#include <iostream>
#include <utility>
#include "cpr/cpr.h"



std::pair<bool, std::string> findBetweenTags(const std::string &str, const std::string &open_tag, const std::string &close_tag)
{
    std::size_t begin, end;
    if(str.empty() || open_tag.empty() || close_tag.empty())
        return std::make_pair(false, "invalid parameters");

    begin =  str.find(open_tag);
    if(str.npos != begin)
    {
        end =  str.find(close_tag, begin+open_tag.size()-1);
        if(str.npos == end)
            return std::make_pair(false, "Not found " + close_tag);
    }
    else
    {
        return std::make_pair(false, "Not found " + open_tag);
    }
    begin += open_tag.size();
    end -= begin;
    return std::make_pair(true, str.substr(begin, end));
}

int main()
{

    auto resp = cpr::Get(cpr::Url("http://httpbin.org/html"), cpr::Header{{"accept", "text/html"}});

    if (resp.status_code == 200)
    {
        auto rt = findBetweenTags(resp.text, "<h1>", "</h1>");
        if (rt.first)
        {
            std::cout << rt.second << std::endl;
        }
        else
        {
            std::cout << rt.second << std::endl;
        }
    }
    else
    {
        std::cout << "Error: " << resp.status_code << std::endl;
    }

    return 0;
}