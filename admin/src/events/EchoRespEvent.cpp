#include "EchoRespEvent.hpp"
#include "Application.hpp"

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
}
