/**
* @file course.c
* @author Javier
* @date April 12, 2022
* @brief Course functions such as enrolling students, printing course info,
*        printing the top student and giving a list of the passing students in a course
*/
#include "course.h"
#include <stdlib.h>
#include <stdio.h>
 
/**
* Enrolls a student in a given course
*
* @param course a pointer to a course
* @param student  a pointer to a student
* @return nothing
*/
void enroll_student(Course *course, Student *student)
{ 
  //Increment the number of students enrolled
  course->total_students++;

  //Dynamically reallocates the array of students
  if (course->total_students == 1) 
  {
    course->students = calloc(1, sizeof(Student));
  }
  else 
  {
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
  }
  
  course->students[course->total_students - 1] = *student;
}

/**
* Prints a given course's name, code and total students enrolled 
*
* @param course a pointer to a course
* @return nothing
*/
void print_course(Course* course)
{
  //Prints the name, course code, total number of students and each student enrolled
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}

/**
* Returns the top student in a given course
*
* @param course a pointer to a course
* @return A pointer to the top student in a course
*/
Student* top_student(Course* course)
{
  //If there are no students then return null
  if (course->total_students == 0) return NULL;
 
  //Sorts through the students to find the student with the highest average
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
 
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      max_average = student_average;
      student = &course->students[i];
    }   
  }

  return student;
}

/**
* Returns a list of passing students in a given course
*
* @param course a pointer to a course
* @param total_passing the number of passing students
* @return a list of passing students
*/
Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  //Increment the number of student passing if the average of a student is equal to or over 50
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++;
  
  //Dyanmically reallocate the array of students passing, with the number of students passing
  passing = calloc(count, sizeof(Student));

  //Populate the array with passing students
  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  }

  *total_passing = count;

  return passing;
}