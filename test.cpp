#include <iostream>
using namespace std;

int add(int, int);

int main() {
   cout << "Hello World!\n";
   cout << " Whatever (said the world)\n\n";
   cout << add(12,29);
   cout << " ewwww lala !!!!\n\n";
   int deesballs = 52;
   cout << deesballs << "\n\n";

   return 0;
}

// this needs to be declared above main to work maybe...... h aha ha ha ahah aha hah ah ah ha hah a
// Fixed!
int add(int a, int b) {
	return a+b;
}
