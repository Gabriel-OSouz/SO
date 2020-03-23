#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

void command_CLS();
void command_DIR();
void command_DATE();
void command_TIME();
int func_strCase();
void error();

int main(int argc,char* argv[])
{

   if(argc > 3)
    {
       printf("Número de agurmentos ou argumento inválido, tente novamente...\n");
       exit(1);
    } else {
 
              int value = func_strCase(argv[1]);


               switch(value)
              {
                
                case 1: command_CLS();              
                        break;
                case 2: command_DIR(argv[2]);
                        break;
                case 3: command_DATE();
                        break;
                case 4: command_TIME();
                        break;
              } // fim switch       

           } // fim else

} // fim main

void command_CLS()
{
  printf("\e[H\e[2J");
}


void command_DIR(char agrm[])
{
                DIR *arq;
                struct dirent *arq_list;
    
                arq = opendir(agrm);
                if(arq)
                {                    
                    while((arq_list = readdir(arq)) != NULL)
                    {
                        printf("%s\n",arq_list->d_name);
                    }
                    closedir(arq_list);
                    free(arq_list);
                      
                } else printf("Erro: arq (opendir)\n");
}


void command_DATE()
{
    
   time_t sec;
   struct tm *temp;
    
   time(&sec);
   temp = localtime(&sec);

   printf("Data atual: %d/%d/%d \n",temp->tm_mday,temp->tm_mon+1,temp->tm_year+1900);

}


void command_TIME()
{

   time_t sec;
   struct tm *temp;
    
   time(&sec);
   temp = localtime(&sec);
    
   printf("Horário atual: %dhr:%dmin:%ds \n",temp->tm_hour,temp->tm_min,temp->tm_sec);
}



void error(char param[])
{
   printf("Error: %s\n",param);
   exit(1);
}



int func_strCase(char *arg[])
{
  int val;
    
  if(strcmp("CLS",arg) == 0)
  val = 1;
  else if(strcmp("DIR",arg) == 0) 
       val = 2;
       else if(strcmp("DATE",arg) == 0)
            val = 3;
            else if(strcmp("TIME",arg) == 0)
                 val = 4;
                 else error(arg);
return val;
}
