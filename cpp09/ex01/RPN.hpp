#include <sstream>
#include <stack>
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include <string>



class RPN
{
    private:

    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);

        static int evalRPN(const std::string &arg);

        ~RPN();
};
