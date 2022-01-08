#ifndef __PR_CHROMIUM_DOWNLOAD_HANDLER_HPP__
#define __PR_CHROMIUM_DOWNLOAD_HANDLER_HPP__

#include <include/cef_download_handler.h>
#include <functional>

namespace cef
{
	class WebDownloadHandler
		: public CefDownloadHandler
	{
	public:
		virtual void OnBeforeDownload(
			CefRefPtr<CefBrowser> browser,CefRefPtr<CefDownloadItem> download_item,
			const CefString& suggested_name,CefRefPtr<CefBeforeDownloadCallback> callback
		) override;
		virtual void OnDownloadUpdated(CefRefPtr<CefBrowser> browser,CefRefPtr<CefDownloadItem> download_item,CefRefPtr<CefDownloadItemCallback> callback);
		void SetDownloadLocation(std::string location);
		void SetCompleteCallback(const std::function<void(const std::string&)> &completeCallback);
		IMPLEMENT_REFCOUNTING(WebDownloadHandler);
	private:
		std::string m_downloadLocation;
		std::function<void(const std::string&)> m_completeCallback = nullptr;
	};
};

#endif
