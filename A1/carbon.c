/*

Patrick Copp
1007602
09/22/18
Assignment 1

*/

#include "header.h"


void nestedFor()
{
  int a,b,c,d,e,f,count;
  char carbon[7];
  strcpy(carbon,"carbon");
  count=0;
  for(a=0;a<6;a++)
  {
    for(b=0;b<6;b++)
    {
      for(c=0;c<6;c++)
      {
        for(d=0;d<6;d++)
        {
          for(e=0;e<6;e++)
          {
            for(f=0;f<6;f++)
            {
	      if(a==b||a==c||a==d||a==e||a==f||b==c||b==d||b==e||b==f||c==d||c==e||c==f||d==e||d==f||e==f)
	      {
              }
              /* Checks to make sure no letters are repeated*/
              else
              {
                count++;
                printf("%d: %c%c%c%c%c%c\n",count,carbon[a],carbon[b],carbon[c],carbon[d],carbon[e],carbon[f]);
              }
            }
          }
        }
      }
    }
  }
}
