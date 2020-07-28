#include "AdminEngineController.hpp"
#include "include/global.hpp"
#include "events/BaseEvent.hpp"
#include "Application.hpp"
#include "events/BaseEvent.hpp"
//#include "events/EchoReqEvent.hpp"
#include "events/EchoRespEvent.hpp"

AdminEngineController* AdminEngineController :: mp_instance = NULL;

AdminEngineController :: AdminEngineController(Application& app) : m_app(app)
{
	cout << "AdminEngineController :: AdminEngineController" << endl;
}

AdminEngineController :: ~AdminEngineController()
{
	cout << "AdminEngineController :: ~AdminEngineController " << endl;
}

AdminEngineController *
AdminEngineController :: get_instance(Application& app)
{
	cout << "AdminEngineController :: get_instance" << endl;
	if (mp_instance == NULL)
	{
		mp_instance = new AdminEngineController(app);
	}
	return mp_instance;
}

void
AdminEngineController :: init()
{
	cout << "AdminEngineController :: init" << endl;
	int l_err1, l_err2;
	l_err1 = pthread_create(&m_msg_to_aec_cntrler_id, NULL, (THREAD_FUNCTION) &AdminEngineController :: msg_to_aec_thread_helper, this);
	l_err2 = pthread_create(&m_aec_to_msg_cntrler_id, NULL, (THREAD_FUNCTION) &AdminEngineController :: aec_to_msg_thread_helper, this);
	
}

void*
AdminEngineController :: msg_to_aec_thread()
{
	cout << "AdminEngineController :: msg_to_aec_thread" << endl;
	BaseEvent* lp_event = NULL;
	while(1)
	{
		lp_event = this -> m_msg_cntrler_to_aec_cntrler_queue . front();
		if (lp_event == NULL)
		{
			continue;
		}
		EchoRespEvent* lp_rcvd_event = dynamic_cast <EchoRespEvent*>(lp_event);
		if(lp_rcvd_event != NULL)
		{
			cout << "AdminEngineController :: msg_to_aec_thread : EchoRespEvent Rcvd" << endl;
			/* We can call the process virtual function of the BaseEvent*/
			lp_rcvd_event -> process();
		}
	}
}

/*
void
AdminEngineController :: process(EchoRespEvent* lp_rcvd_event)
{
	cout << "AdminEngineController :: process " << endl;
	// get Sergeant from dao.
	
	Sergeant* lp_sergeant = m_app . get_sergeant_dao() . get_sergeant(lp_rcvd_event -> get_sergeant_no());
	if (lp_sergeant == NULL)
	{
		cout << "Invalid Sergeant : " << lp_rcvd_event -> get_sergeant_no() << endl;
		return;
	}
	lp_sergeant -> set_current_state(RESP_RCVD);
	
}
*/

void*
AdminEngineController :: aec_to_msg_thread()
{
	cout << "AdminEngineController :: aec_to_msg_thread " << endl;
}


void*
AdminEngineController :: msg_to_aec_thread_helper(void* args)
{
	cout << "AdminEngineController :: msg_to_aec_thread_helper " << endl;
	return ((AdminEngineController*) args) -> msg_to_aec_thread();
}

void*
AdminEngineController :: aec_to_msg_thread_helper(void* args)
{
	cout << "AdminEngineController :: aec_to_msg_thread_helper " << endl;
	return ((AdminEngineController*) args) -> aec_to_msg_thread();
}

pthread_t
AdminEngineController :: get_msg_to_aec_cntrler_id()
{
	return m_msg_to_aec_cntrler_id;
}

pthread_t
AdminEngineController :: get_aec_to_msg_cntrler_id()
{
	return m_aec_to_msg_cntrler_id;
}

queue<BaseEvent*>&
AdminEngineController :: get_msg_cntrler_to_aec_cntrler_queue()
{
	return m_msg_cntrler_to_aec_cntrler_queue;
}

queue<BaseEvent*>&
AdminEngineController :: get_aec_cntrler_to_msg_cntrler_queue()
{
	return m_aec_cntrler_to_msg_cntrler_queue;
}
