// contains screen manipulation functions, such as clearScreen(), gotoxy(), setColor(), etc

#include "screen.h"
#include <stdio.h>

/*
	Function defination of clearScreen()
	This function will use VT100 escape sequence "\ESC[2J" to create the total terminal 
	screen
	input argument: none
	return argument: none
*/

void clearScreen(void){
	printf("%c[2J", ESC);
	fflush(stdout);
}

/*
	Function defination of gotoxy()
	This function uses VT100 escape sequence "\ESC[row:colH" to set the cursor
	to the specific location of the terminal screen
	input argument:
		int row: row number (1 is top)
		int col: col number (1 is left)
	return argument: none
*/

void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);
}

/*
 Function defination setColor()
 This function uses VT100 escape sequence "\ESC, color" to set the color of
 the screen:
 	input argument: color 
*/

void setColor(int color){
	printf("%c[1;%dm", ESC, color);
	fflush(stdout);
}

/*
 Function defination bar()
 This function uses for loop to set the two dimensional rectangular box in screen and different types of color are used 
 to record the data according to their decibel values.
*/

void bar(int col, double dB){
	int i;
	for(i=0; i<dB/4; i++){
		gotoxy(25-i, col+1);	// the first bar start from col=1
#ifndef UNICODE
		printf("%c", '*');
#else 
		if (i<60/4) setColor(WHITE);
		else if(i<80/4) setColor(YELLOW);
		else setColor(RED);
		printf("%s", BAR);
#endif
	}
}
