
#include <iostream>
#include <fstream>
using namespace std;

void registerUser() {
    string username, password;

    cout << "\nEnter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt");

    file << username << " " << password;

    file.close();

    cout << "Registration successful!" << endl;
}

void loginUser() {
    string username, password;
    string savedUsername, savedPassword;

    cout << "\nEnter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    file >> savedUsername >> savedPassword;

    file.close();

    if (username == savedUsername &&
        password == savedPassword) {

        cout << "Login successful!" << endl;

    } else {

        cout << "Invalid username or password!" << endl;
    }
}

void viewDetails() {
    string username, password;

    ifstream file("users.txt");

    if (file >> username >> password) {
        cout << "\n===== Saved Login Details =====" << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
    } else {
        cout << "No details saved!" << endl;
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n===== Login System =====" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. View Saved Details" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        }
        else if (choice == 2) {
            loginUser();
        }
        else if (choice == 3) {
            viewDetails();
        }
        else if (choice == 4) {
            cout << "Thank you!" << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}