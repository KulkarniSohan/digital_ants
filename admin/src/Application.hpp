#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__
class MessageController;
class UdpWorker;
class AdminEngineController;
class SergeantDao;

class Application
{
    private :
        UdpWorker* mp_udp_worker_instance;
		MessageController* mp_mesg_cntrler;
		AdminEngineController* mp_admin_engine_cntrler;
		SergeantDao* mp_sergeant_dao;
    public :
        UdpWorker& get_udp_worker()
        {
            return (*mp_udp_worker_instance);
        }
		MessageController& get_mesg_cntrler()
		{
			return (*mp_mesg_cntrler);
		}
		AdminEngineController& get_admin_engine_cntrler()
		{
			return (*mp_admin_engine_cntrler);
		}
		SergeantDao& get_sergeant_dao()
		{
			return (*mp_sergeant_dao);
		}
        void startup();
};


#endif
