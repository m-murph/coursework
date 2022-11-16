/* CS261- Assignment 1A - Question 1
   Name: Michael Murphy
   Date: 9/22/2022
   Solution description:
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student
{
	int id;
	int score;
};

struct student* allocate()
{
     // Allocate memory for ten students*/
     // Return the pointer*/

     struct student* students = (struct student*)malloc(sizeof(struct student) * 10);
     return students;
}

void generate(struct student* students)
{
     /* Generate random and unique IDs and random scores for ten students, 
	IDs being between 1 and 10, scores between 0 and 100 */  

     srand(time(NULL));
     //10 unique ids
     int ids[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     int index1;
     int index2;
     int tmp;
     //shuffle ids
     for (int i = 0; i<25; i++){
          index1 = rand() % 10;
          index2 = rand() % 10;
          tmp = ids[index1];
          ids[index1] = ids[index2];
          ids[index2] = tmp;
     }
     //assign ids
     for (int i = 0; i<10; i++){
          students[i].id = ids[i];
          students[i].score = rand() % 101;
     }
}

void output(struct student* students)
{
     /* Output information about the ten students in the format:
        ID1 Score1
        ID2 score2
        ID3 score3
        ...
        ID10 score10*/

     for (int i = 0; i<10; i++){
          printf("ID: %d, Score: %d\n", students[i].id, students[i].score);
     }
}

void summary(struct student* students)
{
     /* Compute and print the minimum, maximum and average scores of the 
	ten students */ 
     int min = 101;
     int max = -1;
     int total = 0;

     //find max, min and tally up all the scores
     for (int i = 0; i<10; i++){
          if (students[i].score < min){
               min = students[i].score;
          }
          if (students[i].score > max){
               max = students[i].score;
          }
          total = total + students[i].score;
     }
     printf("Min: %d, Max: %d, Average: %f\n", min, max, total/10.0);
}

void deallocate(struct student* stud)
{
     // Deallocate memory from stud
     if (stud != NULL){
          free(stud);
     }  
}

int main()
{
     // Call allocate
    
    // Call generate
    
    // Call output
    
    // Call summary
    
    // Call deallocate

    struct student* stud = 0;
    stud = allocate();

    generate(stud);

    output(stud);

    summary(stud);

    deallocate(stud);
    
    return 0;
}

