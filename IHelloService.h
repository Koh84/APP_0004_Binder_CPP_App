/* refer to frameworks\av\include\media\IMediaPlayerService.h */

#ifndef ANDROID_IHELLOSERVICE_H
#define ANDROID_IHELLOSERVICE_H

#include <utils/Errors.h>  // for status_t
#include <utils/KeyedVector.h>
#include <utils/RefBase.h>
#include <utils/String8.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

#define HELLO_SVR_CMD_SAYHELLO 1
#define HELLO_SVR_CMD_SAYHELLO_TO 2
#define HELLO_SVR_CMD_GET_FD 3

namespace android {

class IHelloService: public IInterface
{
public:
	DECLARE_META_INTERFACE(HelloService);
	virtual void sayhello(void) = 0;
	virtual int sayhello_to(const char *name ) = 0;	
	virtual int get_fd(void) = 0;	
};

// ----------------------------------------------------------------------------
//declare BnHelloService class
//BpHelloService : IHelloService, BpRefBase
//BnHelloService : IHelloService, BBinder
class BnHelloService: public BnInterface<IHelloService>
{

private:
	int fd;

public:
	virtual status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
	void sayhello(void);
	int sayhello_to(const char *name );	
	int get_fd(void);

	BnHelloService();
	BnHelloService(int fd);
};

};
#endif
