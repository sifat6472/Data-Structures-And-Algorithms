#include<bits/stdc++.h>
using namespace std;


/*
The Node class represents a basic node used in a singly linked list. It 
contains two members: data, which stores the data associated with the node, and 
next, which is a pointer to the next node in the linked list.
There are two members
    -> -> -> int data: An integer variable that holds the data value of the node.
    -> -> -> Node* next: A pointer to the next node .
*/

class Node {
public:
    int data;
    Node* next;
};

/*

The NodeDll class represents a basic node used in a doubly linked list. It 
contains three members: data, which stores the data associated with the node, and 
next, which is a pointer to the next node in the linked list and previous, which 
is a pointer to the previous node in the linked list.
There are three members
    -> -> -> int data: An integer variable that holds the data value of the node.
    -> -> -> Node* next: A pointer to the next node. 
    -> -> -> Node* previous : A pointer to the previous node.
*/
class NodeDll {
public:
    int data;
    NodeDll* next;
    NodeDll* previous;
};

/*
The NodeCll class represents a basic node used in a Circular linked list. It 
contains two members: data, which stores the data associated with the node, and 
next, which is a pointer to the next node in the linked list.
There are two members
    -> -> -> int data: An integer variable that holds the data value of the node.
    -> -> -> Node* next: A pointer to the next node .

*/
class NodeCll {
public:
    int data;
    NodeCll* next;
};

/*
# The SLL_searching function is used to search for a target value in the singly 
linked list.
# It takes two parameters head pointer of the linked list and target value .
# A pointer to a pointer to the head of the linked list . The double pointer 
permits us to modify the head pointer 
# It returns true if it finds the target value else false
*/
bool SLL_searching(Node** head, int target) {
    Node* pointer = *head;
    
    while (pointer != NULL) {
        if (pointer->data == target) return true;
        pointer = pointer->next;
    }
    return false;
}

