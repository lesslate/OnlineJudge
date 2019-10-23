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
	


	for (int i = 0; i < numbers.size(); i++) // 정수들을 문자형 배열에 push
	{
		str.push_back(to_string(numbers[i]));
	}

	sort(str.begin(), str.end(), comp); // comp 함수를 이용한 sorting
	
	for (int i = 0; i < str.size(); i++) // 정렬된 문자들 append
	{
		answer += str[i];
	}
	if (answer[0] == '0') // 배열에 0만 들어있을 때 예외처리
	{
		return "0";
	}

	return answer;
}