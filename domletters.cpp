// Jonathan Rivera
// CS 561
// Domletters
//
// Sources:
// https://stackoverflow.com/questions/13035674/how-to-read-a-file-line-by-line-or-a-whole-text-file-at-once
// https://www.geeksforgeeks.org/split-a-sentence-into-words-in-cpp/


#include "domletters.h"

string process(string input, int & count);
int max_value(int array[]);


int main()
{
	string input;
	string full_text;
	int count = 0;

	while (getline(cin, input))
	{
		full_text += process(input, count);
		full_text.push_back('\n');
	}
	
	cout << full_text << endl;
	cout << "FULL COUNT IS: " << count << endl;

	return 0;
}


// This function processes the input text.
// It returns a string
string process(string input, int & count)
{
	int ascii[128];
	int length = input.length();
	string word = "";
	string processed_text;
	int i;
	bool alpha_flag = true;

	for (i = 0; i < 128; ++i) // initialize array to zeroes
	{
		ascii[i] = 0;
	}

	for (i = 0; i <= length; ++i) { // iterate through the string
		char ch = input[i];
		int max_index = 0;
		int max_val = 0;

		if (isalpha(ch)) {
			ascii[int(ch)] += 1; 
			word = word + ch;
		}
		
		else if (ch != ' ' && ch != '\0') {

			word = word + ch;
			processed_text += word;
			word = "";

			alpha_flag = false;

			for (int j = 0; j < 128; ++j) // reset array to zeroes
			{
				ascii[j] = 0;
			}
		}

		else {
			processed_text += word;
			max_val = max_value(ascii);
			max_index = distance(ascii, max_element(ascii, ascii + 128));
			cout << "MAX INDEX IS: " << max_index << endl;

			if (max_index < 97) {
				max_val += ascii[max_index + 32];
			}
			else {
				max_val += ascii[max_index - 32];
			}

			if (alpha_flag == false) {
				max_val = 0;
			}

			cout << "MAX VALUE IS: " << max_val << endl;

			processed_text.push_back('(');
			processed_text += to_string(max_val);
			processed_text.push_back(')');
			count += max_val;
			
			processed_text.push_back(' ');
			word = "";
			
			for (int j = 0; j < 128; ++j) // reset array to zeroes
			{
				ascii[j] = 0;
			}
			
			alpha_flag = true;
		}
	}

	return processed_text;
}

int max_value(int array[]) {

	int max = array[0];
	int i;

	for(i = 1; i < 128; ++i)
	{
		if(max < array[i]) {
			max = array[i];
		}
	}

	return max;
}