# Doubly Linked Lists

## Details
For this assignment you will be developing a C++ program which implements a 
doubly linked list. Your program will read in a text file called `cmd.txt` that will 
instruct your program what operations to run. Your program will take this file
as a command line argument. Your program should implement a C++ class which will 
represent your linked list. This repo contains the following directories: 
* `src` - Contains the source code for the assignment and the files you will need
complete. Any modifications you make to complete your assignment should be made
inside this directory.  
* `tests` - This directory contains the code that is used to test your program. 
You should not modify any code inside of this directory as it could give you
incorrect results. The code in this directory can be compiled and executed when
you beleive your assignment is complete.  

### Files  
Inside of the `src` directory you will find the following files  
* `main.cpp` - This file is the driver of your program. It creates an instance of
your class and then performs various operations that your class implements. It 
reads information from `cmd.txt` which instructions the program on what actions 
to take. This file has already been completed for you and should not be modified.  
* `node.hpp` - This file defines and implements the `Node` class which is the
basic building block used to create our data structure. This file has already
been completed and should not be modified.
* `dll.hpp` - This file defines and implements the `DLL` class. You are responsible 
for implementing all functions of this class.
* `makefile` - This is the file that can be used to build your program. This file 
has already been completed and should not be modified.
* `cmd.txt` - This file is a sample cmd file that can be used to test your program's 
functionality. You may use it as is or add or change values in order to test
different edge cases.  

In short, the following files are the only ones that you should modify for this
assignment:  
* `dll.hpp` 

No other file should be modified!

### Interface
Below is the prototype for the class you are to implement. It can also be found
in the .hpp file for the class as well. If you have any questions as to the expected 
behavior of a function please do not hesitate to ask  
```C++
template<class T>
class DLL{
private:
    Node<T> *head;          // the pointer to the front of the list
    int count;
public:
    // desc: Inializes a new, empty list
	DLL();

    // desc:  Adds new data to the end of the list
    // param: data The data to add to the list
	void prepend(T &data);

    // desc:  Adds new data to the front of the list
    // param: data The data to add to the list
	void append(T &data);

    // desc:    Searches the list for the node that contains data and removes it
    //          from the list
    // param:   data The data to be searched for and removed
    // returns: true if the node was found and removed, false if not
    bool remove(T data);

    // desc:    Removes the node at the front of the list
    // returns: true if the node was successfully removed, false if not
	bool removeFront(void);

    // desc:    Removes the node at the back of the list
    // returns: true if the node was successfully removed, false if not
	bool removeBack(void);

    // desc:    Searches the list for a node containing the specified data
    // param:   data The data to be searched for
    // returns: A pointer to the node containing the data or NULL if a node
    //          cannot be found
	Node<T> *search(T data);

    // desc::   Returns the data found at the front of the list
    // returns: The data at the front of the list
    T getFront(void);

    // desc::   Returns the data found at the back of the list
    // returns: The data at the back of the list. Return 0 if empty
    T getBack(void);

    // desc: Prints the contents of the list from front to back
	void print();
};
```

## cmd File Format
The cmd file for this assignment consists of two columns of numbers. The first
column indications the function that should be called, and the second column
indications the operand that that function may take. If the function takes no 
operand then the entry will be blank. The first column number to function 
mapping is as follows
```
1    prepend
2    append
3    removeFront
4    removeBack
5    search
6    print
7    remove
8    getFront
9    getBack
```

## Building Your Program  
GNU Make is used to build our program for us. To support that a complete make
file has already been provided for you. In order to build your program perform 
the following steps:  
* cd into the source director `> cd src`  
* Type `make` to build your program.  

## Runing unit tests
The unit tests that will be used to grade your program have already been included 
in this repo. If you beleive your program to be functioning correctly you may
 run them localy in order to verify your programs correctness. To run them, first 
 `cd` into the tests directory. 
 Then type `make` which will build the unit tests for your program, this may take 
 a minute as multiple executables are being compiled. Then finally type `./run_tests.sh` 
 to execute the unit tests and report back if they passed or failed.  

## Continuous Testing
It is highly recommend that you commit code back to the github repository often. 
Each time you commit your code, it will automatically be built by TravisCI and
have unit tests ran against it. You can then see what tests have been successfully
completed and which have not. This gives you a good way to gauge your progress
as you complete the assignment. This also gives me access to view your code and 
easily assist with any problems you may run into. Do note that you should run tests 
locally as well as Travis can sometimes take a substantial amount of time to run 
your code. This is due to everyone in the class sharing a single build server and 
only one person being able to execute a test at a time

## Deliverables
Commit the final version of your code and push it to the github repository
before the due date of the assignment

## Expections
* Your code should build and run, no points will be awarded to code that does
not compile
* No use of any prebuilt linked list libraries
* Your code should be well formatted, points may be taken for sloppy code
* Your output should match the output provided in output.txt
* Your code should be fairly robust and be able to handle obvious edge cases 
such as if I remove every element from the list and begin to add new elements.
You are responsible for comming up with and testing for possible edge cases. 
* Passing all unit tests does not gaurentee you will be awarded full points for 
assignment. Points may be deducted for poor coding practices, unresolved compilation 
warnings, poor formatting, or other syntax or semantic errors
