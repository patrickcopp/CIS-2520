
/*

Patrick Copp
1007602
09/22/18
Assignment 1

*/


#include "header.h"

int ackermann(int m,int n)
{
  if(m==0)
  {
    return n+1;
  }
  if(n==0)
  {
    return ackermann(m-1,1);
  }
  else
  {
    return ackermann(m-1,ackermann(m,n-1));
  }

}
