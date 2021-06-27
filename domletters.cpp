// Jonathan Rivera
// CS 561
// Domletters
//
// Sources:
// https://stackoverflow.com/questions/13035674/how-to-read-a-file-line-by-line-or-a-whole-text-file-at-once
//


#include "domletters.h"

void process(string & text);


int main()
{
	string input;
	string text;

	while (getline(cin, input))
	{
		text += input;
		text.push_back('\n');
	}
	
	cout << text << endl;

	process(text);

	cout << text << endl;

	return 0;
}


// This function reads in text from an external file.
// It returns an integer.
void process(string & text)
{
	//int count = 0;
	text += "Look, I added something.";
	text.push_back('\n');

	return;
}
