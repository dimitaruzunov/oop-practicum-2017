#pragma once

#include "Student.h"

class Group
{
private:
    size_t numberOfStudents;
    Student students[30]; //Maximum number of students in a group can't be >= 30
public:
    Group();
    Group(size_t,Student*);

    size_t getNumberOfStudents() const;
    void setNumberOfStudents(size_t);

    const Student* getStudents() const;
    void setStudents(Student*,size_t numberOfStudents);

    size_t getScholarshipStudentsCount() const;
    double getGPA() const;
    int findStudent(const char*) const;
    int findStudent(size_t) const;
    bool changeFN(const char*,size_t);
    void print() const;

};
