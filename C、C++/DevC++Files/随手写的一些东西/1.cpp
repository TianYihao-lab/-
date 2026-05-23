#include <iostream>
#include <cmath>
using namespace std;

int n;
typedef struct
{
	string name;
	int score;
} stu;
stu ss[100];

void swap(stu &s1, stu &s2)
{
	string temps = s1.name;
	float tempfloat = s1.score;
	s1.name = s2.name;
	s1.score = s2.score;
	s2.name = temps;
	s2.score = tempfloat;
}

// 这道题需要对学生进行排序
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> ss[i].name >> ss[i].score;
	}
	for (int i = 0; i < n; i++)
	{
		int cnt = i;
		for (int j = i; j < n; j++)
		{
			if (ss[j].score > ss[cnt].score)
				cnt = j;
		}
		swap(ss[i], ss[cnt]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << ss[i].name << " " << ss[i].score << endl;
	}
	return 0;
}