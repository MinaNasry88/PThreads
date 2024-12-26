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

		while (ss >> i)
		{
			lines.push_back(i);
		}

		board.push_back(lines);
	}

	return board;
}

int main()
{
	string file = "test.txt";

	vector<vector<int>> board = getFilePath(file);

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}