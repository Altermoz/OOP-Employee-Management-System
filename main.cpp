#include <iostream>
using namespace std;

class Employee {
    protected:
        string name;
        int id;
    
    public:
        Employee(string n, int i): name (n), id(i) {}

        virtual void calculateSalary() = 0;

        void displayInfo() {
            cout << "ID: " << id << ", Name: " << name << endl;
        }

        virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
    private:
        double monthlySalary;
    
    public:
        FullTimeEmployee(string n, int i, double salary) : Employee(n, i), monthlySalary(salary) {}
    
    void calculateSalary() override {
        cout << "Full-Time Employee Salary: $" << monthlySalary << endl;
    }
};

class PartTimeEmployee : public Employee {
    private:
        double hourlyRate;
        int hoursWorked;
    
    public:
        PartTimeEmployee(string n, int i, double rate, int hours) : Employee(n, i), hourlyRate(rate), hoursWorked(hours) {}
    
        void calculateSalary() override {
            cout << "Part-Time Employee Salary: $" << (hourlyRate * hoursWorked) << endl;
        }
};

int main() {
    Employee* emp1 = new FullTimeEmployee("Alice", 101, 5000);
    Employee* emp2 = new PartTimeEmployee("Bob", 102, 20, 25);

    cout << "\n📌 Employee Details & Salary Calculation:\n";
    emp1 -> displayInfo();
    emp1 -> calculateSalary();

    cout << endl;

    emp2 -> displayInfo();
    emp2 -> calculateSalary();

    delete emp1;
    delete emp2;

    return 0;
}