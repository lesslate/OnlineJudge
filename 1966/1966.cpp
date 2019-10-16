#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int N=0, M=0;
		int count=0;
		queue <pair<int, int>> q; 
		priority_queue<int> pq;

		cin >> N >> M; // N = ������ �� , M = �ñ��� ���� ��ġ


		for (int j = 0; j < N; j++)
		{
			int val;
			cin >> val;

			q.push({ j,val }); // �ε�����, �߿䵵 push
			pq.push(val); // �켱���� ť���� �߿䵵 push
		}

		while (!q.empty())
		{
			int currentIndex = q.front().first;
			int currentVal = q.front().second;
			q.pop();

			if (pq.top() == currentVal) // �켱 ����ť�� top�� ���� �߿䵵�� ������ ��� �� ī��Ʈ ����
			{
				pq.pop();
				count++;

				if (currentIndex == M) // ���ϴ� ����Ʈ�� ��µɽ� ������ ī��Ʈ ���
				{
					cout << count << endl;
					break;
				}
			}
			else
			{
				q.push({ currentIndex,currentVal }); // �߿䵵�� ������ �ٽ� push
			}
		}

	}
	return 0;
}