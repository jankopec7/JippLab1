#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

#include "employee.hpp"


using std::vector;
using std::unordered_map;
using std::string;

class hrms {
    
    private:
            unordered_map<string, vector<string>>       departments;
            unordered_map<string, class Employee>       allEmployees;
            unordered_map<string,double>        salaries;
    public:
            hrms(void);
            void add(Employee &employee, string departmentId, double salary);
            void printDepartment(string departmentId);
            void changeSalary(string employee_id, double salary);
            void printSalaries();
            void printSalariesSorted();
};
