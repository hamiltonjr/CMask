// ************************************************
// *    CMASK  -  Calculating mask in ANSI C      *
// * This code implements the clculation of mask  *
// * for the umask UNIX /Linux command.           *
// * Author: Hamilton Gonçalves Junior            *
// * Date: 07/01/2018                             *
// ************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    int numberMask = 0;
    int number = 0;
    int notNumber = 0;
    int u, d, c;
    int digit = 0;
    char mask[4];

    if (argc < 3)
	printf("No enough arguments\n");

    if (!strcmp(argv[1], "-d")) digit = 7;
    else
	if (!strcmp(argv[1], "-f")) digit = 6;
	else
	    printf("Worng argument\n");

    if (strlen(argv[2]) != 3)
	printf("Mask size non-allowed\n");
    else
    	strcpy(mask, argv[2]);

    u = (int)mask[2] - 48;
    d = (int)mask[1] - 48;
    c = (int)mask[0] - 48;

    number = (~u & digit) + (~d & digit)*10 + (~c & digit)*100;
    printf("%d\n", number);

    return 0;
  
}
