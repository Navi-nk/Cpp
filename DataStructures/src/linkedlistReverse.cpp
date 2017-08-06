/*!
This is practice program to learn linkedlist
!*/
#include<iostream>
using namespace std;

//Linked List
struct list{
int listVal;
list* nextNode;
};

//Populate LinkedList with integers falling between start and end arguments with gap between integers being the internal argument
//ex:- if start,end,interval are 1,10 & 2 respectvely then linked list will have 1,3,5,7 & 9 
list* populate(const int start,const int end,const int interval)
{
	if(end <= start)
		return NULL; //foolproofing

	//Initialise the head of the list
	list* head =new list; 
	//traverse holds the current position of the node and we will use it grow the list  
	list* traverse = head;
	
	for(int i=start;i<=end;i+=interval)
	{
	    traverse->listVal = i; //populate current node value
	    
		if((i+interval)>end) //Exit condition: if current node is at last postion, then its next node should point to null 
		{
			traverse->nextNode=NULL;
		}
		else
		{
			traverse->nextNode=new list; //Since we havent reached end of the list, initialise next node and store it in current node  
			traverse=traverse->nextNode; // pass pointer of next node to traverse node 
		}
	}

    return head;
}

void printList(list *head)
{
    list* temp=head;
	if(temp!= NULL) //Empty list : populate list did not get right arguments
	{
		//loop through the list to print values 
	    do 
	    {
	        cout<<temp->listVal<<' ';  
	        temp=temp->nextNode;
	        
	    }while(temp!=NULL);
	    cout<<endl;
	}
	else
	cout<<"Empty linked list"<<endl;
}

int main()
{
	list* l = populate(1,10,1);
	printList(l);
	
return 0;
}

