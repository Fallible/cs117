#include <iostream>
#include <fstream>
#include <string> //This include will allow me to pass a string in as a variable later in the program.  Watch for it!
#include <ios>
#include <iomanip>



/*
This is an old interview style question.  In short, the goal is to take the numbers 1-100,
and write them out with a few modifications.  If the number is divisble by 3, output fizz instead.
If the number is divisible by 5, output buzz instead.  Of course if it is divisible by both 3 and 5
then the output should be fizzbuzz.

In this program we are going to read in our input values from a file, and output our values to a different file
instead of just printing them to the screen.
*/
using namespace std;

int main() {
	ifstream inFS;			//This is what we are calling our input stream
	ofstream outFS;			//Just like above, this is what we are calling our output stream
	int numberFromFile = 0;	//This is where we assign the values coming from the file

	string inputFile = "fizzBuzzInput.txt";	//Setting our filename as a variable because I use it several times.
	string outputFile = "output.txt";

	//We are going to open our output file here, like we did in buildInput
	cout << "Attempting to open " << outputFile << "." << endl;

	outFS.open(outputFile);
	if (!outFS.is_open()) {
		cout << outputFile << " Didn't open." << endl;
		return 1;
	}

	//Again we need to try to open the file, same as we did for output
	cout << "Attempting to open " << inputFile << "." << endl;

	inFS.open(inputFile);
	if (!inFS.is_open()) {
		cout << inputFile << " Didn't open." << endl;
		return 1; // Returning with 1 tells us that there was an error.
	}


	// Now that we have the file open, lets start pulling data from it
	// We are going to grab one value at a time and print that value as we go.
	// The thing I want you to get from this is less the loop and goofy goal of this program.
	// Focus more on how I am opening files and outputting the data.
	
	//Next linechecks for end of file.  Notice the "!" before the call?  We proceed if eof is not hit.
	while (!inFS.eof() && inFS.good()) {	
		inFS >> numberFromFile;

		/* Notice that I am pulling a number from the file here, INSIDE the while loop. 
		This means every time the while loop executes it will pull in a new number.
		Next we need to check for divisible by 3 and/or 5.
		*/

		if (numberFromFile % 3 == 0 && numberFromFile % 5 == 0) {
			outFS << "fizzbuzz" << endl;
		}
		else if (numberFromFile % 3 == 0) {
			outFS << "fizz" << endl;
		}
		else if (numberFromFile % 5 == 0) {
			outFS << "buzz" << endl;
		}
		else if (numberFromFile % 4 == 0) {
			double modifiedNumber = numberFromFile;
			outFS << modifiedNumber << endl;
		}
		else {
			outFS << numberFromFile << endl;
		}
		


		


	}
	inFS.close();
	outFS.close();

	return 0;
}