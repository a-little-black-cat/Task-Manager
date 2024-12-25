#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <ostream>
using namespace std;

struct Task {
    string name;
    int importance;
    string deadline;
};

void addTask(const string& fileName, const Task& task) {
    ofstream outFile(fileName, ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }
    outFile << task.name << " , " << task.importance << " , " << task.deadline << endl;
    outFile.close();
    cout << "Task added successfully." << endl;
}

void completeTask(const string& fileName, int taskNumber) {
    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    vector<string> tasks;
    string line;
    while (getline(inFile, line)) {
        tasks.push_back(line);
    }
    inFile.close();
    

    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cerr << "Error: Invalid task number." << endl;
        return;
    }


    tasks.erase(tasks.begin() + taskNumber - 1);
    
    

    ofstream outFile(fileName);
    if (!outFile) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }
    for (const auto& task : tasks) {
        outFile << task << endl;
    }
    outFile.close();
    cout << "Task completed successfully." << endl;
}

void listTasks(const string& fileName) {
    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    string line;
    int taskNumber = 1;
    cout << "Current Tasks:" << endl;
    while (getline(inFile, line)) {
        cout << taskNumber << ". " << line << endl;
        taskNumber++;
    }
    inFile.close();

    if (taskNumber == 1) {
        cout << "No tasks available." << endl;
    }
}

int main() {
    string fileName = "tasks.txt";
    string mode;

    cout << "Choose a mode: [add], [complete], [list]: ";
    cin >> mode;
    cin.ignore(); // Clear newline character from input buffer

    if (mode == "add") {
        string taskName;
        int importance;
        string deadline;

        cout << "Enter task name: ";
        getline(cin, taskName);
        cout << "Enter importance (1-4): ";
        cin >> importance;
        cin.ignore(); // Clear newline character from input buffer
        cout << "Enter deadline (MM/DD/YY): ";
        getline(cin, deadline);

        if (importance < 1 || importance > 4) {
            cerr << "Error: Importance level must be between 1 and 4." << endl;
            return 1;
        }

        Task newTask = {taskName, importance, deadline};
        addTask(fileName, newTask);

    } else if (mode == "complete") {
        int taskNumber;
        

        cout << "Enter task number to complete: ";
        cin >> taskNumber ;

        completeTask(fileName, taskNumber);

    } else if (mode == "list") {
        listTasks(fileName);

    } else {
        cerr << "Error: Unknown mode." << endl;
        return 1;
    }

    return 0;
}
