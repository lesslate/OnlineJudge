#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) 
{
	int answer = 0;

	sort(citations.begin(), citations.end());

	for (int i = 1; i <= citations.size(); i++)
	{
		int high = 0;
		int low = 0;
		for (int j = 0; j < citations.size(); j++)
		{
			if (citations[j] >= i)
			{
				high++;
			}
			else
			{
				low++;
			}
		}
		if (high>=i)
		{
			if (low<=i)
			{
				answer = i;
			}
		}
	}

	return answer;

}

int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(0);
	v.push_back(6);
	v.push_back(1);
	v.push_back(5);

	cout << solution(v) << endl;
}