#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Patient {
protected:
 string name;
 int age;
 string gender;
 string diagnosis;
public:
 Patient(string n, int a, string g, string d) {
 name = n;
 age = a;
 gender = g;
 diagnosis = d;
 }
 void displayInfo() {
 cout << "Name: " << name << endl;
 cout << "Age: " << age << endl;
 cout << "Gender: " << gender << endl;
 cout << "Diagnosis: " << diagnosis << endl;
 }
};
class PediatricPatient : public Patient {
private:
 string guardianName;
public:
 PediatricPatient(string n, int a, string g, string d, string guardian) : Patient(n, a, g, d) {
 guardianName = guardian;
 }
 void displayInfo() {
 cout << "Name: " << name << endl;
 cout << "Age: " << age << endl;
 cout << "Gender: " << gender << endl;
 cout << "Diagnosis: " << diagnosis << endl;
 cout << "Guardian Name: " << guardianName << endl;
 }
};
int main() {
 vector<Patient*> patients;
 // Add adult patients
 patients.push_back(new Patient("John Doe", 45, "Male", "Fever"));
 patients.push_back(new Patient("Jane Smith", 32, "Female", "Injury"));
 // Add pediatric patients
 patients.push_back(new PediatricPatient("Alex Johnson", 8, "Male", "Flu", "Sarah Johnson"));
 patients.push_back(new PediatricPatient("Emily Brown", 4, "Female", "Cold", "Jessica Brown"));
 // Display information of all patients
 for (Patient* patient : patients) {
 patient->displayInfo();
 cout << endl;
 }
 // Cleanup memory
 for (Patient* patient : patients) {
 delete patient;
 }
 return 0;
}
