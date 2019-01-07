/*
Patrick Copp
1007602
Assignment 2
October 2018
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct available
{
  char plateNumber[20];
  int mileage;
  int returnDate;
  struct available* next;
};

struct rented
{
  char plateNumber[20];
  int mileage;
  int returnDate;
  struct rented* next;
};

struct repair
{
  char plateNumber[20];
  int mileage;
  int returnDate;
  struct repair* next;
};

void addAvailable(char plateNumber[20],int mileage);
void addRepair(char plateNumber[20],int mileage);
void addRented(char plateNumber[20],int mileage,int returnDate);
void returnToAvailable();
void repairToAvailable();
void returnToRepair();
int isItThere(char plateNumber[20]);
int isItThereRepair(char plateNumber[20]);
void printList();
void rentFirst();

void fileWriteAvailable();
void fileWriteRented();
void fileWriteRepair();
void fileReadRepair();
void fileReadRented();
void fileReadAvailable();

struct available *headAvailable=NULL;
struct rented *headRented=NULL;
struct repair *headRepair=NULL;
float totalProfit=0;

int main()
{
  /*These functions read the files*/
  fileReadRented();
  fileReadAvailable();
  fileReadRepair();
  int user=0;
  while(user!=7)
  {
    printf("\n1. add a new car to the available-for-rent list\n");
    printf("2. add a returned car to the available-for-rent list\n");
    printf("3. add a returned car to the repair list\n");
    printf("4. transfer a car from the repair list to the available-for-rent list\n");
    printf("5. rent the first available car\n");
    printf("6. print all the lists\n");
    printf("7. quit\n");

    scanf("%d",&user);
    if(user==1)
    {
        int mileage;
        char plateNumber[20];
        printf("Enter a plate number: ");
        scanf("%s",plateNumber);
        printf("Enter a mileage: ");
        scanf("%d",&mileage);
        addAvailable(plateNumber,mileage);
        printf("Moved %s to available\n",plateNumber);

    }
    else if(user==2)
    {
      returnToAvailable();
    }
    else if(user==3)
    {
      returnToRepair();
    }
    else if(user==4)
    {
      repairToAvailable();
    }
    else if(user==5)
    {
      rentFirst();
    }
    else if(user==6)
    {
      printList();
    }
    else if(user==7)
    {
      break;
    }
    else
    {
      printf("ERROR: Not a valid transaction code.\n");
    }
  }


  fileWriteRepair(); /*These functions write to the files*/
  fileWriteRented();
  fileWriteAvailable();

  printf("Total Profit: $%.2f\n",totalProfit);
  return 0;
}

void fileReadRepair()
{
  FILE *fp;
  struct repair *hold=malloc(sizeof(struct repair));

  fp=fopen("repair.txt","r");
  if(fp==NULL)
  {
    printf("ERROR: Could not read from file, repair list default to NULL.\n");
    return;
  }

  while(fscanf(fp,"%s %d %d\n",hold->plateNumber,&hold->mileage,&hold->returnDate)!=EOF)
  {
    addRepair(hold->plateNumber,hold->mileage);
  }
  fclose(fp);

}
void fileReadRented()
{
  FILE *fp;
  struct rented *hold=malloc(sizeof(struct rented));

  fp=fopen("rented.txt","r");
  if(fp==NULL)
  {
    printf("ERROR: Could not read from file, rented list default to NULL.\n");
    return;
  }

  while(fscanf(fp,"%s %d %d\n",hold->plateNumber,&hold->mileage,&hold->returnDate)!=EOF)
  {
    addRented(hold->plateNumber,hold->mileage,hold->returnDate);
  }

  fclose(fp);
}
void fileReadAvailable()
{
  FILE *fp;
  struct available *hold=malloc(sizeof(struct available));

  fp=fopen("available.txt","r");
  if(fp==NULL)
  {
    printf("ERROR: Could not read from file, available list default to NULL.\n");
    return;
  }

  while(fscanf(fp,"%s %d %d\n",hold->plateNumber,&hold->mileage,&hold->returnDate)!=EOF)
  {
    addAvailable(hold->plateNumber,hold->mileage);
  }
  fclose(fp);
}


