#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	int arr1[5] = { 1,2,3,4,5 };
	int arr2[8] = { 2,1,2,3,2,4,2,5 };
	int arr3[10] = { 3,3,1,1,2,2,4,4,5,5 };

	int score[3] = {};

	int size = answers.size();

	int highScore = 0;


	for (int i = 0; i < size; i++)
	{
		if (answers[i] == arr1[i % 5])
		{
			score[0]++;
		}
		if (answers[i] == arr2[i % 8])
		{
			score[1]++;
		}
		if (answers[i] == arr3[i % 10])
		{
			score[2]++;
		}
	}

	highScore = score[0];

	for (int i = 0; i < 3; i++)
	{
		if (highScore < score[i])
		{
			highScore = score[i];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (highScore == score[i])
		{
			answer.push_back(i+1);
		}
	}

	return answer;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	solution(v);

}