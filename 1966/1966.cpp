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

		cin >> N >> M; // N = 문서의 수 , M = 궁금한 문서 위치


		for (int j = 0; j < N; j++)
		{
			int val;
			cin >> val;

			q.push({ j,val }); // 인덱스와, 중요도 push
			pq.push(val); // 우선순위 큐에는 중요도 push
		}

		while (!q.empty())
		{
			int currentIndex = q.front().first;
			int currentVal = q.front().second;
			q.pop();

			if (pq.top() == currentVal) // 우선 순위큐의 top과 현재 중요도와 같을때 출력 후 카운트 증가
			{
				pq.pop();
				count++;

				if (currentIndex == M) // 원하던 프린트가 출력될시 현재의 카운트 출력
				{
					cout << count << endl;
					break;
				}
			}
			else
			{
				q.push({ currentIndex,currentVal }); // 중요도가 낮으면 다시 push
			}
		}

	}
	return 0;
}