// *************************************************************
// *    CMASK  -  Calculating mask in ANSI C                   *
// * This code implements the clculation of mask for the       *
// * UNIX /Linux command.                                      *
// *                                                           *
// * Author: Hamilton Gonçalves Junior                         *
// * Date: 07/01/2018                                          *
// *                                                           *
// * Umask example usage:                                      *
// * Umask 	Created Files 		Created Directories    * 
// * --------------------------------------------------------- *
// * 000 	666 (rw-rw-rw-) 	777 	(rwxrwxrwx)    *
// * 002 	664 (rw-rw-r--) 	775 	(rwxrwxr-x)    *
// * 022 	644 (rw-r--r--) 	755 	(rwxr-xr-x)    *
// * 027 	640 (rw-r-----) 	750 	(rwxr-x---)    *
// * 077 	600 (rw-------) 	700 	(rwx------)    *
// * 277 	400 (r--------) 	500 	(r-x------)    *
// *                                                           *
// *************************************************************
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
