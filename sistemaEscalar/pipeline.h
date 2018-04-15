#ifndef PIPELINE_H
#define PIPELINE_H
#include "../instrucao/instrucao.h"

class pipeline{
    private:
        fila <instrucao *> *instrucoes;
        int ordenacao; //0 ordem de chegada / 1 do maior para o menor 
        int politicaemissao; //[0](em-ordem/em-ordem)  || [1](em-ordem/fora-de-ordem) || [2](fora-de-ordem/fora-de-ordem) 
        bool foward;

    public:
        pipeline(int o=0, int p=0, int f=0)
        {
            this->ordenacao=o;
            this->politicaemissao=p;
            this->foward=f;
            this->instrucoes=new fila <instrucao *> ();
            instrucao * A;
            A=new instrucao("instrucao 1 dependencias 2 3 4 5");
            this->instrucoes->adicionar(A);
            A=new instrucao("instrucao 2 dependencias 6 1 4 5");
            this->instrucoes->adicionar(A);
            A=new instrucao("instrucao 3");
            this->instrucoes->adicionar(A);
            A=new instrucao("instrucao 4 conflitos 4 5 3 5 4");
            this->instrucoes->adicionar(A);
            A=new instrucao("instrucao 5 dependencias 1 conflitos 5 4");
            this->instrucoes->adicionar(A);
            A=new instrucao("instrucao 6 conflitos 3 5 4");
            this->instrucoes->adicionar(A);
        }
        void execute()
        {
            
        }
        void teste()
        {
            cout<<"eeeee";
            instrucao * aux;
            cout<<"chamando com T=instrucao";
            this->instrucoes->imprimir();
            for(int i=0; i<instrucoes->getsize();i++)
            {
                cout<<"\nInstrucao "<<i<<"    \n";
                aux=instrucoes->get_position(i);
                cout<<*aux;
            }
        }
};

#endif // !PIPELINE_H
