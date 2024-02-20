// lab2trees.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

class Tree {
private:
	class Node {
	public:
		Node* l, * r;
		int val;
		Node(int data) :l(nullptr), r(nullptr), val(data) {};
	};

	Node* head = nullptr;

	void recPrintStraight(Node* v) {
		cout << v->val << " ";
		if (v->l)
			recPrintStraight(v->l);
		if (v->r)
			recPrintStraight(v->r);
	}

	void recPrintSymetric(Node* v) {
		if (v->l)
			recPrintSymetric(v->l);
		cout << v->val << " ";
		if (v->r)
			recPrintSymetric(v->r);
	}

	void recPrintBack(Node* v) {
		if (v->l)
			recPrintBack(v->l);
		if (v->r)
			recPrintBack(v->r);
		cout << v->val << " ";
	}

	void recPrint(Node* v, int spc) {
		if (!v)
			return;
		recPrint(v->r, spc + 5);
		for (int i = 0;i < spc;i++)
			cout << " ";
		cout << v->val << "\n";
		recPrint(v->l, spc + 5);
	}

	void addPlace(Node* v, int data) {
		if (data <= v->val)
			if (v->l)
				addPlace(v->l, data);
			else 
				v->l = new Node(data);
		else
			if (v->r)
				addPlace(v->r, data);
			else 
				v->r = new Node(data);
	}

	Node* findMin(Node* v) {
		if (v->l)
			return findMin(v->l);
		return v;
	}

	Node* removeMin(Node* v) {
		if (!v->l)
			return v->r;
		v->l = removeMin(v->l);
		return v;
	}

	Node* recDelete(Node* v, int data) {
		if (!v)
			return v;
		if (data < v->val)
			v->l = recDelete(v->l, data);
		else if (data > v->val)
			v->r = recDelete(v->r, data);
		else {
			Node* l = v->l;
			Node* r = v->r;
			delete v;
			if (!r)
				return l;
			Node* nw = findMin(r);
			nw->r = removeMin(r);
			nw->l = l;
			return nw;
		}
		return v;
	}

	void recRightThread(Node* v, Node* &prev) {
		if (!v)
			return;
		recRightThread(v->l, prev);
		if (prev && !prev->r)
			cout << prev->val << " -> " << v->val << "\n";
		prev = v;
		recRightThread(v->r, prev);
	}
public:
	void PrintStraight() {
		cout << "straight: ";
		recPrintStraight(head);
		cout << "\n";
	}

	void PrintSymetric() {
		cout << "symetric: ";
		recPrintSymetric(head);
		cout << "\n";
	}

	void PrintBack() {
		cout << "back: ";
		recPrintBack(head);
		cout << "\n";
	}

	void Print() {
		cout << "tree:\n";
		recPrint(head, 10);
		cout << "\n";
	}

	void Add(int data) {
		if (!head)
			head = new Node(data);
		else
			addPlace(head, data);
	}

	void Delete(int data) {
		head = recDelete(head, data);
		cout << "deleted: " << data << "\n";
	}

	void RightThread() {
		Node* prev = nullptr;
		recRightThread(head, prev);
	}
};

int main()
{
	Tree tr;
	tr.Add(7);
	tr.Add(5);
	tr.Add(6);
	tr.Add(4);
	tr.Add(10);
	tr.Add(8);
	tr.Add(12);

	tr.Add(3);
	tr.Add(19);
	tr.Add(11);
	tr.Add(2);

	tr.Print();
	tr.PrintStraight();
	tr.PrintSymetric();
	tr.PrintBack();

	tr.RightThread();
	tr.Delete(10);
	tr.Print();
	tr.RightThread();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
