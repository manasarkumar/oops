#include <iostream>
#include <string>
using namespace std;
class Employee {
int empNo;
string empName;
double basicSalary;
double DA;
double IT;
double netSalary;
double grossSalary;
public:
void readData() {
cout << "Enter Employee Number: ";
cin >> empNo;
cin.ignore(); // Ignore newline character left in the input stream
cout << "Enter Employee Name: ";
getline(cin, empName);
cout << "Enter Basic Salary: ";
cin >> basicSalary;
}
void calculateNetSalary() {
DA = 0.52 * basicSalary;
grossSalary = DA + basicSalary;
IT = 0.30 * grossSalary;
netSalary = DA + basicSalary - IT;
}
void printData() {
cout << "Employee Number: " << empNo << endl;
cout << "Employee Name: " << empName << endl;
cout << "Basic Salary: " << basicSalary << endl;
cout << "DA: " << DA << endl;
cout << "IT: " << IT << endl;
cout << "Gross Salary: " << grossSalary << endl;
cout << "Net Salary: " << netSalary << endl;
cout << endl;
}
};
int main() {
int n;
cout << "Enter the number of employees: ";
cin >> n;
Employee* employees = new Employee[n];
for (int i = 0; i < n; i++) {
cout << "Enter details for Employee " << i + 1 << ":" << endl;
employees[i].readData();
employees[i].calculateNetSalary();
}
cout << endl;
cout << "Employee Details:" << endl;
for (int i = 0; i < n; i++) {
cout << "Employee " << i + 1 << ":" << endl;
employees[i].printData();
}
delete[] employees; // Release the memory allocated for the array of employees
return 0;
}
