#include <stdio.h>
#include "arrayList.h"
#define ARRAYSIZE 9 

//this main tests the arrayList functions
int main()
{
   int i;
   int list[ARRAYSIZE] = {0x12, 0x34, 0x4567, 0x89ab, 0x125678, 
                          0x21, 0x321, 0x4321, 0x54321};

   //can we create an arrayList of chars?
   arrayList * charArray = initialize((primitiveType)charType);
   for (i = 0; i < ARRAYSIZE; i++)
   {
      addElement(charArray, &list[i]);
      printArray(charArray);
   }
   for (i = 0; i < ARRAYSIZE; i++)
   {
      //always delete the first one
      removeElement(charArray, 0);
      printArray(charArray);
   }

   //can we create an arrayList of shorts?
   arrayList * shortArray = initialize((primitiveType)shortType);
   for (i = 0; i < ARRAYSIZE; i++)
   {
      addElement(shortArray, &list[i]);
      printArray(shortArray);
   }
   for (i = 0; i < ARRAYSIZE; i++)
   {
      //always delete the last one
      removeElement(shortArray, shortArray->numElements - 1);
      printArray(shortArray);
   }

   //can we create an arrayList of ints?
   arrayList * intArray = initialize((primitiveType)intType);
   for (i = 0; i < ARRAYSIZE; i++)
   {
      addElement(intArray, &list[i]);
      printArray(intArray);
   }
   for (i = 0; i < ARRAYSIZE; i++)
   {
      //always delete the one in the middle
      removeElement(intArray, intArray->numElements/2);
      printArray(intArray);
   }

   return 0;
}
