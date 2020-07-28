#ifndef __ECHO_RESP_EVENT_HPP__
#define __ECHO_RESP_EVENT_HPP__


#include "BaseEvent.hpp"
#include <iostream>
#include <string>

class Application;

class EchoRespEvent : public BaseEvent
{
	public :
		EchoRespEvent(Application& app, string& ip, uint16_t port, int sergeant_no);
		~EchoRespEvent();
		static BaseEvent* get_instance(Application& app, string& ip, uint16_t port, int sergeant_no);
		void process();

};

#endif
