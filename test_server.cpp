/* refer to frameworks\av\media\mediaserver\Main_mediaserver.cpp */

#define LOG_TAG "HelloService"
//#define LOG_NDEBUG 0

#include <fcntl.h>
#include <sys/prctl.h>
#include <sys/wait.h>
#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <cutils/properties.h>
#include <utils/Log.h>

using namespace android;

void main(void)
{
	/*addService*/

	/*while(1){ read data, parse data, use function}*/

	/*open driver, mmap*/
        sp<ProcessState> proc(ProcessState::self());

	/*Get BpServiceManager*/
	/*This will expose functions such as addService()*/
        sp<IServiceManager> sm = defaultServiceManager();
	sm->addService(String16("hello"), new BnHelloService());

	/*loop*/
        ProcessState::self()->startThreadPool();
        IPCThreadState::self()->joinThreadPool();
}
