#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		cout << mstack.top() << endl;
		mstack.pop();
		cout << mstack.size() << endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			cout << *it << endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		MutantStack<int> mystack;

		mystack.push(3);
		mystack.push(2);
		mystack.push(1);
		MutantStack<int> stk(mystack);
		cout << stk.top() << endl;

		cout << "Forward traversal:" << endl;
		for (MutantStack<int>::const_iterator it = mystack.begin(); it != mystack.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;

		cout << "Reverse traversal:" << endl;
		for (MutantStack<int>::reverse_iterator rit = mystack.rbegin(); rit != mystack.rend(); ++rit) {
			cout << *rit << " ";
		}
		cout << endl;
	}
}