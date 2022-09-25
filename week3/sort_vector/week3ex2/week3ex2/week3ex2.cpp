#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <iterator> 

int main() {
    std::string s1 = "aa";
    std::string s2 = "bb";
    std::string s3 = "ccc";
    std::string s4 = "dddd";
    std::string s5 = "eeee";
    std::string s6 = "eeff";
    std::string s7 = "eeef";

    std::vector<std::string> v = { s5, s4, s1, s7, s2, s6, s3 };
    std::sort(v.begin(), v.end(), [](std::string s_first, std::string s_second){
        if (s_first.std::string::size() != s_second.std::string::size()) {
            return ((s_first.std::string::size() < s_second.std::string::size()));
        }
        else {
            return (s_first < s_second);
        }
                });

    for (auto i : v)
    {
        std::cout << i << '\n';
    }
    std::cout << std::endl;


}