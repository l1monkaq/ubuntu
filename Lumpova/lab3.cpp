#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Subject {
    string name;
    int credits;
};

struct Teacher {
    string name;
    string department;
};

struct Student {
    string name;
    int age;
    string groupName;
};

struct Group {
    string groupName;
    vector<Student> students;
};

struct GradeScale {
    string gradeLetter;
    int minScore;
    int maxScore;
};

struct Report {
    Student student;
    Subject subject;
    Teacher teacher;
    int score;
    string grade;
};

int main() {
    Subject sub1;
    sub1.name = "Mathematics";
    sub1.credits = 4;

    Teacher t1;
    t1.name = "Mr. Smith";
    t1.department = "Math Department";

    Student s1;
    s1.name = "Alice Johnson";
    s1.age = 18;
    s1.groupName = "Group A";

    GradeScale gA;
    gA.gradeLetter = "A";
    gA.minScore = 90;
    gA.maxScore = 100;

    Report r1;
    r1.student = s1;
    r1.subject = sub1;
    r1.teacher = t1;
    r1.score = 95;
    r1.grade = "A";

    cout << "=== Report ===" << endl;
    cout << "Student: " << r1.student.name << endl;
    cout << "Group: " << r1.student.groupName << endl;
    cout << "Subject: " << r1.subject.name << endl;
    cout << "Teacher: " << r1.teacher.name << endl;
    cout << "Score: " << r1.score << endl;
    cout << "Grade: " << r1.grade << endl;

    return 0;
}
