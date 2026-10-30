#include <stdio.h>
#include <string.h>
int main(){
        char *str="Hello worldddddd";
        /* char name[20];
 
        int i =0;
        while(str[i] != '\0'){
            printf("%c",str[i]);
            i++;
        }
        printf("\n");
 
        printf("Enter a name : ");
        gets(name);
        printf("User entered a name is :");
        puts(name);
	*/
	char s[100];
	strcpy(s,str);
	printf("%s \n", s);
	strcpy(str, "Hello UNiverse");
	printf("%s\n", str);

	return 0;

}
