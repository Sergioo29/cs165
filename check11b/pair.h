/*****************************************************
 * File: pair.h
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H
#include <iostream>

// TODO: Fill in this class
// Put all of your method bodies right in this file
template <class T1, class T2>
class Pair
{

private:
  T1 first;
  T2 second;

public:
  T1 getFirst() const { return first; }
  void setFirst(T1 value) { first = value; }
  T2 getSecond() const { return second; }
  void setSecond(T2 value) { second = value; }
  void display() const { cout << first << " - " << second; }

};

#endif // PAIR_H
