/* refer to frameworks\av\media\libmedia\IMediaPlayerService.cpp */
#define LOG_TAG "HelloService"

#include "IHelloService.h"



namespace android {

	status_t BnHelloService::onTransact( uint32_t code,
                             			const Parcel& data,
                             			Parcel* reply,
                             			uint32_t flags)
	{
		/*parse data and then uses sayhello or sayhello_to*/
		switch (code) 
		{
			case HELLO_SVR_CMD_SAYHELLO: {
				sayhello();	
				reply->writeInt32(0); /* no exception */	
			    	return NO_ERROR;
			} break;
			case HELLO_SVR_CMD_SAYHELLO_TO: {

				/*extract parameters from data*/
				int32_t policy = data.readInt32();
				String16 name16_tmp = data.readString16(); /*IHelloService*/

				String16 name16 = data.readString16();
				String8 name8(name16);

			    	int cnt = sayhello_to(name8.string());

				/*insert data back to reply*/
				reply->writeInt32(0); /* no exception */
				reply->writeInt32(cnt);

			    	return NO_ERROR;
			} break;
			default:
			    return BBinder::onTransact(code, data, reply, flags);
	    	}
	}

	void BnHelloService::sayhello(void){
		static int cnt = 0;
		//fprintf(stderr, "say hello : %d\n", cnt++);
		//Android uses ALOGI to print info, it will also print LOG_TAG as defined above
		ALOGI("say hello : %d\n", ++cnt);
	}

	int BnHelloService::sayhello_to(const char *name ){
		static int cnt = 0;
		//fprintf(stderr, "say hello to %s : %d\n", name, cnt++);
		ALOGI("say hello to %s : %d\n", name, ++cnt);
		return cnt;
	}

};
