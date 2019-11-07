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
	char bbuffer [20000];
	int total = fread(cbuffer, 1, sizeof(cbuffer), fp);
	int total2 = fread(bbuffer, 1, sizeof(bbuffer), fp2);

	//search for string in bbuffer
	int i;
	for(i = 0; i < total2; i++ ){
		if(bbuffer[i] == 'h' 
			&& bbuffer[i+1] == 'e'	
			&& bbuffer[i+2] == 'l'
			&& bbuffer[i+3] == 'l' 
			&& bbuffer[i+4] == 'o'){
			printf("value of i = %d\n",i );
			break;
		}
	}

	// replace the contents in bbuffer with text from cbuffer
	int j = 0;
	for(j; j < total; j++, i++ ){
		//printf("%c\n", bbuffer[i]);
		bbuffer[i] = cbuffer[j];
		
		// if (cbuffer[j] == EOF)
		// 	break;
		
	}
	fclose(fp);
	fclose(fp2);
// if run = 2, write contents of a to new .c file

	for(int k = 0; k< sizeof(a)/sizeof(a[0]);k++ )
		printf("%c", a[k]);

	FILE *fp_readme2 = fopen("readme2.c", "w");
	fwrite (a , sizeof(char), sizeof(a), fp_readme2);
	fclose(fp_readme2);
	//char command[50];
    //strcpy( command, "gcc readme2.c -o readme2" );
	//system(command);

}else{

}



// compile .c file

	return 0;
}