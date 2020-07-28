#ifndef __ECHO_REQ_EVENT_HPP__
#define __ECHO_REQ_EVENT_HPP__


#include "BaseEvent.hpp"
#include <iostream>
#include <string>

class Application;

using namespace std;


class EchoReqEvent : public BaseEvent
{
	public :
		static BaseEvent* get_instance(Application& app, string& m_ip, uint16_t port, int sergeant_no);
		EchoReqEvent(Application& app, string& ip, uint16_t port, int sergeant_no);
		~EchoReqEvent();
		void load();
};


#endif
