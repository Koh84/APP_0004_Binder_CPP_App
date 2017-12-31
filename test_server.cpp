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

#include "IHelloService.h"
#include "IGoodbyeService.h"

using namespace android;

int main(void)
{
	/*addService*/

	/*while(1){ read data, parse data, use function}*/

	/*open driver, mmap*/
        sp<ProcessState> proc(ProcessState::self());

	/*Get BpServiceManager*/
	/*This will expose functions such as addService()*/
        sp<IServiceManager> sm = defaultServiceManager();
	sm->addService(String16("hello"), new BnHelloService());
	sm->addService(String16("goodbye"), new BnGoodbyeService());

	/*loop*/
        ProcessState::self()->startThreadPool();
        IPCThreadState::self()->joinThreadPool();

	return 0;
}
