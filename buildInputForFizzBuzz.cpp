#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream outFS;  //Output file stream

	// Open file
	outFS.open("fizzBuzzInput.txt");

	// Check to see if the file is open.  If not, scream about it and return with an error
	if (!outFS.is_open()) {
		cout << "For whatever reason the file you requested could not be opened." << endl;
		return 1;
	}

	//Write some stuff to file
	//What is this loop going to output? Do you think that is what I actually WANTED to output?
	for (int i = 1; i <= 100; i++)
	{
		outFS << i << endl;
	}

	// Remember to not leave your file open.
	// Doing so can cause problems later.
	outFS.close();

	return 0;

}
