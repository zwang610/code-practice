#include <iostream>
#include "Stack.h"
using namespace std;

#include <cstring>
#include <string>

int main() {
	cout << "Programmer: Zheyi Wang\n";
	cout << "File: " << __FILE__ << endl;

	string input = " ";
	Stack <float>stk(20);
	char buff[20] = " ";
	string read = " ";
	float operand1 = 0;
	float operand2 = 0;

	while (true)
	{
		cout << "\nPress enter to continue, enter q or Q to quit: " << endl;
		getline(cin, input);													//get input to check if user want to continue

		if (input == "q" || input == "Q") break;								//if input is q, break

		while (true)
		{
			cout << "Enter a number or an operation (enter q to quit):";		
			getline(cin, read);													//get a number, operation or q from user

			if (read == "q" || read == "Q") break;								//if it is q, then break
			else if (atof(read.c_str())) stk.push(atof(read.c_str()));			//if it is a number, then push it on the stack
			else if (read == "+")												//if it is addition
			{
				operand2 = stk.peek();											//save the value at the top
				stk.pop();														//remove the top
				operand1 = stk.peek();											//save the value at the top
				stk.pop();														//remove the top
				stk.push(operand1 + operand2);									//do the addition
			}
			else if (read == "-")
			{
				operand2 = stk.peek();											//save the value at the top
				stk.pop();														//remove the top
				operand1 = stk.peek();											//save the value at the top
				stk.pop();														//remove the top
				stk.push(operand1 - operand2);									//do the subtraction
			}
			else if (read == "*")
			{
				operand2 = stk.peek();											//save the value at the top
				stk.pop();														//remove the top
				operand1 = stk.peek();											//save the value at the top
				stk.pop();														//remove the top
				stk.push(operand1 * operand2);									//do the multipication
			}
			else if (read == "/")
			{
				operand2 = stk.peek();											//save the value at the top
				stk.pop();														//remove the top
				operand1 = stk.peek();											//save the value at the top
				stk.pop();														//remove the top
				stk.push(operand1 / operand2);									//do the division
			}
		}


		if (stk.size() != 1) cout << "Wrong calulation." << endl;				//if there is not only the result left on the stack, input input error															
		else cout << "The result is: " << stk.peek() << endl;					//if there is only result left on the stack, peek it and output it
		stk.clear();															//clear the stack
	}

	return 0;
}