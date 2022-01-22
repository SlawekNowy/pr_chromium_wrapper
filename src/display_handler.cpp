#include "display_handler.hpp"

void cef::WebDisplayHandler::OnAddressChange(CefRefPtr<CefBrowser> browser,CefRefPtr<CefFrame> frame,const CefString& url)
{
	if(m_onAddressChange)
		m_onAddressChange(url.ToString());
}
void cef::WebDisplayHandler::SetOnAddressChangeCallback(std::function<void(std::string)> onAddressChange)
{
	m_onAddressChange = onAddressChange;
}