/*
The SLL_insert_to_beginning function inserts a node at the beginning of the singular linked list 
It takes two parameters a pointer to the head and the value inserted to be at 
the top
*/
void SLL_insert_to_beginning(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

/*
# The SLL_insert_after function inserts a new node with the given parameter new data and inserts 
it after the target data 
# It takes three parameters a pointer to the head , the value which will be added 
and the target after whom the value will be added
*/
void SLL_insert_after(Node** head, int newData, int target) {
    Node* temp = *head;

    while (temp->next != NULL && temp->data != target) {
        temp = temp->next;
    }

    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = temp->next;
    temp->next = newNode;
}

/*
# The SLL_insert_at_end function inserts a new node at the end of the list 
# It takes two parameters a pointer to the head and the value which will be 
added
*/
void SLL_insert_at_end(Node** head, int newData) {
    Node* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    Node* newNode = new Node();
    newNode->data = newData;
    temp->next = newNode;
}

/*
# The SLL_delete_node function deletes node. it has two parameters 
# A pointer to the head and the value which will be deleted
*/
void SLL_delete_node(Node** head, int hasValue) {
    Node* temp = *head;

    if (temp->data == hasValue) {
        *head = temp->next;
        free(temp);
        return;
    }

    Node* prevNode;
    while (temp != NULL && temp->data != hasValue) {
        prevNode = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "The item doesn't exist \n";
        return;
    }
    prevNode->next = temp->next;
    free(temp);
}

/*
# The DLL_searching function is used to search for a target value in the doubly 
linked list.
# It takes two parameters head pointer of the linked list and target value .
# A pointer to a pointer to the head of the linked list . The double pointer 
permits us to modify the head pointer 
# It returns true if it finds the target value else false
*/
bool DLL_searching(NodeDll** headDl, int target) {
    NodeDll* pointer = *headDl;

    while (pointer != NULL) {
        if (pointer->data == target) return true;
        pointer = pointer->next;
    }
    return false;
}
/*
The DLL_insert_to_beginning function inserts a node at the beginning of the doubly linked list 
It takes two parameters a pointer to the head and the value inserted to be at 
the top
*/
void DLL_insert_to_beginning(NodeDll** headDl, int newData) {
    NodeDll* newItem = new NodeDll();
    newItem->data = newData;
    newItem->next = *headDl;
    newItem->previous = NULL;

    if (*headDl != NULL)
        (*headDl)->previous = newItem;
    else
        *headDl = newItem;

    *headDl = newItem;
}

/*
# The DLL_insert_after function inserts a new node with the given parameter new data and inserts 
it after the target data 
# It takes three parameters a pointer to the head , the value which will be added 
and the target after whom the value will be added
*/
void DLL_insert_after(NodeDll** headDl, int newData, int target) {
    NodeDll* temp = *headDl;
    while (temp->next != NULL && temp->data != target) {
        temp = temp->next;
    }
    NodeDll* newItem = new NodeDll();
    newItem->data = newData;
    newItem->next = temp->next;
    newItem->previous = temp;
    temp->next = newItem;
    newItem->next->previous = newItem;
}

/*
# The DLL_insert_at_end function inserts a new node at the end of the list 
# It takes two parameters a pointer to the head and the value which will be 
added
*/
void DLL_insert_at_end(NodeDll** headDl, int newData) {
    NodeDll* newItem = new NodeDll();
    NodeDll* last = *headDl;
    newItem->data = newData;
    newItem->next = NULL;

    if (*headDl == NULL) {
        newItem->previous = NULL;
        *headDl = newItem;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newItem;
    newItem->previous = last;
}

/*
# The DLL_delete_node function deletes node. it has two parameters 
# A pointer to the head and the value which will be deleted
*/
void DLL_delete_node(NodeDll** headDl, int hasValue) {
    NodeDll* temp = *headDl;
    
    if (temp->data == hasValue) {
        *headDl = temp->next;
        free(temp);
        return;
    }

    NodeDll* prevNode;
    
    while (temp != NULL && temp->data != hasValue) {
        prevNode = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        cout << "The item doesn't exist \n";
        return;
    }
    prevNode->next = temp->next;
    free(temp);
}

/*
# The CLL_searching function is used to search for a target value in the Circular 
linked list.
# It takes two parameters head pointer of the linked list and target value .
# A pointer to a pointer to the head of the linked list . The double pointer 
permits us to modify the head pointer 
# It returns true if it finds the target value else false
*/
bool CLL_searching(NodeCll** headCl, int target) {
    NodeCll* temp = *headCl;
    do {
        if (temp->data == target) {
            return true;
        }
        temp = temp->next;
    } while (temp != *headCl);
    return false;
}

/*
The CLL_insert_to_beginning function inserts a node at the beginning of the Circular linked list 
It takes two parameters a pointer to the head and the value inserted to be at 
the top
*/
void CLL_insert_to_beginning(NodeCll** headCl, int Newdata) {
    NodeCll* newNode = new NodeCll();
    newNode->data = Newdata;
    newNode->next = *headCl;

    if (*headCl == NULL) {
        *headCl = newNode;
    }

    NodeCll* temp = *headCl;
    while (temp->next != *headCl) {
        temp = temp->next;
    }

    *headCl = newNode;
    temp->next = *headCl;
}

/*
# The CLL_insert_after function inserts a new node with the given parameter new data and inserts 
it after the target data 
# It takes three parameters a pointer to the head , the value which will be added 
and the target after whom the value will be added
*/
void CLL_insert_after(NodeCll** headCl, int newData, int targetData) {
    
    if (*headCl == NULL) {}

    NodeCll* newNode = new NodeCll();
    newNode->data = newData;
    
    if ((*headCl)->data == targetData) {
        newNode->next = (*headCl)->next;
        (*headCl)->next = newNode;
    }
    NodeCll* temp = (*headCl)->next;
    
    while (temp->data != targetData && temp != (*headCl)) {
        temp = temp->next;
    }

    if (temp->data != targetData) {}

    newNode->next = temp->next;
    temp->next = newNode;
}

/*
# The CLL_insert_at_end function inserts a new node at the end of the list 
# It takes two parameters a pointer to the head and the value which will be 
added
*/
void CLL_insert_at_end(NodeCll** headCl, int Newdata) {
    NodeCll* newNode = new NodeCll();
    newNode->data = Newdata;

    if (*headCl == NULL) {
        *headCl = newNode;
    }

    NodeCll* temp = *headCl;
    while (temp->next != *headCl) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *headCl;
}

/*
# The CLL_delete_node function deletes node. It has two parameters 
# A pointer to the head and the value which will be deleted
*/
void CLL_delete_node(NodeCll** headCl, int Newdata) {
    NodeCll* temp = *headCl;
    if (*headCl == NULL) {
        return;
    }
    if (temp->data == Newdata) {
        NodeCll* tail = *headCl;
        while (tail->next != *headCl) {
            tail = tail->next;
        }
        *headCl = temp->next;
        tail->next = *headCl;
        free(temp);
        return;
    } else {
        if (temp->next == temp) {
            return;
        } else {
            temp = temp->next;
        }
    }
    NodeCll* prevNode;
    while (temp->data != Newdata && temp != *headCl) {
        prevNode = temp;
        temp = temp->next;
    }
    if (temp->data != Newdata) {
        return;
    }
    prevNode->next = temp->next;
    free(temp);
    return;
}

//The sllInput function takes input for Singular Linked List
void sllInput(){
    Node* head = new Node();
    head->data = 5;
    Node* second = new Node();
    second->data = 4;
    Node* third = new Node();
    third->data = 9;
    Node* fourth = new Node();
    fourth->data = 3;
    Node* fifth = new Node();
    fifth->data = 2;
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    SLL_insert_to_beginning(&head, 5);
    SLL_insert_after(&head, 2, 3);
    SLL_insert_at_end(&head, 0);
    SLL_delete_node(&head, 2);

    printf("Singular Linked List: ");
    Node* Cursor = head;
    while (Cursor) {
        printf("%d -> ", Cursor->data);
        Cursor = Cursor->next;
    }
    printf("NULL\n\n");

    printf("Enter the number to be searched in the Singular Linked List: ");

    int num;
    scanf("%d", &num);

    if (SLL_searching(&head, num))
        printf("\n\nThe number exists.\n\n");
    else
        printf("Can't found the number\n\n");
}

//The dllInput function takes input for Doubly Linked List
void dllInput(){
    NodeDll* headDl = new NodeDll();
    headDl->data = 5;
    NodeDll* secondDl = new NodeDll();
    secondDl->data = 4;
    NodeDll* thirdDl = new NodeDll();
    thirdDl->data = 9;

    headDl->next = secondDl;
    secondDl->next = thirdDl;
    DLL_insert_to_beginning(&headDl, 65);
    DLL_insert_at_end(&headDl, 58);
    DLL_insert_after(&headDl, 23, 4);
    DLL_delete_node(&headDl, 58);
    NodeDll* Current = headDl;
    printf("Doubly Linked List: ");
    while (Current) {
        printf("%d -> ", Current->data);
        Current = Current->next;
    }
    printf("NULL\n\n");
    printf("Enter the number to be searched in the Doubly Linked List: ");

    int numD;
    scanf("%d", &numD);

    if (DLL_searching(&headDl, numD))
        printf("\n\nThe number exists.\n");
    else
        printf("Can't found the number\n");
}

//The cllInput function takes input for Circular Linked List
void cllInput(){
    NodeCll* headCl = new NodeCll();
    headCl->data = 6;
    NodeCll* secondCL = new NodeCll();
    secondCL->data = 42;
    NodeCll* thirdCL = new NodeCll();
    thirdCL->data = 23;
    NodeCll* fourthCL = new NodeCll();
    fourthCL->data = 8;
    NodeCll* fifthCL = new NodeCll();
    fifthCL->data = 4;
    headCl->next = secondCL;
    secondCL->next = thirdCL;
    thirdCL->next = fourthCL;
    fourthCL->next = fifthCL;
    fifthCL->next = headCl;

    CLL_insert_to_beginning(&headCl, 19);

    CLL_insert_at_end(&headCl, 69);

    CLL_insert_after(&headCl, 45, 23);

    CLL_delete_node(&headCl, 8);

    NodeCll* Cur = headCl;
    printf("\n\nCircular Linked List: ");

    if (Cur == NULL)
        printf("NULL\n");
    else {
        printf("%d ->", Cur->data);
        Cur = Cur->next;
    }
    while (Cur != headCl) {
        printf(" %d -> ", Cur->data);
        Cur = Cur->next;
    }
    printf("%d \n", Cur->data);
    printf("\n\nEnter the number to be searched in the Circular Linked List: ");

    int numC;
    scanf("%d", &numC);

    if (CLL_searching(&headCl, numC))
        printf("\nThe number exists.\n");
    else
        printf("\n\nCan't found the number\n");
}

int main() {

    sllInput();
    dllInput();
    cllInput();

    return 0;
}
