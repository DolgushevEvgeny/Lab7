// FindMax.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <assert.h>
#include <string>

using namespace std;

template <typename T, typename Comp = less<T>>
bool FindMax(const vector<T> &inputArray, T &maxValue, Comp const &comp = less<T>())
{
	if (inputArray.size() == 0)
	{
		return false;
	}

	size_t max = 0;

	for (size_t i = 1; i < inputArray.size(); ++i)
	{
		if (comp(inputArray[max],inputArray[i]))
		{
			max = i;
		}
	}
	maxValue = inputArray[max];
	return true;
}

struct Sportsman
{
	string name;
	int age;
	int weight;
	int height;
};

int main(int argc, char* argv[])
{
	vector<int> test = {-1, 2, 0, 4, 45, -19};
	int resultMax;
	FindMax(test, resultMax, [](int a, int b){return a < b; });
	assert(resultMax == 45);

	vector<string> test1 = {"cat", "cow", "dog", "apple"};
	string result;
	FindMax(test1, result, [](string a, string b){return a < b; });
	assert(result == "dog");

	vector<Sportsman> sportsman = {
		{ "Ivan Petrov", 20, 100, 150 },
		{ "Eugene Dolgushev", 20, 87, 188 },
		{ "Vladimir Alitov", 20, 62, 175 },
		{ "Jay Cutler", 41, 130, 175 },
		{ "Usain Bolt", 28, 94, 195}
	};
	Sportsman tallestSportsman;
	FindMax(sportsman, tallestSportsman, [](Sportsman const &a, Sportsman const &b){ return a.height < b.height; });
	assert(tallestSportsman.name == "Usain Bolt");

	Sportsman heaviestSportsman;
	FindMax(sportsman, heaviestSportsman, [](Sportsman const& a, Sportsman const& b){ return a.weight < b.weight;});
	assert(heaviestSportsman.name == "Jay Cutler");

	return 0;
}

