#ifndef HTTPCLIENT_H_
#define HTTPCLIENT_H_

#include <string>
#include "cocos-ext.h"
#include "cocos2d.h"
using namespace cocos2d::extension;
USING_NS_CC;
namespace gamespice {

class APIClient: CCObject {
public:

	static APIClient* getInstance();

	void configure(const std::string apiRoot, std::string version);

	void post(const char* url, std::string data);
	void post(const char* url, std::string data, CCObject* target,
			SEL_HttpResponse handler);
	void get(const char* url, CCObject* target, SEL_HttpResponse handler);

	virtual ~APIClient();

private:

	std::string apiRoot;std::string version;

	void setRequestHeaders(CCHttpRequest* request);
	void setRequestUrl(const char* url, CCHttpRequest* request);
	CCHttpRequest* prepareRequest(const char* url,
			CCHttpRequest::HttpRequestType requestType);
	CCHttpRequest* prepareRequestWithData(const char* url,
			CCHttpRequest::HttpRequestType requestType, std::string data);
	void sendRequestAndRelease(CCHttpRequest* request);
};

} /* namespace gamespice */

#endif /* HTTPCLIENT_H_ */
