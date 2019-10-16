#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

string solution(string s)
{
	string answer = "";

	int half = s.size() / 2.0;
	
	if (s.size() % 2 == 0)
	{
		answer += s[half - 1];
		answer += s[half];
	}
	else
	{
		answer = s[half];
	}

	return answer;
}

int main()
{
	cout << solution("abcde");
}