#pragma once

#include <iostream>
#include "CArray.h"

class Tests {
public:
  void run() 
  {
    passed = 0;
    failed = 0;

    checkInsert();

    std::cout << "Passed: " << passed << " , Failed: " << failed;
    std::cout << std::endl << std::endl;
  }

  void checkInsert()
  {
    {
      // Insert at the beginning
      CArray<int> arr{ 0, 1, 2 };
      arr.insert(0, 5);

      CArray<int> arrChk{ 5, 0, 1, 2 };

      bool flag = arr == arrChk;
      calculate(flag);
      std::cout << "Insert at the beginning: " << (flag ? "Passed" : "Failed") << std::endl;
    }
  }

private:
  unsigned int passed;
  unsigned int failed;

  void calculate (
    bool _flag
  )
  {
    if (_flag)
      ++passed;
    else
      ++failed;
  }
};