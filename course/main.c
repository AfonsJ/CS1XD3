/**
* @mainpage Course and Student function demonstrations
*
* Shows multiple course and student functions, including:
* - enrolling a student in course
* - printing course information
* - finding the top student in a class
* - printing student information
* - finding the number of students passing
* - getting a list of passing students in a course
*
* @file main.c
* @author Javier
* @date April 12, 2022
* @brief Runs the student and course functions.
*/

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

/**
* Creates a course, populates it with random students and demonstrates
* the different course and student functions.
*/
int main()
{
  srand((unsigned) time(NULL));

  //Create a course, with a name and course code
  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  //Enroll students in the course
  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8));
  
  //Print information about the course
  print_course(MATH101);

  //Get the top student in the course, and print who it is
  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  //Get the number of students passing in the course, and print it and a list of the students passing.
  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  return 0;
}