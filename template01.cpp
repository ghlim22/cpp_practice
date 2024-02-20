#include <iostream>
template <typename T> 
T const & max(const T &x, const T &y) { return (x > y ? x : y); }

template <typename T = char>
const T &min(const T &x, const T &y) {
    return (x < y ? x : y);
}

int main(void)
{
    int x = 1;
    int y = 2;
    char c1 = 'a';
    char c2 = 'b';

    std::cout << max<int>(x, y) << std::endl;
    std::cout << min<int>(x, y) << std::endl;
    std::cout << min<char>(c1, c2) << std::endl;

    return 0;
}