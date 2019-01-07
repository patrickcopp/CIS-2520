/*

Patrick Copp
1007602
09/22/18
Assignment 1

*/

#include "header.h"

int main (int argc, char **argv)
{

  int m,n;
  float x;

  if(argc!=4)
  {
    printf("Error: wrong number of command line arguments. See README.TXT\n");
    return -1;
  }
  else
  {

    nestedFor();

    m=atoi(argv[1]);
    n=atoi(argv[2]);
    printf("Ackermann(%d,%d): %d\n",m,n,ackermann(m,n));

    x=atof(argv[3]);
    newtonMain(x);
  }

  return 0;
}
