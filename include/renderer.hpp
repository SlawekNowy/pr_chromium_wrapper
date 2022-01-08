#ifndef __RENDERER_HPP__
#define __RENDERER_HPP__

#include <include/cef_render_handler.h>
#include "download_handler.hpp"
#include "audio_handler.hpp"

class WebRenderHandler;
class WebBrowserClient;
class CefBrowser;
namespace cef
{
	class BrowserProcess;
	using CWebRenderHandler = CefRefPtr<WebRenderHandler>;
	using CWebBrowserClient = CefRefPtr<WebBrowserClient>;
	using CWebBrowser = CefRefPtr<CefBrowser>;
};
class WebRenderHandler
	: public CefRenderHandler
{
public:
	WebRenderHandler(
		cef::BrowserProcess *process,
		void(*fGetRootScreenRect)(cef::CWebRenderHandler*,int&,int&,int&,int&),
		void(*fGetViewRect)(cef::CWebRenderHandler*,int&,int&,int&,int&),
		void(*fGetScreenPoint)(cef::CWebRenderHandler*,int,int,int&,int&)
	);

	virtual ~WebRenderHandler() override;
	virtual bool GetRootScreenRect(CefRefPtr<CefBrowser> browser,CefRect &rect) override;
	virtual void GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;
	virtual bool GetScreenPoint(CefRefPtr<CefBrowser> browser,int viewX,int viewY,int &screenX,int &screenY) override;
	virtual bool GetScreenInfo(CefRefPtr<CefBrowser> browser,CefScreenInfo &screen_info) override;
	virtual void OnPopupShow(CefRefPtr<CefBrowser> browser,bool show) override;
	virtual void OnPopupSize(CefRefPtr<CefBrowser> browser,const CefRect &rect) override;
	virtual void OnPaint(CefRefPtr<CefBrowser> browser,PaintElementType type,const RectList &dirtyRects,const void *buffer,int width, int height) override;
	virtual bool StartDragging(CefRefPtr<CefBrowser> browser,CefRefPtr<CefDragData> drag_data,DragOperationsMask allowed_ops,int x,int y) override;
	virtual void UpdateDragCursor(CefRefPtr<CefBrowser> browser,DragOperation operation) override;
	virtual void OnScrollOffsetChanged(CefRefPtr<CefBrowser> browser,double x,double y) override;
	virtual void OnImeCompositionRangeChanged(CefRefPtr<CefBrowser> browser,const CefRange &selected_range,const RectList &character_bounds) override;
	void SetDataPtr(void *ptr) {m_dataPtr = ptr;}
	void SetUserData(void *userData) {m_userData = userData;;}
	void *GetUserData() {return m_userData;}
	void SetRefPtr(cef::CWebRenderHandler *ptr) {m_refPtr = ptr;}
	IMPLEMENT_REFCOUNTING(WebRenderHandler);
private:
	void *m_dataPtr = nullptr;
	cef::BrowserProcess *m_process = nullptr;
	cef::CWebRenderHandler *m_refPtr = nullptr;
	void *m_userData = nullptr;
	void(*m_fGetRootScreenRect)(cef::CWebRenderHandler*,int&,int&,int&,int&) = nullptr;
	void(*m_fGetViewRect)(cef::CWebRenderHandler*,int&,int&,int&,int&) = nullptr;
	void(*m_fGetScreenPoint)(cef::CWebRenderHandler*,int,int,int&,int&) = nullptr;
};

#endif
