#include <iostream>

using namespace std;

#include "hrms.hpp"
#include "employee.hpp"

int main() {

    Employee employee1("1","Jan","Nowak","I","Java Developer");
    Employee employee2("2","Tomasz","Kowalski","I","Intern");
    Employee employee3("3","Andrzej","Gąsienica","III","Cleaner");
    Employee employee4("4","Tymoteusz","Urbaś","II","Cook");
    Employee employee5("5","Jerzy","Dudek","II","Chief");
    Employee employee6("6","Anna","Wesołowska","III","Secretary");
    Employee employee7("7","Mateusz","Kopeć","I","Senior Java Developer");
    Employee employee8("8","Lech","Kokos","II","Waiter");
    Employee employee9("9","Eugeniusz","Okular","III","Security");
    Employee employee10("10","Krzysztof","Ibisz","I","Frontend Developer");

    hrms x;

    x.add(employee1,"I",15000);
    x.add(employee2,"I",3500);
    x.add(employee3,"III",3300);
    x.add(employee4,"II",5500);
    x.add(employee5,"II",8000);
    x.add(employee6,"III",4100);
    x.add(employee7,"I",25000);
    x.add(employee8,"II",3600);
    x.add(employee9,"III",5000);
    x.add(employee10,"I",12000);

    x.printDepartment("I");
    x.printSalaries();
    x.printSalariesSorted();

    x.changeSalary(employee2.get_id(), 3500);
    x.changeSalary("2", 30000);
    x.changeSalary(employee7.get_id(), 25000);
    x.changeSalary("7", 6000);

    x.printSalaries();
    x.printSalariesSorted();

    return 0;
}

