
#include <include/cef_app.h>

// See https://bitbucket.org/chromiumembedded/cef/wiki/GeneralUsage#markdown-header-separate-sub-process-executable


#ifdef __linux__
#define DLL_PR_CHROMIUM __attribute__((visibility("default")))
#else
#define DLL_PR_CHROMIUM __declspec(dllexport)
#endif

extern "C"
{
	DLL_PR_CHROMIUM bool pr_chromium_subprocess();
};

int main(int argc,char *argv[])
{
	return pr_chromium_subprocess() ? EXIT_SUCCESS : EXIT_FAILURE;
}
