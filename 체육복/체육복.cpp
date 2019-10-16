#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
	int answer = 0;
	int resSize = reserve.size();
	int lostSize = lost.size();
	vector<int> arr(n,1); // 처음에 모두 체육복 1개씩 할당

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	
	for (int i = 0; i < resSize; i++) // 여분가진애들 ++
	{
		arr[reserve[i]-1]++;
	}

	for (int i = 0; i < lostSize; i++) // 도둑맞은애들 --
	{
		arr[lost[i]-1]--;
	}




	if (arr[0] == 0) // 첫번째 친구가 체육복 없을경우
	{
		if (arr[1] == 2)
		{
			arr[0]++;
			arr[1]--;
		}
	}

	for (int i = 1; i < n-1; i++) // 그사이 친구들중 체육복 없는애들
	{
		if (arr[i] == 0) 
		{
			if (arr[i - 1] == 2) // 앞에놈꺼 하나만~
			{
				arr[i - 1]--;
				arr[i]++;
			}
			else if (arr[i + 1] == 2) // 앞엣놈 없으면 뒤엣놈한테 하나만~
			{
				arr[i + 1]--;
				arr[i]++;
			}
		}
	}

	if (arr[n - 1] == 0) // 마지막 친구가 체육복 없을경우
	{
		if (arr[n - 2] == 2)
		{
			arr[n - 2]--;
			arr[n - 1]++;
		}
	}

	for (int i = 0; i < n; i++) // 이제 체육복 가진애들 계산
	{
		if (arr[i] > 0)
		{
			answer++;
		}
	}

	return answer;
}

int main()
{

	//for (int i = 0; i < n; i++)
	//{
	//	cout << arr[i] << " ";
	//}


	int n = 5;
	vector<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);

	vector<int> r;
	r.push_back(1);
	r.push_back(2);
	r.push_back(3);
	

}