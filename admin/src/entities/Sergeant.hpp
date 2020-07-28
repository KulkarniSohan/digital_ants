#ifndef __SERGEANT_HPP__
#define __SERGEANT_HPP__


#include <iostream>
#include <string>
using namespace std;
#define REQ_SENT 100
#define RESP_RCVD 200



class Sergeant
{
	private : 
		string m_ip;
		uint16_t m_port;
		int m_sergeant_no;
		int m_current_state;
	public :
		Sergeant(string& ip, uint16_t port, int sergeant_no);
		~Sergeant();
		string& get_ip();
		void set_ip(string& ip);
		void set_port(uint16_t port);
		uint16_t get_port();
		void set_sergeant_no(int sergeant_no);
		int get_sergeant_no();
		void set_current_state(int current_state);
		int get_current_state();
};

#endif
