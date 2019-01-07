/*
Patrick Copp
1007602
Assignment 2
October 2018
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

float operator(char,int,float[]);

int main(int argv,char **argc)
{
  float numArray[15];
  char charArray[2];
  charArray[1]='\0';
  int count=0,c;

  if(argv!= 2)
  {
    printf("ERROR: Enter 1 argument.\n");
    return -1;
  }

  for(c=0;c<strlen(argc[1]);c++)
  {
    charArray[0]=argc[1][c];

    if(isdigit(argc[1][c])==0) //operator
    {
      numArray[count-2]=operator(argc[1][c],count-1,numArray);
      count-=1;
    }
    else
    {
      numArray[count]=atof(charArray);
      count++;
    }

  }
  printf("%.2f\n",numArray[count-1]);
  return 0;
}


float operator(char operate,int count,float numArray[])
{
  float result;

  if(operate=='+')
  {
    result=numArray[count]+numArray[count-1];
  }
  else if(operate=='-')
  {
    result=numArray[count-1]-numArray[count];
  }
  else if(operate=='*')
  {
    result=numArray[count]*numArray[count-1];
  }
  else if(operate=='/')
  {
    result=numArray[count-1]/numArray[count];
  }
  return result;
}
