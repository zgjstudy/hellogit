#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct StudentInfo
{
	bool sex;
	double score;
};

struct Student
{
	string name;
	StudentInfo info;
};

struct rule
{
	bool operator() (const Student & i1, const Student & i2)
	{
		if( i1.info.score != i2.info.score)
			return i1.info.score > i2.info.score;
		else
			return i1.name < i2.name;
	}
};

typedef set<Student, rule> st;

int main()
{
	freopen("score.csv", "r", stdin);
	int num = 0, mnum = 0, fnum = 0;
	double sum = 0, msum = 0, fsum = 0;
	st sst;
	Student ad;
	char cmd[100];
	cin.getline(cmd,100);
	while(cin.peek() != EOF)
	{
		cin.getline(cmd, 20, ',');
		cin.get();
		ad.name = cmd;
		
		char s;
		cin.get(s);
		if(s == 'M')
			ad.info.sex = 1;
		else
			ad.info.sex = 0;
		
		s = cin.peek();
		while(!isdigit(s))
		{
			cin.get();
			s = cin.peek();
		}
		
		cin.getline(cmd,100);
		ad.info.score = atof(cmd);
		
		sum += ad.info.score;
		num++;
		if(ad.info.sex)
		{
			msum += ad.info.score;
			mnum++;
		}
		else
		{
			fsum += ad.info.score;
			fnum++;
		}
		
		sst.insert(ad);
	}
	
	cout << sum/num << endl << msum/mnum << endl << fsum/fnum << endl;
	
	st::iterator i;
	for(i = sst.begin(); i != sst.end(); ++i)
	{
		cout << i->name << ", ";
		if(i->info.sex)
			cout << "Male, ";
		else
			cout << "Female, ";
		cout << i->info.score << endl;
	}

	return 0;
}
