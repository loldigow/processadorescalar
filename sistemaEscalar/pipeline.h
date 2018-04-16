#ifndef PIPELINE_H
#define PIPELINE_H
#include "../instrucao/instrucao.h"
#include "../pilhasExecucao/pilhasexecucoes.h"
#include <unistd.h>
#include <stdio.h>

class pipeline{
    private:
        fila <instrucao *> *instrucoes;
        int ordenacao; //0 ordem de chegada / 1 do maior para o menor 
        int politicaemissao; //[0](em-ordem/em-ordem)  || [1](em-ordem/fora-de-ordem) || [2](fora-de-ordem/fora-de-ordem) 
        bool foward;
        IF *IFETCH;
        ID *IDECODE;
        EX *EXECUTE;
        WM *WHRITEM;

    public:
        pipeline(int o=0, int p=0, int f=0,int F=1, int D=1, int E=1, int W=1) //params [1]ordenado [2] politicasaida [3]forwarding [4]estagiosIF [5]estagios ID [6] estagios EXE  [7]estagios WM
        {
            this->ordenacao=o;
            this->politicaemissao=p;
            this->foward=f;
            this->instrucoes=new fila <instrucao *> ();
            instrucao * A;
            IFETCH=new IF(F);
            IDECODE=new ID(D);
            EXECUTE=new EX(E);
            WHRITEM=new WM(W);

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
            A=new instrucao("instrucao 7clocks 4 conflitos 3 5 4");
            this->instrucoes->adicionar(A);
        }
        void execute()
        {
            cout<<"\nIF                   ID                      EXE                     WM\n";
            for(;;)
            {
                IFETCH->imprimir();cout<<"      ";
                IDECODE->imprimir();cout<<"      ";
                EXECUTE->imprimir();cout<<"      ";
                WHRITEM->imprimir();cout<<"      ";
                cout<<"i";
                getchar();
            }
        }
        void teste()
        {
            cout<<"pipe simulado com ordena ="<<this->ordenacao;
            cout<<"\n com politica de saida ="<<this->politicaemissao;
            cout<<"\n com "<<instrucoes->getsize()<<" instrucoes para serem executadas";
            instrucao * aux;
            for(int i=0; i<instrucoes->getsize();i++)
            {
                cout<<"\nInstrucao "<<i<<"\n";
                aux=instrucoes->get_position(i);
                cout<<*aux;
            }
        }
};

#endif // !PIPELINE_H
