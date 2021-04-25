#pragma once

#include <iostream>
#include "CArray.h"

class Tests {
public:
  void run() 
  {
    passed = 0;
    failed = 0;

    checkDefaultConstructor();
    checkInitializationListConstructor();
    checkCopyConstructor();
    checkPushBack();
    checkInsert();
    checkErase();
    checkClear();
    checkReserve();
    checkSort();

    std::cout << "Passed: " << passed << " , Failed: " << failed;
    std::cout << std::endl << std::endl;
  }

  void checkDefaultConstructor()
  {
    CArray<int> arr;

    bool flag = arr.size() == 0 &&
                arr.capacity() == 0;

    calculate(flag);
    std::cout << "Default constructor: " << (flag ? "Passed" : "Failed") << std::endl;
  }

  void checkInitializationListConstructor()
  {
    // Check initialization list constructor of integers
    {
      CArray<int> arr{ 0, 1, 2 };

      bool flag = arr[0] == 0 && 
                  arr[1] == 1 &&
                  arr[2] == 2;

      calculate(flag);
      std::cout << "Initialization list constructor of integers: " << (flag ? "Passed" : "Failed") << std::endl;
    }

    // Check initialization list constructor of std::string
    {
      CArray<std::string> arr{ "0", "1", "2" };

      bool flag = arr[0] == "0" &&
        arr[1] == "1" &&
        arr[2] == "2";

      calculate(flag);
      std::cout << "Initialization list constructor of std::string: " << (flag ? "Passed" : "Failed") << std::endl;
    }
  }

  void checkCopyConstructor()
  {
    // Check copy constructor of integers
    {
      CArray<int> arr{ 0, 1, 2 };
      CArray<int> arrCmpr(arr);

      bool flag = arr == arrCmpr &&
                  arr.size() == arrCmpr.size() &&
                  arr.capacity() == arrCmpr.capacity();

      calculate(flag);
      std::cout << "Copy constructor of integers: " << (flag ? "Passed" : "Failed") << std::endl;
    }

    // Check copy constructor of std::string
    {
      CArray<std::string> arr{ "0", "1", "2" };
      CArray<std::string> arrCmpr(arr);

      bool flag = arr == arrCmpr &&
                  arr.size() == arrCmpr.size() &&
                  arr.capacity() == arrCmpr.capacity();

      calculate(flag);
      std::cout << "Copy constructor of std::string: " << (flag ? "Passed" : "Failed") << std::endl;
    }
  }

  void checkPushBack() {
    // Push back for empty array
    {
      CArray<int> arr;
      arr.push_back(5);
      bool flag = arr[0] == 5 &&
                  arr.size() == 1;

      calculate(flag);
      std::cout << "Push back for empty array: " << (flag ? "Passed" : "Failed") << std::endl;
    }

    // Push back for non empty array
    {
      CArray<int> arr { 0, 1, 2, 3, 4 };
      arr.push_back(5);
      CArray<int> arrCmpr{ 0, 1, 2, 3, 4, 5 };

      bool flag = arr == arrCmpr &&
                  arr.size() == arrCmpr.size();

      calculate(flag);
      std::cout << "Push back for non empty array: " << (flag ? "Passed" : "Failed") << std::endl;
    }
  }
  void checkInsert()
  {
    // Insert at the beginning
    {
      CArray<int> arr{ 0, 1, 2 };
      arr.insert(0, 5);
      CArray<int> arrCmpr{ 5, 0, 1, 2 };

      bool flag = (arr == arrCmpr) &&
                  arr.size() == arrCmpr.size();

      calculate(flag);
      std::cout << "Insert at the beginning: " << (flag ? "Passed" : "Failed") << std::endl;
    }

    // Insert at the end
    {
      CArray<int> arr{ 0, 1, 2 };
      arr.insert(3, 5);
      CArray<int> arrCmpr{ 0, 1, 2, 5 };

      bool flag = (arr == arrCmpr) &&
        arr.size() == arrCmpr.size();

      calculate(flag);
      std::cout << "Insert at the end: " << (flag ? "Passed" : "Failed") << std::endl;
    }

    // Insert in the middle
    {
      CArray<int> arr{ 0, 1, 2 };
      arr.insert(1, 5);
      CArray<int> arrCmpr{ 0, 5, 1, 2 };

      bool flag = (arr == arrCmpr) &&
        arr.size() == arrCmpr.size();

      calculate(flag);
      std::cout << "Insert in the middle: " << (flag ? "Passed" : "Failed") << std::endl;
    }

    // Insert into empty array
    {
      CArray<int> arr;
      arr.insert(0, 5);
      CArray<int> arrCmpr{ 5 };

      bool flag = (arr == arrCmpr) &&
        arr.size() == arrCmpr.size();

      calculate(flag);
      std::cout << "Insert into empty array: " << (flag ? "Passed" : "Failed") << std::endl;
    }
  }

