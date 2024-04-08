//PROGRAMMING 1 PROJECT!!!!
//Idea from https://www.geeksforgeeks.org/top-50-cpp-project-ideas-for-beginners-advanced/
#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Course {
public:
    string name;
    int credits;
    double grade;

    Course(string n, int c, double g){ // Constructor to initialize Course objects
        name = n;
        credits = c;
        grade = g;
    }
};

class GPAcalculator {   // Definition of a GPAcalculator class
private:
    vector<Course*> courses;    // Vector to store pointers to Course objects

public:
    void addCourse(string name, int credits, double grade) { // Method to add a course to the calculator
        Course* course = new Course(name, credits, grade);    // Creating a new Course object
        courses.push_back(course); // Adding the pointer to the Course object to the vector
    }

    double calculateGPA() { //calculate GPA function
        double totalCredits = 0;
        double totalPoints = 0;

        for (Course* course : courses) {    // Looping through each Course object in the vector
            totalCredits += (*course).credits;
            totalPoints += (*course).credits * (*course).grade;
        }

        return totalPoints / totalCredits;
    }

    ~GPAcalculator() { // Destructor to free memory
        for (Course* course : courses) {    // Looping through each Course object in the vector
            delete course;
        }
    }
};

int main() {
    double gpa;
    double OldGpa;
    double NewGpa;
    string name;
    int credits;
    double grade;
    int numCourses;

    GPAcalculator calculator;   // Creating a GPAcalculator object
    cout << "Enter your current GPA or 0 if you don't have one: ";

    while(!(cin >> OldGpa)) { //Error While loop from https://www.youtube.com/watch?v=m2P5A4nR51g
        cout << "Error: Enter GPA:"; //Explain Error
        cin.clear(); //Clear the previous input
        cin.ignore(123,'\n'); //Discard previous input


    }

    cout << "\nEnter the number of courses:";

    while(!(cin >> numCourses)) {
        cout << "Error: Enter the number of courses:";
        cin.clear();
        cin.ignore(123,'\n');
    }
    if(numCourses <= 0) {   //
        cout << "Program Finsished.";
        return 0;
    }

    for (int i = 0; i < numCourses; i++) { // Loop to input details of each course
        cout << "Enter the name of course " << i + 1 << ":";
        cin >> name;
        cout << "Enter the number of credits for " << name << ":";

        while(!(cin >> credits)) {
            cout << "Error: Enter the number of credits for " << name << ":";
            cin.clear();
            cin.ignore(123,'\n');

        }
        while(credits <= 0) {   // Validating credits
            cout << name << " has to have credits:";
            cin >> credits; //
        }
        cout << "Enter the grade for " << name << " (0-4):";

        while(!(cin >> grade)) {
            cout << "Error: Enter grade:";
            cin.clear();
            cin.ignore(123,'\n');


        }
        while(grade > 4 || grade < 0) { // Validating grade
            cout << "Invalid grade for " << name << ". Try again (0-4):";
            cin >> grade;
        }

        calculator.addCourse(name, credits, grade);   // Adding course to the calculator
    }

    gpa = calculator.calculateGPA();   // Calculating GPA

    if(OldGpa != 0) {
        NewGpa = (gpa + OldGpa)/2;  // Calculating GPA by taking the average of the old GPA and the new one
        cout << "\nYour GPA is: " << NewGpa << endl;
    }
    else {
        cout << "\nYour GPA is: " << gpa << endl;
    }


    return 0;
}
