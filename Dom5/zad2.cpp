#include  <iostream>
using namespace std;

bool check(bool ** matr, int N)
{
	for (int i = 0; i < N; ++i)
	{

		for (int j = 0; j < N; ++j)
		{
			if (matr[i][j] == false)
				return false;
		}
	}
	return true;

}

void solve(bool ** matr, int N, int x, int y)
{
	matr[x][y] = 1;

	if(x+ 1 < N && y - 2 >= 0 && matr[x + 1][y - 2] == false)
	{																			
		return solve(matr, N, x + 1, y - 2);									
	}																			
																				
	if (x - 1 >= 0 && y - 2 >= 0 && matr[x - 1][y - 2] == false)				
	{																			
		return solve(matr, N, x - 1, y - 2);									
	}

	if (x + 1 < N && y + 2 < N && matr[x + 1][y + 2] == false)
	{
		return solve(matr, N, x + 1, y + 2);
	}

	if (x - 1 >= 0 && y + 2 < N && matr[x - 1][y + 2] == false)
	{
		return solve(matr, N, x - 1, y + 2);
	}

	if (x + 2 < N && y + 1 < N && matr[x + 2][y + 1] == false)
	{
		return solve(matr, N, x + 2, y + 1);
	}

	if (x + 2 <N && y - 1 >= 0 && matr[x + 2][y - 1] == false)
	{
		return solve(matr, N, x + 2, y - 1);
	}

	if (x - 2 >= 0 && y + 1 <N && matr[x - 2][y + 1] == false)
	{
		return solve(matr, N, x - 2, y + 1);
	}

	if (x - 2 >= 0 && y - 1 >= 0 && matr[x - 2][y - 1] == false)
	{
		return solve(matr, N, x - 2, y - 1);
	}

	if (check(matr, N) == true)
		return;

	if (check(matr, N) == false)
	{
		matr[x][y] = 0;
		return;
	}
		
}

int main()
{
	int N, x, y;
	cout << "N: ";
	cin >> N;

	bool **matr = new(nothrow)bool*[N];
	for (int i = 0; i < N; ++i)
	{
		matr[i] = new(nothrow)bool[N];
		for (int j = 0; j < N; ++j)
			matr[i][j] = false;
	}
	cout << "x: ";
	cin >> x;
	cout << "y: ";
	cin >> y;
	if (x > N && y > N)
		return 0;
	
	solve(matr, N, x, y);
	if (check(matr, N) == true)
		cout << "True";
	else
		cout << "False";

	cout << endl;

	return 0;
}