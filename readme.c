#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	static char a[10000] = "hello";
	printf("%s\n", a);

	
	
// Check if run 1 or run 2
	int flag;
	if(a[0] == 'h') flag=0; else flag=1;


/// Print contents of .c file
	/*
	for(int j = 0; j< total ; j++)
	{	
		printf("%c", cbuffer[j]);
	} */

if(flag == 0){
	FILE *fp = fopen("readme.c", "r");
	FILE *fp2 = fopen("readme", "r");
 
	char cbuffer [100000];
	char cbuffer_copy [100000];
	char bbuffer [20000];
	int total = fread(cbuffer, 1, sizeof(cbuffer), fp);
	int total2 = fread(bbuffer, 1, sizeof(bbuffer), fp2);

	//search for string in bbuffer
	int i, j = 0;
		for(i = 0; i < total; i++ )
		{
			cbuffer_copy[i] = cbuffer[i];

			if(cbuffer[i] == 'h' && cbuffer[i+1] == 'e'	&& cbuffer[i+2] == 'l'&& cbuffer[i+3] == 'l' && cbuffer[i+4] == 'o')
			{
				printf("Adding \n " );
				for( j=0; j<total2; j++)
					cbuffer_copy[i+j] = cbuffer[j];
				break;
			}
		}

		for(i = i+5; i < total; i++)
		{
			cbuffer_copy[i+j] = cbuffer[i];
		}
	
	
	fclose(fp);
	fclose(fp2);

	FILE *fp_readme2 = fopen("readme2.c", "w");
	fwrite (cbuffer_copy , sizeof(char), sizeof(cbuffer_copy), fp_readme2);
	fclose(fp_readme2);
	}

	return 0;
}
