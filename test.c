#include <stdio.h>
#include <ctype.h>
#include <string.h>

void readMyFile(const char *fileName);
int myreadfile(void);

int main(){
  const char fileName[1] = "a";
  readMyFile(fileName);

  myreadfile();

  return 0;
}

void readMyFile(const char *fileName) {
  FILE *file;
  file = fopen(fileName, "rb");
  unsigned char ch[50];

  if (file != NULL) {


    while ((ch[0] = fgetc(file)) != EOF) {
      if (isprint(ch[0])) {
        printf("%c", ch[0]);
      }
      else {
        printf("'%02X'", ch[0]);
        //if (ch[0] == '\n') {
          //fputs("\n", stdout);
        //}
      }
    fclose(file);
  }

}
}


int myreadfile(void)
{
    FILE *fp;

    int i = 0, n;
    unsigned char a[5000];

    if (!(fp=fopen("a","rb")))
    	return(0);

    fseek(fp, 0, SEEK_END);
	int lSize = ftell(fp);
	rewind (fp);



    while(fread(a,lSize-1,sizeof(a), fp) && a[i] != EOF)
    {

        printf("%02x\n", a[i]);
        i++;

        // for (i=0; i<n; i++){
        //   // printf("%02x ",a[i]);
        //   printf("%c",a[i]);
        // }

    }
    fclose(fp);
    return 1;
}
