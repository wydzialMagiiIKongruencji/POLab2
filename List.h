#include <iostream>
#include <cstdio>

using namespace std;

class ListElement
{
    public:
    int key;
    ListElement *next;

    int getKey();
    ListElement(int key);
    friend class List;
};

ListElement::ListElement(int key)
{
this->key=key;
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
       //void addToBeginning(ListElement element);
       void addToEnd(int key);
      // void addToEnd(ListElement element);
       ListElement getElement(int key);
      // bool contains(int key);
      // void removeKey(int key);
      //void clearAll();
       void printList();
        friend class ListElement;
};



void List::addToEnd(int key)
{
if(firstElement==NULL)
    {

    ListElement* temp= new ListElement(key);
    this->firstElement=temp;
    this->firstElement->next=NULL;

    cout<<endl<<firstElement->key<<endl<<endl;
    }
else
{
    ListElement* temp= new ListElement(key);
    ListElement* nowy= new ListElement(key);
    temp=firstElement;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=nowy;
    nowy->next=NULL;
}
}

void List::addToBeginning(int key)
{
if(firstElement==NULL)
    {
    ListElement* firstElement= new ListElement(key);
    firstElement->next=NULL;

    }
else
{
    ListElement* temp= new ListElement(key);
    ListElement* nowy= new ListElement(key);
    temp=firstElement;
    firstElement=nowy;
    nowy->next=temp;
}
}

void List::printList()
{
if(firstElement==NULL)
    {
cout<<"Brak elementow"<<endl;
    }
else
{   int key=0;
    int licznik=0;
    ListElement* temp= new ListElement(key);
    temp=firstElement;
    cout<<"List: ";
    while(temp->next!=NULL)
    {
        licznik++;
        cout<<temp->key;
        temp=temp->next;
        cout<<" -> ";
    }
    cout<<" size: "<<licznik<<endl;
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




      getchar();
      return 0;
 }

class List
{
public:
	//ListElement* firstElement;
	int size;
public:
	void addToEnd(int key);
	void addToBeginning(int key);
	bool containt(int key);
	void removeKey(int key);
	void clearAll();
	void printList();
	List();
	~List();
};

