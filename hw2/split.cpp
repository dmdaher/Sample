#include <iostream>

using namespace std;

struct Node{
	Node* next;
	int value;

};

Node *head = NULL;

void split (Node* &in, Node*& odds, Node*& evens)
{
	if(in==NULL)
	{
		cout<<"split has empty list!"<<endl;
		return;
	}
	split(in->next, odds, evens);
	if(in->value%2==1)
	{
		in->next = odds;
		odds = in;
		in = NULL;
	}
	else
	{
		in ->next = evens;
		evens = in;
		in = NULL;
	}	
}

void pushback(int inputValue)
{
	cout<<"in pushback";
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
		cout<<"what is the value here: "<<inputValue<<endl;
	}
} 
int main ()
{
	int total;
	cout << "choose a list size: "<<endl;
	cin >> total;
	int *original = new int[total];
	cout << "Type in " << total <<" numbers to add to a list: "<<endl;
	int counter1 = 0;
	for (int i = 0; i < total; i++)
	{
		cin >> original[i];
		pushback(original[i]);
		counter1++;
	}
	Node *odds = NULL;
	Node *evens = NULL;
	split(head, odds, evens);

	while(odds!=NULL)
	{
		cout<<"odd numbers are: "<<odds->value<<endl;
		odds = odds->next;
	}
	while(evens!=NULL)
	{
		cout<<"even numbers are: "<<evens->value<<endl;
		evens = evens->next;
	}
return 0;
}