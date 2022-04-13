/**
* @file course.h
* @author Javier
* @date April 12, 2022
* @brief Includes the function definitions for the course functions and the course type definition
*/
#include "student.h"
#include <stdbool.h>
 
/**
* Course type stores a course with the course name, code, students and total number of students.
*/
typedef struct _course 
{
  char name[100]; /**< the course's name */
  char code[10]; /**< the course's code */
  Student *students; /**< the student's taking the course*/
  int total_students; /**< total number of students in the course*/
} Course;


void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);


