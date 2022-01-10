#include "audio_handler.hpp"
#include <iostream>

cef::WebLifeSpanHandler::~WebLifeSpanHandler()
{
	std::cout<<"WebLifeSpanHandler destroyed!"<<std::endl;
}
void cef::WebLifeSpanHandler::OnAfterCreated(CefRefPtr<CefBrowser> browser)
{
	m_afterCreated = true;
	std::cout<<"OnAfterCreated!"<<std::endl;
}
void cef::WebLifeSpanHandler::OnBeforeClose(CefRefPtr<CefBrowser> browser)
{
	m_beforeClose = true;
	std::cout<<"OnBeforeClose!"<<std::endl;
}

///

cef::WebAudioHandler::~WebAudioHandler()
{
	std::cout<<"WebAudioHandler destroyed!"<<std::endl;
}
bool cef::WebAudioHandler::GetAudioParameters(CefRefPtr<CefBrowser> browser,CefAudioParameters& params)
{
	return true;
}

void cef::WebAudioHandler::OnAudioStreamStarted(CefRefPtr<CefBrowser> browser,const CefAudioParameters& params,int channels)
{
	std::cout<<"Stream start"<<std::endl;
}

void cef::WebAudioHandler::OnAudioStreamPacket(CefRefPtr<CefBrowser> browser,const float** data,int frames,int64 pts)
{

}

void cef::WebAudioHandler::OnAudioStreamStopped(CefRefPtr<CefBrowser> browser)
{
	std::cout<<"Stream stopped"<<std::endl;
}

void cef::WebAudioHandler::OnAudioStreamError(CefRefPtr<CefBrowser> browser,const CefString& message)
{

}
