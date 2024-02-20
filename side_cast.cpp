#include <iostream>

struct BaseClass {
  virtual const char *behave() = 0;
};

struct Left : BaseClass {
  virtual const char *behave() { return "Left"; }
};

struct Right : BaseClass {
  virtual const char *behave() { return "Right"; }
};

struct MostDerived : Left, Right {};

int main() {
  MostDerived *mostDerived = new MostDerived();
  // implicit upcast through the diamond results in a compile-time error,
  // ambiguous: BaseClass * baseClass = mostDerived;

  //BaseClass *basePtr = dynamic_cast<Left *>(mostDerived);

  Left *left = mostDerived;
  BaseClass *baseClassThroughLeft = left; // or, equivalently:
  // BaseClass * baseClassThroughLeft = reinterpret_cast<Left*>(mostDerived);
  Right *right = mostDerived;
  BaseClass *baseClassThroughRight = right;

  // this is of course ambiguous and does not compile
  // std::cout << mostDerived->behave() << std::endl;

  // note, only the right has a pointer value of 8 more
  // the two BaseClass pointers point to the same as left,
  // as does mostDerived
  std::cout << "left:  " << left << std::endl
            << "right: " << right << std::endl
            << mostDerived << std::endl
            << baseClassThroughRight << std::endl
            << baseClassThroughLeft << std::endl;

  std::cout << "Cast Left BaseClass * expression to Right *" << std::endl;
  std::cout << "with static_cast, behaves as "
            << static_cast<Right *>(baseClassThroughLeft)->behave()
            << " at addr: " << static_cast<Right *>(baseClassThroughLeft)
            << std::endl;
  std::cout << "with dynamic_cast, behaves as "
            << dynamic_cast<Right *>(baseClassThroughLeft)->behave()
            << " at addr: " << dynamic_cast<Right *>(baseClassThroughLeft)
            << std::endl;

  std::cout << "Cast Right BaseClass * expression to Left *" << std::endl;
  std::cout << "with static_cast, behaves as "
            << static_cast<Left *>(baseClassThroughRight)->behave()
            << " at addr: " << static_cast<Left *>(baseClassThroughRight)
            << std::endl;
  std::cout << "with dynamic_cast, behaves as "
            << dynamic_cast<Left *>(baseClassThroughRight)->behave()
            << " at addr: " << dynamic_cast<Left *>(baseClassThroughRight)
            << std::endl;

  delete mostDerived;
  return 0;
}
