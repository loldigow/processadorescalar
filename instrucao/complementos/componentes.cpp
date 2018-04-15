#include <iostream>
using namespace std;
int convert(string in1)
{
    int i=0; 
    int retur=0;
    int casa_decimal=1;
    while(in1[i]!='\0')i++;
    i--;
    while(i>=0)
    {
        int casa=in1[i]-48;
        retur+=casa*casa_decimal;
        i--;
        casa_decimal*=10;
    }
    return retur;
}

template <class T>
void separa(T dado, string linha)
{
    int i=0;
    string palavra="";
    while(linha[i]!='\0')
    {
        if(linha[i]==' ')
        {
            if(palavra=="instrucao")
            {
                i++;
                string buffer="";
                while((linha[i]!=' ') && (linha[i]!='\0'))
                {
                    buffer+=linha[i];
                    i++;
                    
                }
                dado->nome=buffer;
                palavra="";
            }else if(palavra=="clocks")
            {
                i++;
                string buffer="";
                while((linha[i]!=' ') && (linha[i]!='\0'))
                {
                    buffer+=linha[i];
                    i++;
                    
                }
                dado->clocks=convert(buffer);
                palavra="";
            }
            else if(palavra=="dependencias" || palavra=="ependencias")
            {
                 while((linha[i]!='c') && (linha[i]!='\0'))
                 {
                     string buffer="";
                     i++;
                     while((linha[i]!=' ') && (linha[i]!='\0') && (linha[i]!='c'))
                     {
                         buffer+=linha[i];
                         i++;
                        
                       }
                       int aux=convert(buffer);
                       if(aux!=0)dado->dependencias->adicionar(convert(buffer));
                 }
                 palavra="";
                 
            }
            if(palavra=="onflitos" || palavra=="conflitos")
            {
                 while((linha[i]!='\0') && (linha[i]!='d'))
                 {
                     
                     string buffer="";
                     i++;
                     while((linha[i]!=' ') && (linha[i]!='\0') && (linha[i]!='d'))
                     {
                         buffer+=linha[i];
                         i++;
                        
                       }
                       int aux=convert(buffer);
                       if(aux!=0)dado->conflitos->adicionar(convert(buffer));
                 }
                 palavra="";
            }
        }
        else
        {
            palavra+=linha[i];
        }
        i++;
    }
    
}