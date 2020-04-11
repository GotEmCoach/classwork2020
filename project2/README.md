# Priority Queues
Due: See dropbox details  
Submit: All code to github by due date

## Details
For this assignment you will be developing a C++ program which implements a 
priority queue data structure. Your program should implement a C++ class
which will be used to represent your priority queue. As a method of testing
your program will read in a file called `cmd.txt` which contains commands
which tells your program what it should do. The name of the file will be 
given to your program as a command line argument. A description of that 
file has been provided below.

This repo contains the following directories:
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
been completed and should not be modified. You should look at this file to see 
functions are exported by the node class and are available for you to use
* `pq.hpp` - This file defines and implements the `PQ` class. You are responsible
for implementing all functions of this class.
* `makefile` - This is the file that can be used to build your program. This file
has already been completed and should not be modified.
* `cmd.txt` - This file is a sample cmd file that can be used to test your program's
functionality. You may use it as is or add or change values in order to test
different edge cases.

## Your Task
You are to look at the class defined in`pq.hpp` and create the corresponding
implementation in `pq.hpp`. You may not change any of the existing declarations
but you may add more functions as you deem necesarry. Each item that is put into
the queue will have an associated priority. The lower the number that is assigned
to that priority value, the higher that elements priority. The priority value can
be found in `node.hpp`

In short, the following files are the only ones that you should modify for this
assignment:
* `pq.hpp`

No other file should be modified!

## cmd File Format
The cmd file for this assignment will consist of one to three columns of numbers. 
The first column indications the function that should be called, the second column
indications the operand that that function may take, and in the case of enqueue a 
third parameter will be provided which represent that element's priority. If the function takes no parameters then only 1 number will appear on the line. 
The first column number to function mapping is as follows
```
1    enqueue
2    dequeue
3    get_front
4    isEmpty
5    clear
6    get_count
```

The path to the command file will be read in from the command line. The name 
of the file should NOT be hardcoded into your program. Below is an example cmd file

```
1 1 1
3
1 9 2
3
1 33 3
3
1 2 4
3
1 89 5
3
1 999 0
```

## Interface 
Below is the prototype for the class you are to implement. This will also be
found in the .hpp file for the class as well. Remember you cannot change any
existing definitions but you may add functions as necesarry.

```C++
template<class T>
class PQ{
private:
    Node<T> *head;          // the pointer to the front of the list
    int count;

public:
    // desc: Inializes a new, empty queue
	PQ();

    // desc:    Adds new data to the queue
    // param:   data The data to add to the list
    // param:   priority The priority assigned to this node
    // returns: void
	void enqueue(T &data, int priority);

    // desc:    Removes the front element form the queue
    // returns: void
	void dequeue(void);   

    // desc:    Removes the value found at the front of the queue
    // returns: The data found at the front of the queue
    T get_front(void); 

    // desc:    Checks if the queue is empty or not
    // returns: true is the queue is empty, false if not
    bool isEmpty(void);

    // desc:    Clears the queue
    // returns: void
    void clear(void);

    // desc:    Returns the number of elements in the queue
    // returns: The number of elements in the queue
    int get_count(void);
};
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
* Your code should be fairly robust and be able to handle obvious edge cases
such as if I remove every element from the list and begin to add new elements.
You are responsible for comming up with and testing for possible edge cases.
* Passing all unit tests does not gaurentee you will be awarded full points for
assignment. Points may be deducted for poor coding practices, unresolved compilation
warnings, poor formatting, or other syntax or semantic errors
