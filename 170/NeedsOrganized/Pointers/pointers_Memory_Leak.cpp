//This program does not use delete. It has a memory leak.

//WARNING, this program will quickly use up all of your available memory.
//Do not run.

int main()
{

	int* p;
	
	while(true) //forever
	{
		p = new int; //delete is never used, more and more memory is borrowed
	}

    return 0;
}





