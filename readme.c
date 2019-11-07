#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	static char a[10000] = "hello";
	printf("%s\n", a);

	FILE *fp = fopen("readme.c", "r");
	FILE *fp2 = fopen("readme", "r");
 
	char cbuffer [100000];
	char bbuffer [20000];
	int total = fread(cbuffer, 1, sizeof(cbuffer), fp);
	int total2 = fread(bbuffer, 1, sizeof(bbuffer), fp2);
	
	int j = 0;
	int flag = 0;

/// Print contents of .c file
	for(j = 0; j< total ; j++)
	{	
		printf("%c", cbuffer[j]);
	}

//search for string in bbuffer


// replace the contents in bbuffer with text from cbuffer


// if run = 2, write contents of a to new .c file


// compile .c file
	printf("%s", "size = ");
	printf("%d \n ", total2);

	
	fclose(fp);
	fp = fopen("readme2.c", "w");
	fwrite (cbuffer , sizeof(char), sizeof(cbuffer), fp);


	fclose(fp);
	fclose(fp2);

   //char command[50];

   //strcpy( command, "gcc readme2.c -o readme2" );
	//system(command);

	return 0;
}