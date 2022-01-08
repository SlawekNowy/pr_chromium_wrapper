#ifndef __BROWSERCLIENT_HPP__
#define __BROWSERCLIENT_HPP__

#include <include/cef_client.h>
#include "audio_handler.hpp"
#include "download_handler.hpp"

class WebRenderHandler;
class WebBrowserClient
	: public CefClient
{
public:
	WebBrowserClient(WebRenderHandler *renderHandler,cef::WebAudioHandler *audioHandler,cef::WebDownloadHandler *dlHandler);
	virtual CefRefPtr<CefRenderHandler> GetRenderHandler() override;
	virtual CefRefPtr<CefAudioHandler> GetAudioHandler() override;
	virtual CefRefPtr<CefDownloadHandler> GetDownloadHandler() override;

	virtual bool OnProcessMessageReceived(
		CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefProcessId source_process,
		CefRefPtr<CefProcessMessage> message
	) override;

	bool WasPageLoadedSuccessfully() const;
	bool HasPageLoadingStarted() const;
	
	void SetPageLoadedSuccessfully(bool b);
	void SetPageLoadingStarted(bool b);

	void SetUserData(void *userData) {m_userData = userData;;}
	void *GetUserData() {return m_userData;}

	IMPLEMENT_REFCOUNTING(WebBrowserClient);
private:
	CefRefPtr<CefRenderHandler> m_renderHandler;
	CefRefPtr<CefAudioHandler> m_audioHandler;
	CefRefPtr<CefDownloadHandler> m_downloadHandler;
	void *m_userData = nullptr;
	bool m_bPageLoadedSuccessfully = false;
	bool m_bPageLoadingStarted = false;
};

#endif
