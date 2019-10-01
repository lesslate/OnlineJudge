#include "iostream"

using namespace std;

int n = 0;
int max_Candy = 0;
char arr[51][51];

void Horizontal() // ���� ���� �̾��� ĵ�� ���
{
	for (int i = 0; i < n; i++)
	{
		int count = 1;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == arr[i][j + 1]) // ���� ĵ��� ��ŭ ī��Ʈ ����
			{
				count++;
			}
			else 
			{
				if (max_Candy < count) // �ִ� ����
				{
					max_Candy = count;
				}
				count = 1; // ī��Ʈ �ʱ�ȭ
			}
		}
	}
}

void Vertical()
{
	for (int i = 0; i < n; i++) // ���� ���� �̾��� ĵ�� ���
	{
		int count = 1;
		for (int j = 0; j < n; j++)
		{
			if (arr[j][i] == arr[j + 1][i]) // ���� ĵ��� ��ŭ ī��Ʈ ����
			{
				count++;
			}
			else
			{
				if (max_Candy < count) // �ִ� ����
				{
					max_Candy = count;
				}
				count = 1; // ī��Ʈ �ʱ�ȭ
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}


	for (int i = 0; i < n; i++)  // ���� ��ȯ
	{
		for (int j = 0; j < n - 1; j++)
		{
			char tmp = arr[i][j];      // ���� ĵ�� ����
			arr[i][j] = arr[i][j + 1]; 
			arr[i][j + 1] = tmp;		
			
			Vertical();				   // �̾��� ĵ��� �˻�
			Horizontal();

			tmp = arr[i][j];		   // ���� ����ġ
			arr[i][j] = arr[i][j + 1];
			arr[i][j + 1] = tmp;
		}
	}

	for (int i = 0; i < n; i++)  // ���� ��ȯ
	{
		for (int j = 0; j < n - 1; j++)
		{
			char tmp = arr[j][i];	 //���� ĵ�� ����
			arr[j][i] = arr[j+1][i];
			arr[j+1][i] = tmp;

			Vertical();		         // �̾��� ĵ��� �˻�
			Horizontal();

			tmp = arr[j][i];		 // ���� ����ġ
			arr[j][i] = arr[j+1][i];
			arr[j+1][i] = tmp;
		}
	}

	cout << max_Candy << endl;
}

