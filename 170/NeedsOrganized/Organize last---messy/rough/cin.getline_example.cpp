//this does not work

	#include<iostream>
	using namespace std;
	
	int main()
	{
		//advantages of using getline over >>
		//can get multiple words (it does not stop at white space)
		//has bounds checking
		//when more characters are entered than the limit 
		//  set, an error flag is set
		char s[100];
		cin.getline(s,10);
		cout << s << endl;
		
		//removes the error that may have been set by 
		//entering too many characters
		cin.clear(); 
		
		//throws away all of the characters in the input buffer
		int bufferSize = cin.rdbuf()->in_avail();
		cin.ignore(bufferSize);
		
		cin.getline(s,10);
		cout << s << endl;
		return 0;
	}
