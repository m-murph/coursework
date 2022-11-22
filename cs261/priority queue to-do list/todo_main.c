/*
 * This is where you will develop your to-do list application using your priority queue
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pq.h"
#include "dynarray.h"


void getInput(char* array){
  fflush(stdin);
  fgets(array, 2000, stdin);
}

void addTask(struct pq* q){
  char* s = (char*)malloc(sizeof(char)*100);
  char prio[25];

  printf("Please enter the task description (max 100 charters): ");
  getInput(s);
  //printf("\n");
  s[strcspn(s, "\r\n")] = 0;

  printf("Please enter the task priority (0-999): ");
  getInput(prio);
  int num; 
  
  sscanf(prio, "%d", &num);
  addPq(q, s, num);
  printf("The task ");
  printf("'%s'", s);
  printf(" has been added to your to-do list.\n\n");
}

pq* loadPQ(struct pq* q){
  freePq(q);
  q = createPq();
  char fname[100];
  printf("What is the name of the file you want to load from? ");
  getInput(fname);
  fname[strcspn(fname, "\r\n")] = 0;
  FILE* reader = fopen(fname, "r");
  char line[100];
  char sprio[25];
  
  if (reader == NULL){
    printf("Error, file not found.\n");
    return q;
  }

  while (fgets(line, sizeof(line), reader) != NULL){
    char* line2 = (char*)malloc(sizeof(char)*sizeof(line));
    int prio;
    fgets(sprio, sizeof(sprio), reader);
    line[strcspn(line, "\r\n")] = 0;
    sprio[strcspn(sprio, "\r\n")] = 0;
    //printf("%s\n", line);
    //printf("%s\n", sprio);
    sscanf(sprio, "%d", &prio);
    for (int i = 0; i<sizeof(line); i++){
      line2[i] = line[i];
    }
    addPq(q, line2, prio);
  }
  fclose(reader);
  return q;
}

void savePQ(struct pq* q){
  char fname[100];
  printf("What is the name of the file you want to save to? ");
  getInput(fname);
  fname[strcspn(fname, "\r\n")] = 0;
  FILE* writer = fopen(fname, "w");

  int k = 0;
  while(isemptyPq(q) == 0){
    char* message = (char*)getPq(q);
    fprintf(writer, "%s", message);
    fprintf(writer, "\n");
    fprintf(writer, "%d", k);
    fprintf(writer, "\n");
    removePq(q);
    k++;
  }
  fclose(writer);
}



int main(int argc, char** argv)
{
  struct pq* q = createPq();

  while (1){
    char input[10];
    printf("Press: \n");
    printf(" 'l' to load to-do list from a file\n");
    printf(" 's' to save to-do list to a file\n");
    printf(" 'a' to add a new task\n");
    printf(" 'g' to get the first task\n");
    printf(" 'r' to remove the first task\n");
    printf(" 'p' to print the list\n");
    printf(" 'e' to exit the program\n");

    getInput(input);

    if(*input == 'l'){
      q = loadPQ(q);
    }
    else if (*input == 's'){
      savePQ(q);
    }
    else if (*input == 'a'){
      addTask(q);
    }
    else if (*input == 'g'){
      char* message = (char*)getPq(q);
      if(message != NULL){
        printf("\nYour first task is: ");
        printf("%s\n", message);
        printf("\n");
      }
      else{
        printf("\nThere is nothing in the to-do list!\n\n");
      }
    }
    else if (*input == 'r'){
      char* message = (char*)getPq(q);
      if(message != NULL){
        printf("\nYou removed: ");
        printf("%s\n", message);
        printf("\n");
        removePq(q);
      }
      else{
        printf("\nThere is nothing in the to-do list!\n\n");
      }
    }
    else if (*input == 'p'){
      printf("\n");
      printPq(q);
      printf("\n");
    }
    else if (*input == 'e'){
      printf("program ending...\n");
      break;
    }
    else{
      printf("Error, unrecognized input, try again.\n");
    }
  }
  freePq(q);
  return 0;
}