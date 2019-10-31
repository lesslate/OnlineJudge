#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) 
{
	vector<int> answer;
	int j = 0;
	for (int i = 0; i < heights.size(); i++)
	{
		if (i == 0)
		{
			answer.push_back(0);
		}
		else
		{
			for (j = i; j < 0; j--)
			{
				if (heights[i] < heights[j])
				{
					answer.push_back(j+1);
					break;
				}
				else if (j == 0)
				{
					answer.push_back(0);
				}
			}
			
		}
	}

	return answer;
}