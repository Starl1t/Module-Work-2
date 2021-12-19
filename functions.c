#include "functions.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

int num1(char* str_)
{
   int len = strlen(str_);
   int fwLenght = 0;  // first word lenght
   int lwLenght = 0;  // last word lenght
   int lwIndex = 0;   // index of last word first letter
   char fw[100];      // first word
   char lw[100];      // last word
   int i = 0;
   int j = 0;

   // fw lenght //
  while (str_[i] != ' ') 
   {
      fwLenght++;
      i++;
   }

   
   // str with only first word //
   for (i = 0; i < fwLenght; i++) 
   {
      fw[i] = str_[i];
      fw[i + 1] = '\0';
   }

   
   // lw lenght //
   i = len - 1;
   
   while (str_[i] != ' ') 
   {
      lwLenght++;
      i--;
   }
  
   
   // lw index //
   lwIndex = len - lwLenght;

   
   // str with only last word //
   for (i = lwIndex; str_[i] != '\0'; i++)
   {
      lw[j] = str_[i];
      lw[j + 1] = '\0';
      j++;
   }

   
   // array with all other words //
   char* otherWords = (char*)malloc(len * sizeof(char));
   j = 0;
   for (i = fwLenght; i < lwIndex; i++)
   {
      otherWords[j] = str_[i];
      otherWords[j + 1] = '\0';
      j++;
   }

   
   // array lenght //
   int wordsLen = len - fwLenght - lwLenght;

   
   // array with swapped words //
   char* reverse = (char*)malloc(len * sizeof(char));

   for (i = 0; i < lwLenght; i++)
   {
      reverse[i] = lw[i];
      reverse[i + 1] = '\0';
   }

   for (j = 0; j < wordsLen; j++)
   {
      reverse[i] = otherWords[j];
      reverse[i + 1] = '\0';
      i++;
   }

   for (j = 0; j < fwLenght; j++)
   {
      reverse[i] = fw[j];
      reverse[i + 1] = '\0';
      i++;
   }

   printf("%s", reverse);
   
   return 0;
}

void num2() //ne uspel
{
}






void num3()
{
   FILE* f = NULL;
   FILE* g = NULL;

   
   errno_t err1 = fopen_s(&f, "f.txt", "r");
   
   if (err1)
   {
      printf("error");
      return 1;
   }

   errno_t err2 = fopen_s(&g, "g.txt", "w");
   
   if (err2)
   {
      printf("error");
      return 1;
   }
  
   int count = 1;
   
   for (char tmp; fscanf_s(f, "%c", &tmp) != EOF;)
   {
      if (tmp == 'Ï' || tmp == 'ï' || count % 4 == 0)
      {
         count++;
         
         while (tmp != ' ')
         {
            fscanf_s(f, "%c", &tmp);
         }
      }
      else
      {
         fprintf_s(g, "%c", tmp);
      }
   }
   
   fclose(f);
   fclose(g);
}

