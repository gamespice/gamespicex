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

CCHttpRequest* APIClient::prepareRequestWithData(const char* url,
		CCHttpRequest::HttpRequestType requestType, std::string data) {
	auto request = prepareRequest(url, requestType);
	request->setRequestData(data.c_str(), strlen(data.c_str()));
	return request;
}

void APIClient::sendRequestAndRelease(CCHttpRequest* request) {
	CCHttpClient::getInstance()->send(request);
	request->release();
}

void APIClient::post(const char* url, std::string data, CCObject* target,
		SEL_HttpResponse handler) {
	auto request = prepareRequestWithData(url, CCHttpRequest::kHttpPost, data);
	request->setResponseCallback(target, handler);
	sendRequestAndRelease(request);
}

CCHttpRequest* APIClient::prepareRequest(const char* url,
		CCHttpRequest::HttpRequestType requestType) {
	auto request = new CCHttpRequest();
	setRequestHeaders(request);
	setRequestUrl(url, request);
	request->setRequestType(requestType);
	return request;
}

void APIClient::post(const char* url, std::string data) {
	sendRequestAndRelease(
			prepareRequestWithData(url, CCHttpRequest::kHttpPost, data));
}

void APIClient::setRequestUrl(const char* url, CCHttpRequest* request) {
	std::string requestUrl = apiRoot;
	requestUrl += url;
	request->setUrl(requestUrl.c_str());
}

void APIClient::get(const char* url, CCObject* target,
		SEL_HttpResponse handler) {
	auto request = prepareRequest(url, CCHttpRequest::kHttpGet);
	request->setResponseCallback(target, handler);
	sendRequestAndRelease(request);
}

APIClient::~APIClient() {
// TODO Auto-generated destructor stub
}

} /* namespace gamespice */
