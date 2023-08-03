#include <iostream>
#include <string>
using namespace std;
class Student {
string usn;
string name;
int marks[3];
public:
void readData() {
cout << "Enter USN: ";
cin >> usn;
cout << "Enter Name: ";
cin.ignore();
getline(cin, name);
cout << "Enter Marks for 3 Subjects:" << endl;
for (int i = 0; i < 3; i++) {
cout << "Subject " << i + 1 << ": ";
cin >> marks[i];
}
}
void displayData() {
cout << "USN: " << usn << endl;
cout << "Name: " << name << endl;
cout << "Marks: ";
for (int i = 0; i < 3; i++) {
cout << marks[i] << " ";
}
cout << endl;
}
double calculateAverage() {
int sum = 0;
int lowestMark = marks[0];
for (int i = 0; i < 3; i++) {
sum += marks[i];
if (marks[i] < lowestMark) {
lowestMark = marks[i];
}
}
sum -= lowestMark;
return static_cast<double>(sum) / 2;
}
static Student findTopper(Student students[], int n) {
Student topper = students[0];
double highestAverage = topper.calculateAverage();
for (int i = 1; i < n; i++) {
double average = students[i].calculateAverage();
if (average > highestAverage) {
highestAverage = average;
topper = students[i];
}
}
return topper;
}
};
int main() {
int n;
cout << "Enter the number of students: ";
cin >> n;
Student* students = new Student[n];
 for (int i = 0; i < n; i++) {
cout << "Enter details for Student " << i + 1 << ":" << endl;
students[i].readData();
}
cout << endl;
cout << "Student Details:" << endl;
for (int i = 0; i < n; i++) {
cout << "Student " << i + 1 << ":" << endl;
students[i].displayData();
cout << "Average of Best 2 Marks: " << students[i].calculateAverage() << endl;
cout << endl;
}
Student topper = Student::findTopper(students, n);
cout << "Topper:" << endl;
topper.displayData();
cout << "Average of Best 2 Marks: " << topper.calculateAverage() << endl;
delete[] students;
return 0; }
