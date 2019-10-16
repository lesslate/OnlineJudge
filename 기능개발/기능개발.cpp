#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;

	queue<int> q;
	queue<int> speedQue;
	int day = 0;

	int size = progresses.size();

	for (int i = 0; i < size; i++)  // 큐에 정보를 담음
	{
		q.push(progresses[i]);
		speedQue.push(speeds[i]);
	}



	while (!q.empty())
	{
		int count = 0;
		day =(int)ceil((100.0 - q.front()) / speedQue.front());
		q.pop();
		speedQue.pop();
		count++;

		if (!q.empty())
		{
			int front = q.front() + day * speedQue.front();
			while (front >= 100)
			{
				q.pop();
				speedQue.pop();
				count++;
				if (!q.empty())
					front = q.front() + day * speedQue.front();
				else
					break;
			}

		}
		answer.push_back(count);

	}



	return answer;
}

int main()
{
	vector<int> p;
	p.push_back(5);
	p.push_back(5);
	p.push_back(5);

	vector<int> s;
	s.push_back(21);
	s.push_back(25);
	s.push_back(20);

	vector<int> ans;
	ans= solution(p, s);

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}

}