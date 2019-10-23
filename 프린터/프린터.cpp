#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location)
{
	int answer = 0;

	queue<pair<int,int>> q;
	priority_queue<int> pq;
	for (int i = 0; i < priorities.size(); i++)
	{
		q.push({ i,priorities[i] });
		pq.push(priorities[i]);
	}

	while (!q.empty())
	{
		int currentIndex = q.front().first;
		int currentVal = q.front().second;
		q.pop();

		if (pq.top() == currentVal) // �켱 ����ť�� top�� ���� �߿䵵�� ������ ��� �� Answer(counter) ����
		{
			pq.pop();
			answer++;

			if (currentIndex == location) // ���ϴ� ����Ʈ�� ��µɽ� ������ Answer(counter) ��ȯ
			{
				return answer;
			}
		}
		else
		{
			q.push({ currentIndex,currentVal }); // �߿䵵�� ������ �ٽ� push
		}
	}

	
}