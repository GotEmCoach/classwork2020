#include <fstream>  // Include to open files
#include <cstddef>  // Include to use NULL, otherwise use nullptr
#include <iostream> // Include to print to the screen
#include "dll.hpp"     // The header file for our custom linked list class
using namespace std;

int main(int argc, char** argv)
{
	DLL<int> myList;
    Node<int> *searchResult;
	ifstream input;
	int cmd, argument, ret;

    if(argc < 2)
    {
        cout << "useage: ./a1.out <cmd file>\n";
        return 0;
    }

	input.open(argv[1]);

    // while there is something to read from the file, read
	while (input >> cmd)
	{
        // switch on the command we read from the file
		switch (cmd)
		{
        // if the cmd requires a parameter, read it from the file and call the 
        // associated function
		case 1:
			input >> argument;
			myList.prepend(argument);
            cout << "Prepended " << argument << endl;
			break;
		case 2:
			input >> argument;
			myList.append(argument);
            cout << "Apended " << argument << endl;
			break;
		case 3:
			if(myList.removeFront())
            {
                cout << "Succesfully removed the front of the list\n";
            }
            else
            {
                cout << "List is empty, nothing to remove\n";
            }
			break;
		case 4:
			if(myList.removeBack())
            {
                cout << "Succesfully removed the back of the list\n";
            }
            else
            {
                cout << "List is empty, nothing to remove\n";
            }
			break;
		case 5:
			input >> argument;
			searchResult = myList.search(argument);
			if(NULL != searchResult)
                cout << "Found " << searchResult->get_data() << " in list!"<<endl;
            else
                cout << "Did not find " << argument << " in the list"<<endl;
            break;
		case 6:
			myList.print();
			break;
        case 7:
            input >> argument;
            cout << "Attempting to remove " << argument << endl;
			if(myList.remove(argument))
            {
                cout << "Succesfully removed the element from the list\n";
            }
            else
            {
                cout << "Could not remove the element from the list\n";
            }
            break;
        case 8:
            ret = myList.getFront();
            if(ret != 0) cout << "Front: " << ret << endl;
            else cout << "List is empty\n";
            break;
        case 9:
            ret = myList.getBack();
            if(ret != 0) cout << "Back: " << ret << endl;
            else cout << "List is empty\n";
            break;
        }
	}
	input.close();

	return 0;
}
