#include <iostream>
#include <string>

using namespace std;

int add (const int a, const int b)
{
	return a + b;
}

string add (const string& str1, const string& str2)
{
	return str1 + str2;
}
int main(int argc, char* argv[])
{
	cout << add("the result of", "£¨add(1, 2)£©:") << add(1, 2) << endl;
	return 0;
}
