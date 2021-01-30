#include <iostream>
#include <string>
#include "hrms.hpp"

using namespace std;

hrms::hrms(){};

void hrms::add(Employee& employee, string departmentId, double salary){

    allEmployees[employee.get_id()] = employee;
    departments[employee.get_departmentId()].push_back(employee.get_id());
    salaries[employee.get_id()] = salary;
}

void hrms::printDepartment(string departmentId){

    cout << "//Pracownicy departamentu: " << departmentId << "//\n";
    auto department = departments[departmentId]; 

    for (string &id : department){

        Employee &e = allEmployees.find(id)->second;
        cout << id << " = " << e.get_name() << " " << e.get_surname() << endl;
    }
    cout << endl;
}

void hrms::changeSalary(string employee_id, double salary){

    salaries[employee_id] = salary;
}

void hrms::printSalaries(){

    cout << "\n// Wynagrodzenia: //\n";
    for (auto &s : allEmployees){

        Employee &e = s.second;
        cout << "ID: " << e.get_id() << endl;
        cout << "Name: " << e.get_name() << endl;
        cout << "Surname: " << e.get_surname() << endl;
        cout << "Department ID: " << e.get_departmentId() << endl;
        cout << "Position: " << e.get_position() << endl;
        cout << "Salary: " << salaries[e.get_id()]<< "PLN\n\n";
    }
    
}

void hrms::printSalariesSorted(){
    
    std::vector<pair<string, Employee>> elements(this->allEmployees.begin(), this->allEmployees.end());
    std::sort(elements.begin(), elements.end(), 
    [this](pair<string, Employee>& p1, pair<string, Employee>& p2)
    {
        return this->salaries[p1.first] > this->salaries[p2.first];
    });

    cout << "Pracownicy w kolejności malejącego wynagrodzenia:" <<endl;
    for (auto &s : elements){
        auto& e = s.second;
        string id = e.get_id();

        cout << "ID: " << id << "\n";
        cout << "Name: " << e.get_name() << "\n";
        cout << "Surname: " << e.get_surname() << "\n";
        cout << "Department ID: " << e.get_departmentId() << "\n";
        cout << "Position: " << e.get_position() << "\n";
        cout << "Salary: " << this->salaries[id] << "PLN\n\n";
    }
}
