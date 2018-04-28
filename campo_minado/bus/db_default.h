#ifndef _DB_DEFAULT_
#define _DB_DEFAULT_

#include "distribuidor_bomba.h"
#include <iostream>

using namespace std;

namespace campo_minado {
	namespace bus {
		class db_default : public distribuidor_bomba {
		public:
			void m() {
				cout << "db_default::m foi chamado!" << endl;
			}
		};
	}
}



#endif