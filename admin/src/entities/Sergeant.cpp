#include "Sergeant.hpp"

Sergeant :: Sergeant(string& ip, uint16_t port, int sergeant_no) : m_ip(ip), m_port(port), m_sergeant_no(sergeant_no)
{
	cout << "Sergeant :: Sergeant " << endl;
}

Sergeant :: ~Sergeant()
{
	cout << "Sergeant :: ~Sergeant " << endl;
}

void
Sergeant :: set_ip(string& ip)
{
	m_ip = ip;
}

string&
Sergeant :: get_ip()
{
	return m_ip;
}

void
Sergeant :: set_port(uint16_t port)
{
	m_port = port;
}

uint16_t
Sergeant :: get_port()
{
	return m_port;
}

void
Sergeant :: set_current_state(int current_state)
{
	m_current_state = current_state;
}

int
Sergeant :: get_current_state()
{
	return m_current_state;
}

void
Sergeant :: set_sergeant_no(int sergeant_no)
{
	m_sergeant_no = sergeant_no;
}

int
Sergeant :: get_sergeant_no()
{
	return m_sergeant_no;
}
