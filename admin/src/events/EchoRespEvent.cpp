#include "EchoRespEvent.hpp"
#include "Application.hpp"
#include "include/global.hpp"
#include "entities/Sergeant.hpp"
#include "dao/SergeantDao.hpp"

EchoRespEvent :: EchoRespEvent(Application& app, string& ip, uint16_t port, int sergeant_no) : BaseEvent(app, ip, port, sergeant_no)
{
	cout << "EchoRespEvent :: EchoRespEvent " << endl;
}

EchoRespEvent :: ~EchoRespEvent()
{
	cout << "EchoRespEvent :: ~EchoRespEvent" << endl;
}

BaseEvent*
EchoRespEvent :: get_instance(Application& app, string& ip, uint16_t port, int sergeant_no)
{
	return new EchoRespEvent(app, ip, port, sergeant_no);
}

void
EchoRespEvent :: process()
{
	cout << "EchoRespEvent :: process " << endl;
	Sergeant* lp_sergeant = m_app . get_sergeant_dao() . get_sergeant_map( this -> get_sergeant_no());
	if (lp_sergeant == NULL)
	{
		cout << "Invalid Sergeant " << endl;
		return;
	}
	lp_sergeant -> set_current_state(RESP_RCVD);
}
