#include "Message.hpp"

Message :: Message()
{
	cout << "Message :: Message" << endl;
}

Message :: ~Message()
{
	cout << "Message :: ~Message" << endl;
}

Message*
Message :: extract_message(void* lp_event)
{
	cout << "Message :: extract_message" << endl;
	Message* lp_rcvd_event = (Message*)lp_event;
	this -> m_msg_type = lp_rcvd_event -> get_mesg_type();
	this -> m_sergeant_no = lp_rcvd_event -> get_sergeant_no();
	this -> m_ip = lp_rcvd_event -> get_ip();
	this -> m_port = lp_rcvd_event -> get_port();
	return this;
}

void
Message :: set_mesg_type(int msg_type)
{
	m_msg_type = msg_type;
}

int
Message :: get_mesg_type()
{
	return m_msg_type;
}

void
Message :: set_sergeant_no(uint32_t sergeant_no)
{
	m_sergeant_no = sergeant_no;
}

uint32_t
Message :: get_sergeant_no()
{
	return m_sergeant_no;
}

void
Message :: set_ip(string& ip)
{
	m_ip = ip;
}

string&
Message :: get_ip()
{
	return m_ip;
}

void
Message :: set_port(uint16_t port)
{
	m_port = port;
}

uint16_t
Message :: get_port()
{
	return m_port;
}
