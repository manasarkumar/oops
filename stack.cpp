#include<iostream>
using namespace std;
#define size 5
class stack {
 int top = -1;
 int stack[size];
 public :
 void push (int ele) {
 if(top == size-1){
 cout<<"Overflow"<<endl;
 } else {
 top++;
 stack[top] = ele;
 cout<<"Element pushed into the stack is "<<stack[top]<<endl;
 }
 }
 void pop(){
 if(top == -1){
 cout<<"Underflow"<<endl;
 } else {
 top--;
 cout<<"Poped element is "<<stack[top]<<endl;
 }
 }
 void display(){
 if(top == -1){
 cout<<"No element";
 } else {
 for(int i = top;i>=0;i--){
 cout<<stack[i]<<endl;
 }
 }
 }
};
int main(){
 int n,ele;
 stack S;
 cout<<"1.Push"<<endl<<"2.pop"<<endl<<"3.Display"<<endl<<"4.Exit";
 while(1){
 cout<<"Enter your choice :";
 cin>>n;
 switch(n){
 case 1: cout<<"Enter no :";
 cin>>ele;
 S.push(ele);
 break;
 case 2: S.pop();
 break;
 case 3: S.display();
 break;
 case 4: exit(0);
 break;
 default : cout<<"Invalid"<<endl;
 }
 }
 return 0;
}
