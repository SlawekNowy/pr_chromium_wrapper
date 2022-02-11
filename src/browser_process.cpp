#include "browser_process.hpp"
#include "browser_render_process_handler.hpp"

#include <iostream>
#pragma optimize("",off)
cef::BrowserProcess::BrowserProcess()
	: m_renderProcessHandler(new BrowserRenderProcessHandler())
{}

cef::BrowserProcess::~BrowserProcess()
{
	std::cout<<"BrowserProcess destroyed!"<<std::endl;
}

CefRefPtr<CefRenderProcessHandler> cef::BrowserProcess::GetRenderProcessHandler() {return m_renderProcessHandler;}

void cef::BrowserProcess::OnBeforeCommandLineProcessing(const CefString& process_type,CefRefPtr<CefCommandLine> command_line)
{
	command_line->AppendSwitch("off-screen-rendering-enabled");
}
#pragma optimize("",on)
