#pragma once

#include <iostream>
#include <string>

using namespace std;
class Employee {

    private:
            string id;
            string name;
            string surname;
            string departmentId;
            string position;

    public:

            Employee(string _id, string _name, string _surname, string _departmentId, string _position);
            Employee();
            
            string get_id();
            string get_name();
            string get_surname();
            string get_departmentId();
            string get_position();
          

};
