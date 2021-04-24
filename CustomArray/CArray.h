#pragma once

#include <algorithm>
#include <iostream>

template <typename TData>
class CArray
{
public:
  // Конструктор по умолчанию
  CArray() :
    sz{ 0 }, 
    cpct{ 0 }, 
    arr{ nullptr } 
  {
      
  }

  // Копирующий конструктор
  CArray (
      const CArray& _array
    ) :
      sz{ _array.sz }, 
      cpct{ _array.cpct }, 
      arr{ new TData[_array.sz] } 
  {
    std::copy(_array, _array + sz, arr);
  }

  // Деструктор
  ~CArray() 
  {
    if (sz != 0)
      delete[] arr;
  }

  // Добавить элемент в конец массива
  void push_back (
      const TData& _value
    )
  {
    if (cpct == 0) 
    {
      reserve(8);
    }
    else if (sz == cpct) 
    {
      reserve(cpct * 2);
    }
    arr[sz] = _value;
    ++sz;
  }

  // Добавить элемент в массив по заданному индексу
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

  // Удалить элемент массива по заданному индексу
  void erase(
      unsigned int _index
    ) 
  {
    if (_index >= sz)
      return;

    for (unsigned int i = _index; i < sz - 1; ++i)
      arr[i] = arr[i + 1];
    --sz;
  }

  // Очистить массив
  void clear() 
  {
    if (arr != nullptr) 
    {
      delete[] arr;
      sz = 0;
      cpct = 0;
    }
  }

  // Получить размер массива
  unsigned int size() const 
  {
    return sz;
  }

  // Зарезервировать память
  void reserve(
      unsigned int _capacity
    ) 
  {
    if (_capacity < cpct)
      return;

    TData* tmp = new TData[_capacity];
    for (unsigned int i = 0; i < sz; ++i)
      tmp[i] = arr[i];
    if (arr != nullptr)
      delete[] arr;
    cpct = _capacity;
    arr = tmp;
  }

  // Получить элемент массива по заданному индексу
  TData& operator[](
      unsigned int _index
    ) 
  {
    return arr[_index];
  }

protected: // Attributes
  unsigned int sz;
  unsigned int cpct;
  TData* arr;
};

template <typename T>
void sort(
    CArray<T>& _arr
  ) 
{
  unsigned int size = _arr.size();
  for (unsigned int i = 1; i < size; ++i) 
  {
    for (unsigned int j = 0; j < size - i; ++j) 
    {
      if (_arr[j] > _arr[j + 1]) 
      {
        T elm = _arr[j];
        _arr[j] = _arr[j + 1];
        _arr[j + 1] = elm;
      }
    }
  }
}

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
