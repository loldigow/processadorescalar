#ifndef INSTRUCAO_H
#define INSTRUCAO_H
#include <iostream>
#include "complementos/componentes.cpp"
#include "complementos/fila.cpp"
using namespace std;


class instrucao{
            
    public:
        string nome;
        int clocks;
        fila <int>* dependencias;
        fila <int>* conflitos;
        int IF;
        int ID;
        int EX;
        int WM;

        instrucao(string linha="")
        {
            nome="";
            clocks=1;
            dependencias=new fila<int>();
            conflitos= new fila<int>();
            separa(this, linha);
            IF=0;
            ID=0;
            EX=0;
            WM=0;
        }

        void print(){
            cout<<"\ninstrucao "<<this->nome<<"\nnecessita de "<<this->clocks<<" clocks para ser executada\n";
            cout<<"dependencias:  ";this->dependencias->imprimir();cout<<"";
            cout<<"\nconflitos:  ";this->conflitos->imprimir();cout<<"\n\n";
        }

        bool IFf()
        {
            this->IF++;
            if(this->IF==this->clocks)return true;
            else return false;
        }
        bool IDf()
        {
            this->ID++;
            if(this->ID==this->clocks)return true;
            else return false;
        }
        bool EXf()
        {
            this->EX++;
            if(this->EX==this->clocks)return true;
            else return false;
        }
        bool WMf()
        {
            this->WM++;
            if(this->WM==this->clocks)return true;
            else return false;
        }
        bool dado_disponivel()
        {
            if((this->EX) == (this->clocks))return true;
            else return false;
        }
        void status()
        {
            cout<<"status instrucao \n";
            cout<<"IF :"<<this->IF<<"\n";
            cout<<"ID :"<<this->ID<<"\n";
            cout<<"EX :"<<this->EX<<"\n";
            cout<<"WM :"<<this->WM<<"\n";
        }
        friend ostream& operator <<(ostream & os, const instrucao& dado );




};


ostream& operator <<(ostream & os, const instrucao& dado )
{
    os<<"\n\nsobrecarga\n";
    os<<"instrucao "<<dado.nome<<"\nnecessita de "<<dado.clocks<<" clocks para ser executada\n";
    cout<<"dependencias:  ";dado.dependencias->imprimir();cout<<"";
    cout<<"\nconflitos:  ";dado.conflitos->imprimir();cout<<"\n\n";
}

#endif
