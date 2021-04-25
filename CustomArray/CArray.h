#pragma once

#include <algorithm>
#include <iostream>
#include <cassert>

template <typename TData>
class CArray
{
public:
  using value_type = TData;
  // TODO !!!

  // size_t вместо unsigned int // почитать
  // вернуть конструктор перемещения
  // constexpr size_t для reserve 8
  // assert 
  // перенести reserve 8 
  // insert в позицию size
  
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
      arr{ new value_type[_array.cpct] }
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
      const value_type& _value
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
      const value_type& _value
    ) 
  {
    assert(_index < sz);

    if (cpct == 0) 
      reserve(8);
    else if (sz == cpct) 
      reserve(cpct * 2);

    std::move(arr + _index, arr + sz, arr + (_index + 1));

    arr[_index] = _value;
    ++sz;
  }

  // Remove array element at given index
  void erase (
      unsigned int _index
    ) 
  {
    assert(_index < sz);

    std::move(arr + (_index + 1), arr + sz, arr + _index);
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

    value_type* tmp = new value_type[_capacity];
    std::move(arr, arr + sz, tmp);

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
  value_type& operator[] (
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
  value_type* arr;
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
