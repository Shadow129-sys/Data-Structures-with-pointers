#include <iostream>
using namespace std;
    

void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}

struct Node{
	int data = 0;
	Node *next = NULL;
};
Node* insertEnd(Node* head,int n);
Node* insertFront(Node* head,int n);
void PrintList(Node* head);
Node* DeleteFront(Node* head);

int main(){

	//REFERENCE VARIABLES
	int a = 10;
	int &b = a;
	std::cout << b << " " << a << '\n';
	std::cout << &b << " " << &a << '\n';
	b += 1;
	std::cout << b << " " << a << '\n';

	/*
	Here 'b' is a reference variable of variable 'a' which actually means we are giving another name
	to the same address in memory, that means both 'b' and 'a' are actually same variable or 'a' and 'b' points to the same 
	location in memory i.e. if we change the value of b by 1 then value of a will also be changed because when
	we change 'b' what actually happens is that the value at that memory address is changed, that is why value of 'a'
	changes
	we can check if 'a' and 'b' are pointing to same memory address or not by just printing their value and address.
	*/

	int x = 10,y = 5;
	std::cout << x << " " << y << '\n';
	swap(x,y);
	std::cout << x << " " << y << '\n';

	/*
	The main application of reference is when we take function parameters as reference this means if we change the values
	of those variables in the function itself then we don't need to return then anymore they will change automatically
	in the main function as shown above.
	*/

	//POINTER VARIABLES

	std::cout << "int size : " << sizeof(int) << '\n';
	std::cout << "int size : " << sizeof(short) << '\n';
	std::cout << "int size : " << sizeof(char) << '\n';
	int n = 1089;
	int *pnt = &n;
	std::cout << pnt << " " << &n << '\n';
	std::cout << *pnt << " " << n << '\n';
	char *c = (char*)pnt;
	std::cout << *c << '\n';

	/*
	we that size of int -> 4bytes, short -> 2bytes and char -> 1byte
	when an integer is stored in memory it is stored like this, let's say n is 1089, and we want to store n in memory
	 byte 3    byte 2    byte 1    byte 0    
	00000000  00000000  00000100  01000001 : bits in each byte
	  203       202       201       200    : address
	int actually takes 4 consecutive address in the memory.

	The first bit from the right most side is called 'sign bit' it basically indicates if the value is -ve or +ve.

	When we write 'int *pnt = &n;' this means now 'pnt' stores the address in memory where 'n' is located
	we can check this by printing 'pnt' and '&n', in the next line we print the value stored in that memory address
	by '*pnt' this is called dereferencing a pointer.

	we know that 'int' takes 4 bytes and 'char' takes 1 byte so if we explicitly convert 'int*' to 'char*' what will happen
	is that the 'char*' will get assigned by the 0th byte of that integer variable, the value stored in 0th byte is actually
	(01000001)base2 = 0 x 2^7 + 1 x 2^6 + 0 x 2^5 + 0 x 2^4 + 0 x 2^3 + 0 x 2^2 + 0 x 2^1 + 1 x 2^0 = 64 + 1 = (65)base10
	the value will be 65 which is actually the ascii value of uppercase 'A', so now if we try to dereference 'c' and print
	it's value it will print 'A' 
	*/

	short *p = new short[5];
	for(short i=0;i<5;i++){
		p[i] = i + 1;
	}
	std::cout << p[0] << " " << *p << '\n';

	for(short i=0;i<5;i++){
		std::cout << &p[i] << " " << p+i << '\n';
	}

	std::cout << "Size of short datatype : "<< sizeof(short) << '\n';
	//checking if the size of short datatype is actually 2bytes or not

	/*
	  p . . . . . . .p+4  : address, here p points to p[0] 
	[ 1 , 2 , 3 , 4 , 5 ] : actual array
	  0	  1   2   3   4   : index of p array

	'p' -> is the address in memory of 'p[0]'

	'*p' -> is the value stored in that memory address,this is called dereferencing a pointer.

	'&p[0]' -> means the address of 'p[0]'

	The code above prints the ADDRESS of elements in array 'p'
	also note that the address are increasing by 2 as 'i' increases,this is due to the fact
	that the size of a short datatype is 2 bytes we can also check this
	'&p[i]' and 'p+i' will be same as they both refer to same location in memory
	but the thing to remember is that 'p[i]' is the value where as '&p[i]' and 'p+i' shows the
	memory address of that location.
	*/

	short &ref = p[1];
    short *zeroth_address = &p[0];
	p += 1;
	std::cout << ref << " " << p[0] << '\n';
	std::cout << zeroth_address << " " << p-1 << '\n';
	std::cout << *zeroth_address << " " << *(p-1) << '\n';
	std::cout << p[4] << '\n';

	/*
	Initially:
	  p              p+4   : pointer
	[ 1 , 2 , 3 , 4 , 5 ]  : actual array
	  0   1   2   3   4    : index of p array

	So, if we write 'p += 1', remember p is a short pointer, sizeof(short) is 2
	this tells the pointer 'p' to shift 1 position right from it's inital position,
	shifting 1 position right in the array means that array index will change accordingly.

	After we wtite p += 1 or p++:
	      p          p+3   : pointer
	[ 1 , 2 , 3 , 4 , 5 ]  : actual array
	      0   1   2   3    : index of p array

	short '&ref = p[1]', says that give reference variable 'ref' the same address as 'p[1]'
	then we write 'p += 1','p' changed to 'p+1'
	Now we can see that the value of 'ref' and 'p[0]' are same,due to the fact we changed 'p' to 'p+1'
	'*zeroth_address' contains the memory address of 'p[0]' before we shifted 'p' by 1
	So, we can also check like this, that if the address 'zeroth_address' and 'p-1' is same or not
	or we can also check if their value in the memory is same of not just by dereferencing
	'zeroth_address' and 'p-1'
	but now if we try to get the value of 'p[4]' it will return some 'garbage value'
	*/

	//APPLICATIONS OF POINTERS
	/*
	There are maybe different application of pointers in Data Structure like Singly LinkedList,Double LinkedList,Circular LinkedList,
	BST, BT, Tries, ternary search tree,etc. but for the sake of simplicity we will just see the basic implementation of 
	Singly LinkedList.
	'struct' is basically an used defines datatype in c/c++
	*/

	Node *head = NULL;
	for(int i: {4,5,7,8,2}){
		head = insertEnd(head,i);
	}
	PrintList(head);

	/*
	We need to declare a pointer variable 'struct Node' in order to create a node pointer and assign it to NULL
	then we run a for loop actually this is a foreach loop in c++ eg.

	for(datatype variable: array){
		//code
	}

	here I have shown some basic functions that are used for linked list such as :
	Node* insertEnd(Node* head,int n) -> this function takes in the head pointer of the linked list and the new data 'n' that we need
	to insert at the end of the linkedlist
	Node* insertFront(Node* head,int n) -> this function inserts the data 'n' at the front of linked list
	Node* DeleteFront(Node* head) -> deletes the first node of the LinkedList
	void PrintList(Node* head) -> prints the LinkedList

	*/
	return 0;
}

