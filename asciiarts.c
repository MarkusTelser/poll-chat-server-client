#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#define TEXT_LENGTH 4096
#define BUFF_SIZE 256

/*
This function opens a file with exported ascii art in it.
Then reads from the file and returns the file context in a char *
back with the function. 
*/
char* getAsciiText(char *loc){
  FILE *file;
	char *text = malloc(sizeof(char) * TEXT_LENGTH);
	char buffer[BUFF_SIZE];
	
	//open file		
	file = fopen(loc,"r");
	if(file == NULL){
  	printf("Error!");   
    exit(1);             
  }
	
	//read one line and append to text (char *)
	while(fgets(buffer, BUFF_SIZE, file)!=NULL)
		strcat(text, buffer);	
	
	return text;
}

/*
This function prints the given ascii art from text onto the window. 
Everything gets printed from starting position (x|y). The last parameter is the color pair
id of the color pair that gets used to display the ascii text in another color. The id 0 
is the standard implemented color by the terminal. The text also gets printed with an 
extra attribute A_BOLD, to make it more appearing on the screen.  
*/
void printAsciiText(WINDOW *window,char *asciitext, int y, int x, int cpair_id){
	int n = 0;
	int sub = 0;
	wattron(window, COLOR_PAIR(cpair_id));
	wattron(window, A_BOLD);
	for(int i = 0; i < strlen(asciitext); i++){
		mvwprintw(window, y+n,x+i-sub,"%c",asciitext[i]);
		if(asciitext[i]=='\n'){
			n++;
			sub = i+1;
		}
	}
	wattroff(window, COLOR_PAIR(cpair_id));
	wattroff(window, A_BOLD);
}

