#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes)
{
	int answer = 0;
	int size = clothes.size();
	int multi=0;
	vector<string> type;
	vector<int> num;

	for (int i = 0; i < size; i++) // 종류만 배열에 추가
	{
		type.push_back(clothes[i][1]);
	}
	sort(type.begin(), type.end());
	type.erase(unique(type.begin(), type.end()),type.end()); // 종류 중복 제거

	for (int i = 0; i < type.size(); i++)
	{
		int sum = 0;
		for (int j = 0; j < size; j++)
		{
			if (type[i] == clothes[j][1])
			{			
				sum++;
			}
		}
		num.push_back(sum); // 종류별 갯수 배열에 추가
	}



	if (num.size() != 1) // 한종류가 아닐시
	{
		multi = num[0]+1;

		for (int i = 1; i < num.size(); i++) // 각 종류 갯수+1로 곱한 값 저장
		{
			multi *= num[i]+1;
		}
		answer = multi-1; // 아무것도 안고른값 1가지를 빼고 answer에 저장
	}
	else // 한종류 일시 갯수만큼 저장
	{
		answer = num[0];
	}
	return answer;
}

int main()
{
	vector<vector<string>> clo;

	vector<string> s;

	s.push_back("hat1");
	s.push_back("head");

	vector<string> d;

	d.push_back("hat2");
	d.push_back("head");

	vector<string> f;

	f.push_back("hat3");
	f.push_back("head");

	vector<string> g;

	g.push_back("pant1");
	g.push_back("pant");

	vector<string> h;

	h.push_back("pant2");
	h.push_back("pant");

	

	clo.push_back(s);
	clo.push_back(d);
	clo.push_back(f);

	clo.push_back(g);
	clo.push_back(h);


	cout << solution(clo);
}