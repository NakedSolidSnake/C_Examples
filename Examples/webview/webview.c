/*

sudo apt-get install webkit2gtk-4.0

*/

#include "webview.h"
#ifdef WIN32
int WINAPI WinMain(HINSTANCE hInt, HINSTANCE hPrevInst, LPSTR lpCmdLine,
                   int nCmdShow) {
#else
int main() {
#endif
	webview_t w = webview_create(0, NULL);
	webview_set_title(w, "Webview Example");
	webview_set_size(w, 480, 320, WEBVIEW_HINT_NONE);
	webview_navigate(w, "https://en.m.wikipedia.org/wiki/Main_Page");
	webview_run(w);
	webview_destroy(w);
	return 0;
}