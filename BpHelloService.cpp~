/* refer to frameworks\av\media\libmedia\IMediaPlayerService.cpp */

#include "IHelloService.h"

//BnHelloService : IHelloService, BBinder
//BpHelloService : IHelloService, BpRefBase
class BpHelloService: public BpInterface<IHelloService>
{
public:
	BpHelloService(const sp<IBinder>& impl)
        : BpInterface<IHelloService>(impl)
	{
	}

	void sayhello(void){
		/*construct data package*/
		/*send data package*/
		Parcel data, reply;
		data.writeInt32(0);
		remote()->transact(HELLO_SVR_CMD_SAYHELLO, data, &reply);
	}
	int sayhello_to(const char *name ){
		/*construct data package*/
		/*send data package*/
		Parcel data, reply;
		data.writeInt32(0);
		data.writeString16(String16(name));

		remote()->transact(HELLO_SVR_CMD_SAYHELLO_TO, data, &reply);

		return reply.readInt32();
	}	
};

IMPLEMENT_META_INTERFACE(HelloService, "android.media.IHelloService");
