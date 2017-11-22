#include "stdafx.h"
#include <iostream>
#include <ctime>
// работа с матрицей, изменение размера, вывод, автозаполнение, вывод подматрицы
using namespace std;
class matrix {
private:
	int n, m;
	float **arr;
public:
	matrix(int row, int col) {
		n = row;
		m = col;
		arr = new float*[n];
		srand(time(NULL));
		for (int i = 0; i < m; i++) {
			arr[i] = new float[m];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = 0.01 * (rand() % 1001);
			}
		}
	}
	void print_matrix() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << "  |  ";
			}
			cout << endl;
		}
		cout << endl;
	}

	void set_r(int new_row, int new_col) {
		float **t_arr = new float*[new_row];
		for (int i = 0; i < new_row; i++) {
			t_arr[i] = new float[new_col];
		}
		for (int i = 0; i < new_row; i++) {
			for (int j = 0; j < new_col; j++) {
				if ((i >= n) || (j >= m)) {
					t_arr[i][j] = 0.01 * (rand() % 1001);
				}
				else {
					t_arr[i][j] = arr[i][j];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			delete(arr[i]);
		}
		n = new_row;
		m = new_col;
		arr = new float*[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new float[m];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = t_arr[i][j];
			}
		}
		delete(t_arr);
	}
		

	void print_submatrix(int start_row, int start_col, int need_row, int need_col) {
		if ((--start_row + need_row > n) || (--start_col + need_col > m)) {
			cout << "Error!\n";
			return;
		}
		for (int i = start_row; i < start_row + need_row; i++) {
			for (int j = start_col; j < start_col + need_col; j++) {
				cout << arr[i][j] << "  |  ";
			}
			cout << endl;
		}
		cout << endl;
	}
	void del() {
		for (int i = 0; i < n; i++) {
			delete(arr[i]);
		}
	}
};
int main()
{
	int n, m, e = -1, start_row, start_col, need_row, need_col;
	cout << "Enter n and m:\n";
	cin >> n >> m;
	matrix obj(n, m);
	while (e != 0) {
		cout << "Enter 1 for print array\n2 for set new row and column\n3 for print submatrix\n0 for exit\n";
		cin >> e;
		if (e == 1) {
			obj.print_matrix();
		}
		if (e == 2) {
			cout << "Enter new row and column\n";
			cin >> n >> m;
			obj.set_r(n, m);
		}
		if (e == 3) {
			cout << "Enter start row, start column\n";
			cin >> start_row >> start_col;
			cout << "Enter need rows and need columns\n";
			cin >> need_row >> need_col;
			obj.print_submatrix(start_row, start_col, need_row, need_col);
		}
	}
	obj.del();

	system("pause");
    return 0;
}

