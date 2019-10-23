#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int depth)
{
	int sum = 0;
	if (depth == numbers.size())
	{
		for (int i = 0; i < numbers.size(); i++)
		{
			sum += numbers[i];
		}

		if ( target == sum )
		{
			answer++;
		}
	}
	else
	{
		numbers[depth] = +numbers[depth];
		dfs(numbers, target, depth + 1);
		numbers[depth] = -numbers[depth];
		dfs(numbers, target, depth + 1);
	}
	
}

int solution(vector<int> numbers, int target)
{
	dfs(numbers, target, 0);
	return answer;
}

int main()
{
	vector<int> number(5, 1);
	
	solution(number, 3);

	cout << answer;
}