Node* insertEnd(Node* head,int n){

	Node *newNode = new Node();
	//helps to create a memory for the new Node or assign a empty space in memory to the 'newNode' variable

	newNode->data = n;
	//sets the data value of this 'newNode' to n

	if(!head)return newNode;
	//checks if head is NULL if head is NULL that means List is empty that means we can simply return the 'newNode'

	Node *temp = head;

	while(temp->next)temp = temp->next;
	//loops until temp reaches the value of last node i.e. whose next pointer points to NULL

	temp->next = newNode;
	//assign the next pointer of last node to 'newNode'

	return head;
}

Node* insertFront(Node* head,int n){
	Node *newNode = new Node();
	newNode->data = n;

	newNode->next = head;
	//it simply assigns the value of 'next' pointer to 'head' that means now 'newNode' is the actual 'head' of the LinkedList

	return newNode;
}

Node* DeleteFront(Node* head){
	if(!head)return NULL;

	return head->next;
	//just returns the value of 'next' pointer of 'head' is 'head' is not NULL
	//NOTE : if 'head' is NULL then the program will actually stop executing.
}

void PrintList(Node* head){
	std::cout << "LinkedList : ";

	if(!head)std::cout << "null";
	//checks if 'head' is NULL or not

	while(head!=NULL){
		cout << head->data << " ";
		head = head->next;
	}
	//loops through all the value of linkedList and prints then one-by-one

	std::cout << '\n';
}
