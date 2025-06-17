#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string title;
    bool isDone;
};

void createTask(vector<Task>& list);
void showTasks(const vector<Task>& list);
void completeTask(vector<Task>& list);
void deleteTask(vector<Task>& list);

int main() {
    vector<Task> taskList;
    int option;

    while (true) {
        cout << "\n===== TO-DO LIST MENU =====\n";
        cout << "1. Add a Task\n";
        cout << "2. Show All Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Delete a Task\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";
        cin >> option;
        cin.ignore();

        if (option == 1) {
            createTask(taskList);
        } else if (option == 2) {
            showTasks(taskList);
        } else if (option == 3) {
            completeTask(taskList);
        } else if (option == 4) {
            deleteTask(taskList);
        } else if (option == 5) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid input. Try again.\n";
        }
    }

    return 0;
}

void createTask(vector<Task>& list) {
    Task newTask;
    cout << "Enter task name: ";
    getline(cin, newTask.title);
    newTask.isDone = false;
    list.push_back(newTask);
    cout << "Task added.\n";
}

void showTasks(const vector<Task>& list) {
    if (list.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    for (size_t i = 0; i < list.size(); ++i) {
        cout << i + 1 << ". " << list[i].title
             << " [" << (list[i].isDone ? "Done" : "Pending") << "]\n";
    }
}

void completeTask(vector<Task>& list) {
    int num;
    showTasks(list);
    if (list.empty()) return;

    cout << "Enter task number to mark as done: ";
    cin >> num;

    if (num >= 1 && num <= list.size()) {
        list[num - 1].isDone = true;
        cout << "Marked as done.\n";
    } else {
        cout << "Invalid number.\n";
    }
}

void deleteTask(vector<Task>& list) {
    int num;
    showTasks(list);
    if (list.empty()) return;

    cout << "Enter task number to remove: ";
    cin >> num;

    if (num >= 1 && num <= list.size()) {
        list.erase(list.begin() + num - 1);
        cout << "Task removed.\n";
    } else {
        cout << "Invalid number.\n";
    }
}
