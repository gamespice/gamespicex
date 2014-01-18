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

void APIClient::setRequestHeaders(HttpRequest* request) {
	std::string versionHeader = "Accept-Version=" + version;
	request->setHeaders( { versionHeader, "Content-type: application/json" });
}

HttpRequest* APIClient::prepareRequestWithData(const char* url,
		HttpRequest::Type requestType, std::string data) {
	auto request = prepareRequest(url, requestType);
	request->setRequestData(data.c_str(), strlen(data.c_str()));
	return request;
}

void APIClient::put(const char* url, std::string data) {
	sendRequestAndRelease(
			prepareRequestWithData(url, HttpRequest::Type::PUT,
					data));
}

void APIClient::sendRequestAndRelease(HttpRequest* request) {
	HttpClient::getInstance()->send(request);
	request->release();
}

void APIClient::post(const char* url, std::string data, Object* target,
		SEL_HttpResponse handler) {
	auto request = prepareRequestWithData(url,
			HttpRequest::Type::POST, data);
	request->setResponseCallback(target, handler);
	sendRequestAndRelease(request);
}

HttpRequest* APIClient::prepareRequest(const char* url,
		HttpRequest::Type requestType) {
	auto request = new HttpRequest();
	setRequestHeaders(request);
	setRequestUrl(url, request);
	request->setRequestType(requestType);
	return request;
}

void APIClient::post(const char* url, std::string data) {
	sendRequestAndRelease(
			prepareRequestWithData(url,
					HttpRequest::Type::POST, data));
}

void APIClient::setRequestUrl(const char* url, HttpRequest* request) {
	std::string requestUrl = apiRoot;
	requestUrl += url;
	request->setUrl(requestUrl.c_str());
}

void APIClient::get(const char* url, Object* target,
		SEL_HttpResponse handler) {
	auto request = prepareRequest(url, HttpRequest::Type::GET);
	request->setResponseCallback(target, handler);
	sendRequestAndRelease(request);
}

APIClient::~APIClient() {
}

} /* namespace gamespice */
