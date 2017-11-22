#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
const int n = 2;
const int max_length = 20;

class Factory {
protected:
	char id[max_length];
public:
	Factory(char* id) {
		int i = 0;
		for (i = 0; i < strlen(id); i++) {
			this->id[i] = id[i];
		}
		this->id[i] = '\0';
	};
	char* get_id() {
		return id;
	}
	~Factory() {
		cout << "Object " << this->id << " was deleted!";
		delete this;
	}

};

class Triangle : public Factory {
private:
	float a[n], b[n], c[n];// [0] - x;[1] - y
	float ab, bc, ac, S, p;
public:
	Triangle(float* aa, float* bb, float* cc, char* id):Factory(id) {
		for (int i = 0; i < n; i++) {
			a[i] = aa[i];
			b[i] = bb[i];
			c[i] = cc[i];
		}
		ab = sqrt(pow((b[0] - a[0]), 2) + pow((b[1] - a[1]), 2));
		bc = sqrt(pow((c[0] - b[0]), 2) + pow((c[1]- b[1]), 2));
		ac = sqrt(pow((c[0] - a[0]), 2) + pow((c[1] - a[1]), 2));
		p = (ab + bc + ac) / 2;
		S = sqrt(p*(p - ab)*(p - bc)*(p - ac));
	}
	void print_data() {
		cout << "Triangle info:\nId = " << this->get_id() << endl;
		cout << "A(" << a[0] << ";" << a[1] << "). B(" << b[0] << ";" << b[1] << "). C(" << c[0] << ";" << c[1] << ")\n";
		cout << "Lengts:\n" << "AB = " << ab << ". BC = " << bc << ". AC = " << ac << endl;
		cout << "Area = " << S << endl;
	}
	void MoveO(float step_x, float step_y) {
		a[0] += step_x;
		b[0] += step_x;
		c[0] += step_x;
		a[1] += step_y;
		b[1] += step_y;
		c[1] += step_y;
		this->print_data();
	}
	float get_s() {
		return S;
	}
};

class Rectangle: public Factory {
private:
	float a[n], b[n], c[n], d[n];// [0] - x;[1] - y
	float s_a, s_b, S;
public:
	Rectangle(float* aa, char* id):Factory(id) {
		for (int i = 0; i < n; i++) {
			a[i] = aa[i];
		}
		srand(time(NULL));
		b[0] = a[0] + 0.1*(rand() % 10);
		b[1] = a[1];
		c[0] = a[0];
		c[1] = a[1] + 0.1*(rand() % 10);
		d[0] = b[0];
		d[1] = c[1];
		s_a = sqrt(pow((b[0] - a[0]), 2) + pow((b[1] - a[1]), 2));
		s_b = sqrt(pow((d[0] - a[0]), 2) + pow((d[1] - a[1]), 2));
		S = s_a * s_b;
	}
	void print_data() {
		cout << "Rectangle info:\nId = " << this->get_id() << endl;
		cout << "A(" << a[0] << ";" << a[1] << "). B(" << b[0] << ";" << b[1] << ")\n";
		cout << "C(" << c[0] << "; " << c[1] << "). D(" << d[0] << ";" << d[1] << ")\n";
		cout << "Lengts:\n" << "AB = " << s_a << ". BC = " << s_b << ". AD = " << s_b << ". CD = " << s_a << endl;;
		cout << "Area = " << S << endl;
	}
	void MoveO(float step_x, float step_y) {
		a[0] += step_x;
		b[0] += step_x;
		c[0] += step_x;
		d[0] += step_x;
		a[1] += step_y;
		b[1] += step_y;
		c[1] += step_y;
		d[1] += step_y;
		this->print_data();
	}
	float get_s() {
		return S;
	}
};

void compare(Triangle* t1, Rectangle* t2) {
	float s1 = t1->get_s(), s2 = t2->get_s();
	if (s1 > s2) cout << "Triangle area >\n";
	else if (s2 > s1) cout << "Rectangle area >\n";
	else cout << "Areas is equal!\n";
}

int main()
{
	int e = -1;
	Triangle *t1;
	Rectangle *t2;
	float a[n], b[n], c[n];// create Objects
	srand(time(NULL));
	bool ex_1 = false, ex_2 = false;
	while (e != 0) {
		cout << "\nEnter:\n1 - create Triangle\n2 - create Rectangle\n3 - move Triangle\n4 - move Rectangle\n5 - compare their areas\n0 - Exit\n";
		cin >> e;
		if (e == 1) {
			ex_1 = true;
			for (int i = 0; i < n; i++) {
				a[i] = 0.1 * (rand() % 100);
				b[i] = 0.1 * (rand() % 100);
				c[i] = 0.1 * (rand() % 100);
			}
			t1 = new Triangle(a, b, c, "T1");
			t1->print_data();
		}
		if (e == 2) {
			ex_2 = true;
			for (int i = 0; i < n; i++) {
				a[i] = 0.1 * (rand() % 100);
			}
			t2 = new Rectangle(a, "T2");
			t2->print_data();
		}
		if (e == 3) {// move Triangle
			if (ex_1 == false) {
				cout << "Object not created!\n";
				continue;
			}
			cout << "Enter x and y steps:\n";
			float step_x, step_y;
			cin >> step_x >> step_y;
			t1->MoveO(step_x, step_y);
		}
		if (e == 4) {
			if (ex_2 == false) {
				cout << "Object not created!\n";
				continue;
			}
			cout << "Enter x and y steps:\n";
			float step_x, step_y;
			cin >> step_x >> step_y;
			t2->MoveO(step_x, step_y);
		}
		if (e == 5) {
			if (ex_1 == false) {
				cout << "Triangle not created!\n";
				continue;
			}
			if (ex_2 == false) {
				cout << "Rectangle not created!\n";
				continue;
			}
			compare(t1, t2);
		}
		}
    return 0;
}

