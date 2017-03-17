#include "Student.h"

Student::Student()
{
    strcpy(name,"");
    course = 1;
    fn = 70000;
    for(size_t i = 0; i < 5; i++)
    {
        grades[i] = 0;
    }
}
Student::Student(const char* newName,size_t newCourse,size_t newFN,int* newGrades) //example for constructor with setters and getters
{
    setName(newName);
    setCourse(newCourse);
    setFN(newFN);
    setGrades(newGrades);
}

const char* Student::getName() const
{
    return name;
}
void Student::setName(const char* newName)
{
    strcpy(name,newName);
}

size_t Student::getCourse() const
{
    return course;
}
void Student::setCourse(size_t newCourse)
{
    course = newCourse;
}

size_t Student::getFN() const
{
    return fn;
}
void Student::setFN(size_t newFN)
{
    fn = newFN;
}

const int* Student::getGrades() const
{
    return grades; //returns array of grades
}
void Student::setGrades(const int* newGrades)
{
    for(size_t i = 0; i < 5; i++)
    {
        grades[i] = newGrades[i];
    }
}

double Student::getGPA() const
{
    double sum = 0;
    for(size_t i = 0; i < 5; i++)
    {
        sum += grades[i];
    }

    return sum / 5;
}
void Student::print() const
{
    cout<<"----------Student Info----------"<<endl;
    cout<<"Name: "<<getName()<<endl;
    cout<<"Course: "<<getCourse()<<endl;
    cout<<"FN: "<<getFN()<<endl;
    cout<<"GPA: "<<getGPA()<<endl;
}

