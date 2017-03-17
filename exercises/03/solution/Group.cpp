#include "Group.h"

Group::Group()
{
    numberOfStudents = 0;
}
Group::Group(size_t newNumberOfStudents,Student* newStudents)
{
    numberOfStudents = newNumberOfStudents;
    for(size_t i = 0; i < numberOfStudents; i++)
    {
        students[i] = newStudents[i];
    }
}

size_t Group::getNumberOfStudents() const
{
    return numberOfStudents;
}
void Group::setNumberOfStudents(size_t newNumberOfStudents)
{
    numberOfStudents = newNumberOfStudents;
}

const Student* Group::getStudents() const
{
    return students; //returns an array
}
void Group::setStudents(Student* newStudents,size_t newNumberOfStudents)
{
    numberOfStudents = newNumberOfStudents;
    for(size_t i = 0; i < numberOfStudents; i++)
    {
        students[i].setName(newStudents[i].getName());
        students[i].setCourse(newStudents[i].getCourse());
        students[i].setFN(newStudents[i].getFN());
        students[i].setGrades(newStudents[i].getGrades());
    }
}

size_t Group::getScholarshipStudentsCount() const
{
    size_t cnt = 0;
    for(size_t i = 0; i < numberOfStudents; i++)
    {
        if(students[i].getGPA() > 4.50)
        {
            ++cnt;
        }
    }

    return cnt;
}
double Group::getGPA() const
{
    double sum = 0;
    for(size_t i = 0; i < numberOfStudents; i++)
    {
        sum += getStudents()[i].getGPA(); //example for using getter for array
    }

    return sum / numberOfStudents;
}
int Group::findStudent(const char* findName) const
{
    for(size_t i = 0 ; i < numberOfStudents; i++)
    {
        if(strcmp(findName,students[i].getName()) == 0)
        {
            return i;
        }
    }

    return -1;
}
int Group::findStudent(size_t fn) const
{
    for(size_t i = 0; i < numberOfStudents; i++)
    {
        if(fn == students[i].getFN())
            return i;
    }
    return -1;
}

bool Group::changeFN(const char* name,size_t newFN)
{
    if(findStudent(name) != -1)
    {
        students[findStudent(name)].setFN(newFN);
        return true;
    }
    return false;
}
void Group::print() const
{
    cout<<"-------Group-------"<<endl;
    for(size_t i = 0; i < numberOfStudents; i++)
    {
        students[i].print();
    }
    cout<<"--------------------------------\n";
    cout<<"GPA: "<<getGPA()<<endl;
    cout<<"Scholarship Students Count: "<<getScholarshipStudentsCount()<<endl;
    cout<<"--------------------------------\n";
}
