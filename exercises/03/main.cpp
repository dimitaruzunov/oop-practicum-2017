#include "Group.h"

void build_group()
{
    int gradesGosho[5] = {6, 5, 4, 6, 5};
    Student gosho("Gosho", 1, 75251, gradesGosho);

    int gradesPesho[5] = {6, 6, 4, 6, 6};
    Student pesho("Pesho", 1, 74231, gradesPesho);

    int gradesVlado[5] = {6, 5, 5, 6, 2};
    Student vlado("Vlado", 1, 71211, gradesVlado);

    int gradesGinka[5] = {3, 5, 4, 3, 2};
    Student ginka("Ginka", 1, 75256, gradesGinka);

    int gradesMariq[5] = {6, 6, 3, 4, 5};
    Student mariq("Mariq", 1, 75252, gradesMariq);

    Student students[5] = {gosho,pesho,vlado,ginka,mariq};

    Group group = Group(5,students);

    group.print();
}

int main()
{
    build_group();

    return 0;
}
