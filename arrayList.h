

typedef enum { charType, shortType, intType} primitiveType;


typedef struct
{
   void * array;
   int elementSize;
   int numElements;
   int arraySize;
   primitiveType type;
} arrayList;

arrayList * initialize(primitiveType type);

void addElement(arrayList * ptr, void * element);

void removeElement(arrayList * ptr, int index);

void printArray(arrayList * ptr);




   


