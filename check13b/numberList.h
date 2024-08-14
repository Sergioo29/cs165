/*******************
 * NumberList class
 *******************/
#ifndef NUMBER_LIST_H
#define NUMBER_LIST_H

#include <iostream>

class NumberList
{
private:
   int size;
   int *array;

public:
   NumberList()
   {
      size = 0;
      array = NULL;
   }


   // TODO: Add your constructor and destructor
   NumberList(int size)
   {
     this->size = size;
     array = new int[size];

     for (int i = 0; i < size ; i++)
     {
       array[i] = 0;
     }
   }
   ~NumberList()
   {
     delete[] array;
     array = NULL;
     std::cout << "Freeing memory\n";
   }

   // Add a copy constructor and overload the assignment operator
   NumberList(const NumberList & rhs)
   {
     size = rhs.size;
     array = new int(size);

     for (int i = 0; i < size; i++)
     {
       array[i] = rhs.array[i];
     }
   }

  NumberList & operator = (const NumberList & rhs)
  {
    if (array != NULL)
    {
      delete[] array;
      array = NULL;
    }
    size = rhs.size;
    array = new int[size];

    for (int i = 0; i < size; i++)
    {
      array[i] = rhs.array[i];
    }

    return *this;
  }






   int getNumber(int index) const;
   void setNumber(int index, int value);

   void displayList() const;

};

#endif
