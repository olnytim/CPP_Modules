#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
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
			std::cout << *it << std::endl;
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
		std::cout << stk.top() << std::endl;

		std::cout << "Forward traversal:" << std::endl;
		for (MutantStack<int>::const_iterator it = mystack.begin(); it != mystack.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Reverse traversal:" << std::endl;
		for (MutantStack<int>::reverse_iterator rit = mystack.rbegin(); rit != mystack.rend(); ++rit) {
			std::cout << *rit << " ";
		}
		std::cout << std::endl;
	}
}