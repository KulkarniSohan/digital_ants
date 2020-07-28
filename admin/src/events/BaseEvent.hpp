#ifndef __BASE_EVENT_HPP__
#define __BASE_EVENT_HPP__


#include <iostream>
#include <string>
using namespace std;

class Application;

class BaseEvent 
{
	protected :
		Application& m_app;
	private :
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
		int get_sergeant_no()
		{
			cout << "BaseEvent :: get_sergeant_no" << endl;
			return m_sergeant_no;
		}
		uint16_t get_port()
		{
			cout << "BaseEvent :: get_port" << endl;
			return m_port;
		}
		virtual void process()
		{
			cout << "BaseEvent :: process" << endl;
		}
		virtual void load()
		{
			cout << "BaseEvent :: load" << endl;
		}
};


#endif
