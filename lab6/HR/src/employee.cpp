#include <iostream>
#include "employee.hpp"


using namespace std;
using std::cout;


Employee::Employee(string _id, string _name, string _surname, string _departmentId, string _position){
    this -> id = _id;
    this -> name = _name;
    this -> surname = _surname;
    this -> departmentId = _departmentId;
    this -> position = _position;
}

Employee::Employee() {};


string Employee::get_id()            { return this->id; }
string Employee::get_name()          { return this->name; }  
string Employee::get_surname()       { return this->surname; }
string Employee::get_departmentId()  { return this->departmentId; }
string Employee::get_position()      { return this->position; }

