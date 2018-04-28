
#include <campo_minado\bus\distribuidor_bomba.h>
#include <campo_minado\bus\db_default.h>
#include <campo_minado\bus\db_alternativo.h>

#include <iostream>
#include <memory>

using namespace campo_minado::bus;
using namespace std;

#define OK 1

struct test001 {

	int operator()() {
		m_db = make_shared<db_default>();
		m_db->m();

		m_db = make_shared<db_alternativo>();
		(*m_db).m();

		return OK;
	}

private:
	shared_ptr<distribuidor_bomba> m_db;
};


int main() {
	test001 _test001;

	cout << "_test001 : " << (_test001() == OK ? "SUCESSO" : "FALHA") << endl;
}
