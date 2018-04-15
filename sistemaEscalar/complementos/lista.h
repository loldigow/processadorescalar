#ifndef FILA_H
#define FILA_H
#include "no.h"

namespace pipe
{
	template <class T>
	class fila{
		private:
			int size;
			no<T>*inicio;
			no<T>* fim;
			
			
		public:
			fila();
			void adicionar(T dado_para_inserir);
			void imprimir();
			void remove();
			T primeiro_dado();
			T ultimo_dado();
			bool vazia();
			void limpa_fila();
			void invert();
			
			

			
			
	};
}
#endif
