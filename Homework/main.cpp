#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
    string name;
    string surname;
    int course;

public:
    Student(const string& n, const string& s, int c) : name(n), surname(s), course(c) {}

    string getName() {
        return name;
    }

    string getSurname() {
        return surname;
    }

    int getCourse() {
        return course;
    }

    friend ostream& operator<<(ostream& os, const Student& student) {
        os << student.name << endl;
        os << student.surname << endl;
        os << student.course << endl;
        return os;
    }
};

void printVector(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << student << endl;
    }
    cout << "---------------------------" << endl;
}

void sortByName(vector<Student>& students) {
    for (size_t i = 0; i < students.size(); i++) {
        for (size_t j = 0; j < students.size() - 1; j++) {
            if (students[j].getName() > students[j + 1].getName()) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void stableSortBySurname(vector<Student>& students) {
    for (size_t i = 0; i < students.size(); i++) {
        for (size_t j = 0; j < students.size() - 1; j++) {
            if (students[j].getSurname() > students[j + 1].getSurname()) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

void moveYoungestToStart(vector<Student>& students) {
    for (size_t i = 0; i < students.size(); i++) {
        for (size_t j = 0; j < students.size() - 1; j++) {
            if (students[j].getCourse() > students[j + 1].getCourse()) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

int main() {
    vector<Student> students;

    students.push_back(Student("Stepa", "Doe", 2));
    students.push_back(Student("Sasha", "Smith", 1));
    students.push_back(Student("Grisha", "Brownye", 3));
    students.push_back(Student("Bob", "Scot", 2));
    students.push_back(Student("Charlie", "Davis", 1));

    cout << "Initial list of students:" << endl;
    printVector(students);

    sortByName(students);
    cout << "After sorting by first names:" << endl;
    printVector(students);

    stableSortBySurname(students);
    cout << "After stable sorting by last names:" << endl;
    printVector(students);

    moveYoungestToStart(students);
    cout << "After moving youngest students to the start:" << endl;
    printVector(students);
}