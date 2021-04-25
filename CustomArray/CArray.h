#pragma once

#include <algorithm>
#include <iostream>
#include <cassert>

template <typename TData>
class CArray
{
public:
  using value_type = TData;
  
  // Default constructor
  CArray() :
    sz{ 0 }, 
    cpct{ 0 }, 
    arr{ nullptr } 
  {
      
  }

  // Initialization list constructor
  CArray (
      std::initializer_list<value_type> _arr
    ) :
      sz {_arr.size() },
      cpct { _arr.size() },
      arr { new value_type[_arr.size()]}
  {
    std::copy(_arr.begin(), _arr.end(), arr);
  }

  // Copy constructor
  CArray (
      const CArray& _array
    ) :
      sz{ _array.sz }, 
      cpct{ _array.cpct }, 
      arr{ new value_type[_array.cpct] }
  {
    std::copy(_array.arr, _array.arr + sz, arr);
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
    increaseCapacityIfNeeded();
    arr[sz] = _value;
    ++sz;
  }

  // Add an element to an array at a given index
  void insert(
      unsigned int _index, 
      const value_type& _value
    ) 
  {
    assert(_index <= sz);

    increaseCapacityIfNeeded();
    std::move_backward(arr + _index, arr + sz, arr + (sz + 1));

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

  // Get the capacity of an array
  unsigned int capacity() const
  {
    return cpct;
  }

  // Reserve memory
  void reserve (
      unsigned int _capacity
    ) 
  {
    if (_capacity <=  cpct)
      return;

    value_type* tmp = new value_type[_capacity];
    std::move(arr, arr + sz, tmp);

    delete[] arr;
    arr = tmp;
    cpct = _capacity;
  }

  // Sort array
  void sort ()
  {
    for (unsigned int i = 1; i < sz; ++i)
    {
      for (unsigned int j = 0; j < sz - i; ++j)
      {
        if (arr[j] > arr[j + 1])
          std::swap(arr[j], arr[j + 1]);
      }
    }
  }

  // Get an element of an array at a given index
  value_type& operator[] (
      unsigned int _index
    ) 
  {
    assert(_index < sz);
    
    return arr[_index];
  }

  // Get an element of an array at a given index
  const value_type& operator[] (
    unsigned int _index
    ) const
  {
    assert(_index < sz);

    return arr[_index];
  }
  
  bool operator== (
      const CArray<value_type>& _arrCmpr
    )
  {
    if (_arrCmpr.size() != sz) {
      return false;
    }
    return std::equal(arr, arr + sz, _arrCmpr.arr);
  }
private:
  inline void increaseCapacityIfNeeded()
  {
    if (cpct == 0)
      reserve(default_capacity);
    else if (sz == cpct)
      reserve(cpct * 2);
  }
  
private:
  static constexpr size_t default_capacity = 8;
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
