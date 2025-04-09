#include "utilities.hpp"

std::string stringReplace(const std::string& line, const std::string& s1, const std::string& s2)
{
    std::string result;
    size_t  pos = 0;
    size_t find = 0;

    if (s1.empty()) {
        return (line);
    }

    while((find = line.find(s1, pos)) != std::string::npos)
    {
        result.append(line, pos, find - pos);
        result.append(s2);
        pos = find + s1.length();
    }
    result.append(line, pos , line.length() - pos);

    return (result);
}

int fileManipulation(const std::string& fileName, const std::string& s1, const std::string& s2){
    std::string line;

    std::ifstream input(fileName);
    if (!input)
    {
        std::cout << "error : cannot open a file " << fileName << std::endl;
        return 1;
    }

    std::ofstream output(fileName + ".replace");
    if (!output)
    {
        std::cout << "error : cannot creat a file " << fileName << ".replace" << std::endl;
        return 1;
    }

    while (std::getline(input, line)){
        output << stringReplace(line, s1, s2) << std::endl;
    }

    input.close();
    output.close();
    return (0);
}
