#include <afxwin.h>
class CMainFrame : public CFrameWnd {
public:
    CMainFrame();
protected:
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    DECLARE_MESSAGE_MAP()
};
CMainFrame::CMainFrame() {

    // Create the window's frame
    Create(NULL, L"MFC Messages Demo", WS_OVERLAPPEDWINDOW,
        CRect(120, 100, 700, 480), NULL);
}
class CMessagesApp : public CWinApp {
public:
    BOOL InitInstance();
};
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
    ON_WM_CREATE()
END_MESSAGE_MAP()
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) {
    // Call the base class to create the window
    if (CFrameWnd::OnCreate(lpCreateStruct) == 0) {
        // If the window was successfully created, let the user know
        MessageBox(L"The window has been created!!!");
        // Since the window was successfully created, return 0
        return 0;
    }
    // Otherwise, return -1
    return -1;
}
BOOL CMessagesApp::InitInstance() {
    m_pMainWnd = new CMainFrame;
    m_pMainWnd->ShowWindow(SW_SHOW);
    m_pMainWnd->UpdateWindow();
    return TRUE;
}
CMessagesApp theApp;