#include "interface/UdpWorker.hpp"
#include "interface/UdpServerSocket.hpp"
#include "controller/MessageController.hpp"
#include "controller/AdminEngineController.hpp"
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <queue>
#include <netinet/in.h>
#include <thread>
#include <unistd.h>
#include <strings.h>
#include <arpa/inet.h>
#include "Application.hpp"
#include "dao/SergeantDao.hpp"

using namespace std;

//typedef void * (*THREAD_FUNCTION) (void*);

void
Application :: startup ()
{
	pthread_t l_sock_recv_thread, l_mesg_cntrler_thread, l_msg_aec_cntrler_thread, l_aec_msg_cntrler_thread;
	mp_sergeant_dao = SergeantDao :: get_instance();
    mp_udp_worker_instance = UdpWorker :: get_instance(*this);
    l_sock_recv_thread = mp_udp_worker_instance -> init();
	mp_mesg_cntrler = MessageController :: get_instance(*this);
	mp_mesg_cntrler -> init();
	l_mesg_cntrler_thread = mp_mesg_cntrler -> get_mesg_cntrler_id();
	mp_admin_engine_cntrler = AdminEngineController :: get_instance(*this);
	mp_admin_engine_cntrler -> init();
	l_msg_aec_cntrler_thread = mp_admin_engine_cntrler -> get_msg_to_aec_cntrler_id();
	l_aec_msg_cntrler_thread = mp_admin_engine_cntrler -> get_aec_to_msg_cntrler_id();
	
    pthread_join(l_sock_recv_thread, NULL);
	pthread_join(l_mesg_cntrler_thread, NULL);
	pthread_join(l_msg_aec_cntrler_thread, NULL);
	pthread_join(l_aec_msg_cntrler_thread, NULL);
}


Application g_app;

int main(int argc, char* argv[])
{

	g_app . startup();
	/*
	pthread_t l_sock_recv_thread;
	UdpWorker* l_worker_instance = UdpWorker::get_instance();
	l_sock_recv_thread = l_worker_instance -> init();

	pthread_join(l_sock_recv_thread, NULL);*/
}
