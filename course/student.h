/**
* @file student.h
* @author Javier
* @date April 12, 2022
* @brief Includes the function defintions for the student functions and the student type definiton
*/

/**
* Student type that has a student's first name, last name, student ID, grades and number of grades
*/
typedef struct _student 
{ 
  char first_name[50]; /**< the student's first name*/
  char last_name[50]; /**< the student's last name*/
  char id[11]; /**< the student's ID*/
  double *grades;  /**<the student's grade*/
  int num_grades;  /**<the number of grades */
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
