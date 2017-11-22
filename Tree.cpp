// сравнивает два дерева на равенство
#include "stdafx.h"
#include <iostream>
#include <ctime>
using namespace std;
struct Node {
	int x; // Значение
	Node *l, *r;// Указатели на новые звенья
};

void del_tree(Node *&Tree) {// Удаление дерева, после завершения работы программы
	if (Tree != NULL) {
		del_tree(Tree->l);
		del_tree(Tree->r);
		delete Tree;
		Tree = NULL;
	}
}

void show(Node *Tree, int level) {// Выводит в инфиксной форме (слева направо)
	if (Tree) {
		show(Tree->l, level + 1);
		for (int i = 0; i < level; i++) cout << "___";
		cout << Tree->x << endl;
		show(Tree->r, level + 1);
	}
}

void add_node(int x,Node *&MyTree) {// Добавление элемента в дерево
	if (NULL == MyTree) {//При первом создании
		MyTree = new Node;
		MyTree->x = x;
		MyTree->l = MyTree->r = NULL;
	}
	if (x < MyTree->x) {// добавление влево
		if (MyTree->l != NULL)  add_node(x, MyTree->l);
		else {
			MyTree->l = new Node;
			MyTree->l->l = MyTree->l->r = NULL;
			MyTree->l->x = x;
		}
	}
	if (x > MyTree->x) {// добавление вправо
		if (MyTree->r != NULL) add_node(x, MyTree->r);
		else {
			MyTree->r = new Node;
			MyTree->r->l = MyTree->r->r = NULL;
			MyTree->r->x = x;
		}
	}


}


bool unequal(Node *tree_1, Node *tree_2) {// сама функция сравнения
	if ((tree_1 == NULL && tree_2 != NULL) || (tree_1 != NULL && tree_2 == NULL)) {// если одно из них null то они не равны
		return false;
	}
	else if ((tree_1 == NULL && tree_2 == NULL)) {// оба null => равны
		return true;
	}
	if (tree_1->x == tree_2->x) return unequal(tree_1->l, tree_2->l) && (unequal(tree_1->r, tree_2->r));// рекурсивно вызываем для левых и правых элементов
	return false;
}

int main()
{
	const int max = 6;
	Node *T1 = NULL;
	Node *T2 = NULL;
	int value = 0;
	cout << "Enter values for first tree..." << endl;
	for (int i = 0; i < max - 1; i++) {
		cout << "Enter value №" << i + 1 << " : ";
		cin >> value;
		add_node(value, T1);
	}
	cout << "Enter values for second tree..." << endl;
	for (int i = 0; i < max; i++) {
		cout << "Enter value №" << i + 1 << " : ";
		cin >> value;
		add_node(value, T2);
	}
	cout << "This is T1 : " << endl;
	show(T1, 0);
	cout << endl << "This is T2 : " << endl;
	show(T2, 0);
	if (unequal(T1, T2)) cout << "T1 = T2" << endl;
	else cout << "T1 != T2" << endl;
	system("pause");
	del_tree(T1);
	del_tree(T2);
    return 0;
}

