
//Código realizado por Maria Ariza Cervera
#include <iostream>
#include <ctime>  //para meter fecha

using namespace std;
struct vox{
    string v;
    int expediente;
    string fecha;

    vox *sgt;
};
vox *peek = NULL;
void push(string m, int e, string f){
    vox *nvox =  new vox;
    // m="Maria Ariza Cervera";
    // e=21941298;
    // f="25/04/2001";
    nvox->v=m;
    nvox->expediente=e;
    nvox->fecha=f;
    nvox->sgt=peek;
    peek=nvox;
}
void pop(){
    if(peek==NULL)
        cout<<"Nada que imprimir, Stack vacia \n";
    else
        peek=peek->sgt;
}
void prt(){
    vox *aux = peek;
    if(aux==NULL)
        cout<<"Nada que imprimir, Stack vacia\n";
    else
        while(aux!=NULL){
            cout<<aux->v<<"-> Nombre ;";
            cout<<aux->expediente<<"-> Num. Expediente ; ";
            cout<<aux->fecha<<"-> Fecha de nacimiento. ";
            aux=aux->sgt;

        }
}
int main(){
    int op, e;
    string m;

    string f;

    do{
        cout<<"\n(1) Push    (2) Pop    (3) Print   (4) Salir \n ";
        cout<<"\n Elija opcion  ?: ",cin>>op;
        switch (op){
            case 1:

                cout<<"Ingrese su nombre :  ";
                cin.ignore();
                getline(cin, m);  //Esto es para que si mete dos palabras distitas no entre en un bucle infinito.


                //cout<<"Ingresa su fecha de nacimiento en este formato XX/XX/XXXX:  ",cin>>f;
                //push(m,e,f);
                cout<<"Ingrese su número de expediente :  ",cin>>e;
                cout<<"Ingresa su fecha de nacimiento en este formato XX/XX/XXXX:  ",cin>>f;
                push(m,e,f);

                break;
            case 2:
                cout<<"Eliminando ..... : ";
                pop();
                break;
            case 3:
                cout<<"Imprimiendo..... : ";
                prt();
                break;
            case 4:
                cout<<"------Bye--------";
        }
    }while(op!=4);
}
