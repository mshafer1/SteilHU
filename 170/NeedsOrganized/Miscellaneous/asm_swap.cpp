#include <iostream>
#include <iomanip>
using namespace std;
void main()
{
	int a;
	int b;

	cin >> a;
	cin >> b;

	//typical method using an extra variable
	//the best way
	//int c = a;
	//a = b;
	//b =c;


	//Using addition and subtraction
	//a = a + b;
	//b = a - b;
	//a = a - b;

	__asm
    {
        mov    eax, a
        xchg   b, eax
        xchg   a, eax
    }


	//using bitwize math
	//a = a ^ b;
	//b = a ^ b;
	//a = a ^ b;

	//a ^= b ^= a ^= b;
	
	cout << a << endl;
	cout << b;
}
