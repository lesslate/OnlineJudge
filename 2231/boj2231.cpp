#include <iostream>



using namespace std;

int Hap(int M) // 분해합 계산
{
	int hap = M;

	while (M != 0) // 각 자리수 더하기
	{
		int Rest = M % 10;
		hap += Rest;
		M /= 10;
	}

	return hap;
}

int Solution(int N)
{
	for (int i = 0; i <= 1000000; i++)
	{
		if (Hap(i) == N) // N과 같은 생성자가 나올시 출력
		{
			return i;
		}
	}

	return 0; // 없을 시 0 출력
}

int main()
{
	int N = 0;

	cin >> N;

	cout << Solution(N) << endl;
}