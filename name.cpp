#include"name.h"

#include <stdlib.h> 
#include <time.h>  
string Name::getName()
{
    srand((unsigned)time(NULL));
      int n =rand()%(nameDataBase.length()-4)
      n-=n%2;
      string s(nameDataBase,n,4);
    return s;
}