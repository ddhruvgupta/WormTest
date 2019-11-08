#include <stdio.h>
#include <ctype.h>
#include <string.h>

void readMyFile(const char *fileName);
int myreadfile(void);

int main(){
  const char fileName[1] = "a";
  // readMyFile(fileName);

  myreadfile();

  return 0;
}

void readMyFile(const char *fileName) {
  FILE *file;
  file = fopen(fileName, "rb");
  if (file != NULL) {
    unsigned char ch[50];


    while ((ch[0] = fgetc(file)) != EOF) {
      if (isprint(ch[0])) {
        printf("%c", ch[0]);
      }
      else {
        printf("'%02X'", ch[0]);
        if (ch[0] == '\n') {
          fputs("\n", stdout);
        }
      }
    fclose(file);
  }

}
}


int myreadfile(void)
{
    FILE *fp;
    int i, n;
    unsigned char a[100];
    if (!(fp=fopen("a","rb"))) return(0);
    while(n = fread(a,1,5, fp))
    {
      // printf("%s\n", "running");
        if(strcmp(a,"hello") == 0){
          printf("%s\n", a);
        }
        for (i=0; i<n; i++){
          // printf("%02x ",a[i]);
          printf("%c",a[i]);
        }

        printf("\n");
    }
    fclose(fp);
    return 1;
}
