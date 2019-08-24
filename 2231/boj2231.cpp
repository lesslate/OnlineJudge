#include <iostream>



using namespace std;

int Hap(int M) // ������ ���
{
	int hap = M;

	while (M != 0) // �� �ڸ��� ���ϱ�
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
		if (Hap(i) == N) // N�� ���� �����ڰ� ���ý� ���
		{
			return i;
		}
	}

	return 0; // ���� �� 0 ���
}

int main()
{
	int N = 0;

	cin >> N;

	cout << Solution(N) << endl;
}