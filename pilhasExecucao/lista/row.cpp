#include "row.h"



	template<class T>
	row<T>::row()
	{
		fim=0; 
		inicio=0;
	}

	template <class T>
	void row<T>::adicionar(T dado_para_inserir)
	{
		if(inicio)
		{
			fim->prox=new node<T>(dado_para_inserir,0);
			size++;
			fim=fim->prox;
		}
		else
		{
			inicio=new node<T>(dado_para_inserir,0);
			size++;
			fim=inicio;
		}
	}


	template <class T>
	void row<T>::imprimir()
	{
		if(inicio)
		{
			node<T>*aux=inicio;
			while(aux)
			{
				cout<<(aux->dado)<<", ";
				aux=aux->prox;
			}
		}
		else cout<<"sem dados   ";
	}


	template <class T>
	void row<T>::remove()
	{
		if(inicio)
		{
			if(inicio!=fim)
			{
				node<T>*aux=inicio;
				inicio=aux->prox;
				size--;
				delete(aux);
			}
			else
			{
				node<T>* aux=inicio;
				size--;
				delete(aux);
				inicio=0;
				fim=0;
			}		
		}
		else cout<<"sem dependencias";

	}


	template <class T>
	T row<T>::primeiro_dado()
	{
		if(inicio)
		{
			return inicio->dado;
		}
		else return 0;
	}

	template <class T>
	T row<T>::get_position(int pos)
	{
		if(pos>=0 && pos<this->size)
		{
			 node<T>* aux=inicio;
			int i=0;
			while(i<pos)
			{
			    aux=aux->prox;
				i++;
			}
			return aux->dado;
		}
		else cout<<"posicao invalida";
		return 0;
	}




	template <class T>
	T row<T>::ultimo_dado()
	{
		if(fim)
		{
			return fim->dado;
		}else return 0;
	}




	template <class T>
	bool row<T>::vazia()
	{
		if(!inicio&&!fim)return 1;
		else return 0;
	}


	template<class T>
	void row<T>::limpa_row()
	{
		if(fim)
		{
			if(fim!=inicio)
			{
				while(inicio){
					node<T>*aux=inicio;
					inicio=aux->prox;
					delete(aux);
				}
				inicio=0; 
				fim=0;
			}
			else
			{
				node<T>* aux=inicio;
				delete(aux);
				inicio=0;
				fim=0;
			}
		}
	}


	//template <class T>
	//void row<T>::invert()
	//{
	//	if(inicio)
	//	{
	//		row <T>A;
	//		A.
	//	}
	//}





