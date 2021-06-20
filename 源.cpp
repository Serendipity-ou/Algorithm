#include <iostream>
using namespace std;

#define maxsize 100

int MIN(int i, int j, int k)
{
	int min;
	if (i < j)
		min = i;
	else
		min = j;

	if (min > k)
		min = k;

	return min;
}

int StrDist(char* str1, char* str2){
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int** deal = new int* [len1 + 1];
	for (int i = 0; i < len1 + 1; i++)
		deal[i] = new int[len2 + 1];

	for (int i = 0; i < len1; i++)
		deal[i][len2] = len1 - i;

	for (int j = 0; j < len2; j++)
		deal[len1][j] = len2 - j;
	deal[len1][len2] = 0;

	for (int i = len1 - 1; i >= 0; i--)
	{
		for (int j = len2 - 1; j >= 0; j--)
		{
			if (str1[i] == str2[j])
				deal[i][j] = deal[i + 1][j + 1];
			else
				deal[i][j] = MIN(deal[i + 1][j + 1], deal[i][j + 1], deal[i + 1][j]) + 1;
		}
	}

	int result = deal[0][0];
	for (int i = 0; i < len1 + 1; i++)
	{
		if (deal[i] != NULL)
			delete[]deal[i];
		deal[i] = NULL;
	}
	return result;
}

int main()
{
	char src[maxsize], dest[maxsize];
	int len1, len2, num;

	cout << "请输入源字符串：";
	cin >> src;
	cout << "请输入目标字符串：";
	cin >> dest;

	len1 = strlen(src);
	len2 = strlen(dest);

	num = StrDist(src, dest);
	cout << "最小操作次数为：" << num << endl;

	return 0;
}
