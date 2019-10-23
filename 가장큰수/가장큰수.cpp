#include <string>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool comp(const string &a, const string &b)
{
	if (b + a < a + b)
		return true;
	return false;
}

string solution(vector<int> numbers)
{
	string answer = "";

	vector<string> str;
	


	for (int i = 0; i < numbers.size(); i++) // �������� ������ �迭�� push
	{
		str.push_back(to_string(numbers[i]));
	}

	sort(str.begin(), str.end(), comp); // comp �Լ��� �̿��� sorting
	
	for (int i = 0; i < str.size(); i++) // ���ĵ� ���ڵ� append
	{
		answer += str[i];
	}
	if (answer[0] == '0') // �迭�� 0�� ������� �� ����ó��
	{
		return "0";
	}

	return answer;
}