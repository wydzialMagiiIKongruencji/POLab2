// La2bzad2v2.cpp: Definiuje punkt wejœcia dla aplikacji konsolowej.
//


#include <iostream>
#include <cstdio>

using namespace std;

class ListElement
{
public:
	int key;
	ListElement *next;

	int getKey();
	ListElement();
	ListElement(int key);

	friend class List;
};

ListElement::ListElement(int key)
{
	this->key = key;
}

int ListElement::getKey()
{
	return this->key;
}

class List
{
public:
	ListElement *firstElement;
	int size;


	void addToBeginning(int key);
	void addToEnd(int key);
	bool contains(int key);
	void removeKey(int key);
	void clearAll();
	void printList();
	friend class ListElement;
};
void List::clearAll()
{
	firstElement=NULL;

}
bool List::contains(int key)
{

	ListElement* obecna = new ListElement(0);
	obecna = firstElement;
	bool findkey = false;
	while (obecna != NULL)
	{
		if (obecna->key == key)
		{
			findkey= true;

		}
		obecna=obecna->next;
	}
	return findkey;
}
void List::removeKey(int key)
{
	ListElement* obecna = new ListElement(0);
    ListElement* poprzedni = new ListElement(0);
	obecna = firstElement;
	poprzedni = obecna;
    if (firstElement->key== key)
    {
        firstElement=firstElement->next;
    }
	while (obecna != NULL)
	{
		if (obecna->key== key)
		{
			poprzedni = obecna->next;
			break;
		}
		poprzedni = obecna;
		obecna=obecna->next;
	}
}

void List::addToEnd(int key)
{
	if (firstElement == NULL)
	{

		ListElement* temp = new ListElement(key);
		this->firstElement = temp;
		this->firstElement->next = NULL;

		cout << endl << firstElement->key << endl << endl;
	}
	else
	{
		ListElement* temp = new ListElement(key);
		ListElement* nowy = new ListElement(key);
		temp = firstElement;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = nowy;
		nowy->next = NULL;
	}
}

void List::addToBeginning(int key)
{
	if (firstElement == NULL)
	{
		ListElement* firstElement = new ListElement(key);
		firstElement->next = NULL;

	}
	else
	{
		ListElement* temp = new ListElement(key);
		ListElement* nowy = new ListElement(key);
		temp = firstElement;
		firstElement = nowy;
		nowy->next = temp;
	}
}

void List::printList()
{
	if (firstElement == NULL)
	{
		cout << "Brak elementow" << endl;
	}
	else
	{
		int key = 0;
		int licznik = 0;
		ListElement* temp = new ListElement(key);
		temp = firstElement;
		cout << "List: ";
		while (temp != NULL)
		{
			licznik++;
			cout << temp->key;
			temp = temp->next;
			cout << " -> ";
		}
		cout << " size: " << licznik << endl;
	}
}



int main()
{

	List* list = new List();
	list->addToEnd(3);
	list->addToBeginning(2);
	list->printList();
	list->addToBeginning(1);
	list->addToEnd(4);
	list->printList();
   if (list->contains(4)) {
   cout << "contains 4" << endl;
    }
    else {
       cout << "not contains 4" << endl;
    }
    if (list->contains(5)) {
       cout << "contains 5" << endl;
    }
    else {
       cout << "not contains 5" << endl;
    }

      list->removeKey(3);
      list->printList();

      list->removeKey(5);
      list->printList();
      list->removeKey(1);
      list->printList();

      list->clearAll();
      list->addToEnd(0);
      list->printList();
      getchar();
      return 0;


	getchar();
	return 0;
}
