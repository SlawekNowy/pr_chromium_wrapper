#include "audio_handler.hpp"
#include <iostream>

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
