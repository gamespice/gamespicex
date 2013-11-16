#include "APIClient.h"

#include <string>

namespace gamespice {

static APIClient* clientInstance;

APIClient* APIClient::getInstance() {
	if (!clientInstance) {
		clientInstance = new APIClient();
	}
	return clientInstance;
}

void APIClient::configure(const std::string apiRoot, std::string version) {
	this->apiRoot = apiRoot;
	this->version = version;
}

void APIClient::setRequestHeaders(CCHttpRequest* request) {
	std::string versionHeader = "Accept-Version=" + version;
	request->setHeaders( { versionHeader, "Content-type: application/json" });
}

CCHttpRequest* APIClient::prepareRequest(const char* url,
		CCHttpRequest::HttpRequestType requestType) {
	CCHttpRequest* request = new CCHttpRequest();
	setRequestHeaders(request);
	setRequestUrl(url, request);
	request->setRequestType(requestType);
	return request;
}

void APIClient::post(const char* url, std::string data) {
	CCHttpRequest* request = prepareRequest(url, CCHttpRequest::kHttpPost);
	request->setRequestData(data.c_str(), strlen(data.c_str()));
	CCHttpClient::getInstance()->send(request);
	request->release();
}

void APIClient::setRequestUrl(const char* url, CCHttpRequest* request) {
	std::string requestUrl = apiRoot;
	requestUrl += url;
	request->setUrl(requestUrl.c_str());
}

void APIClient::get(const char* url, CCObject* target,
		SEL_HttpResponse handler) {
	CCHttpRequest* request = prepareRequest(url, CCHttpRequest::kHttpGet);
	request->setResponseCallback(target, handler);
	CCHttpClient::getInstance()->send(request);
	request->release();
}

APIClient::~APIClient() {
// TODO Auto-generated destructor stub
}

} /* namespace gamespice */