void fileWriteRepair()
{
  FILE *fp;
  fp=fopen("repair.txt","w");
  struct repair *hold;

  for(hold=headRepair;hold!=NULL;hold=hold->next)
  {
    fprintf(fp,"%s %d 0\n",hold->plateNumber,hold->mileage);
  }

  fclose(fp);
}
void fileWriteRented()
{
  FILE *fp;
  fp=fopen("rented.txt","w");
  struct rented *hold;

  for(hold=headRented;hold!=NULL;hold=hold->next)
  {
    fprintf(fp,"%s %d %d\n",hold->plateNumber,hold->mileage,hold->returnDate);
  }

  fclose(fp);
}
void fileWriteAvailable()
{
  FILE *fp;
  fp=fopen("available.txt","w");
  struct available *hold;

  for(hold=headAvailable;hold!=NULL;hold=hold->next)
  {
    fprintf(fp,"%s %d 0\n",hold->plateNumber,hold->mileage);
  }

  fclose(fp);
}

void addAvailable(char plateNumber[20],int mileage) /*Creates available node and puts it in correct order in regard to the list*/
{
  struct available *hold=malloc(sizeof(struct available));
  strcpy(hold->plateNumber,plateNumber);
  hold->mileage=mileage;
  hold->returnDate=000000;
  if(headAvailable==NULL)
  {
    headAvailable=hold;
  }
  else
  {
    struct available *temp=headAvailable;
    while(temp->next!=NULL && temp->next->mileage<hold->mileage)
    {
      temp=temp->next;
    }
    if(temp==headAvailable && hold->mileage<headAvailable->mileage)
    {
      headAvailable=hold;
      hold->next=temp;
      return;
    }
    hold->next=temp->next;
    temp->next=hold;

  }
}

void returnToAvailable()/*Finds mileage of given plate number using isItThere , calculates charge, and then adds to available*/
{
  char plateNumber[20];
  int mileage, charge,newMileage;
  float price;
  printf("Enter the car's plate number: ");
  scanf("%s",plateNumber);
  printf("Enter the car's mileage: ");
  scanf("%d",&mileage);
  newMileage=isItThere(plateNumber);

  if(newMileage==-1)
  {
    printf("ERROR: plate number not found.\n");
    return;
  }

  charge= mileage-newMileage;

  if(charge<100)
  {
    printf("Charge: $40.00\n");
    totalProfit+=40;
  }
  else
  {
    price=40+(0.15*(charge-100));
    printf("Charge: $%.2f\n",price);
    totalProfit+=price;
  }

  addAvailable(plateNumber,mileage);
  printf("Moved %s from rented to available\n",plateNumber);
}

void printList()/*prints all 3 lists*/
{
  struct available *print;
  print=headAvailable;
  printf("\nAvailable-for-Rent:");
  printf("\n******************\n");
  while(print)
  {
    printf("%s\t%d\n",print->plateNumber,print->mileage);
    print=print->next;
  }

  struct rented *print1;
  print1=headRented;
  printf("\nRented:");
  printf("\n******\n");
  while(print1)
  {
    printf("%s\t%d\t%d\n",print1->plateNumber,print1->mileage,print1->returnDate);
    print1=print1->next;
  }

  struct repair *print2;
  print2=headRepair;
  printf("\nRepair:");
  printf("\n******\n");
  while(print2)
  {
    printf("%s\t%d\n",print2->plateNumber,print2->mileage);
    print2=print2->next;
  }
}

int isItThere(char plateNumber[20]) /*Finds plate number in rented and nulls it, returns mileage*/
{
  int hold;
  struct rented *temp=malloc(sizeof(struct rented));
  temp=headRented;
  if(headRented==NULL)
  {
    return -1;
  }
  if(strcmp(temp->plateNumber,plateNumber)==0)
  {
    hold=temp->mileage;
    headRented=headRented->next;
    return hold;

  }

  else
  {
    while(temp->next!=NULL)
    {
      if(strcmp(temp->next->plateNumber,plateNumber)==0)
      {
        if(temp->next->next!=NULL)
        {
        temp->next=temp->next->next;
        }
        hold=temp->next->mileage;
        temp->next=NULL;
        return hold;
      }
      temp=temp->next;
    }
  }


  return -1;
}

