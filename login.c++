#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
void registerUser() {
    string username, password;
    cout << "\n--- User Registration ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << "\n";
        file.close();
        cout << "Registration successful!\n";
    } else {
        cout << "Error: Could not open file for registration.\n";
    }
}
bool loginUser() {
    string username, password;
    string storedUsername, storedPassword;
    cout << "\n--- User Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    ifstream file("users.txt");
    if (file.is_open()) {
        bool found = false;
        while (file >> storedUsername >> storedPassword) {
            if (storedUsername == username && storedPassword == password) {
                found = true;
                break;
            }
        }
        file.close(); 
        if (found) {
            cout << "Login successful! Welcome, " << username << "!\n";
            return true;
        } else {
            cout << "Invalid username or password. Please try again.\n";
            return false;
        }
    } else {
        cout << "Error: Could not open user data file. No users registered yet?\n";
        return false;
    }
}
int main() {
    int choice;
    do {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                }
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
