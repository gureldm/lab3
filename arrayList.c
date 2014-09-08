#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

/*
    Deniz Gurel
    arrayList.c
*/

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

/*
 *  Function: initialize
 *  -----------------
 *  Initializes the array by allocating space for 4 items
 *
 *  type: the type of array we are going to create(char, short, int) 
 *
 *  returns: a pointer to our arrayList struct which contains information
 *      about the array and a pointer to the array
*/


arrayList * initialize(primitiveType type)
{
   arrayList *listPtr;
   listPtr = (arrayList*) malloc(sizeof(arrayList));
   listPtr -> elementSize = getSize(type);
   listPtr -> numElements = 0;
   listPtr -> arraySize = 4;
   listPtr -> type = type;
   listPtr -> array = (void*) malloc(getSize(type) * 4);

   return listPtr;
}

/*
 *  Function: getSize
 *  -----------------
 *  Calculates the size in bytes of a primitive type
 *
 *  type: An enumerated value representing a primitive type
 *
 *  returns: The size in bytes of the primitive type
 *
*/


int getSize(primitiveType type)
{
   if(type == charType)
       return sizeof(char);
   else if (type == shortType)
       return sizeof(short);
   else if (type == intType)
       return sizeof(int);
   else
       return -1;  
}

/*
 *  Function: addElement
 *  -----------------
 *  Adds an element on to the end of the list
 *
 *  element: the element we wish to add to the array.
 *  arylstP: A pointer to an arrayList struct.
 *
 *  returns: void
 *
*/


void addElement(arrayList * arylstP, void * element)
{
    //The size of the array in bytes
    int arrSizeBytes = (arylstP -> elementSize) * (arylstP -> numElements);
    int i;

    //If the array is full we double the size
    if (arylstP -> arraySize == arylstP -> numElements)
    {
       //allocate space for an array twice the size of our current array
      void* newArr = malloc(arrSizeBytes * 2);

       //copy information from our current array into the new array byte by byte
       for(i = 0; i < arrSizeBytes; i++)
           ((char*)newArr)[i] = ((char*)(arylstP -> array))[i];
        
       //free space alloc by old array, point to new array, and update size 
       free(arylstP->array);
       arylstP->array = newArr;
       arylstP -> arraySize *= 2;
    }
   
    //place new element into array byte by byte
    for(i = 0; i < arylstP -> elementSize; i++)
    {
       ((char*)(arylstP -> array))[i + arrSizeBytes] = ((char*)element)[i];          
    }
    
    (arylstP -> numElements)++; 


}

/*
 *  Function: removeElement
 *  -----------------
 *  Removes the element at the specified index from the array
 *
 *  index: The index of the element to be removed
 *  arylstP: Pointer to the arrayList struct
 *
 *  returns: void
 *
*/

void removeElement(arrayList * arylstP, int index)
{
   int arrSizeBytes = (arylstP -> elementSize) * (arylstP -> numElements);
   int i;

   //Essentially converting array into a char array in order to have one branch.
   //we start at the index of the element to be removed and loop until second to last element.
   
   //We set each byte equal to the byte in the chunk immediately after it.
   //For example if the array consists of shorts the byte at index 2 would be set to the
   //   byte at index 4 in order to preserve the elements in the array
   for(i = index * (arylstP -> elementSize); i < arrSizeBytes - (arylstP -> elementSize); i++)
        ((char*)(arylstP -> array ))[i] = ((char*)(arylstP -> array))[i + (arylstP -> elementSize)];
   
   (arylstP -> numElements)--;
}

/*
 *  Function: printArray
 *  -----------------
 *  prints out the contents of the array
 *
 *  arylstP: a pointer to the arrayList struct * 
 *
 *  returns: void
 *
*/
      

void printArray(arrayList * arylstP)
{
   int i;
   printf("array size: %d, num elements: %d contents: ", 
          arylstP->arraySize, arylstP->numElements);
   for (i = 0; i < arylstP->numElements; i++)
   {
      if (arylstP->type == charType)
         //fill in the missing code that gets the element and &s it with 0xff
         printf("%02x ", 0xff & ((char*)(arylstP -> array))[i]);
      else if (arylstP->type == shortType)
         //fill in the missing code that gets the element and &s it with 0xffff
         printf("%04x ", 0xffff & ((short*)(arylstP -> array))[i]);
      else if (arylstP->type == intType)
         //fill in the missing code that gets the element and &s it with 0xffffffff
         printf("%08x ", 0xffffffff & ((int*)(arylstP -> array))[i] );
   }
   printf("\n");
}

