﻿#include <iostream>

struct treenode
{
	int data;
	treenode* next;
	treenode* prev;
};
treenode* head;
void AddList(int value, int position)
{
	treenode* node = new treenode;
	node->data = value;
	if (head == NULL)
	{
		node->next = node;
		node->prev = node;
		head = node;
	}
	else
	{
		treenode* p = head;
		for (int i = position; i > 1; i--) p = p->next;
		p->prev->next = node;
		node->prev = p->prev;
		node->next = p;
		p->prev = node;
	}
	std::cout << "\nЭлемент добавлен...\n\n";
}
int DeleteList(int position)
{
	if (head == NULL) { std::cout << "\nСписок пуст\n\n"; return 0; }
	if (head == head->next)
	{
		delete head;
		head = NULL;
	}
	else
	{
		treenode* a = head;
		for (int i = position; i > 1; i--) a = a->next;
		if (a == head) head = a->next;
		a->prev->next = a->next;
		a->next->prev = a->prev;
		delete a;
	}
	std::cout << "\nЭлемент удален...\n\n";
}

void PrintList()
{
	if (head == NULL) std::cout << "\nСписок пуст\n\n";
	else
	{
		treenode* a = head;
		std::cout << "\nЭлементы списка: ";
		do
		{
			std::cout << a->data << " ";
			a = a->next;
		} while (a != head); std::cout << "\n\n";
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int value, position, x;
	do
	{
		std::cout << "1. Добавить элемент" << std::endl;
		std::cout << "2. Удалить элемент" << std::endl;
		std::cout << "3. Вывести список" << std::endl;
		std::cout << "0. Выйти" << std::endl;
		std::cout << "\nНомер операции > "; std::cin >> x;
		switch (x)
		{
		case 1:
			std::cout << "Значение > "; std::cin >> value;
			std::cout << "Позиция > "; std::cin >> position;
			AddList(value, position); break;
		case 2:
			std::cout << "Позиция > "; std::cin >> position;
			DeleteList(position); break;
		case 3: PrintList(); break;
		}
	} while (x != 0);
}