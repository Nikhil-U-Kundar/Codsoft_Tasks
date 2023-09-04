#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

vector<Task> tasks;

// Function to add a task to the list
void addTask(const string& description) {
    tasks.push_back(Task(description));
    cout << "Task added: " << description << endl;
}

// Function to view tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
        return;
    }

    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << "[" << (tasks[i].completed ? "X" : " ") << "] " << (i + 1) << ". " << tasks[i].description << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].completed = true;
        cout << "Task " << index << " marked as completed." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

// Function to remove a task from the list
void removeTask(int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        cout << "Task removed: " << tasks[index - 1].description << endl;
        tasks.erase(tasks.begin() + index - 1);
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    int choice;
    string taskDescription;

    cout << "Simple To-Do List Manager" << endl;

    while (true) {
        cout << "\nOptions:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                addTask(taskDescription);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                int markIndex;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> markIndex;
                markTaskCompleted(markIndex);
                break;
            case 4:
                int removeIndex;
                cout << "Enter the index of the task to remove: ";
                cin >> removeIndex;
                removeTask(removeIndex);
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
