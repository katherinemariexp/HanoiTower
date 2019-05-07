#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

static vector <int> source, temporary, destination;

void showTowers();
void moveDiscs(vector<int> &, vector<int> &, vector<int> &, int);

int main()
{
    int discs, count;
    
	cout << "Enter tower height ";
	cin >> discs;
	count = discs;
	
	for(int i = 0;i < discs; i++)
	{
	    source.push_back(count);
	    count--;
	}
	
	showTowers();
	moveDiscs(source, destination, temporary, discs);
	
}
void showTowers()
{
    cout << "src: ";
    for (vector<int>::const_iterator iter = source.begin(); iter != source.end(); iter++)
    {
        cout << *iter << " ";
    }
    
    cout << " | ";
    cout << "dest: ";
    for (vector<int>::const_iterator iter = destination.begin(); iter != destination.end(); iter++)
    {
        cout << *iter << " ";
    }
    
    cout << " | ";
    cout << "temp: ";
    for (vector<int>::const_iterator iter = temporary.begin(); iter != temporary.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

void moveDiscs(vector<int> &source, vector<int> &destination, vector<int> &temporary, int size)
{
    if(size > 0)
    {
        moveDiscs(source, temporary, destination, size - 1);
        destination.push_back(source.back());
        source.pop_back();
        showTowers();
        moveDiscs(temporary, destination, source, size - 1);
    }
}