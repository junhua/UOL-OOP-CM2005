// This program needs better comments and formatting
// TODO: Improve the comments and make the code more readable
#include<iostream>
#include<string>
using namespace std;
class Student{
private:
string n;int a;double g;
public:
Student(string name,int age,double gpa){
n=name;a=age;g=gpa;
}
void p(){
cout<<"Name: "<<n<<endl;
cout<<"Age: "<<a<<endl;
cout<<"GPA: "<<g<<endl;
}
double c(){
if(g>=3.5)return 4.0;
else if(g>=3.0)return 3.0;
else if(g>=2.0)return 2.0;
else return 0.0;
}
string getL(){
if(c()==4.0)return"A";
else if(c()==3.0)return"B";
else if(c()==2.0)return"C";
else return"F";
}
};
int main(){
// TODO: Add proper variable names and comments
Student s("John",20,3.8);
s.p();
cout<<"Grade: "<<s.getL()<<endl;
// TODO: Add more students and calculate average
Student s2("Jane",19,2.9);
s2.p();
cout<<"Grade: "<<s2.getL()<<endl;
double avg=(3.8+2.9)/2;
cout<<"Average GPA: "<<avg<<endl;
return 0;
}

/*
Instructions:
1. Add appropriate comments to explain the code
2. Use proper formatting and indentation
3. Improve variable and function names
4. Add documentation comments for the class and methods
5. Follow consistent naming conventions
6. Break long lines for readability
7. Remove redundant comments
8. Add meaningful comments where needed

Tips:
- Use descriptive names
- Add proper spacing
- Document class purpose
- Explain complex logic
- Use consistent style
- Format for readability
*/
