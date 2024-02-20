#include <iostream>
struct A {
  A() { std::cout << "Default constructor" << std::endl; };
  A(const int val) : val(val) {
    std::cout << "Conversion from int constructor" << std::endl;
  };
  explicit A(const A &other) : val(other.val) {

    std::cout << "explicit copy constructor" << std::endl;
  };
  ~A(){};
  operator double() const {
    std::cout << "user defined conversion function (to double)" << std::endl;
    return 2 * val;
  };
  int val;

private:
  A &operator=(const A &rhs) { return *this; };
};

int main() {
  A a;
  A b(12);
  A c = b; // a -> double(a) -> c = A(int(double(b)))
  std::cout << "a->val: " << a.val << std::endl;
  std::cout << "b->val: " << b.val << std::endl;
  std::cout << "c->val: " << c.val << std::endl;
  return 0;
}