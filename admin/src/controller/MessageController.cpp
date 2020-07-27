#include "MessageController.hpp"
#include "events/BaseEvent.hpp"
#include "Application.hpp"
#include "include/global.hpp"
#include "events/BaseEvent.hpp"
#include "events/EchoReqEvent.hpp"
#include "events/EchoRespEvent.hpp"
#include "enc_dec/Message.hpp"

MessageController* MessageController :: mp_instance = NULL;

MessageController :: MessageController (Application& app) : m_app(app)
{
	cout << "MessageController :: MessageController " << endl;
	// initialize the unorderd map of the MesgTypes
	m_instance_map[1] = EchoReqEvent :: get_instance;
	m_instance_map[2] = EchoRespEvent :: get_instance;
	/*
	m_instance_map[3] = FirefoxKillReqEvent :: get_instance;
	m_instance_map[4] = FirefoxKillRespEvent :: get_instance;
	m_instance_map[5] = CalcKillReqEvent :: get_instance;
	m_instance_map[6] = CalcKillRespEvent :: get_instance;
	*/
}

MessageController*
MessageController :: get_instance(Application& app)
{
	if (mp_instance == NULL)
	{
		mp_instance = new MessageController(app);
	}
	return mp_instance;
}

MessageController :: ~MessageController()
{
	cout << "MessageController :: ~MessageController " << endl;
}

std::queue<void*>&
MessageController :: get_iface_to_cntrler_queue()
{
	return m_ad_iface_to_cntrler_queue;
}

void
MessageController :: init()
{
	int l_err = pthread_create(&m_mesg_cntrler_id, NULL, (THREAD_FUNCTION) &MessageController :: queue_listen_thread_helper, this);
}

void*
MessageController :: queue_listen_thread()
{
	cout << "MessageController :: queue_listen_thread" << endl;
	void* lp_void_event = NULL;
	while (1)
	{
		lp_void_event = this -> m_ad_iface_to_cntrler_queue . front();
		if (lp_void_event == NULL)
		{
			continue;
		}
		Message* lp_msg = extract_msg_type(lp_void_event);
		BaseEvent* lp_event =  m_instance_map[lp_msg -> get_mesg_type()](m_app, lp_msg -> get_ip(), lp_msg -> get_port(), lp_msg -> get_sergeant_no());
		//m_app  . get_admin_engine() . get_cntrler_to_engine_queue(lp_event);
		// pass the event based on extracted data to the AdminEngineThread
	}
}


void*
MessageController :: queue_listen_thread_helper(void* args)
{
	cout << "MessageController :: queue_listen_thread_helper" << endl;
	return ((MessageController*) args) -> queue_listen_thread();
}

pthread_t
MessageController :: get_mesg_cntrler_id()
{
	return m_mesg_cntrler_id;
}

Message*
MessageController :: extract_msg_type(void* lp_event)
{
	cout << "MessageController :: extract_message" << endl;
	Message* lp_msg = new Message();
	lp_msg -> extract_message((void*)lp_event);
	return lp_msg;
	
}
