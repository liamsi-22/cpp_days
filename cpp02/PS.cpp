#include <cmath>
#include <iostream>
#include <string>

bool solution(std::string const &str, std::string const &ending) {
    if (ending.size() > str.size())
        return (false);
    return (str.substr(str.size() - ending.size()) == ending);
}

int main(){

    std::string str = "hello world";
    std::string ending = "d";
    std::cout << solution(str, ending) << std::endl;
}