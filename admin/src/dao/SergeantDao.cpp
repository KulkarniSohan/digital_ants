#include "SergeantDao.hpp"

SergeantDao* SergeantDao :: mp_instance = NULL;

SergeantDao :: SergeantDao()
{
	cout << "SergeantDao :: SergeantDao " << endl;
}

SergeantDao :: ~SergeantDao()
{
	cout << "SergeantDao :: ~SergeantDao" << endl;
}

SergeantDao*
SergeantDao :: get_instance()
{
	cout << "SergeantDao :: get_instance" << endl;
	if (mp_instance == NULL)
	{
		mp_instance = new SergeantDao();
	}
	return mp_instance;
}

void
SergeantDao :: add_sergeant_map(int sergeant_no, Sergeant* p_sergeant)
{
	cout << "SergeantDao :: add_sergeant_map" << endl;
	m_sergeant_map [sergeant_no] = p_sergeant;
}

Sergeant*
SergeantDao :: get_sergeant_map(int sergeant_no)
{
	cout << "SergeanDao :: get_sergeant_map " << endl;
	//find logic
	auto itr = m_sergeant_map . find(sergeant_no);
	if (itr == m_sergeant_map . end())
	{
		return NULL;
	}
	return itr -> second;
}

void
SergeantDao :: remove_sergeant_map(int sergeant_no)
{
	cout << "SergeantDao :: remove_sergeant_map" << endl;
	m_sergeant_map . erase(sergeant_no);
}

