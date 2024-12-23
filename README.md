Connect4_Game/              # Root directory of the project
├── src/                    # Source code files for core application logic
│   ├── Board.cpp           # Implementation of the game board
│   ├── Player.cpp          # Implementation of player-related functions
│   ├── Computer.cpp        # Implementation of AI opponent logic
│   ├── GameController.cpp  # Manages the overall game flow and rules
│   └── main.cpp            # Entry point for the application
│
├── include/                # Header files for class declarations
│   ├── Board.hpp           # Header for Board class
│   ├── Player.hpp          # Header for Player class
│   ├── Computer.hpp        # Header for Computer class
│   ├── GameController.hpp  # Header for GameController class
│   └── ...                 # Can add or remove files
│
├── test/                   # Unit tests using Google Test Framework
│   ├── BoardTest.cpp       # Tests for Board class
│   ├── PlayerTest.cpp      # Tests for Player class
│   ├── ComputerTest.cpp    # Tests for Computer AI
│   ├── GameControllerTest.cpp # Tests for game controller logic
│   └── runtest.cpp         # Entry point for running all tests
│
├── build/                  # Build and debug directory (created during compilation)
│   ├── CMakeFiles/         # CMake-generated files
│   ├── Makefile            # Makefile for building the project
│   ├── connect4            # Final compiled executable
│   ├── test/               # Compiled GTest executables
│   
│
├── CMakeLists.txt          # CMake build configuration file
├── README.md               # Documentation for project overview and setup i
└── main.cpp                # Main file 



**Connect4 Game - Assignment Documentation**  

## Environment Setup

1. Install g++ (GCC)**  
Ensure that **g++** is installed on your system:  

sudo apt update
sudo apt install g++

2. Install Google Test Framework for Unit Testing**  

sudo apt install libgtest-dev
sudo apt install cmake


## Time Spent on the Assignment 

I spent approximately **12 hours** completing this assignment. The time distribution is as follows:  

- **Requirement Analysis and Design**: 1 hour  
- **Implementation and Coding**: 7 hours  
- **Testing and Debugging**: 3 hours  
- **Documentation and Comments**: 1 hour  

---

## Instructions for Compiling and Running the Project

# Compile and Run the Game

1. Navigate to the build directory:  

   cd /ConnectFour/build

2. Compile and build the game:  

   clear && cmake .. && make clean && make

3. Run the executable:  

   clear && ./connect4


## Running Google Test (GTest)

1. Navigate to the build directory:  

   cd /ConnectFour/build

2. Compile and build the test suite:  

   clear && cmake .. && make clean && make

3. Run the tests:  

   clear && ./test/runtest

   (This command displays test results directly on the terminal.)

4. (Optional) Save test results to a text file:  

   clear && ./test/runtest > GTestResult.txt


## Static Analysis with `cppcheck` (optional)

1. Build the project with the `cppcheck` target:  

   cmake -S . -B build
   cmake --build build --target cppcheck


## Debugging with `gdb`  

### 1. Clean the Build Directory (Optional) 
(Caution: This deletes all files in the directory.) 
rm -rf *

### **2. Build the Project in Debug Mode**  

cmake -DCMAKE_BUILD_TYPE=Debug ..

### **3. Compile the Executable**  
make

### **4. Start Debugging with `gdb`**  
gdb ./Connect4


### 5. Use Common `gdb` Commands
- **`r`** – Run the program  
- **`b <line/function>`** – Set a breakpoint  
- **`s`** – Step into a function  
- **`bt`** – Print a backtrace  
- **`n`** – Step over a line  
- **`c`** – Continue execution  

---

## **Additional Notes and Future Improvements**  

### Work Still to Be Done
1. **Performance Testing**:  
   - Evaluate the performance under stress and load conditions.  

2. **Input Validation**:  
   - Add more checks for invalid or malformed inputs.  

3. **Dynamic Resizing**:  
    Implement support for resizing the grid dynamically.  

### Bugs / Non-Working Use Cases**  
1. **Edge Cases**:  
   - Currently, the game does not handle edge cases for extremely large board sizes.  

2. **Undo/Redo Functionality**:  
   - Undo/Redo operations are not implemented yet.  

---

### Improvements and New Features Planned**  
1. **Graphical User Interface (GUI)**:  
   - Add a GUI using **Qt** or **Web-based UI** for improved usability.  

2. **Save/Load Game State**:  
   - Implement saving and resuming games later.  

3. **AI Enhancements**:  
   - Improve AI strategies to make the computer opponent more competitive.  

4. **Multiplayer Support**:  
   - Enable network-based multiplayer using sockets.  



