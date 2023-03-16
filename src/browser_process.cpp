#include "browser_process.hpp"
#include "browser_render_process_handler.hpp"

#include <iostream>
#pragma optimize("", off)
cef::BrowserProcess::BrowserProcess() : m_renderProcessHandler(new BrowserRenderProcessHandler()) {}

cef::BrowserProcess::~BrowserProcess() {}

CefRefPtr<CefRenderProcessHandler> cef::BrowserProcess::GetRenderProcessHandler() { return m_renderProcessHandler; }

void cef::BrowserProcess::OnBeforeCommandLineProcessing(const CefString &process_type, CefRefPtr<CefCommandLine> command_line)
{
	command_line->AppendSwitch("off-screen-rendering-enabled");
	//command_line->AppendSwitch("no-zygote"); //for Linux?, this would disable zygote
	command_line->AppendSwitch("in-process-gpu");
	command_line->AppendSwitch("disable-gpu-sandbox");
	//--password-store=basic
	command_line->AppendSwitchWithValue("password-store", "basic");
}
#pragma optimize("", on)
