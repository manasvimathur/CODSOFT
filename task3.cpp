// ToDoList CPP porgram
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


struct Task {
    int id;
    string description;
    bool isCompleted;
};


void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore(); 
    getline(cin, newTask.description);
    newTask.id = tasks.size() + 1;
    newTask.isCompleted = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}


void viewTasks(const vector<Task>& tasks) {
    cout << "Tasks:\n";
    for (const auto& task : tasks) {
        cout << task.id << ". " << task.description;
        if (task.isCompleted) {
            cout << " - Completed\n";
        } else {
            cout << " - Pending\n";
        }
    }
}

void markTaskAsCompleted(vector<Task>& tasks) {
    int taskId;
    cout << "Enter the task ID to mark as completed: ";
    cin >> taskId;


    auto it = find_if(tasks.begin(), tasks.end(), [taskId](const auto& task) {
        return task.id == taskId;
    });

   
    if (it!= tasks.end()) {
        it->isCompleted = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task ID!\n";
    }
}


void removeTask(vector<Task>& tasks) {
    int taskId;
    cout << "Enter the task ID to remove: ";
    cin >> taskId;

  
    auto it = find_if(tasks.begin(), tasks.end(), [taskId](const auto& task) {
        return task.id == taskId;
    });

 
    if (it!= tasks.end()) {
        tasks.erase(it);
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task ID!\n";
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "To-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }

        cout << "\n";
    }

    return 0;
}