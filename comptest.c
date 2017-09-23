#include "Sorter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]){
 char tempstr[] = "12";
  char* endptr;
  float fl = 0.0;
  long in = 0;
     if(strchr(tempstr, '.')){ //if it has a '.', it's a string or a float/double
       fl = strtof(tempstr, &endptr);
       if((endptr == tempstr) || (endptr != (tempstr+strlen(tempstr)))){ //if endptr == tempstr, no floats at the start, the other conditional checks to make sure that the end of the read in float is the end of the string inputted
	 printf("no float\n");
       }
       else{
	printf("%f\n", fl); 
       }
	
     //use strtof
   }
   else{ //if it has no '.', it's either an int or a string
     in = strtol(tempstr, &endptr, 10);
     if((endptr == tempstr) || (endptr != (tempstr+strlen(tempstr)))){ //if endptr == tempstr, no floats at the start, the other conditional checks to make sure that the end of the read in float is the end of the string inputted
	 printf("no int\n");
       }
       else{
	printf("%ld\n", in); 
       }
     
     
   }
  
}