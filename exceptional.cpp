#include <iostream>
#include <exception>
using namespace std;
// Custom exception class for divide by zero
class DivideByZeroException : public exception {
public:
 const char* what() const throw() {
 return "Error: Divide by zero exception.";
 }
};
// Custom exception class for negative number input
class NegativeNumberException : public exception {
public:
 const char* what() const throw() {
 return "Error: Negative number exception.";
 }
};
double divideNumbers(int numerator, int denominator) {
 if (denominator == 0) {
 throw DivideByZeroException();
 }
 return static_cast<double>(numerator) / denominator;
}
int main() {
 int numerator, denominator;
 cout << "Enter the numerator: ";
 cin >> numerator;
 cout << "Enter the denominator: ";
 cin >> denominator;
 try {
 double result = divideNumbers(numerator, denominator);
 cout << "Result: " << result << endl;
 } catch (const DivideByZeroException& ex) {
 cout << ex.what() << endl;
 } catch (const NegativeNumberException& ex) {
 cout << ex.what() << endl;
 } catch (...) {
 cout << "Unknown exception occurred." << endl;
 }
 return 0;
}
