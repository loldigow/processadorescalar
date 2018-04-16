#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template <class T>
class node{
	public:
		T dado;
		node<T>* prox;
		inline node(T dado_en, node<T>* ant_entrada)
		{
			dado=dado_en;
			prox=ant_entrada;
		}
		void print()
		{
			cout<<*dado<<"|"<<prox;
		}
		
		friend ostream& operator << (ostream& out, const node<T>& dado);
		
};

template <class T>
ostream& operator << (ostream& out, const node<T>& dado)
{
		out<<dado.dado<<"|"<<dado.prox<<"\n";
		return out;
}
#endif
