//this program receives values from the user and generates an average.
//		- "for" loop intro
//		- "if-else" statements intro
//			- includes "if-else-if" statements

#include<iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	int numberCount;

	cout << "How many number do you want to average? ";
	cin >> numberCount;

	float total = 0;

	float numberFromUser;

	//"for" loop format: 
	//
	//		for([initialization expression]; [boolean expression]; [update expression])
	//		{
	//			[code]
	//		}
	//
	// initialization expression (optional)
	//		-executed once, at the beginning of the loop
	//		-usually initializes a counter variable
	//		-you can also declare a variable here
	//			-If a variable is declared here, it's scope is limited to the code being looped.
	//		-supports multiple expressions/declarations, seperated by commas 
	//		-examples: 
	//			-for(int i = 0; ...; ...){...}
	//			
	//			-for(int i = 0, int j = 0; ...; ...){...}
	//
	//			-int x;
	//			 for(x = 0; ...; ...){...}
	//
	// boolean expression
	//		-same as what is used in an "if" statement.
	//		-A semicolon must ALWAYS precede this expression. 
	//		-A semicolon must ALWAYS follow this expression.
	//		-example: for(...; x > y && y > 0; ...){...}
	//
	// update expression (optional)
	//		-executed at the end of every block of code being looped
	//			-in other words, imagine this expression being the very last line in the code being looped
	//		-usually used to increment/decrement a counter variable
	//		-can be used for other things such as function calls
	//		-supports multiple expressions, seperated by commas (not semicolons)
	//		-example: for(...; ...; i++){...}

	
	for(int currentNumber = 1; currentNumber <= numberCount; currentNumber++)
	{
		cout << "Enter the " << currentNumber;
		
		int onesPlace = (currentNumber) - ((currentNumber)/10 * 10);
		int teensPlace = (currentNumber) - ((currentNumber)/100 * 100);

		if(teensPlace == 11 || teensPlace == 12 || 
		 teensPlace == 13 || onesPlace > 3 || onesPlace == 0)
		{
			cout << "th number: ";
		}
		else if(onesPlace == 1) 	// the keyword "else" may be used only directly following an "if" statement,
									// to create an "if-else" statement. The code following "else" is only executed 
		{							// when its counterpart is if(false). If multiple lines of code are to be
		cout << "st number: ";		// executed using "else," curly braces ({}) must be used. One way to use
		}							// "else" is to link multiple "if" and "else" statements, collectively known
		else if(onesPlace == 2) 	// as an "if-else-if" statement. The code to the left is an example of an
		{							// "if-else-if" statement. See line 95 for an example of "else" that is not
			cout << "nd number: ";	// an "if-else-if" statement.
		}							
		else if(onesPlace == 3)
		{
			cout << "rd number: ";
		}
		cin >> numberFromUser;
		total += numberFromUser; //same as "total = total + numberFromUser"
		
		// "currentNumber++" is executed now, as determined in the for loop expressions	
	}

	
	if(numberCount > 0)
	{
		cout << "The average is " << total/numberCount << endl;
	}
	else
	{
		cout << "No numbers entered" << endl;
	}
	return 0;
}