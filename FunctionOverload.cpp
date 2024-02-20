#include <iostream>
int max(double x, double y) {
    if (x >= y)
        return x;
    return y;
}
int max(int x, int y) {
    if (x >= y)
        return x;
    return y;
}

int main(void)
{
    std::cout << max(3.14, 1.0) << std::endl;
    return 0;
}