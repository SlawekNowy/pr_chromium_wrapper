#ifndef __CEFPROCESS_HPP__
#define __CEFPROCESS_HPP__

#include <include/cef_app.h>

namespace cef {
	class BrowserProcess : public CefApp {
	  public:
		BrowserProcess();
		virtual ~BrowserProcess() override;
		virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override;
		virtual void OnBeforeCommandLineProcessing(const CefString &process_type, CefRefPtr<CefCommandLine> command_line) override;
	  private:
		IMPLEMENT_REFCOUNTING(BrowserProcess);
		CefRefPtr<CefRenderProcessHandler> m_renderProcessHandler = nullptr;
	};
};

#endif
