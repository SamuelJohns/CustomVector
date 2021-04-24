#pragma once

#include <algorithm>
#include <iostream>

template <typename TData>
class CArray
{
public:
  // TODO !!!
  //using data_type TData
  // size_t вместо unsigned int // почитать
  // вернуть конструктор перемещения
  // constexpr size_t для reserve 8
  // assert 
  // перенести reserve 8 
  // insert в позицию size
  // в insert переделать на move // для 
  // в деструктор вставить clear
  
  // Default constructor
  CArray() :
    sz{ 0 }, 
    cpct{ 0 }, 
    arr{ nullptr } 
  {
      
  }

  // Copy constructor
  CArray (
      const CArray& _array
    ) :
      sz{ _array.sz }, 
      cpct{ _array.cpct }, 
      arr{ new TData[_array.cpct] }
  {
    std::copy(_array, _array + sz, arr);
  }

  // Destructor
  ~CArray() 
  {
    clear();
  }

  // Add an element to the end of an array
  void push_back (
      const TData& _value
    )
  {
    if (cpct == 0) 
      reserve(8);
    else if (sz == cpct) 
      reserve(cpct * 2);
    arr[sz] = _value;
    ++sz;
  }

  // Add an element to an array at a given index
  void insert(
      unsigned int _index, 
      const TData& _value
    ) 
  {
    if (_index >= sz) 
      return;

    if (cpct == 0) 
      reserve(8);
    else if (sz == cpct) 
      reserve(cpct * 2);

    for (unsigned int i = sz; i > _index; --i)
      arr[i] = arr[i - 1];
    arr[_index] = _value;
    ++sz;
  }

  // Remove array element at given index
  void erase (
      unsigned int _index
    ) 
  {
    if (_index >= sz)
      return;

    for (unsigned int i = _index; i < sz - 1; ++i)
      arr[i] = arr[i + 1];
    --sz;
  }

  // Clear array
  void clear() 
  {
      delete[] arr;
      arr = nullptr;
      sz = 0;
      cpct = 0;
  }

  // Get the size of an array
  unsigned int size() const 
  {
    return sz;
  }

  // Reserve memory
  void reserve (
      unsigned int _capacity
    ) 
  {
    if (_capacity < sz)
      return;

    TData* tmp = new TData[_capacity];
    for (unsigned int i = 0; i < sz; ++i)
      tmp[i] = arr[i];

    delete[] arr;
    arr = tmp;
    cpct = _capacity;
  }

  void sort ()
  {
    for (unsigned int i = 1; i < sz; ++i)
    {
      for (unsigned int j = 0; j < sz - i; ++j)
      {
        if (arr[j] > arr[j + 1])
        {
          std::swap(arr[j], arr[j + 1]);
        }
      }
    }
  }

  // Get an element of an array at a given index
  TData& operator[] (
      unsigned int _index
    ) 
  {
    // TODO ASSERT _index < size
    // TODO add const version
    return arr[_index];
  }

private: // Attributes
  unsigned int sz;
  unsigned int cpct;
  TData* arr;
};

template <typename T>
void printArray(
    CArray<T>& _arr
  ) 
{
  std::cout << "Array: ";
  for (unsigned int i = 0; i < _arr.size(); ++i)
    std::cout << _arr[i] << " ";
  std::cout << std::endl;
}
