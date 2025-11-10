#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdio>
#include <cctype>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float marks[5];
    float total;
    float percent;
    char grade;

    void inputData();
    void calculate();
    void displayData();
};

string subjects[5] = {"English", "Mathematics", "Science", "Computer", "Social Studies"};

void Student::inputData() {
    // --- Roll number validation ---
    while (true) {
        cout << "\nEnter Roll Number: ";
        if (!(cin >> rollNo)) {
            cout << "? Invalid input! Please enter a numeric roll number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        if (rollNo <= 0) {
            cout << "? Roll number must be positive!\n";
            continue;
        }
        cin.ignore(1000, '\n');
        break;
    }

    // --- Name validation ---
    while (true) {
        cout << "Enter Name: ";
        getline(cin, name);

        if (name.empty()) {
            cout << "? Name cannot be empty! Please re-enter.\n";
            continue;
        }

        bool valid = true;
        for (int i = 0; i < (int)name.length(); i++) {
            char c = name[i];
            if (!isalpha(c) && c != ' ') {
                valid = false;
                break;
            }
        }

        if (!valid) {
            cout << "? Name must contain only letters and spaces! Try again.\n";
            continue;
        }
        break;
    }

    // --- Marks input ---
    total = 0;
    for (int i = 0; i < 5; i++) {
        while (true) {
            cout << "Enter marks for " << subjects[i] << " (0-100): ";
            if (!(cin >> marks[i])) {
                cout << "? Invalid input! Please enter a number.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            if (marks[i] < 0 || marks[i] > 100) {
                cout << "? Marks must be between 0 and 100. Try again.\n";
                continue;
            }
            total += marks[i];
            break;
        }
    }
    cin.ignore(1000, '\n'); // clear newline
    calculate();
}

void Student::calculate() {
    percent = total / 5.0f;
    if (percent >= 90) grade = 'A';
    else if (percent >= 80) grade = 'B';
    else if (percent >= 70) grade = 'C';
    else if (percent >= 60) grade = 'D';
    else if (percent >= 50) grade = 'E';
    else grade = 'F';
}

void Student::displayData() {
    cout << left << setw(10) << rollNo
         << setw(20) << name
         << setw(10) << total
         << setw(10) << fixed << setprecision(2) << percent
         << setw(10) << grade << endl;
}

bool fileIsEmptyOrMissing(const char* filename) {
    ifstream f(filename, ios::in);
    if (!f) return true; // file not found
    f.seekg(0, ios::end);
    return f.tellg() == 0; // empty file
}

void addStudent() {
    Student s;

    // Step 1: Check if file exists and has content
    bool fileEmpty = true;
    {
        ifstream fin("report.txt");
        if (fin) {
            fin.seekg(0, ios::end);
            if (fin.tellg() > 0)
                fileEmpty = false;
        }
        fin.close();
    }

    // Step 2: Open file for appending
    ofstream file("report.txt", ios::app);
    if (!file) {
        cout << "? Error: Could not open report.txt for writing.\n";
        return;
    }

    // Step 3: If file is empty or new, write header
    if (fileEmpty) {
        file << left << setw(10) << "Roll No"
             << setw(20) << "Name"
             << setw(10) << "Total"
             << setw(10) << "Percent"
             << setw(10) << "Grade" << endl;
    }

    // Step 4: Input and write data
    s.inputData();
    file << left << setw(10) << s.rollNo
         << setw(20) << s.name
         << setw(10) << s.total
         << setw(10) << fixed << setprecision(2) << s.percent
         << setw(10) << s.grade << endl;

    file.close();
    cout << "\n? Record added successfully to report.txt!\n";
}



// ---------- Display All ----------
void displayAll() {
    ifstream file("report.txt");
    if (!file) {
        cout << "? No records found.\n";
        return;
    }

    string line;
    bool first = true;

    cout << "\n---------------- STUDENT REPORTS ----------------\n";
    cout << left << setw(10) << "Roll No"
         << setw(20) << "Name"
         << setw(10) << "Total"
         << setw(10) << "Percent"
         << setw(10) << "Grade" << endl;
    cout << "-------------------------------------------------\n";

    while (getline(file, line)) {
        if (first && line.find("Roll No") != string::npos) {
            first = false;
            continue;
        }
        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        Student s;

        getline(ss, token, ',');
        stringstream(token) >> s.rollNo;
        getline(ss, s.name, ',');
        getline(ss, token, ',');
        stringstream(token) >> s.total;
        getline(ss, token, ',');
        stringstream(token) >> s.percent;
        getline(ss, token, ',');
        s.grade = token.empty() ? '?' : token[0];

        s.displayData();
    }

    cout << "-------------------------------------------------\n";
    file.close();
}

// ---------- Modify Record ----------
void modifyStudent() {
    int roll;
    cout << "\nEnter Roll Number to modify: ";
    if (!(cin >> roll)) {
        cout << "? Invalid input.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }
    cin.ignore(1000, '\n');

    ifstream fin("report.txt");
    if (!fin) {
        cout << "? No records found.\n";
        return;
    }
    ofstream fout("temp.txt");
    string line;
    bool found = false, first = true;

    while (getline(fin, line)) {
        if (first && line.find("Roll No") != string::npos) {
            fout << line << endl;
            first = false;
            continue;
        }

        stringstream ss(line);
        string token;
        int currentRoll;
        getline(ss, token, ',');
        stringstream(token) >> currentRoll;

        if (currentRoll == roll) {
            cout << "Record found. Enter new details:\n";
            Student s;
            s.rollNo = roll;
            s.inputData();
            fout << s.rollNo << "," << s.name << "," << s.total << ","
                 << s.percent << "," << s.grade << endl;
            found = true;
        } else {
            fout << line << endl;
        }
    }

    fin.close();
    fout.close();
    remove("report.txt");
    rename("temp.txt", "report.txt");

    if (found)
        cout << "? Record updated successfully.\n";
    else
        cout << "? Record not found.\n";
}

// ---------- Delete Record ----------
void deleteStudent() {
    int roll;
    cout << "\nEnter Roll Number to delete: ";
    if (!(cin >> roll)) {
        cout << "? Invalid input.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        return;
    }
    cin.ignore(1000, '\n');

    ifstream fin("report.txt");
    if (!fin) {
        cout << "? No records found.\n";
        return;
    }
    ofstream fout("temp.txt");
    string line;
    bool found = false, first = true;

    while (getline(fin, line)) {
        if (first && line.find("Roll No") != string::npos) {
            fout << line << endl;
            first = false;
            continue;
        }

        stringstream ss(line);
        string token;
        int currentRoll;
        getline(ss, token, ',');
        stringstream(token) >> currentRoll;

        if (currentRoll == roll) {
            found = true;
            continue; // skip to delete
        }
        fout << line << endl;
    }

    fin.close();
    fout.close();
    remove("report.txt");
    rename("temp.txt", "report.txt");

    if (found)
        cout << "? Record deleted successfully.\n";
    else
        cout << "? Record not found.\n";
}

// ---------- Main Menu ----------
int main() {
    int choice;
    do {
        cout << "\n===== STUDENT REPORT CARD SYSTEM =====\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Modify Record by Roll Number\n";
        cout << "4. Delete Record by Roll Number\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "? Invalid input! Enter a number (1-5).\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore(1000, '\n');

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: modifyStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "\n?? Exiting... Goodbye!\n"; break;
            default: cout << "? Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

