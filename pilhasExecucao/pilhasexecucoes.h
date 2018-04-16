#ifndef EX_H
#define EX_H
#include "../instrucao/instrucao.h"
#include "lista/row.cpp"



class pilha{

    protected:
        int pilhas;
        row <instrucao * > *para_executar;
        instrucao * emexecucao;
    public:

        void imprimir()
        {
            for(int i=0; i< pilhas; i++)
            {
                if(emexecucao[i].nome!="0")
                {
                    cout<<emexecucao[i]<<"d ";
                }
                else cout<<"stall ";
            }
        }
};

class IF:public pilha
{
    public:
        IF(int p=1)
        {
            this->pilhas=p;
            emexecucao=new instrucao[p];
            cout<<emexecucao[0];
        }
};

class ID:public pilha
{
    public:
        ID(int p=1)
        {
            this->pilhas=p;
            emexecucao=new instrucao[p];
        }
};

class EX:public pilha
{
    public:
        EX(int p=1)
        {
            this->pilhas=p;
            emexecucao=new instrucao[p];
        }
};

class WM:public pilha
{
    public:
        WM(int p=1)
        {
            this->pilhas=p;
            emexecucao=new instrucao[p];
        }
};
#endif
