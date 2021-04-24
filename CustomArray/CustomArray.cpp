#include "CArray.h"
#include <random>
#include <string>
#include <iostream>

int getRandomInRange(
  int _min,
  int _max
)
{
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(_min, _max);
  return distr(gen);
}

std::string random_string(
    size_t _length
  )
{
  auto randchar = []() -> char
  {
    const char charset[] = "abcdefghijklmnopqrstuvwxyz";
    int randCharPos = getRandomInRange(0, sizeof(charset) - 1);
    return charset[randCharPos];
  };
  std::string str(_length, 0);
  std::generate_n(str.begin(), _length, randchar);
  return str;
}

bool contain(
    const std::string& _source, 
    const std::string& _rule
  ) 
{
  for (unsigned int i = 0; i < _rule.length(); ++i) {
    if (_source.find(_rule.at(i)) != std::string::npos) {
      return true;
    }
  }
  return false;
}

int main()
{
  {
    CArray<int> arr;
    // 1.1
    {
      std::cout << "1.1 Insert 20 random numbers from 0 to 100 : " << std::endl;

      for (int i = 0; i < 20; ++i)
        arr.push_back(getRandomInRange(0, 100));

      printArray(arr);
    }

    //1.2
    {
      std::cout << std::endl << "1.2 Sort " << std::endl;

      arr.sort();

      printArray(arr);
    }

    //1.3
    {
      std::cout << std::endl << "1.3 Remove every second item :  " << std::endl;

      unsigned int maxPos = arr.size() / 2;
      for (unsigned int i = 1; i <= maxPos; ++i)
        arr.erase(i);

      printArray(arr);
    }

    // 1.4
    {
      std::cout << std::endl << "1.4 Insert 10 random numbers from 0 to 100 in random positions : " << std::endl;

      int randPos, randValue;
      for (int i = 0; i < 10; ++i) 
      {
        randPos = getRandomInRange(0, arr.size() - 1);
        randValue = getRandomInRange(0, 100);
        arr.insert(randPos, randValue);
      }

      printArray(arr);
    }

    // 1.5
    {
      std::cout << std::endl << "1.5 Clear : " << std::endl;

      arr.clear();
        
      printArray(arr);
      std::cout << "size " << arr.size();
      std::cout << std::endl << std::endl;
    }
  }

  {
    CArray<std::string> arr;
    // 2.1
    {
      std::cout << std::endl << "2.1 Insert 15 random strings : " << std::endl;

      for (int i = 0; i < 15; ++i)
        arr.push_back(random_string(5));

      printArray(arr);
    }

    // 2.2
    {
      std::cout << std::endl << "2.2 Sort " << std::endl;

      arr.sort();

      printArray(arr);
    }

    // 2.3
    {
      std::cout << std::endl << "2.3 Remove all words containing the following characters : 'a','b','c','d','e' :" << std::endl;

      std::string rule = "abcde";
      unsigned int i = 0;
      while (i < arr.size()) 
      {
        if (contain(arr[i], rule)) 
        {
          arr.erase(i);
        }
        else 
        {
           ++i;
        }
      }

      printArray(arr);
    }

    // 2.4
    {
      std::cout << std::endl << "2.4 Insert 3 random words in random positions : " << std::endl;

      int randPos;
      for (int i = 0; i < 3; ++i) 
      {
        randPos = getRandomInRange(0, arr.size() - 1);
        arr.insert(randPos, random_string(5));
      }

      printArray(arr);
    }
  }
}