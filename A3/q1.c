/*

Patrick Copp
1007602
Assignment 3
November, 2018

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
  char data[10];
  struct node *left;
  struct node *right;

};

float numberStack[100];
char operatorStack[100];
char expression[100];
struct node Tree[100];


int stackCount=0;
int opStackCount=0;


int main (int argc,char *argv[])
{

  if(argc!=2)
  {
    printf("Wrong number of command line arguments, consult README.TXT\n");
    return 1;
  }

  strcpy(expression,argv[1]);

  for(int i=0;i<strlen(expression);i++)
  {
    if(expression[i]=='(')
    {
      operatorStack[opStackCount]=expression[i];
      opStackCount++;
    }
    else if(isdigit(expression[i])!=0)
    {
      numberStack[stackCount]=expression[i]-48;
      numberStack[stackCount]+=(expression[i+2]-48)*0.10;
      numberStack[stackCount]+=(expression[i+3]-48)*0.01;
      stackCount++;
      i+=3;
    }

    else if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*' || expression[i]=='/')
    {
      operatorStack[opStackCount]=expression[i];
      opStackCount++;
    }

    else if(expression[i]==')')
    {
      printf("dsad");
      struct node *newNode=malloc(sizeof(struct node));
      newNode->data[0]=operatorStack[opStackCount];
      newNode->data[1]='\0';
      opStackCount--;
    }


  }




  return 0;
}
