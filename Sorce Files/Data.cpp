#include <iostream>
#include <string>
#include <iomanip> 
#include "Data.h"
#include "Presentation.h"

bool checkInteger(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) == false)
			return false;
	}
	return true;
}
int getIndexById(STUDENTS* students, int count, int ID)
{

	for (int j = 0; j < count; j++)
	{
		if (students[j].studentID == ID)
		{
			return j;
		}

	}
	return -1;
}
void createStudent(STUDENTS* students, int& studentCount, int& maxStudentID, STUDENTS newStudent)

{
	newStudent.studentID = maxStudentID++;
	students[studentCount] = newStudent;
	studentCount++;
}
void updateStudent(STUDENTS* students, int studentCount, int studentID, STUDENTS newStudent)
{

	int index = getIndexById(students, studentCount, studentID);

	students[index] = newStudent;

}
void deleteStudent(STUDENTS* students, int& studentCount, int studentID)
{

	int index = getIndexById(students, studentCount, studentID);

	for (int j = index; j < studentCount - 1; j++)
	{
		students[j] = students[j + 1];
	}

	studentCount--;

}
STUDENTS getStudent(STUDENTS* students, int& studentCount, int studentID)
{

	int index = getIndexById(students, studentCount, studentID);

	return students[index];

}
bool checkAvailableStudents(STUDENTS* students, int& studentCount, string searchedRole)
{
	int studentsWithRole = 0;
	for (int i = 0; i < studentCount; i++)
	{
		if (students[i].role == searchedRole and students[i].hasTeam == false)
		{
			studentsWithRole++;
		}
	}
	if (studentsWithRole == 0)
	{
		cout << "there are no available students with this role." << endl;
		return false;
	}
	else
	{
		return true;
	}
}
int getTeacherIndexByID(TEACHERS* teachers, int& teacherCount, int teacherID)
{

	for (int j = 0; j < teacherCount; j++)
	{
		if (teachers[j].teacherID == teacherID)
		{
			return j;
		}

	}
	return -1;
}
void createTeacher(TEACHERS* teachers, int& teacherCount, int& maxTeacherID, TEACHERS newTeacher)

{
	newTeacher.teacherID = maxTeacherID++;
	teachers[teacherCount] = newTeacher;
	teacherCount++;
}
void updateTeacher(TEACHERS* teachers, int teacherCount, int teacherID, TEACHERS newTeacher)
{

	int index = getTeacherIndexByID(teachers, teacherCount, teacherID);

	teachers[index] = newTeacher;

}
void deleteTeacher(TEACHERS* teachers, int& teacherCount, int teacherID)
{
	int index = getTeacherIndexByID(teachers, teacherCount, teacherID);

	for (int j = index; j < teacherCount - 1; j++)
	{
		teachers[j] = teachers[j + 1];
	}
	teacherCount--;
}
TEACHERS getTeacher(TEACHERS* teachers, int& teacherCount, int teacherID)
{
	int index = getTeacherIndexByID(teachers, teacherCount, teacherID);
	return teachers[index];
}