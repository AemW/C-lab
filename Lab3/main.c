#include <stdio.h>
#include <string.h>

char morse[26][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

int bokst_nr(char c){
	int ret = -1;
	
	if('A'<= c && c <= 'Z'){
		ret = c - 'A';
		
	}else if('a' <= c && c <= 'z'){
		ret = c - 'a';
	}

	return ret;
	
}

char* till_morse(char c){
	
	char *ret = bokst_nr(c) == -1? "" : morse[bokst_nr(c)];
	
	return ret;
}


int sok(char *string){
	int i = 0;
	while(strcmp(morse[i], string) != 0){
		i++;
		
	}
	
	return i;
}

char fran_morse(char *string){
	
	return 'a' + sok(string);
	
}

int main(int argc, char **argv){
	int in =1;
//	printf("text->morse:0\n morse->text:1\n");
//	scanf("%i", &in);
	
	printf("enter stuff\n");
	
	if(in == 0){
		char rad[256];
		fgets(rad, 256, stdin);
		char *c = rad;
		while(*c != '\0'){
			if(*c == ' '){
				printf("\t");
			} else {
				printf("%s ",till_morse(*c));
			}
			c++;
		}
		printf("\n");
	} else {
		char c[256];
		while(scanf("%s",c) == 1){
			if(c == "\t"){
				printf(" ");
			} else {
				printf("%c", fran_morse(c));
			}
			
			
		}
		
		
	}
	
	return 0;
}
