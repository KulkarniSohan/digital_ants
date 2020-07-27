#ifndef __MESSAGE_HPP__
#define __MESSAGE_HPP__


#include <iostream>
#include <string>

using namespace std;


class Message
{
	private :
		int m_msg_type;
		uint32_t m_sergeant_no;
		string m_ip;
		uint16_t m_port;
	public :
		Message();
		~Message();
		Message* extract_message(void* lp_event);
		int get_mesg_type();
		uint32_t get_sergeant_no();
		string& get_ip();
		uint16_t get_port();

		void set_mesg_type(int msg_type);
		void set_sergeant_no(uint32_t seq_no);
		void set_ip(string& ip);
		void set_port(uint16_t port);
};


#endif
