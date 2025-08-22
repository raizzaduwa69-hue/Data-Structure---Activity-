#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a TODO item
struct Todo {
    int id;
    string title;
    string description;
    string status;
};

// Function to load TODO items from a file
vector<Todo> loadTodos(const string& filename) {
    vector<Todo> todos;
    ifstream inputFile(filename);

    if (inputFile.is_open()) {
        int id;
        string title, description, status;
        while (inputFile >> id >> title >> description >> status) {
            todos.push_back({id, title, description, status});
        }
        inputFile.close();
    } else {
        cerr << "Error opening file for reading." << endl;
    }
    return todos;
}


// Function to save TODO items to a file
void saveTodos(const string& filename, const vector<Todo>& todos) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const auto& todo : todos) {
            outputFile << todo.id << " " << todo.title << " " << todo.description << " " << todo.status << endl;
        }
        outputFile.close();
    } else {
        cerr << "Error opening file for writing." << endl;
    }
}

// Function to display all TODO items
void displayTodos(const vector<Todo>& todos) {
    if (todos.empty()) {
        cout << "No TODO items found." << endl;
        return;
    }
    cout << ">>>>>>>TODO LIST<<<<<<" << endl;
    for (const auto& todo : todos) {
        cout << "ID: " << todo.id << endl;
        cout << "Title: " << todo.title << endl;
        cout << "Description: " << todo.description << endl;
        cout << "Status: " << todo.status << endl << endl;
    }
}

// Function to add a new TODO item
void addTodo(vector<Todo>& todos) {
    Todo newTodo;
    cout << "Enter ID: ";
    cin >> newTodo.id;
    cin.ignore(); // Consume the newline character left by cin
    cout << "Enter Title: ";
    getline(cin, newTodo.title);
    cout << "Enter Description: ";
    getline(cin, newTodo.description);
    newTodo.status = "Pending";
    todos.push_back(newTodo);
    cout << "Todo added successfully!" << endl;
}

// Function to update an existing TODO item
void updateTodo(vector<Todo>& todos) {
    int id;
    cout << "Enter ID of TODO to update: ";
    cin >> id;
    for (auto& todo : todos) {
        if (todo.id == id) {
            cin.ignore();
            cout << "Enter new Title: ";
            getline(cin, todo.title);
            cout << "Enter new Description: ";
            getline(cin, todo.description);
            cout << "Enter new Status (Pending/Done): ";
            getline(cin, todo.status);
            cout << "Todo updated successfully!" << endl;
            return;
        }
    }
    cout << "TODO item not found." << endl;
}


// Function to delete a TODO item
void deleteTodo(vector<Todo>& todos) {
    int id;
    cout << "Enter ID of TODO to delete: ";
    cin >> id;
    for (auto it = todos.begin(); it != todos.end(); ++it) {
        if (it->id == id) {
            todos.erase(it);
            cout << "Todo deleted successfully!" << endl;
            return;
        }
    }
    cout << "TODO item not found." << endl;
}

int main() {
    string filename = "todos.txt";
    vector<Todo> todos = loadTodos(filename);

    int choice;
    do {
        cout << ">>>>>>TODO LIST MENU <<<<<<<" << endl;
        cout << "1. View All Todos" << endl;
        cout << "2. Add New Todo" << endl;
        cout << "3. Update Todo" << endl;
        cout << "4. Delete Todo" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: displayTodos(todos); break;
            case 2: addTodo(todos); break;
            case 3: updateTodo(todos); break;
            case 4: deleteTodo(todos); break;
            case 5: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice. Please try again." << endl;
        }
        saveTodos(filename, todos); //Save after every operation

    } while (choice != 5);

    return 0;
}
