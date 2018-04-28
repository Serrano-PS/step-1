#ifndef _CAMPO_MINADO_H_
#define _CAMPO_MINADO_H_

#include <cstdint>
#include <vector>
#include <memory>

#include "distribuidor_bomba.h"

using namespace std;

namespace campo_minado {
	namespace bus {

		/*	*/
		typedef bool marcada;

		/*	*/
		typedef bool tem_bomba;
		
		/* */
		typedef uint8_t qtde_bomba;

		/* */
		typedef uint8_t dimensao;

		/* qtde de bombas ao redor de uma célula */
		typedef uint8_t risco;

		/**/
		class celula {

		private:

			/* */
			marcada m_marcada;

			/**/
			risco m_risco;

			/**/
			tem_bomba m_tem_bomba;
		};

		class celulas {

			/* procurem overload de operador [] 
				ou implementem método pos(dimensao, dimensao)
			*/
			celula & pos(dimensao i, dimensao j);

		private:
			std::vector<std::vector<celula>> m_matriz;
		};
		
		/* */
		class tabuleiro {

			tabuleiro(shared_ptr<distribuidor_bomba> p_dt, dimensao p_h, dimensao p_v);

			~tabuleiro();
		private:

			shared_ptr<distribuidor_bomba> m_distribuidora_bomba;

			/* */
			dimensao m_qtde_marcadas;

			/* */
			celulas m_celulas;

			/*	*/
			const qtde_bomba m_qtde_bomba;

			/* */
			const dimensao m_h;

			/* */
			const dimensao m_v;

		};


		
		//class marcada {
		//public:
		//	marcada(bool p_value = true);
		//	marcada(const marcada & p_marcada);
		//	marcada(marcada && p_marcada);

		//	marcada & operator=(const marcada & p_marcada);
		//	marcada & operator=(marcada && p_marcada);

		//	bool operator==(const marcada & p_marcada) const;
		//	bool operator!=(const marcada & p_marcada) const;

		// void off();
		// void on();

		// bool off() const;
		// bool on() const;

		//private:
		//	bool m_value;
		//};


	}
}


#endif