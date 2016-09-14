#include <iostream>

using namespace std;

struct Node{
	Node* next;
	int value;

};

/*class LinkedList
{
	LinkedList()
}*/

Node *head;

void split (Node* &in, Node*& odds, Node*& evens)
{
	Node *oddsTemp;
	Node *oddsTemp2;
	Node *evensTemp;
	Node *evensTemp2;

	while(in!=NULL)
	{
		if (in->value % 2 == 1)
		{
			if(odds==NULL)
			{
				odds = in;
				goto 42;
			}
			oddsTemp = odds;
			while(oddsTemp!=NULL)
			{
				oddsTemp2 = oddsTemp;
				oddsTemp = oddsTemp->next;
			}
			oddsTemp2 -> next = in;
		}
		if (in->value % 2 == 0)
		{
			if (evens == NULL)
			{
				evens = in;
			}

		}
		in = in -> next;
	}
	/*
	while (odds!=NULL)
	{
		if(odds->value % 2 == 1)
		{
			tempOddsRunner = odds;
			odds = odds -> next;
			tempOddsRunner->next = odds;
		}

	}*/
	/*while (evens!=NULL)
	{
		if (head->value % 2 == 0)
	}*/
}

void pushback(int inputValue)
{
	if (head == NULL)
	{
		head = new Node;
		head->next = NULL;
		head->value = inputValue;
	}
	else 
	{
		Node *temp = head;
		Node *temp1 = head;
		while(temp!=NULL)
		{
			temp1 = temp;
			temp = temp->next;
		}
		Node* newnode = new Node;
		newnode->value = inputValue;
		newnode->next = NULL;
		temp1->next = newnode;
	}
} 
int main ()
{
	int total;
	cout << "choose a list size: "<<endl;
	cin >> total;
	int original[total];
	cout << "Type in " << total <<" numbers to add to a list: "<<endl;
	
	/*head = new Node;
	head -> next = NULL;*/

	for (int i = 0; i < total; i++)
	{
		cin >> original[i];
		pushback(original[i]);
	}

	cout << "you typed these numbers: ";
	while (head!=NULL)
	{
		cout << head->value<<" ";
		head = head->next;
	}
	Node *odds;
	Node *evens;
	split(head, odds, evens);
return 0;
}