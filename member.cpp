#include <iostream>
using namespace std;
class ListNode {
public:
 int data;
 ListNode* next;
 ListNode(int value) {
 data = value;
 next = nullptr;
 }
};
class List {
private:
 ListNode* head;
public:
 List() {
 head = nullptr;
 }
 void insertFront(int value) {
 ListNode* newNode = new ListNode(value);
 if (head == nullptr) {
 head = newNode;
 } else {
 newNode->next = head;
 head = newNode;
 }
 cout << "Element " << value << " inserted at the front of the list." << endl;
 }
 void deleteFront() {
 if (head == nullptr) {
 cout << "List is empty. Cannot delete element from the front." << endl;
 } else {
 int deletedValue = head->data;
 ListNode* temp = head;
 head = head->next;
 delete temp;
 cout << "Element " << deletedValue << " deleted from the front of the list." << endl;
 }
 }
 void displayList() {
 if (head == nullptr) {
 cout << "List is empty." << endl;
 } else {
 ListNode* current = head;
 cout << "Elements in the list: ";
 while (current != nullptr) {
 cout << current->data << " ";
 current = current->next;
 }
 cout << endl;
 }
 }
};
int main() {
 List myList;
 myList.insertFront(10);
 myList.insertFront(20);
 myList.insertFront(30);
 myList.displayList(); // Output: Elements in the list: 30 20 10
 myList.deleteFront();
 myList.displayList(); // Output: Elements in the list: 20 10
 myList.deleteFront();
 myList.deleteFront();
 myList.displayList(); // Output: List is empty.
 return 0;
}
