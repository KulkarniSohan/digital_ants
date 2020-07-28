#ifndef __SERGEANT_DAO_HPP__
#define __SERGEANT_DAO_HPP__


#include <iostream>
#include <string>
#include <unordered_map>
class Sergeant;

using namespace std;


class SergeantDao
{
	private :
		unordered_map<int, Sergeant*> m_sergeant_map;
		SergeantDao();
	public :
		~SergeantDao();
		static SergeantDao* mp_instance;
		static SergeantDao* get_instance();
		void add_sergeant_map(int sergeant_no, Sergeant* p_sergeant);
		Sergeant* get_sergeant_map(int sergeant_no);
		void remove_sergeant_map(int sergeant_no);
};

#endif
