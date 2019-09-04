// introduction to bitwise operators.
// Run program to see examples.

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

/*
Operator Description 

&  The bitwise-AND operator compares each bit of its first operand to the 
corresponding bit of its second operand. If both bits are 1, the corresponding
result bit is set to 1. Otherwise, the corresponding result bit is set to 0.   

^  The bitwise-exclusive-OR operator compares each bit of its first 
operand to the corresponding bit of its second operand. If one bit is 
0 and the other bit is 1, the corresponding result bit is set to 1. 
Otherwise, the corresponding result bit is set to 0.   

| The bitwise-inclusive-OR operator compares each bit of its first operand to 
the corresponding bit of its second operand. If either bit is 1, the corresponding 
result bit is set to 1. Otherwise, the corresponding result bit is set to 0.   

*/ 

int main()
{
	int x = 2;
	int y = 4;
	int answer = 0;

	answer = x | y;
	cout << "2 | 4 = " << answer << endl;

	answer = 9 | 13;
	cout << "9 | 13 = " << answer << endl << endl;

   answer = x & y;
	cout << "2 & 4 = " << answer << endl;

   answer = 9 & 13;
	cout << "9 & 13 = " << answer << endl  << endl;

	answer = x ^ y;
	cout << "2 ^ 4 = " << answer << endl;

	answer = 9 ^ 13;
	cout << "9 ^ 13 = " << answer << endl;
	
	cin.get();
	return 0;
}
	
/*
	Exercises

	1.	12 | 3	_______________

	2.	12 & 3	_______________

	3.	12 ^ 3	_______________

	4.	14 | 7	_______________

	5.	14 & 7	_______________

	6.	14 ^ 7	_______________

*/

