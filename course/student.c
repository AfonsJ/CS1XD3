/**
* @file student.c
* @author Javier
* @date April 12, 2022
* @brief Students functions such as adding grades to a student, getting
*        the average of a student's grades, printing their info and randomly 
*        generating a student.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/**
* Adds a grade to a student
*
* @param student a pointer to a student
* @param grade a grade to assign to a student
* @return nothing
*/
void add_grade(Student* student, double grade)
{
  //Increments the number of grades
  student->num_grades++;
  //Dynamically allocates space to the array of grades
  if (student->num_grades == 1) student->grades = calloc(1, sizeof(double));
  else 
  {
    student->grades = 
      realloc(student->grades, sizeof(double) * student->num_grades);
  }
  //Adds the grade to the array
  student->grades[student->num_grades - 1] = grade;
}

/**
* Returns the average of a student's grades
*
* @param student a pointer to a student
* @return the average of a student's grades
*/
double average(Student* student)
{
  //If there are no grades then return 0
  if (student->num_grades == 0) return 0;

  //Returns the average of the students grades using each grade and the number of grades
  double total = 0;
  for (int i = 0; i < student->num_grades; i++) total += student->grades[i];
  return total / ((double) student->num_grades);
}

/**
* Prints all the info about a student, their name, ID, grades and average
*
* @param student a pointer to a student
* @return nothing
*/
void print_student(Student* student)
{
  //Prints all the info on a student: name, ID, grades and overall average
  printf("Name: %s %s\n", student->first_name, student->last_name);
  printf("ID: %s\n", student->id);
  printf("Grades: ");
  for (int i = 0; i < student->num_grades; i++) 
    printf("%.2f ", student->grades[i]);
  printf("\n");
  printf("Average: %.2f\n\n", average(student));
}

/**
* Returns a randomly generated student, with a name, id and grades
* 
* @param grades the number of grades to add to the student
* @return a randomly generated student
*/
Student* generate_random_student(int grades) 
{
  //List of first names and last names
  char first_names[][24] = 
    {"Shahrzad", "Leonti", "Alexa", "Ricardo", "Clara", "Berinhard", "Denzel",
     "Ali", "Nora", "Malcolm", "Muhammad", "Madhu", "Jaiden", "Helena", "Diana",
     "Julie", "Omar", "Yousef",  "Amir", "Wang", "Li", "Zhang", "Fen", "Lin"};

  char last_names[][24] = 
   {"Chen", "Yang", "Zhao", "Huang", "Brown", "Black", "Smith", "Williams", 
    "Jones", "Miller", "Johnson", "Davis", "Abbas", "Ali", "Bakir", "Ismat", 
    "Khalid", "Wahed", "Taleb", "Hafeez", "Hadid", "Lopez", "Gonzalez", "Moore"};
  
  //Declares a new student of type student
  Student *new_student = calloc(1, sizeof(Student));

  //Randonmly selects a first and last name
  strcpy(new_student->first_name, first_names[rand() % 24]);
  strcpy(new_student->last_name, last_names[rand() % 24]);

  //Randomly selects a new student ID
  for (int i = 0; i < 10; i++) new_student->id[i] = (char) ((rand() % 10) + 48);
  new_student->id[10] = '\0';

  //Adds grades to the new student
  for (int i = 0; i < grades; i++) 
  {
    add_grade(new_student, (double) (25 + (rand() % 75)));
  }

  return new_student;
}