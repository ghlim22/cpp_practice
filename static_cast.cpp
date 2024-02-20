
#include <iostream>
#include <string>
class Base {
public:
  Base(int num) : mNum(num){};
  virtual ~Base(){};
  int getNum() const { return mNum; };

private:
  int mNum;
};

class Left : public Base {
public:
  Left(int leftNum) : Base(0), mLeftNum(leftNum){};
  int GetLeftNum() const { return mLeftNum; };

private:
  int mLeftNum;
};

class Right : public Base {
public:
  Right(int rightNum) : Base(1), mRightNum(rightNum){};
  int GetRightNum() const { return mRightNum; };

private:
  int mRightNum;
};

int main(void) {
  Left leftObj(7);
  Right rightObj(8);

  std::cout << "static_cast" << std::endl;
  {
    Base &baseThroughLeft = static_cast<Base &>(leftObj);
    Right &rightThroughBaseLeft = static_cast<Right &>(baseThroughLeft);

    std::cout << rightThroughBaseLeft.getNum() << ' '
              << rightThroughBaseLeft.GetRightNum() << std::endl;
  }

  std::cout << "dynamic_cast" << std::endl;
  {
    Base &baseThroughLeft = dynamic_cast<Base &>(leftObj);
    Right &rightThroughBaseLeft = dynamic_cast<Right &>(baseThroughLeft); // run-time exception!

    std::cout << rightThroughBaseLeft.getNum() << ' '
              << rightThroughBaseLeft.GetRightNum() << std::endl;
  }

  return 0;
}