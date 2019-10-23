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

		if (pq.top() == currentVal) // 우선 순위큐의 top과 현재 중요도와 같을때 출력 후 Answer(counter) 증가
		{
			pq.pop();
			answer++;

			if (currentIndex == location) // 원하던 프린트가 출력될시 현재의 Answer(counter) 반환
			{
				return answer;
			}
		}
		else
		{
			q.push({ currentIndex,currentVal }); // 중요도가 낮으면 다시 push
		}
	}

	
}