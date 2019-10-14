#include "GenStack.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
	GenStack<char> stack;

	std::ifstream file;
	string fileName;
	std::cout << "What file do you want to check? " << flush;
	while(true){
		file.close();
    	file.clear();
		getline(cin, fileName); //get the file name from terminal
		file.open(fileName.c_str()); //open the file
		if(file){
			break;
		}
		std::cout << "Invalid file name, please enter a valid name: " << flush;
	}

	if (file.is_open()) {
	    std::string line;
		int currLine = 0;
	    while (getline(file, line)) {
			char cur;
			++currLine;
			for(int i = 0; i<line.length(); ++i){
				cur = char(line.at(i));
				//add each delimiter to stack
				if(cur == '(' || cur == '{' || cur == '['){
					stack.push(cur);
				}else if(cur == ')' || cur == '}' || cur == ']'){
					if(!stack.isEmpty()){
						char last = stack.pop();
						if(cur == ')' && last != '('){
							std::cout << "Line " << currLine << ": Expected ( Found " << last << '\n';
							return 0;
						}else if(cur == '}' && last != '{'){
							std::cout << "Line " << currLine << ": Expected { Found " << last << '\n';
							return 0;
						}else if(cur == ']' && last != '['){
							std::cout << "Line " << currLine << ": Expected [ Found " << last << '\n';
							return 0;
						}
					}else{
						if(cur == ')'){
							std::cout << "Line " << currLine << ": ) Found Without (" << '\n';
							return 0;
						}else if(cur == '}'){
							std::cout << "Line " << currLine << ": } Found Without {" << '\n';
							return 0;
						}else if(cur == ']'){
							std::cout << "Line " << currLine << ": ] Found Without [" << '\n';
							return 0;
						}
					}
				}
			}
	    }
	    file.close();

		//check if there are any remaining delimiters in the stack
		if(!stack.isEmpty()){
			char missing = stack.pop();
			if(missing == '('){
				std::cout << "Reached end of file: missing )" << '\n';
				return 0;
			}else if(missing == '{'){
				std::cout << "Reached end of file: missing }" << '\n';
				return 0;
			}else if(missing == '['){
				std::cout << "Reached end of file: missing ]" << '\n';
				return 0;
			}
		}
	}
	std::cout << "There are no missing delimiters in the file." << '\n';
	return 0;
};
