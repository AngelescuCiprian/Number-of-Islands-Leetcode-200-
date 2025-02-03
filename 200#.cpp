using namespace std;
#include <iostream>
void readMatrix(int &n, int &m, int a[100][100])
{
	cout << "Enter the number of raws and columns:\n";
	cout << "Rows= "; cin >> n;
	cout << "Columns= "; cin >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "a[" << i << "][" << j << "]= ";
			cin >> a[i][j];
		}
	}
}
void search(int n, int m, int a[100][100],int i,int j)
{
	//We verify if we are outside the limits of the cell is already 0
	if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == 0)
		return;
	a[i][j] = 0;
	search(n, m, a, i + 1, j); //down
	search(n, m, a, i - 1, j); //up
	search(n, m, a, i, j + 1); //right
	search(n, m, a, i, j - 1); //left

}
void island(int n, int m, int a[100][100])
{
	int count = 0;
	for(int i=0;i<n;i++)
		for (int j = 0;j < m;j++)
			if (a[i][j] == 1)
			{
				count++;
				search(n, m, a, i, j);
			}
	cout << "The numbers of island are:" << count;
}
int main()
{
	int n, m, a[100][100];
	readMatrix(n, m, a);
	island(n, m, a);
	
}
