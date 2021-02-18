#include <iostream>

using namespace std;


class nodo{
public:
    int dato;
    nodo* siguiente;
};

nodo* head = nullptr;

void insertarFinal(int numero){
    nodo* aux = new nodo();
    aux -> dato = numero;
    nodo* temp = head;
    while(temp != nullptr){
        if(temp -> siguiente == nullptr){
            temp -> siguiente = aux;
            break;
        }
        temp = temp -> siguiente;
    }
}

void recorrer(){
    nodo* temp = head;
    while(temp != nullptr){
        cout << temp -> dato << endl;
        temp = temp -> siguiente;
    }
}

int main()
{
    nodo* second = nullptr;
    nodo* third = nullptr;

    head = new nodo();
    second = new nodo();
    third = new nodo();

    head -> dato = 1;
    second -> dato = 2;
    third -> dato = 3;

    head -> siguiente = second;
    second -> siguiente = third;
    third -> siguiente = nullptr;

        insertarFinal(4);

    recorrer();
    return 0;
}

