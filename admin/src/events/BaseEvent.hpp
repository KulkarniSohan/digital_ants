#ifndef __BASE_EVENT_HPP__
#define __BASE_EVENT_HPP__


#include <iostream>
#include <string>
using namespace std;

class Application;

class BaseEvent 
{
	private :
		Application& m_app;
		string m_ip;
		uint16_t m_port;
		int m_sergeant_no;
	public :
		BaseEvent(Application& app, string& ip, uint16_t port, int sergeant_no) : m_app(app), m_ip(ip), m_port(port), m_sergeant_no(sergeant_no)
		{
			cout << "BaseEvent :: BaseEvent " << endl;
		}
		~BaseEvent()
		{
			cout << "BaseEvent :: ~BaseEvent " << endl;
		}
		string& get_ip()
		{
			cout << "BaseEvent :: get_ip" << endl;
			return m_ip;
		}
		uint16_t get_port()
		{
			cout << "BaseEvent :: get_port" << endl;
			return m_port;
		}
};


#endif
