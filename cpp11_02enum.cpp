#include <iostream>
using namespace std; 

enum  class Alert { green, yellow, election, red }; // ´«Í³Ã¶¾Ù

int main()
{
	Alert testA = Alert::red;
	Alert testB = Alert(3);
	
	return 0;
}
