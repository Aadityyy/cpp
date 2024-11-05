  #include <iostream>
using namespace std;

class Student {
private:
    string name[20];
    int age[20];
    string reg_no[20];
    int roll_no[20];
    string semester[20];
    float attendance[20];
    float marks[20][5]; // Assuming 5 subjects for each student
    float percentage[20];

public:
    void get_Details(int n) {
        for (int i = 0; i < n; ++i) {
            cout << "Enter details for student " << (i + 1) << ":" << endl;
            
            cout << "Enter Name: ";
            cin >> name[i];

            cout << "Enter Age: ";
            cin >> age[i];

            cout << "Enter Registration Number: ";
            cin >> reg_no[i];

            cout << "Enter Roll Number: ";
            cin >> roll_no[i];

            cout << "Enter Semester: ";
            cin >> semester[i];

            cout << "Enter Attendance: ";
            cin >> attendance[i];

            cout << "Enter Marks for 5 subjects: ";
            for (int j = 0; j < 5; ++j) {
                cin >> marks[i][j];
            }
            cout << endl;
        }
    }

    void show_Details(int n) {
        for (int i = 0; i < n; ++i) {
            cout << "Details for student " << (i + 1) << ":" << endl;
            cout << "Name: " << name[i] << endl;
            cout << "Age: " << age[i] << endl;
            cout << "Registration No: " << reg_no[i] << endl;
            cout << "Roll No: " << roll_no[i] << endl;
            cout << "Semester: " << semester[i] << endl;
            cout << "Attendance: " << attendance[i] << "%" << endl;
            cout << "Marks: ";
            for (int j = 0; j < 5; ++j) {
                cout << marks[i][j] << " ";
            }
            cout << endl;
        }
    }

    void showShortage(int n) {
        for (int i = 0; i < n; ++i) {
            if (attendance[i] < 75) {
                cout << "Roll No " << roll_no[i] << ", Name: " << name[i] << " has an attendance shortage." << endl;
            }
        }
    }

    void getPercentage(int n) {
        for (int i = 0; i < n; ++i) {
            float total = 0;
            for (int j = 0; j < 5; ++j) {
                total += marks[i][j];
            }
            percentage[i] = (total / 500) * 100;
            cout << "Percentage for student " << (i + 1) << " (" << name[i] << "): " << percentage[i] << "%" << endl;
        }
    }

    void printAttendance(int n) {
        for (int i = 0; i < n; ++i) {
            cout << "Roll No: " << roll_no[i] << ", Name: " << name[i] << ", Attendance: " << attendance[i] << "%" << endl;
        }
    }

    void show_90percent(int n) {
        for (int i = 0; i < n; ++i) {
            if (percentage[i] >= 90) {
                cout << "Student with percentage above 90: Name: " << name[i] << ", Percentage: " << percentage[i] << "%" << endl;
            }
        }
    }
};

int main() {
    int num_students;
    cout << "Enter the number of students: ";
    cin >> num_students;

    if (num_students > 20) {
        cout << "Maximum number of students is 20. Setting number to 20." << endl;
        num_students = 20;
    }

    Student s;
    s.get_Details(num_students);
    s.show_Details(num_students);
    s.showShortage(num_students);
    s.getPercentage(num_students);
    s.printAttendance(num_students);
    s.show_90percent(num_students);

    return 0;
}
