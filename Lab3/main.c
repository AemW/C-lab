#include <stdio.h>
#include <string.h>

char morse[26][5] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

typedef enum { false, true } bool;
bool first;

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
	while(strcmp(morse[i++], string) != 0);
	
	return i;
}

char fran_morse(char *string){
	
	if(first){
		first = false;
		return 'A' + sok(string);
	} 
	return 'a' + sok(string);
	
}

int main(int argc, char **argv){
	int in = 0;
	
	printf("text->morse: please change code\nmorse->text: 1\n");
	scanf("%i", &in);
	
	printf("enter stuff\n");
	
	if(in == 0){
		char rad[256];
		fgets(rad, 256, stdin);
		char *p = rad;
		while(*p != '\0'){
			if(*p == ' '){
				printf("\t");
			} else {
				printf("%s ",till_morse(*p));
			}
			p++;
		}
		printf("\n");
	} else {
		first = true;
		char str[256];
		char c;
		while(scanf("%s",str) == 1){
			
			printf("%c", fran_morse(str));
			
			if((c = getchar()) == '\t'){
				printf(" ");
			} else if( c == '\n'){
				break;// somehow when using chosing method 1:0 above
					// a infinite loop can be created even if code otherwise
					// work perfectly without chosing from terminal
			}
			
		}
		
	}
	
	return 0;
}
