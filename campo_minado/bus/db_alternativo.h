#ifndef _DB_ALT_
#define _DB_ALT_

#include "distribuidor_bomba.h"
#include <iostream>

using namespace std;

namespace campo_minado {
	namespace bus {
		class db_alternativo : public distribuidor_bomba {
		public:
			void m() {
				cout << "db_alternativo::m foi chamado!" << endl;
			}
		};
	}
}



#endif
