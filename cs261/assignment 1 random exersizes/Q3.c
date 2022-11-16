/* CS261- Assignment 1A - Question 3
   Name: Michael
   Date: Murphy
   Solution description:
*/

#include <stdio.h>
#include <stdlib.h>


char toUpperCase(char ch){
  // Convert ch to upper case, assuming it is in lower case currently

  //32 is the difference between lower and upper case chars on the ascii table
  return (ch - 32);
}

char toLowerCase(char ch){
  // Convert ch to lower case, assuming it is in upper case currently

  //32 is the difference between lower and upper case chars on the ascii table
  return (ch + 32);             
}

int stringLength(char s[]){
  // Return the length of the string
  return 25;
}


void camelCase(char* word){
  //convert to camelCase
  for (int i = 0; i<25; i++){
    if(word[i] == 95 && i < 24 && i > 0){
      word[i] = 0;
      word[i+1] = toUpperCase(word[i+1]);
    }
  }	
}

void normalizeInput(char* input){
  //this function turns any non alaphabetical charter to an underscore and then removes any duplicate, leading, and trailing underscores.

  //remove uppercase charters then replace any charter thats not a letter or an underscore with an underscore.
  for (int i = 0; i<25; i++){
    if (input[i] >= 65 && input[i] <= 90){
      input[i] = toLowerCase(input[i]);
    }
    else if (!(input[i] >= 97 && input[i] <= 122) && input[i] != 95 && input[i] != 0){
      input[i] = '_';
    }
  }
  //remove duplicate underscores and underscores from start of array
  int foundChar = 0;
  for (int i = 0; i <25; i++){
    if (!(input[i] >= 97 && input[i] <= 122) && foundChar == 0){
      input[i] = 0;
    }
    else if (foundChar == 0){
      foundChar = 1;
    }
    else{
      if (i >= 1 && input[i] == '_' && input[i+1] == '_'){
        input[i] = 0;
      }
    }
  }

  //remove underscores from end of array
  foundChar = 0;
  for (int i = 24; i >= 0; i--){
    if (!(input[i] >= 97 && input[i] <= 122) && foundChar == 0){
      input[i] = 0;
    }
    else{
      foundChar = 1;
    }
  }
}


int checkInput(char* input){

  //this function makes sure the string as letters and is broken up by underscores
  //IT ONLY WORKS IF IT IS RUN AFTER normalizeInput()

  //returns 0 if the input has breaks and letters, returns 1 otherwise

  int hasBreaks = 0;
  int hasLetters = 0;

  for (int i = 0; i<25; i++){
    if (input[i] == 95){
      hasBreaks = 1;
    }
    else{
      hasLetters = 1;
    }
  }

  if (hasLetters == 1 && hasBreaks == 1){
    return 0;
  }
  else{
    return 1;
  }
}


int main(){
	// Read the string from the keyboard
	
	// Call camelCase
	
	// Print the new string

  int length = 25;
  char input[length];

  for (int i = 0; i<length; i++){
    input[i] = 0;
  }

  printf("input a string %d charters or less: ", length);
  scanf("%[^\n]%*c", input);

  printf("Your Input: ");
  for (int i = 0; i<length; i++){
      printf("%c", input[i]);
  }
  printf("\n");

  normalizeInput(input);
 
  if (checkInput(input) == 1){
    printf("Invalid input string\n");
    return 1;
  }

  camelCase(input);
  printf("After camelCase: ");
  for (int i = 0; i<length; i++){
    printf("%c", input[i]);
  }
  printf("\n"); 

  return 0;
}