void rentFirst()/*Takes first available car and adds it to rented list*/
{
  char plateNumber[20];
  int mileage,returnDate;
  struct available *hold=malloc(sizeof(struct available));
  hold=headAvailable;

  if(headAvailable==NULL)
  {
    printf("ERROR: No cars available to rent.\n");
    return;
  }

  headAvailable=headAvailable->next;
  strcpy(plateNumber,hold->plateNumber);
  mileage=hold->mileage;
  printf("Enter an expected return date (yymmdd): ");
  scanf("%d",&returnDate);
  addRented(plateNumber,mileage,returnDate);
  printf("Moved %s from available to rented\n",plateNumber);

}

void addRented(char plateNumber[20],int mileage,int returnDate)/*Creates rented node and puts it in correct order in regard to the list*/
{
  struct rented *hold=malloc(sizeof(struct rented));
  strcpy(hold->plateNumber,plateNumber);
  hold->mileage=mileage;
  hold->returnDate=returnDate;

  if(headRented==NULL)
  {
    headRented=hold;
  }
  else
  {

    struct rented *temp=headRented;

    while(temp->next!=NULL && temp->next->returnDate<hold->returnDate)
    {
      temp=temp->next;
    }
    if(temp==headRented && hold->returnDate<temp->returnDate)
    {
      headRented=hold;
      hold->next=temp;
      return;
    }
    hold->next=temp->next;
    temp->next=hold;

  }
}

void returnToRepair()/*Finds mileage of given plate number using isItThere, calculates charge, and then adds to repair*/
{
  char plateNumber[20];
  int mileage, charge,newMileage;
  float price;
  printf("Enter the car's plate number: ");
  scanf("%s",plateNumber);
  printf("Enter the car's mileage: ");
  scanf("%d",&mileage);
  newMileage=isItThere(plateNumber);

  if(newMileage==-1)
  {
    printf("ERROR: plate number not found.\n");
    return;
  }

  charge= mileage-newMileage;

  if(charge<100)
  {
    printf("Charge: $40.00\n");
    totalProfit+=40;
  }
  else
  {
    price=40+(0.15*(charge-100));
    printf("Charge: $%.2f\n",price);
    totalProfit+=price;
  }

  addRepair(plateNumber,mileage);
  printf("Moved %s from rented to repair\n",plateNumber);
}

void addRepair(char plateNumber[20],int mileage)/*Creates repair node and puts it in correct order in regard to the list*/
{
  struct repair *hold=malloc(sizeof(struct repair));
  strcpy(hold->plateNumber,plateNumber);
  hold->mileage=mileage;
  hold->returnDate=000000;
  if(headRepair==NULL)
  {
    headRepair=hold;
  }
  else
  {
    struct repair *temp=headRepair;
    while(temp->next!=NULL && temp->next->mileage<hold->mileage)
    {
      temp=temp->next;
    }
    if(temp==headRepair && hold->mileage<headRepair->mileage)
    {
      headRepair=hold;
      hold->next=temp;
      return;
    }
    hold->next=temp->next;
    temp->next=hold;

  }
}

int isItThereRepair(char plateNumber[20]) /*Finds plate number in repair and nulls it, returns mileage*/
{
  int hold;
  struct repair *temp=malloc(sizeof(struct repair));

  temp=headRepair;
  if(headRepair==NULL)
  {
    return -1;
  }
  if(strcmp(temp->plateNumber,plateNumber)==0)
  {
    hold=temp->mileage;
    headRepair=headRepair->next;
    return hold;

  }

  else
  {
    while(temp->next!=NULL)
    {
      if(strcmp(temp->next->plateNumber,plateNumber)==0)
      {
        if(temp->next->next!=NULL)
        {
        temp->next=temp->next->next;
        }
        hold=temp->next->mileage;
        temp->next=NULL;
        return hold;
      }
      temp=temp->next;
    }
  }

  return -1;
}

void repairToAvailable()/*Finds mileage of given plate number using isItThereRepair, and then adds to available*/
{
  char plateNumber[20];
  int newMileage;
  printf("Enter the car's plate number: ");
  scanf("%s",plateNumber);
  newMileage=isItThereRepair(plateNumber);
  if(newMileage==-1)
  {
    printf("ERROR: plate number not found.\n");
    return;
  }
  addAvailable(plateNumber,newMileage);
  printf("Moved %s from repair to available\n",plateNumber);
}
