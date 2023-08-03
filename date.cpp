#include <iostream>
#include <string>
using namespace std;
class Date {
private:
 int day;
 int month;
 int year;
public:
 Date() {
 day = 1;
 month = 1;
 year = 2000;
 }
 Date(int d, int m, int y) {
 day = d;
 month = m;
 year = y;
 }
 Date(string dateStr) {
 // Assuming the date string is in the format "DD-MM-YYYY"
 string delimiter = "-";
 size_t pos = 0;
 string token;
 // Extract day
 pos = dateStr.find(delimiter);
 token = dateStr.substr(0, pos);
 day = stoi(token);
 dateStr.erase(0, pos + delimiter.length());
 // Extract month
 pos = dateStr.find(delimiter);
 token = dateStr.substr(0, pos);
 month = stoi(token);
 dateStr.erase(0, pos + delimiter.length());
 // Extract year
 year = stoi(dateStr);
 }
 void displayDate() {
 cout << "Date: " << day << "-" << month << "-" << year << endl;
 }
};
int main() {
 Date defaultDate;
 Date specificDate(15, 9, 2022);
 Date dateString("24-06-2023");
 defaultDate.displayDate();
 specificDate.displayDate();
 dateString.displayDate();
 return 0;
}
