#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	const int numOfRows = 15, numOfColumns = 15;
	int Matrix[numOfRows][numOfColumns];
	for (unsigned int row_iterator = 0; row_iterator < numOfRows; row_iterator++)
	{
		for (unsigned int column_iterator = 0; column_iterator < numOfColumns; column_iterator++)
		{
			Matrix[row_iterator][column_iterator] = 0;
		}
	}
	Matrix[2][1] = 1;
	Matrix[2][12] = 1;
	Matrix[9][1] = 1;
	Matrix[9][14] = 1;
	Matrix[4][12] = 1;
	Matrix[4][14] = 1;
	for (unsigned int row_iterator = 0; row_iterator < numOfRows; row_iterator++)
	{
		int howManyOnesInRow = 0;
		bool isTheFirstOne = true;
		int firstOneColNumber = 0;
		for (unsigned int column_iterator = 0; column_iterator < numOfColumns; column_iterator++)
		{
			if (Matrix[row_iterator][column_iterator] == 1)
			{
				howManyOnesInRow++;
				
			}
			if (Matrix[row_iterator][column_iterator] == 1 && isTheFirstOne == true)
			{
				firstOneColNumber = column_iterator;
				isTheFirstOne = false;
			}
		}
		int lastOneColNumber = 0;
		bool isTheLastOne = true;
		for (int column_iterator = numOfColumns-1; column_iterator >= 0; column_iterator--)
		{
			
			if (Matrix[row_iterator][column_iterator] == 1 && isTheLastOne == true)
			{
				lastOneColNumber = column_iterator;
				isTheLastOne = false;
			}
		}
		if (howManyOnesInRow > 1)
		{
			for (unsigned int i = firstOneColNumber; i < lastOneColNumber; i++)
			{
				if (Matrix[row_iterator][i] != 1)
				{
					Matrix[row_iterator][i] = 2;
				}
			}
		}
	}
	for (unsigned int column_iterator = 0; column_iterator < numOfRows; column_iterator++)
	{
		int howManyOnesInColumn = 0;
		bool isTheFirstOne = true;
		int firstOneRowNumber = 0;
		for (unsigned int row_iterator = 0; row_iterator < numOfColumns; row_iterator++)
		{
			if (Matrix[row_iterator][column_iterator] == 1)
			{
				howManyOnesInColumn++;

			}
			if (Matrix[row_iterator][column_iterator] == 1 && isTheFirstOne == true)
			{
				firstOneRowNumber = row_iterator;
				isTheFirstOne = false;
			}
		}
		int lastOneRowNumber = 0;
		bool isTheLastOne = true;
		for (int row_iterator = numOfColumns - 1; row_iterator >= 0; row_iterator--)
		{

			if (Matrix[row_iterator][column_iterator] == 1 && isTheLastOne == true)
			{
				lastOneRowNumber = row_iterator;
				isTheLastOne = false;
			}
		}
		if (howManyOnesInColumn > 1)
		{
			for (unsigned int i = firstOneRowNumber; i < lastOneRowNumber; i++)
			{
				if (Matrix[i][column_iterator] != 1)
				{
					Matrix[i][column_iterator] = 2;
				}
			}
		}
	}
	for (unsigned int row_iterator = 0; row_iterator < numOfRows; row_iterator++)
	{
		for (unsigned int column_iterator = 0; column_iterator < numOfColumns; column_iterator++)
		{
			cout << setw(2) << Matrix[row_iterator][column_iterator];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}