#include "browserclient.hpp"
#include "renderer.hpp"

#include <iostream>
WebBrowserClient::WebBrowserClient(WebRenderHandler *renderHandler,cef::WebAudioHandler *audioHandler,cef::WebDownloadHandler *dlHandler)
	: m_renderHandler{renderHandler},m_audioHandler{audioHandler},m_downloadHandler{dlHandler}
{}
bool WebBrowserClient::OnProcessMessageReceived(
	CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefProcessId source_process,
	CefRefPtr<CefProcessMessage> message
)
{
	auto msgName = message->GetName().ToString();
	std::cout<<"MSG: "<<msgName<<std::endl;
	if(msgName == "LoadStart")
		SetPageLoadingStarted(true);
	else if(msgName == "LoadComplete")
		SetPageLoadedSuccessfully(true);
	else
		return false;
	return true;
}
CefRefPtr<CefRenderHandler> WebBrowserClient::GetRenderHandler() {return m_renderHandler;}
CefRefPtr<CefAudioHandler> WebBrowserClient::GetAudioHandler() {return m_audioHandler;}
CefRefPtr<CefDownloadHandler> WebBrowserClient::GetDownloadHandler() {return m_downloadHandler;}

bool WebBrowserClient::HasPageLoadingStarted() const {return m_bPageLoadingStarted;}
bool WebBrowserClient::WasPageLoadedSuccessfully() const {return m_bPageLoadedSuccessfully;}

void WebBrowserClient::SetPageLoadedSuccessfully(bool b) {m_bPageLoadedSuccessfully = b;}
void WebBrowserClient::SetPageLoadingStarted(bool b) {m_bPageLoadingStarted = b;}
