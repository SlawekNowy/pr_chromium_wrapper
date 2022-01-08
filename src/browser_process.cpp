#include "browser_process.hpp"
#include "browser_render_process_handler.hpp"

cef::BrowserProcess::BrowserProcess()
	: m_renderProcessHandler(new BrowserRenderProcessHandler())
{}

CefRefPtr<CefRenderProcessHandler> cef::BrowserProcess::GetRenderProcessHandler() {return m_renderProcessHandler;}
