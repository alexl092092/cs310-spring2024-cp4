#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	string input;
	getline(cin, input);
	//Start of tokenizing string
	while(input != "quit")
	{
		vector<string> tokens;
		string token;
		int numTokens;
		bool prevWhitespace = false;
		bool inQuotes = false;
		for(int i = 0; i < input.length(); i++)
		{
			if(input[i] == ' ' && !inQuotes)
			{
				if(!prevWhitespace)
				{
					tokens.push_back(token);
					token = "";
					prevWhitespace = true;
				}
			}
			else
			{
				if(input[i] == '"')
				{
					if(inQuotes)
						inQuotes = false;
					else
						inQuotes = true;
				}
				else
				{
					token += input[i];
					prevWhitespace = false;
				}
			}
		}
		//End quotes error checking
		if(!inQuotes)
			tokens.push_back(token);
		else
		{
			cout << "Your input does not include end quotes. Try again." << endl;
			printCommands();
			getline(cin, input);
			continue;
		}
		//End of tokenizing string
		
		//Start of general error checking
		//Check for empty input
		if(tokens[0] == "" && tokens[1] == "")
		{
			cout << "Input is empty. Try again." << endl;
			printCommands();
			getline(cin, input);
			continue;
		}
		
		/* If whitespace exists before the command, there will be a blank string at index 0
		of tokens, meaning each token has to be moved back 1 index */
		if(tokens[0] == "")
		{
			for(int i = 0; i < size(tokens) - 1; i++)
			{
				tokens[i] = tokens[i + 1];
			}
			tokens.pop_back();
		}
		
		//Actual Code
		
		
		
	}
}
