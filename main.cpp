#include "instrucao/instrucao.h"
#include "sistemaEscalar/pipeline.h"



int main()
{
    //instrucao B("instrucao 1 dependencias 2 3 4 5");
    //cout<<B;
    pipeline A(1,1,0,2,2,4,2);
    A.execute();

}