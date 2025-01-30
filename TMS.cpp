#include <iostream>
#include <vector>
using namespace std;

class Teacher {
public:
    string name;
    int id;
    string subject;

    Teacher(int id, string name, string subject) {
        this->id = id;
        this->name = name;
        this->subject = subject;
    }
};

class TeacherManagementSystem {
private:
    vector<Teacher> teachers;

public:
    void addTeacher() {
        int id;
        string name, subject;
        cout << "Enter teacher ID: ";
        cin >> id;
        cout << "Enter teacher name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter subject: ";
        getline(cin, subject);

        Teacher newTeacher(id, name, subject);
        teachers.push_back(newTeacher);
        cout << "Teacher added successfully!\n";
    }

    void viewTeachers() {
        if (teachers.empty()) {
            cout << "No teachers to display.\n";
            return;
        }
        cout << "\nTeacher List:\n";
        for (const auto &teacher : teachers) {
            cout << "ID: " << teacher.id << " | Name: " << teacher.name << " | Subject: " << teacher.subject << endl;
        }
    }

    void removeTeacher() {
        int id;
        cout << "Enter teacher ID to remove: ";
        cin >> id;
        
        bool found = false;
        for (auto it = teachers.begin(); it != teachers.end(); ++it) {
            if (it->id == id) {
                teachers.erase(it);
                cout << "Teacher removed successfully!\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Teacher with ID " << id << " not found.\n";
        }
    }

    void menu() {
        int choice;
        do {
            cout << "\nTeacher Management System Menu\n";
            cout << "1. Add Teacher\n";
            cout << "2. View Teachers\n";
            cout << "3. Remove Teacher\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addTeacher();
                    break;
                case 2:
                    viewTeachers();
                    break;
                case 3:
                    removeTeacher();
                    break;
                case 4:
                    cout << "Exiting the system...\n";
                    break;
                default:
                    cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    TeacherManagementSystem system;
    system.menu();
    return 0;
}
