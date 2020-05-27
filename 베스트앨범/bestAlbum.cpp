#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
	map<string,int> albumMap;
	vector<pair<string,int>> albums;

	
	
	for (int i = 0; i < genres.size(); i++)
	{
		albumMap[genres[i]] += plays[i];
	}

	map<string, int>::iterator iter = albumMap.begin();
	for (iter = albumMap.begin(); iter != albumMap.end(); iter++)
	{
		albums.push_back(make_pair(iter->first, iter->second));
	}

	sort(albums.begin(), albums.end(), cmp);


	for (int i = 0; i < albums.size(); i++)
	{
		int first = 0, second = 0, firstIdx = 0, secondIdx = 0 ;
		for (int j = 0; j < genres.size(); j++)
		{
			if (genres[j] == albums[i].first)
			{
				if (plays[j]>first)
				{
					second = first;
					secondIdx = firstIdx;
					first = plays[j];
					firstIdx = j;
				}
				else if (plays[j]>second)
				{
					second = plays[j];
					secondIdx = j;
				}
			}
		}
		answer.push_back(firstIdx);
		if (second > 0)
		{
			answer.push_back(secondIdx);
		}

	}

    return answer;
}

int main()
{
	vector<string> s;
	s.push_back("classic");
	s.push_back("classic");
	s.push_back("classic");
	s.push_back("pop");
	s.push_back("pop");

	vector<int> n;
	n.push_back(1000);
	n.push_back(500);
	n.push_back(1000);
	n.push_back(100);
	n.push_back(100);


	
	solution(s, n);
}