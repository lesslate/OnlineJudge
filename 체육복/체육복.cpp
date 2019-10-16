#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
	int answer = 0;
	int resSize = reserve.size();
	int lostSize = lost.size();
	vector<int> arr(n,1); // ó���� ��� ü���� 1���� �Ҵ�

	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	
	for (int i = 0; i < resSize; i++) // ���а����ֵ� ++
	{
		arr[reserve[i]-1]++;
	}

	for (int i = 0; i < lostSize; i++) // ���ϸ����ֵ� --
	{
		arr[lost[i]-1]--;
	}




	if (arr[0] == 0) // ù��° ģ���� ü���� �������
	{
		if (arr[1] == 2)
		{
			arr[0]++;
			arr[1]--;
		}
	}

	for (int i = 1; i < n-1; i++) // �׻��� ģ������ ü���� ���¾ֵ�
	{
		if (arr[i] == 0) 
		{
			if (arr[i - 1] == 2) // �տ��� �ϳ���~
			{
				arr[i - 1]--;
				arr[i]++;
			}
			else if (arr[i + 1] == 2) // �տ��� ������ �ڿ������� �ϳ���~
			{
				arr[i + 1]--;
				arr[i]++;
			}
		}
	}

	if (arr[n - 1] == 0) // ������ ģ���� ü���� �������
	{
		if (arr[n - 2] == 2)
		{
			arr[n - 2]--;
			arr[n - 1]++;
		}
	}

	for (int i = 0; i < n; i++) // ���� ü���� �����ֵ� ���
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