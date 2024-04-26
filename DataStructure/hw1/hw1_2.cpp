/*
데이타구조 04분반 22000220 남종운
*/
#include <iostream>
using namespace std;

class RC 
{
    private:
    string dorm;
    int room;

    public:
    // default constructor
    RC() : dorm(" "), room(0) {}
    // parameterized constructor
    RC(string name, int num){
        dorm = name;
        room = num;
    }
    // get dorm name
    string getDorm() const {
        return dorm;
    }
    // assign dorm
    void AssignDorm(string d){
        dorm = d;
    }
    // get room number
    int getRoom() const {
        return room;
    }
    // assign room
    void AssignRoom(int r){
        room = r;
    }
};

class Student
{
    private:
    string name;
    RC address;

    public:
    // constructor
    Student(string name, RC &addr){
        this->name = name;
        address = addr;
    }
    // get student name
    string getName() const {
        return name;
    }
    // get address (RC name & room number)
    // of student
    RC getAddress() const {
        return address;
    }
    // display student name and address
    // using member function of class Student
    void displayInfo() const {
        cout << "Student Name: " << name << endl;
        cout << "Address is " << address.getDorm()<< ", " << address.getRoom() << endl;
    }
};

int main(){
    RC kuyper1;
    RC kuyper2("Creation", 204);
    RC torrey1("Vision", 312);
    // Create a Customer object using the Address object
    Student student1("Alan Turing", kuyper1);
    Student student2("Beatles", torrey1);
    Student student3("Timothee Chalamet",kuyper2);
    // Display customer information
    student1.displayInfo();
    student2.displayInfo();
    student3.displayInfo();

    return 0;
}