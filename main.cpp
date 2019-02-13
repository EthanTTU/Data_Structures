#include <stdio.h>
#include <iostream>
#include "D_List.h"
using namespace std;

int main()
{
	Node function;
	function.List();
	for (int i = 0; i <= 100 ; i++)
		function.addNode(i);
	try{
	function.remNode(1);
	function.remNode(5);
	function.remNode(3);
	}
	catch (const char *msg){
		cout << msg << endl;
	}
	function.print_list();
	cout << "Size of the list is: " << function.sizelist() << endl;
	return 0;
}
