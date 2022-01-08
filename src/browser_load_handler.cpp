#include "browser_load_handler.hpp"
#include "browserclient.hpp"

void cef::BrowserLoadHandler::OnLoadingStateChange(CefRefPtr<CefBrowser> browser,bool isLoading,bool canGoBack,bool canGoForward)
{
}
void cef::BrowserLoadHandler::OnLoadStart(CefRefPtr<CefBrowser> browser,CefRefPtr<CefFrame> frame,TransitionType transition_type)
{
	browser->GetMainFrame()->SendProcessMessage(PID_BROWSER,CefProcessMessage::Create("LoadStart"));
}
void cef::BrowserLoadHandler::OnLoadEnd(CefRefPtr<CefBrowser> browser,CefRefPtr<CefFrame> frame,int httpStatusCode)
{
	if(httpStatusCode == 200)
		browser->GetMainFrame()->SendProcessMessage(PID_BROWSER,CefProcessMessage::Create("LoadComplete"));
}
void cef::BrowserLoadHandler::OnLoadError(CefRefPtr<CefBrowser> browser,CefRefPtr<CefFrame> frame,ErrorCode errorCode,const CefString& errorText,const CefString& failedUrl)
{
}