  void checkErase()
  {
    // Erase first element for integers
    {
      CArray<int> arr{ 0, 1, 2 };
      arr.erase(0);
      CArray<int> arrCmpr{ 1, 2 };
      
      bool flag = (arr == arrCmpr) &&
        arr.size() == arrCmpr.size();

      calculate(flag);
      std::cout << "Erase first element for integers: " << (flag ? "Passed" : "Failed") << std::endl;
    }

    // Erase first element for std::string
    {
      CArray<std::string> arr{ "0", "1", "2" };
      arr.erase(0);
      CArray<std::string> arrCmpr{ "1", "2" };

      bool flag = (arr == arrCmpr) &&
                  arr.size() == arrCmpr.size();

      calculate(flag);
      std::cout << "Erase first element for std::string: " << (flag ? "Passed" : "Failed") << std::endl;
    }

    // Erase last element for integers
    {
      CArray<int> arr{ 0, 1, 2 };
      arr.erase(2);
      CArray<int> arrCmpr{ 0, 1 };

      bool flag = (arr == arrCmpr) &&
        arr.size() == arrCmpr.size();

      calculate(flag);
      std::cout << "Erase last element for integers: " << (flag ? "Passed" : "Failed") << std::endl;
    }

    // Erase last element for std::string
    {
      CArray<std::string> arr{ "0", "1", "2" };
      arr.erase(2);
      CArray<std::string> arrCmpr{ "0", "1" };

      bool flag = (arr == arrCmpr) &&
                  arr.size() == arrCmpr.size();

      calculate(flag);
      std::cout << "Erase last element for std::string: " << (flag ? "Passed" : "Failed") << std::endl;
    }

    // Erase element in the middle for integers
    {
      CArray<int> arr{ 0, 1, 2 };
      arr.erase(1);
      CArray<int> arrCmpr{ 0, 2 };

      bool flag = (arr == arrCmpr) &&
                  arr.size() == arrCmpr.size();

      calculate(flag);
      std::cout << "Erase element in the middle for integers: " << (flag ? "Passed" : "Failed") << std::endl;
    }

    // Erase element in the middle for std::string
    {
      CArray<std::string> arr{ "0", "1", "2" };
      arr.erase(1);
      CArray<std::string> arrCmpr{ "0", "2" };

      bool flag = (arr == arrCmpr) &&
                  arr.size() == arrCmpr.size();

      calculate(flag);
      std::cout << "Erase element in the middle for std::string: " << (flag ? "Passed" : "Failed") << std::endl;
    }
  }

  void checkClear()
  {
    CArray<std::string> arr{ "0", "1", "2" };
    arr.clear();

    bool flag = arr.size() == 0 &&
                arr.capacity() == 0;

    calculate(flag);
    std::cout << "Clear: " << (flag ? "Passed" : "Failed") << std::endl;
  }

  void checkReserve()
  {
    // Reserve of capacity bigger than size for integers
    {
      CArray<int> arr{ 0, 1, 2 ,3 };
      CArray<int> arrCmpr{ 0, 1, 2 ,3 };
      unsigned int sz = arr.size();
      unsigned int expectedCapacity = 5;
      arr.reserve(expectedCapacity);

      bool flag = arr.size() == sz &&
                  arr.capacity() == expectedCapacity &&
                  arr == arrCmpr;

      calculate(flag);
      std::cout << "Reserve of capacity bigger than size for integers: " << (flag ? "Passed" : "Failed") << std::endl;
    }

    // Reserve of capacity bigger than size for std::string
    {
      CArray<std::string> arr{ "0", "1", "2" ,"3" };
      CArray<std::string> arrCmpr{ "0", "1", "2" ,"3" };
      unsigned int sz = arr.size();
      unsigned int expectedCapacity = 5;
      arr.reserve(expectedCapacity);

      bool flag = arr.size() == sz &&
        arr.capacity() == expectedCapacity &&
        arr == arrCmpr;

      calculate(flag);
      std::cout << "Reserve of capacity bigger than size for std::string: " << (flag ? "Passed" : "Failed") << std::endl;
    }

    // Reserve of capacity less than size for integers
    {
      CArray<int> arr{ 0, 1, 2 ,3 };
      CArray<int> arrCmpr{ 0, 1, 2 ,3 };
      unsigned int sz = arr.size();
      unsigned int cpct = arr.capacity();
      arr.reserve(1);

      bool flag = arr.size() == sz &&
                  arr.capacity() == cpct && 
                  arr == arrCmpr;

      calculate(flag);
      std::cout << "Reserve of capacity less than size for integers: " << (flag ? "Passed" : "Failed") << std::endl;
    }

    // Reserve of capacity less than size for std::string
    {
      CArray<std::string> arr{ "0", "1", "2" ,"3" };
      CArray<std::string> arrCmpr{ "0", "1", "2" ,"3" };
      unsigned int sz = arr.size();
      unsigned int cpct = arr.capacity();
      arr.reserve(1);

      bool flag = arr.size() == sz &&
        arr.capacity() == cpct &&
        arr == arrCmpr;

      calculate(flag);
      std::cout << "Reserve of capacity less than size for std::string: " << (flag ? "Passed" : "Failed") << std::endl;
    }
  }

  void checkSort()
  {
    // Sort for integers
    {
      CArray<int> arr{ 0, 8, 1 ,7, 2, 6, 3, 5, 4 };
      CArray<int> arrCmpr{ 0, 1, 2 ,3, 4, 5, 6, 7, 8 };
      arr.sort();

      bool flag = arr == arrCmpr;

      calculate(flag);
      std::cout << "Sort for integers: " << (flag ? "Passed" : "Failed") << std::endl;
    }

    // Sort for std::string
    {
      CArray<std::string> arr{ "aaa", "hhh", "bbb" ,"iii", "ccc", "ggg", "ddd", "fff", "eee" };
      CArray<std::string> arrCmpr{ "aaa", "bbb", "ccc", "ddd", "eee", "fff", "ggg", "hhh", "iii" };
      arr.sort();

      bool flag = arr == arrCmpr;

      calculate(flag);
      std::cout << "Sort for std::string: " << (flag ? "Passed" : "Failed") << std::endl;
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