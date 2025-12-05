My_exception::My_exception(const std::string &msg): _msg(msg){}

My_exception::~My_exception() throw() {}

const char *My_exception::what() const throw() {
    return _msg.c_str();
}

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator x = std::find(container.begin(), container.end(), value);
    if (x == container.end())
        throw My_exception("The item could not be found in container !");
    return (x);
}