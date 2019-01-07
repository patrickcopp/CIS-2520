
/*

Patrick Copp
1007602
09/22/18
Assignment 1

*/

#include "header.h"


void newtonMain(float x)
{
  float result,e,a;

  e=0.000001;
  a=x/2;
  result=newton(a,e,x,0);
  printf("Recursive square root: %f\n",result);
  newtonIterative(a,e,x);
}

float newton(float a,float e,float x,int counter)
{
  float negCheck;
  counter++;
  if(counter==100)
  {
  return a; /*Limit*/
  }
  negCheck=a*a-x;
  if(negCheck<0)
  {
    negCheck*=-1;
  }
  if(negCheck<=e)
  {
    return a;
  }
  else
  {
    a=newton((a+x/a)/2,e,x,counter);
  }

  return a;
}


void newtonIterative(float a, float e,float x)
{
  int c;
  float negCheck;
  for(c=0;c<100;c++)
  {
    negCheck=a*a-x;
    if(negCheck<0)
    {
      negCheck*=-1; /*Absolute value function*/
    }
    if(negCheck<=e)
    {
      break;
    }

    else
    {
      a=(a+(x/a))/2;
    }


  }

  printf("Iterative square root: %f\n",a);

}

