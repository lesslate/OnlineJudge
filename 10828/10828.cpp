#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> stk;

void push(int a)
{
	stk.push(a);
}

void pop()
{
	if (stk.empty())
	{
		cout << "-1" << "\n";
		return;
	}

	cout << stk.top() << "\n";
	stk.pop();
}

void size()
{
	cout << stk.size() << "\n";
}

void empty()
{
	if (stk.empty())
	{
		cout << 1 << "\n";
	}
	else
	{
		cout << 0 << "\n";
	}
}

void top()
{
	if (stk.empty())
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << stk.top() << "\n";
	}
}
int main()
{
	int n;
	string str;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> str;

		if (str == "push")
		{
			int num;
			cin >> num;
			push(num);
		}
		else if (str == "pop")
		{
			pop();
		}
		else if (str == "size")
		{
			size();
		}
		else if (str == "empty")
		{
			empty();
		}
		else 
		{
			top();
		}
	}

	
}