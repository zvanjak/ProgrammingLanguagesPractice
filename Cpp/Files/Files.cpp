// Files.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>

/*
This rather paranoid example has a get_int function that tries to read an integer from file, and checks everything.
The function has three reference - type parameters : an input stream to read from, a bool good_flag parameter, which
will be set to true if a valid integer was read in, and an integer variable, in which the read - in value will be stored.It
returns a bool value that is true if we should continue reading from the stream, and false if we should stop.Function
main() calls get_int in the condition of a while loop which continues as long as get_int returns true.When get_int
returns, if value_is_good is true, then datum contains an integer that was successfully read in.We print it, and then
continue to the loop.When get_int returns false, we stop looping and terminate.
Inside get_int, we first attempt to read an integer.If the stream is good, the variable contains a valid value, and we
can continue reading the stream.If eof was encountered, a valid variable value was not obtained, and it time to stop
reading the input.Likewise, if there was a "hard I/O" error.Finally, if the input was invalid, a valid value was not
obtained.The example follows a policy to skip the rest of the line is skipped, and we should continue trying to read
the stream(unless we hit end of file while skipping the rest of the line).The pattern represented by this example is :

	Attempt to read some input.
	Check the stream state.
	If the state is good, process the input.
	If the state is not good, do the following:
			If the state is eof, then handle an end-of-file condition:
					If an eof is expected and normal, continue processing.
					Otherwise, it is an error; print a message, and take appropriate action.
			If the state is bad bit; print a message and terminate.
			If the state is fail due to invalid input, do the following:
					Print a message informing the user of the bad input.
					Clear the stream state with the clear() function.
					Skip the offending material.
					Resume processing.

*/

using namespace std;

bool get_int(istream&, bool&, int&);

int _tmain(int argc, _TCHAR* argv[])
{
	int datum;
	bool value_is_good = false;
	
	ifstream input_file("data.input");		// open the input file
	if (!input_file.is_open()) {					// check for successful opening
		cout << "File could not be opened! Terminating!" << endl;
		return 1;
	}

	// continue reading integer values as long as get_int returns true
	// but don't use the value unless value_is_good is true
	while (get_int(input_file, value_is_good, datum))
		if (value_is_good)
			cout << "value read is " << datum << endl;

	input_file.close();
	cout << "Done!" << endl;

	return 0;
}

bool get_int(istream& in_strm, bool& good_flag, int& x)
{
	bool continue_flag;

	in_strm >> x;

	if (in_strm.good()) 
	{
		good_flag = true;
		continue_flag = true;										// can keep going
	}
	else if (in_strm.eof()) 
	{
		cout << "End of file encountered." << endl;
		good_flag = false;											// input value was not obtained
		continue_flag = false;									// time to stop
	}
	else if (in_strm.bad()) 
	{
		cout << "Hard I/O error" << endl;
		good_flag = false;
		continue_flag = false;									// give up!
	}
	else if (in_strm.fail()) 
	{
		cout << "Invalid input - skipping rest of line" << endl;
		
		in_strm.clear();												// don't forget! Must clear the stream to read it!
		
		char c;
		while (in_strm.get(c) && c != '\n');		// may hit eof while skipping
		
		good_flag = false;											// value is not good
		if (in_strm.good())											// did we hit eof or something else?
			continue_flag = true;									// no - can keep going
		else 
		{
			continue_flag = false;								// yes - time to stop
			cout << "End of file or error while skipping rest of line." << endl;
		}
	}
	else 
	{
		cout << "Should be impossible to be here!" << endl;			// for demo only!
		good_flag = false;
		continue_flag = false;
	}

	return continue_flag;
}