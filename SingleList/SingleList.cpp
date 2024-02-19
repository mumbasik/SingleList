#include <iostream>
using namespace std;
struct Element
{
	//Данные
	char data;
	//Адрес следующего элемента списка
	Element* Next;
};
//Односвязный список
class List
{
	//Адрес головного элемента списка
	Element* Head;
	//Адрес концевого элемента списка
	Element* Tail;
	//Количество элементов списка
	int Count;
public:
	//Конструктор
	List();
	//Деструктор
	~List();
	//Добавление элемента в список
	//(Новый элемент становится последним)
	void Add(char data);
	//Удаление элемента списка
	//(Удаляется головной элемент)
	void Del();
	//Удаление всего списка
	void DelAll();
	//Распечатка содержимого списка
	//(Распечатка начинается с головного элемента) 
	void CoutEl(int el);
	void Print();
	
	//Получение количества элементов,
	//находящихся в списке
	int GetCount();
};
List::List()
{
	//Изначально список пуст
	Head = Tail = NULL;
	Count = 0;
}
List::~List()
{
	//Вызов функции удаления
	DelAll();
}
int List::GetCount()
{
	//Возвращаем количество элементов
	return Count;
}
void List::Add(char data)
{
	//создание нового элемента
	Element* temp = new Element;
	//заполнение данными
	temp->data = data;
	//следующий элемент отсутствует
	temp->Next = NULL;
	//новый элемент становится последним элементом списка
	//если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	//новый элемент становится единственным
	//если он первый добавленный
	else {
		Head = Tail = temp;
	}
}
void List::Del()
{
	//запоминаем адрес головного элемента
	Element* temp = Head;
	//перебрасываем голову на следующий элемент
	Head = Head->Next;
	//удаляем бывший головной элемент
	delete temp;
}
void List::DelAll()
{
	//Пока еще есть элементы 
	while (Head != 0)
		//Удаляем элементы по одному
		Del();
}

void List::Print()
{
	//запоминаем адрес головного элемента
	Element* temp = Head;
	//Пока еще есть элементы
	while (temp != 0)
	{
		//Выводим данные
		cout << temp->data << " ";
		//Переходим на следующий элемент
		temp = temp->Next;
	}
	cout << "\n\n";
}
void List::CoutEl(int el){
	Element* temp = Head;
	for (int i = 1; i < el; i++) {
		temp = temp->Next;
		if (temp == 0) {
			cout << "Element over list" << endl;
			return;
		}
	}
	cout << "This element: "  << el << "=" << temp->data << endl;
}

//Тестовый пример
void main()
{
	//Создаем объект класса List
	List lst;
	//Тестовая строка
	char s[] = "Hello, World !!!";
	//Выводим строку
	cout << s << "\n\n";
	//Определяем длину строки
	int len = strlen(s);
	//Загоняем строку в список
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	//Распечатываем содержимое списка
	lst.Print();
	//Удаляем три элемента списка
	lst.Del();
	lst.Del();
	lst.Del();
	//Распечатываем содержимое списка
	lst.Print();
	lst.CoutEl(6);
}
