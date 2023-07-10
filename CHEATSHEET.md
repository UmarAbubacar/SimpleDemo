// C++ Cheat Sheet for Biodynamo

// Basic Structure of a C++ Program
#include <iostream>

int main() {
    // Code goes here
    return 0;
}

// Data Types
int     // Integer
float   // Floating-point number
double  // Double-precision floating-point number
bool    // Boolean (true or false)
char    // Character

// Variables
int myVariable;            // Declaration
myVariable = 10;           // Assignment

int anotherVariable = 20;  // Declaration and assignment

// Output
std::cout << "Hello, world!" << std::endl;

// Input
int userInput;
std::cin >> userInput;

// Basic Arithmetic Operations
int sum = 2 + 3;    // Addition
int difference = 5 - 2;   // Subtraction
int product = 4 * 6;   // Multiplication
int division = 10 / 2;   // Division
int remainder = 13 % 5;   // Modulo (remainder)

// Control Structures
if (condition) {
    // Code to execute if condition is true
} else {
    // Code to execute if condition is false
}

for (int i = 0; i < 5; i++) {
    // Code to execute repeatedly
}

while (condition) {
    // Code to execute repeatedly while condition is true
}

// Functions
returnType functionName(parameters) {
    // Function body
    // Code to be executed
}

// Arrays
dataType arrayName[size];   // Declaration
arrayName[index] = value;   // Assignment

// Pointers
dataType* pointerName;   // Declaration
pointerName = &variable;   // Assignment (store the address of a variable)

// Classes and Objects
class ClassName {
public:
    // Member variables and functions
};

ClassName objectName;   // Object instantiation

// Accessing Class Members
objectName.memberVariable;
objectName.memberFunction();

// Comments
// This is a single-line comment

/*
    This is a
    multi-line comment
*/

// Biodynamo-specific Concepts and Functions
// (These are just examples; refer to the Biodynamo documentation for detailed usage)

#include "biodynamo.h"   // Including Biodynamo headers
#include "neuroscience/neuroscience.h"   // Including neuroscience headers

// Namespaces
// This is so that you don't have to type "bdm::" before every Biodynamo function
// for example, you can just type "Cell" instead of "bdm::Cell"
namespace bdm {
    // Code goes here
}


// Simulation
// This is the main class that you will be using to run simulations
Simulation simulation;   // Instantiating a simulation object


// ResourceManager
// This is the class that you will be using to manage the resources of your simulation
// For example, you can use it to create cells and substances
auto* rm = simulation.GetResourceManager();
