/* refer to frameworks\av\media\mediaserver\Main_mediaserver.cpp */

#define LOG_TAG "TestService"
//#define LOG_NDEBUG 0

#include <fcntl.h>
#include <sys/prctl.h>
#include <sys/wait.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <cutils/properties.h>
#include <utils/Log.h>
#include <unistd.h>

#include "IHelloService.h"
#include "IGoodbyeService.h"

using namespace android;

/*	./test_client <hello|goodbye>		*/
/*	./test_client <readfile>		*/
/* 	./test_client <hello|goodbye> <name>	*/
int main(int argc, char **argv)
{
	int cnt;

	if(argc < 2)
	{
		ALOGI("Usage\n");
		ALOGI("%s <hello|goodbye>\n", argv[0]);
		ALOGI("%s <readfile>\n", argv[0]);
		ALOGI("%s <hello|goodbye> <name>\n", argv[0]);
		return -1;
	}

	/*getService*/
	/*open driver, mmap*/
        sp<ProcessState> proc(ProcessState::self());

	/*Get BpServiceManager*/
	/*This will expose functions such as getService()*/
        sp<IServiceManager> sm = defaultServiceManager();

	if(strcmp(argv[1],"hello") == 0)
	{
		sp<IBinder> binder = sm->getService(String16("hello"));

		if(binder == 0)
		{
			ALOGI("Can't get hello service\n");
			return -1;
		}

			sp<IHelloService> service = interface_cast<IHelloService>(binder);

		/*User functions in service*/	
		if(argc < 3)
		{
			service->sayhello();
			ALOGI("client call sayhello\n");
		}
		else
		{
			cnt = service->sayhello_to(argv[2]);
			ALOGI("client call sayhello_to, cnt = %d\n", cnt);
		}
	}
	else if(strcmp(argv[1],"readfile") == 0)
	{
		sp<IBinder> binder = sm->getService(String16("hello"));

		if(binder == 0)
		{
			ALOGI("Can't get hello service\n");
			return -1;
		}

			sp<IHelloService> service = interface_cast<IHelloService>(binder);

		/*User functions in service*/	
		int fd = service->get_fd();

		ALOGI("client call get_fd = %d\n", fd);

		char buf[500];
		int len;
		int cnt = 0;
		
		while(1)
		{
			len = sprintf(buf, "Hello, test Server, cnt = %d\n", cnt++);
			write(fd, buf, len);

			lseek(fd, 0, SEEK_SET); /* allow us to re-read the data in 1.txt. if not the pointer will point to end of string, we can see it anymore */

			len = read(fd, buf, 500);
			buf[len] = '\0';	
			ALOGI("client read file = %s\n", buf);
			sleep(5);
		}
	}
	else
	{
		sp<IBinder> binder = sm->getService(String16("goodbye"));

		if(binder == 0)
		{
			ALOGI("Can't get goodbye service\n");
			return -1;
		}

			sp<IGoodbyeService> service = interface_cast<IGoodbyeService>(binder);

		/*User functions in service*/	
		if(argc < 3)
		{
			service->saygoodbye();
			ALOGI("client call saygoodbye\n");
		}
		else
		{
			cnt = service->saygoodbye_to(argv[2]);
			ALOGI("client call saygoodbye_to, cnt = %d\n", cnt);
		}
	}

	return 0;

}
