#ifndef __PR_CHROMIUM_AUDIO_HANDLER_HPP__
#define __PR_CHROMIUM_AUDIO_HANDLER_HPP__

#include <include/cef_audio_handler.h>

namespace cef
{
	class WebAudioHandler
		: public CefAudioHandler
	{
	public:
		virtual bool GetAudioParameters(CefRefPtr<CefBrowser> browser,CefAudioParameters& params);
		virtual void OnAudioStreamStarted(CefRefPtr<CefBrowser> browser,const CefAudioParameters& params,int channels);

		virtual void OnAudioStreamPacket(CefRefPtr<CefBrowser> browser,const float** data,int frames,int64 pts);

		virtual void OnAudioStreamStopped(CefRefPtr<CefBrowser> browser);

		virtual void OnAudioStreamError(CefRefPtr<CefBrowser> browser,const CefString& message);
		IMPLEMENT_REFCOUNTING(WebAudioHandler);
	};
};

#endif
