#include <iostream>
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Wmissing-variable-declarations"

using namespace std;

/*
 * Add or remove attributes
 */
class GenericClass{
public:
    int data;
};

/*
 * Add previous if needed (Use to build doubly linked list)
 */
class GenericNode{
public:
    GenericClass genClass;
    GenericNode* next;
};

/*
 * Head of the data structure
 */
GenericNode* head = nullptr;


/*
 * Method for insert in the end of the data structure
 * Use this method into Queues
 */
void TailInsertion(int number){
    GenericNode* newGeneric = new GenericNode();
    newGeneric -> genClass.data = number;
    GenericNode* temp = head;
    while(temp != nullptr){
        if(temp -> next == nullptr){
            temp -> next = newGeneric;
            break;
        }
        temp = temp -> next;
    }
}

/*
 * Method used to insert in the begining of the data structure
 * Use this method into Stacks
 */
void HeadInsertion(int number){
    GenericNode* newGeneric = new GenericNode();
    newGeneric -> genClass.data = number;
    GenericNode* temp = head;
    newGeneric -> next = temp;
    head = newGeneric;
}

/*
 * Method used to print the data structure
 */
void print(){
    GenericNode* temp = head;
    while(temp != nullptr){
        cout << temp -> genClass.data << endl;
        temp = temp -> next;
    }
}

/*
 * Method used to delete from the Head
 * Use this method into Simple Stacks
 */
void HeadDelete(){
    GenericNode* temp = new GenericNode();
    temp = head -> next;
    head = temp;
}

/*
 * Method used to delete from the Tail
 * Use this method into Simple Stacks
 */
void TailDelete(){

}

int main()
{
    GenericNode* second = nullptr;
    GenericNode* third = nullptr;

    head = new GenericNode();
    second = new GenericNode();
    third = new GenericNode();

    head -> genClass.data = 1;
    second -> genClass.data = 2;
    third -> genClass.data = 3;

    head -> next = second;
    second -> next = third;
    third -> next = nullptr;

    TailInsertion(4);
    HeadInsertion(5);
    TailInsertion(6);

    HeadDelete();

    print();

    return 0;
}
