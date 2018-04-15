#include "lista.h"



	template<class T>
	fila<T>::fila()
	{
		fim=0; 
		inicio=0;
	}

	template <class T>
	void fila<T>::adicionar(T dado_para_inserir)
	{
		if(inicio)
		{
			fim->prox=new no<T>(dado_para_inserir,0);
			size++;
			fim=fim->prox;
		}
		else
		{
			inicio=new no<T>(dado_para_inserir,0);
			size++;
			fim=inicio;
		}
	}


	template <class T>
	void fila<T>::imprimir()
	{
		if(inicio)
		{
			no<T>*aux=inicio;
			while(aux)
			{
				cout<<(aux->dado)<<", ";
				aux=aux->prox;
			}
		}
		else cout<<"sem dados   ";
	}


	template <class T>
	void fila<T>::remove()
	{
		if(inicio)
		{
			if(inicio!=fim)
			{
				no<T>*aux=inicio;
				inicio=aux->prox;
				size--;
				delete(aux);
			}
			else
			{
				no<T>* aux=inicio;
				size--;
				delete(aux);
				inicio=0;
				fim=0;
			}		
		}
		else cout<<"sem dependencias";

	}


	template <class T>
	T fila<T>::primeiro_dado()
	{
		if(inicio)
		{
			return inicio->dado;
		}
		else return 0;
	}

	template <class T>
	T fila<T>::get_position(int pos)
	{
		if(pos>=0 && pos<this->size)
		{
			 no<T>* aux=inicio;
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
	T fila<T>::ultimo_dado()
	{
		if(fim)
		{
			return fim->dado;
		}else return 0;
	}




	template <class T>
	bool fila<T>::vazia()
	{
		if(!inicio&&!fim)return 1;
		else return 0;
	}


	template<class T>
	void fila<T>::limpa_fila()
	{
		if(fim)
		{
			if(fim!=inicio)
			{
				while(inicio){
					no<T>*aux=inicio;
					inicio=aux->prox;
					delete(aux);
				}
				inicio=0; 
				fim=0;
			}
			else
			{
				no<T>* aux=inicio;
				delete(aux);
				inicio=0;
				fim=0;
			}
		}
	}


	//template <class T>
	//void fila<T>::invert()
	//{
	//	if(inicio)
	//	{
	//		fila <T>A;
	//		A.
	//	}
	//}





