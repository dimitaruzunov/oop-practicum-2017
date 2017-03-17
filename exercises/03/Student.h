#pragma once

#include <iostream>
#include <cstring>

using namespace std;


class Student
{
private:
    char name[30];
    size_t course;
    size_t fn;
    int grades[5];
public:
    Student();
    Student(const char*,size_t,size_t,int*);

    const char* getName() const;
    void setName(const char*);

    size_t getCourse() const;
    void setCourse(size_t);

    size_t getFN() const;
    void setFN(size_t);

    const int* getGrades() const;
    void setGrades(const int*);

    double getGPA() const;
    void print() const;

};
