#ifndef ROW_H
#define ROW_H
#include "node.h"


template <class T>
	class row{
		private:
			int size;
			node<T>*inicio;
			node<T>* fim;
			
			
		public:
			row();
			void adicionar(T dado_para_inserir);
			void imprimir();
			void remove();
			T primeiro_dado();
			T ultimo_dado();
			T get_position(int pos);
			bool vazia();
			int getsize(){return this->size;}
			void limpa_row();
			void invert();		
	};
#endif
