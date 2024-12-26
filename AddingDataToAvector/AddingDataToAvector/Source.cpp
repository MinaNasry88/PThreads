#if 0
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

vector<vector<int>> y;

void getLine(vector<int> x)
{
	

	y.push_back(x);

}

void getFilePath(string path)
{
	ifstream file;
	file.open(path);
	string line;

	while (getline(file, line))
	{
		istringstream ss(line);
		int i;
		vector<int> lines;

		while (ss >> i)
		{
			lines.push_back(i);
		}

		getLine(lines);
	}
}

int main()
{
	getFilePath("test.txt");

	for (int i = 0; i < y.size(); i++)
	{
		for (int j = 0; j < y[i].size(); j++)
		{
			cout << y[i][j] << " ";
		}
		cout << "\n";
	}
}





int main()
{
	vector<int> a = { 1, 2, 3, 4, 5 };
	vector<int> b = { 6, 7, 8, 9, 10 };

	vector<vector<int>> ab;

	ab.push_back(a);
	ab.push_back(b);

	for (int i = 0; i < ab.size(); i++)
	{
		for (int j = 0; j < ab[i].size(); j++)
		{
			cout << ab[i][j] << " ";
		}
		cout << "\n";
	}
}
#endif



#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cout;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;


#if 0
vector<vector<int>> getFilePath(string x)
{
	vector<int> lines;
	vector<vector<int>> board;

	ifstream file;
	file.open(x);

	string line;

	while (getline(file, line))
	{
		istringstream ss(line);

		int i;
		char c;

		while (ss >> i >> c)
		{
			lines.push_back(i);
		}
	
		board.push_back(lines);
		lines.clear();
	}

	return board;
}

void printBoard(vector<vector<int>> y)
{
	for (int i = 0; i < y.size(); i++)
	{
		for (int j = 0; j < y[i].size(); j++)
		{
			cout << y[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	string file = "1.board";

	vector<vector<int>> board = getFilePath(file);

	printBoard(board);
}
#endif


int main()
{
	enum class color {white, blue, red, orange, black};

	color my_color = color::white;

	cout << my_color;
}