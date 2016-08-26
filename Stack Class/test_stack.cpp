#include "Stack.h"
using namespace std;


int main() {
	Stack stack;
	string user_input;
	while (getline(cin, user_input)) {
		for (int i = 0; i < user_input.length(); i++) {
			stack.push(user_input[i]);
		} while (!stack.isEmpty()) {
			cout << stack.pop();
		} cout << endl;
	}
	return 0;
}
