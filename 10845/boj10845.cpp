#include <iostream>
#include <queue>
#include <string>

using namespace std;




int main()
{
	int n;
	cin >> n;

	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;

		if (input == "push")
		{
			int data;
			cin >> data;
			q.push(data);
		}
		else if (input == "pop")
		{
			int num;

			if (q.size() != 0)
			{
				num=q.front();
				q.pop();
			}
			else // ��������� -1 ���
			{
				num = -1;
			}
			cout << num << endl;
		}
		else if (input == "size")
		{
			cout << q.size() << endl;
		}
		else if (input == "empty")
		{
			cout << q.empty() << endl;
		}
		else if (input == "front")
		{
			if (q.size() != 0)
			{
				cout << q.front() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else   // back
		{
			if (!q.empty())
			{
				int size = q.size();

				for (int i = 0; i < size - 1; i++) // pop�� push�� �ݺ��Ͽ� �� ���� ���� front�� �ǵ�����
				{
					int num = q.front();
					q.pop();
					q.push(num);
				}
				int num = q.front();
				
				cout << num << endl; // �� �ڿ� ��(back)�� front���Ǿ����� ���

				q.pop(); // �ٽ� pop& push�Ͽ� ť ����
				q.push(num);
			}
			else
			{
				cout << -1 << endl;
			}
		}
	}
}