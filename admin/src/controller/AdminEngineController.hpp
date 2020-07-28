#ifndef __ADMIN_ENGINE_CONTROLLER_HPP__
#define __ADMIN_ENGINE_CONTROLLER_HPP__

#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Application;
class BaseEvent;
class EchoRespEvent;


class AdminEngineController
{
	private :
		Application& m_app;
		pthread_t m_msg_to_aec_cntrler_id;
		pthread_t m_aec_to_msg_cntrler_id;
		queue<BaseEvent*> m_msg_cntrler_to_aec_cntrler_queue;
		queue<BaseEvent*> m_aec_cntrler_to_msg_cntrler_queue;
		AdminEngineController(Application& app);
	public :
		static AdminEngineController* mp_instance;
		~AdminEngineController();
		static AdminEngineController* get_instance(Application& app);
		void init();
		static void* aec_to_msg_thread_helper(void* args);
		static void* msg_to_aec_thread_helper(void* args);
		void* aec_to_msg_thread();
		void* msg_to_aec_thread();

		pthread_t get_msg_to_aec_cntrler_id();
		pthread_t get_aec_to_msg_cntrler_id();

		queue<BaseEvent*>& get_msg_cntrler_to_aec_cntrler_queue();
		queue<BaseEvent*>& get_aec_cntrler_to_msg_cntrler_queue();

		void process(EchoRespEvent* lp_rcvd_event);
};


#endif
