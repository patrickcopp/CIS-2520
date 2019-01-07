/*

Patrick Copp
1007602
Assignment 3
November, 2018

*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printKeys(int [11][21]);
void swap(int,int,int [11][21]);
void printAll(int [11][21]);
int main()
{
  FILE *fp;
  char file[10]="f.dat";
  int heapArray[11][21];
  int count=1;
  int num1,num2,num3,num4,num5,num6,num7,num8,num9,num10;

  fp=fopen(file,"r");




  while(!feof(fp))
  {
    fscanf(fp,"%d %d %d %d %d %d %d %d %d %d",&num1,&num2,&num3,&num4,&num5,&num6,&num7,&num8,&num9,&num10);
    heapArray[0][count]=num1+num2+num3;
    heapArray[1][count]=num1;
    heapArray[2][count]=num2;
    heapArray[3][count]=num3;
    heapArray[4][count]=num4;
    heapArray[5][count]=num5;
    heapArray[6][count]=num6;
    heapArray[7][count]=num7;
    heapArray[8][count]=num8;
    heapArray[9][count]=num9;
    heapArray[10][count]=num10;
    count++;
  }
  fclose(fp);


  for(int yolo=0;yolo<2;yolo++) /* log 20=2 */
  {

    for(int floor=10;floor>-1;floor--) /* n/2 */
    {

    if(heapArray[0][floor]>heapArray[0][floor*2] && heapArray[0][floor]>heapArray[0][floor*2+1])
    {
      if(floor*2+1<20 && heapArray[0][floor*2]>heapArray[0][floor*2+1])
      {
        swap(floor,floor*2+1,heapArray);
      }
      else
      {
        swap(floor,floor*2,heapArray);
      }
    }

    else if(heapArray[0][floor]>heapArray[0][floor*2])
    {
      swap(floor,floor*2,heapArray);
    }

    if(floor*2+1>20)
    {
      continue;
    }

    else if(floor*2+1<20 && heapArray[0][floor]>heapArray[0][floor*2+1])
    {
      swap(floor,floor*2+1,heapArray);
    }

  }
    for(int floor=10;floor>-1;floor--) /*n/2*/
    {

      if(heapArray[0][floor]>heapArray[0][floor*2] && heapArray[0][floor]>heapArray[0][floor*2+1])
      {
        if(floor*2+1<20 && heapArray[0][floor*2]>heapArray[0][floor*2+1])
        {
          swap(floor,floor*2+1,heapArray);
        }
        else
        {
          swap(floor,floor*2,heapArray);
        }
      }

      else if(heapArray[0][floor]>heapArray[0][floor*2])
      {
        swap(floor,floor*2,heapArray);
      }

      if(floor*2+1>20)
      {
        continue;
      }

      else if(floor*2+1<20 && heapArray[0][floor]>heapArray[0][floor*2+1])
      {
        swap(floor,floor*2+1,heapArray);
      }

    }

  }

  printAll(heapArray);
  return 0;
}

void swap(int parent,int child,int heapArray[11][21])  /*Copies all values from child to parent and vice versa*/
{

  int temp0,temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9,temp10;
  temp0=heapArray[0][parent];
  temp1=heapArray[1][parent];
  temp2=heapArray[2][parent];
  temp3=heapArray[3][parent];
  temp4=heapArray[4][parent];
  temp5=heapArray[5][parent];
  temp6=heapArray[6][parent];
  temp7=heapArray[7][parent];
  temp8=heapArray[8][parent];
  temp9=heapArray[9][parent];
  temp10=heapArray[10][parent];

  heapArray[0][parent]=heapArray[0][child];
  heapArray[1][parent]=heapArray[1][child];
  heapArray[2][parent]=heapArray[2][child];
  heapArray[3][parent]=heapArray[3][child];
  heapArray[4][parent]=heapArray[4][child];
  heapArray[5][parent]=heapArray[5][child];
  heapArray[6][parent]=heapArray[6][child];
  heapArray[7][parent]=heapArray[7][child];
  heapArray[8][parent]=heapArray[8][child];
  heapArray[9][parent]=heapArray[9][child];
  heapArray[10][parent]=heapArray[10][child];

  heapArray[0][child]=temp0;
  heapArray[1][child]=temp1;
  heapArray[2][child]=temp2;
  heapArray[3][child]=temp3;
  heapArray[4][child]=temp4;
  heapArray[5][child]=temp5;
  heapArray[6][child]=temp6;
  heapArray[7][child]=temp7;
  heapArray[8][child]=temp8;
  heapArray[9][child]=temp9;
  heapArray[10][child]=temp10;



}

void printKeys(int heapArray[11][21])
{
  for(int i=1;i<21;i++)
  {
    printf("%d ",heapArray[0][i]);
  }
  printf("\n");
}

void printAll(int heapArray[11][21])
{
  for(int i=1;i<21;i++)
  {
    for(int i2=1;i2<11;i2++)
    {
      printf("%d\t",heapArray[i2][i]);
    }
    printf("\n");
  }
  printf("\n");

}
