#ifndef NO_H
#define NO_H
#include <iostream>
using namespace std;

template <class T>
class no{
	public:
		T dado;
		no<T>* prox;
		inline no(T dado_en, no<T>* ant_entrada)
		{
			dado=dado_en;
			prox=ant_entrada;
		}
		
		friend ostream& operator << (ostream& out, const no<T>& dado);
		
};

template <class T>
ostream& operator << (ostream& out, const no<T>& dado)
{
		out<<dado.dado<<"|"<<dado.prox<<"\n";
		return out;
}
#endif
