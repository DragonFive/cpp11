#include <iostream>
using namespace std; 

enum  class Alert { green, yellow, election, red }; // ��ͳö��

int main()
{
	Alert testA = Alert::red;
	Alert testB = Alert(3);
	
	return 0;
}
