#include <iostream>
#include <string>
#pragma GCC diagnostic ignored "-Wpadded"
#pragma GCC diagnostic ignored "-Wmissing-variable-declarations"

using namespace std;

/*
 * Agregar o eliminar atributos segun sea el caso
 */
class GenericClass{
public:
    int data;
};

/*
 * Agregar o eliminar atributos segun sea el caso
 */
class GenericNode{
public:
    GenericClass genClass;
    GenericNode* next;
};

/*
 * Cabeza de la estructura
 */
GenericNode* head = nullptr;


/*
 * Metodo que devuelve True si la estructura está vacia
 * de lo contrario devuelve False
 */
bool isEmpty(){
    if(head == nullptr)
        return true;
    return false;
}

/*
 * Metodo para verificar si un nodo es el ultimo de la estructura
 */
bool isLast(GenericNode* node){
    if(node -> next == nullptr)
        return true;
    return false;
}

/*
 * Metodo usado para imprimir la estructura
 */
void print(){
    GenericNode* temp = head;
    if(!isEmpty()){
        while(temp != nullptr){
            cout << temp -> genClass.data << endl;
            temp = temp -> next;
        }
    }else{
        cout << "La estructura está vacia" << endl;
    }
}

/*
 * Metodo para modificar un nodo
 */
string EditNode(int actualValue, int nextValue){
    GenericNode* temp = head;
    while(temp != nullptr){
        if(temp -> genClass.data == actualValue){
            temp -> genClass.data = nextValue;
            return "El Item: " + to_string(actualValue) + " fue modificado por: " + to_string(nextValue);
        }
        temp = temp -> next;
    }
    return "El Item: " + to_string(actualValue) + " no fue encontrado. No pudo ser modificado";
}

/*
 * Metodo para insertar un nuevo nodo al inicio de la estructura
 * Utilizar este metodo para Pilas
 */
string HeadInsertion(int number){
    GenericNode* newGeneric = new GenericNode();
    newGeneric -> genClass.data = number;
    GenericNode* temp = head;
    newGeneric -> next = temp;
    head = newGeneric;
    return "Item insertado exitosamente";
}

/*
 * Metodo para insertar un nuevo nodo de manera que este no esté en la cabeza o en la cola
 */
string MidleInsertion(int referenceNumber, int number){
    GenericNode* newGeneric = new GenericNode();
    newGeneric -> genClass.data = number;
    GenericNode* temp = head;
    while(temp != nullptr){
        if(temp -> genClass.data == referenceNumber){
            newGeneric -> next = temp -> next;
            temp -> next = newGeneric;
            return "Item insertado exitosamente";
        }
        temp = temp -> next;
    }
    return "Item: " + to_string(referenceNumber) + " no existe. El Item: " + to_string(number)
            + " no pudo ser insertado";
}

/*
 * Metodo para insertar un nuevo nodo al final de la estructura
 * Utilizar este metodo para Colas
 */
string TailInsertion(int number){
    GenericNode* newGeneric = new GenericNode();
    newGeneric -> genClass.data = number;
    GenericNode* temp = head;
    while(temp != nullptr){
        if(temp -> next == nullptr){
            temp -> next = newGeneric;
            return "Item insertado exitosamente";
        }
        temp = temp -> next;
    }
    return "Item no pudo ser insertado";
}

/*
 * Metodo para eliminar un nodo al inicio de la estructura
 */
string HeadDelete(){
    GenericNode* temp = new GenericNode();
    if(!isEmpty()){
        temp = head -> next;
        head = temp;
        return "Nodo removido exitosamente";
    }
    return "La estructura está vacia";
}

/*
 * Metodo para eliminar un nodo al final de la estructura
 */
string TailDelete(){
    GenericNode* temp = new GenericNode();
    temp = head;
    while(temp != nullptr){
        GenericNode* temp2 = temp -> next;
        if(isLast(temp2)){
            temp -> next = nullptr;
            return "Nodo removido exitosamente";
        }
        temp = temp -> next;
    }
    return "La estructura está vacia";
}

/*
 * Metodo para eliminar un nodo en especifico
 */
string SpecificDelete(int value){
    GenericNode* temp = new GenericNode();
    GenericNode* prev = nullptr;
    temp = head;
    while(temp != nullptr){
        if(temp -> genClass.data == value){
            if(isLast(temp)){
                return TailDelete();
            }else if(temp == head){
                return HeadDelete();
            }
            GenericNode* temp2 = temp -> next;
            prev -> next = temp2;
            return "Item removido exitosamente";
        }
        prev = temp;
        temp = temp -> next;
    }

    return "El Item: " + to_string(value) + " no existe. No pudo ser eliminado";
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

    /*HeadDelete();
    HeadDelete();
    HeadDelete();
    HeadDelete();
    TailDelete();
    cout << SpecificDelete(3) << endl;*/

    cout << EditNode(4,10) << endl;
    print();

    return 0;
}
