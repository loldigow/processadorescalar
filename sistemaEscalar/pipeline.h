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
        }
        void teste()
        {
            instrucoes->imprimir();
        }
};

#endif // !PIPELINE_H
