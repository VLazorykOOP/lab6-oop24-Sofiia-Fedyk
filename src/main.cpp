#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <string>
#include <algorithm>
#include "task1.h"
#include "task2.h"
#include "task3.h"  
// Include all headers from the three tasks
// Assuming task1.cpp, task2.cpp, and task3.cpp are included as separate files
// or their content is copied here

using namespace std;

// Function prototypes from the tasks
void runAllDemonstrations();                    // from task1.cpp
void demonstrateFigures();                      // from task2.cpp  
void demonstrateStudentFatherHierarchy();      // from task3.cpp
void demonstrateStudentFatherIO();             // from task3.cpp

// Menu display function
void displayMenu() {
    cout << "1. Task 1: Inheritance Hierarchies (Virtual vs Non-Virtual)" << endl;
    cout << "2. Task 2: Abstract Classes and Polymorphism (Geometric Figures)" << endl;
    cout << "3. Task 3: Multiple Inheritance (Student-Father Hierarchy)" << endl;
    cout << "4. Task 3 Bonus: Interactive Input/Output Demo" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to pause and wait for user input
// Renamed from pause() to waitForUser() to avoid conflict with system pause()
void waitForUser() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

// Function to clear screen (works on most systems)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {

    int choice;
    bool continueProgram = true;
    
    while (continueProgram) {
        displayMenu();
        
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        cin.ignore(); // Clear the input buffer
        
        switch (choice) {
            case 1: {
                clearScreen();
                cout << string(60, '#') << endl;
                cout << "TASK 1: INHERITANCE HIERARCHIES DEMONSTRATION" << endl;
                // cout << string(60, '#') << endl;
                // cout << "\nThis task demonstrates:" << endl;
                // cout << "- Diamond inheritance problem" << endl;
                // cout << "- Virtual vs non-virtual inheritance" << endl;
                // cout << "- Constructor/destructor call order" << endl;
                // cout << "- Memory layout differences" << endl;
                // cout << "\nStarting demonstration...\n" << endl;
                
                try {
                    runAllDemonstrations();
                } catch (const exception& e) {
                    cerr << "Error in Task 1: " << e.what() << endl;
                }
                
                waitForUser();
                break;
            }
            
            case 2: {
                clearScreen();
                cout << string(60, '#') << endl;
                cout << "TASK 2: ABSTRACT CLASSES AND POLYMORPHISM" << endl;
                // cout << string(60, '#') << endl;
                // cout << "\nThis task demonstrates:" << endl;
                // cout << "- Abstract base classes" << endl;
                // cout << "- Pure virtual functions" << endl;
                // cout << "- Runtime polymorphism" << endl;
                // cout << "- Geometric figure calculations" << endl;
                // cout << "\nStarting demonstration...\n" << endl;
                
                try {
                    demonstrateFigures();
                } catch (const exception& e) {
                    cerr << "Error in Task 2: " << e.what() << endl;
                }
                
                waitForUser();
                break;
            }
            
            case 3: {
                clearScreen();
                cout << string(60, '#') << endl;
                cout << "TASK 3: MULTIPLE INHERITANCE DEMONSTRATION" << endl;
                // cout << string(60, '#') << endl;
                // cout << "\nThis task demonstrates:" << endl;
                // cout << "- Multiple inheritance" << endl;
                // cout << "- Name conflict resolution" << endl;
                // cout << "- Operator overloading" << endl;
                // cout << "- Complex class hierarchies" << endl;
                // cout << "\nStarting demonstration...\n" << endl;
                
                try {
                    demonstrateStudentFatherHierarchy();
                } catch (const exception& e) {
                    cerr << "Error in Task 3: " << e.what() << endl;
                }
                
                waitForUser();
                break;
            }
            
            case 4: {
                clearScreen();
                cout << string(60, '#') << endl;
                cout << "TASK 3 BONUS: INTERACTIVE INPUT/OUTPUT" << endl;
                cout << string(60, '#') << endl;
                cout << "\nThis interactive demo allows you to:" << endl;
                cout << "- Create a StudentFather object interactively" << endl;
                cout << "- Test operator overloading for >> and <<" << endl;
                cout << "- See how multiple inheritance works in practice" << endl;
                cout << "\nStarting interactive demo...\n" << endl;
                
                try {
                    demonstrateStudentFatherIO();
                } catch (const exception& e) {
                    cerr << "Error in Task 3 Interactive Demo: " << e.what() << endl;
                }
                
                waitForUser();
                break;
            }
                  
            case 0: {
                continueProgram = false;
                // cout << "\n" << string(50, '*') << endl;
                // cout << "Thank you for using the C++ OOP Demo!" << endl;
                // cout << "Demonstration concepts covered:" << endl;
                // cout << "✓ Virtual and Non-Virtual Inheritance" << endl;
                // cout << "✓ Diamond Problem Resolution" << endl;
                // cout << "✓ Abstract Classes and Pure Virtual Functions" << endl;
                // cout << "✓ Runtime Polymorphism" << endl;
                // cout << "✓ Multiple Inheritance" << endl;
                // cout << "✓ Operator Overloading" << endl;
                // cout << "✓ Constructor/Destructor Chains" << endl;
                // cout << string(50, '*') << endl;
                cout << "Goodbye!" << endl;
                break;
            }
            
            default: {
                cout << "\nInvalid choice! Please select a number between 0 and 5." << endl;
                waitForUser();
                break;
            }
        }
        
        if (continueProgram) {
            clearScreen();
        }
    }
    
    return 0;
}

// Additional utility function for error handling in main
void handleTaskError(const string& taskName, const exception& e) {
    cerr << "\n" << string(40, '!') << endl;
    cerr << "ERROR IN " << taskName << endl;
    cerr << string(40, '!') << endl;
    cerr << "Error details: " << e.what() << endl;
    cerr << "The program will continue with other tasks." << endl;
    cerr << string(40, '!') << endl;
}