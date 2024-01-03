
#include <iostream>
using namespace std;

// Node class represents a node in the linked list
class Node{
public:
    int data;      // Data of the node
    Node* next;    // Pointer to the next node
};

// Insert a new node at the beginning of the linked list
void LL_insert_to_beginning(Node** head, int newData){ 
    Node* newNode = new Node();    // Create a new node
    newNode->data = newData;       // Set its data
    newNode->next = *head;         // Point new node to the current head
    *head = newNode;               // Update the head to the new node
}

// Delete the node at the beginning of the linked list and return its data
int LL_delete_node(Node** head){
    Node* temp = *head;            // Store the current head
    *head = temp->next;            // Move head to the next node
    return temp->data;             // Return data of the deleted node
}

// Check if the stack (linked list) is empty
bool isEmpty(Node* ST){
    return (ST->next == NULL);     // Stack is empty if the next node is NULL
}

// Push a new element onto the stack
void push(Node** ST, int val){
    LL_insert_to_beginning(ST, val);  // Insert new element at the beginning
}

// Pop the top element from the stack
int pop(Node** ST){
    if (!isEmpty(*ST)){
        return LL_delete_node(ST);   // If stack is not empty, delete and return the top element
    }
    cout << "The Stack is empty \n";
    return 0;
}

// Print the value at the top of the stack
void peek(Node** ST){
    Node* newNode = *ST;
    cout << "Top of the Stack is:" << newNode->data << endl;
}

// Print the linked list starting from the given node
void printNode(Node* head){
    Node* current = head;
    while(current!= NULL){
        cout << current->data << " " << "-> ";
        current = current->next;
    }
    cout<<"NULL\n";
}

int main(){

    Node* StackTop = new Node();
    StackTop -> data = -99;
    StackTop -> next = NULL;

    int control = 1;
    while(control){
        
        cout << "\n\nWhat to do?\n" << "1: push\n" << "2: pop\n" << "3: peek\n" << "0: quit\n";
        
        cin >> control;

        if(control == 1){
            
            cout << "Enter the value you want to push : \n";
            
            int val;
            
            cin >> val;
            
            push(&StackTop, val);
            
            cout<< "The new stack is: ";
            
            printNode(StackTop);
        }
        else if(control == 2){
            
            int popped = pop(&StackTop);
            
            cout << "You have popped: " << popped<<endl;
            
            cout<< "The new stack is: ";
            
            printNode(StackTop);
        }
        else if(control == 3){
            
            peek(&StackTop);
            
            cout<< "The stack is: ";
            
            printNode(StackTop);
        }
    }

}
