#include "EchoReqEvent.hpp"
#include "Application.hpp"

EchoReqEvent :: EchoReqEvent(Application& app, string& ip, uint16_t port, int sergeant_no) : BaseEvent(app, ip, port, sergeant_no)
{
	cout << "EchoReqEvent :: EchoReqEvent " << endl;
}

BaseEvent*
EchoReqEvent :: get_instance(Application& app, string& ip, uint16_t port, int sergeant_no)
{
	return new EchoReqEvent(app, ip, port, sergeant_no);
}

EchoReqEvent :: ~EchoReqEvent()
{
	cout << "EchoReqEvent :: ~EchoReqEvent" << endl;
}
