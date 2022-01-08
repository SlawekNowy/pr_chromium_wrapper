#include "download_handler.hpp"
#include <iostream>

void cef::WebDownloadHandler::OnBeforeDownload(
	CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefDownloadItem> download_item,
	const CefString& suggested_name,
	CefRefPtr<CefBeforeDownloadCallback> callback
)
{
	if(m_downloadLocation.empty())
		callback->Continue("",false);
	else
	{
		auto filePath = m_downloadLocation +suggested_name.ToString();
		callback->Continue(filePath,false);
	}
}

void cef::WebDownloadHandler::SetCompleteCallback(const std::function<void(const std::string&)> &completeCallback) {m_completeCallback = completeCallback;}

void cef::WebDownloadHandler::OnDownloadUpdated(CefRefPtr<CefBrowser> browser,CefRefPtr<CefDownloadItem> download_item,CefRefPtr<CefDownloadItemCallback> callback)
{
	if(m_completeCallback && download_item->IsValid() && download_item->IsComplete())
		m_completeCallback(download_item->GetFullPath().ToString());
}
void cef::WebDownloadHandler::SetDownloadLocation(std::string location)
{
	for(auto &c : location)
	{
		if(c == '/')
			c = '\\';
	}
	m_downloadLocation = std::move(location);
	if(!m_downloadLocation.empty() && m_downloadLocation.back() != '\\')
		m_downloadLocation += '\\';
}
