#include <afxwin.h>
class CMainFrame : public CFrameWnd {
public:
    CMainFrame();
protected:
    afx_msg
        void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
    int OnCreate(LPCREATESTRUCT lpCreateStruct);
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
    ON_WM_KEYDOWN()
    ON_WM_LBUTTONDOWN()
    ON_WM_RBUTTONUP()
END_MESSAGE_MAP()
void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
    switch (nChar) {

    case VK_RETURN:
        MessageBox(L"You pressed Enter");
        break;
    case VK_F1:
        MessageBox(L"Help is not available at the moment");
        break;
    case VK_DELETE:
        MessageBox(L"Can't Delete This");
        break;
    default:
        MessageBox(L"Whatever");
    }
}
void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point) {
    CString MsgCoord;
    MsgCoord.Format(L"Left Button at P(%d, %d)", point.x, point.y);
    MessageBox(MsgCoord);
}
void CMainFrame::OnRButtonUp(UINT nFlags, CPoint point) {
    MessageBox(L"Right Mouse Button Up");
}
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