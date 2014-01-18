#ifndef HTTPCLIENT_H_
#define HTTPCLIENT_H_

#include <string>
#include "cocos2d.h"
#include "network/HttpClient.h"
namespace gamespice {

USING_NS_CC;
using namespace network;
class APIClient: Object {
public:

	static APIClient* getInstance();

	void configure(const std::string apiRoot, std::string version);

	void post(const char* url, std::string data);
	void post(const char* url, std::string data, CCObject* target,
			SEL_HttpResponse handler);
	void put(const char* url, std::string data);
	void get(const char* url, CCObject* target, SEL_HttpResponse handler);

	virtual ~APIClient();

private:

	std::string apiRoot;std::string version;

	void setRequestHeaders(HttpRequest* request);
	void setRequestUrl(const char* url, HttpRequest* request);
	HttpRequest* prepareRequest(const char* url, HttpRequest::Type requestType);
	HttpRequest* prepareRequestWithData(const char* url,
			HttpRequest::Type requestType, std::string data);
	void sendRequestAndRelease(HttpRequest* request);
};

} /* namespace gamespice */

#endif /* HTTPCLIENT_H_ */
