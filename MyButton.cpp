#include "pch.h"
#include "MyButton.h"
#include "ChangeIcon.h"


BEGIN_MESSAGE_MAP(MyButton, CBitmapButton)
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSELEAVE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

void MyButton::Init(CString typeName) {

	if (typeName == _T("close_button")) 
	{
		this->LoadBitmaps(IDB_BITMAP2, NULL, NULL, NULL);
		this->SizeToContent();
		close_button = this->GetDlgCtrlID();
	}
	else if (typeName == _T("full_button")) {

		this->LoadBitmaps(IDB_BITMAP3, IDB_BITMAP5, IDB_BITMAP5, NULL);
		this->SizeToContent();
		this->isMini = TRUE;
		full_button = this->GetDlgCtrlID();
	}
	else if (typeName == _T("hide_button")) {
		this->LoadBitmaps(IDB_BITMAP6, IDB_BITMAP7, NULL, NULL);
		this->SizeToContent();
		hide_button = this->GetDlgCtrlID();
	}
}
void MyButton::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int id = this->GetDlgCtrlID();
	if (id == close_button) {
		this->LoadBitmaps(IDB_BITMAP1, NULL, NULL, NULL);
		this->SizeToContent();
	}
	else if (id == full_button) {
		if (this->isMini) {
			this->LoadBitmaps(IDB_BITMAP4, NULL, NULL, NULL);
			this->SizeToContent();

		}
		else {
			this->LoadBitmaps(IDB_BITMAP8, NULL, NULL, NULL);
			this->SizeToContent();

		}
	}
	else if (id == hide_button) {
		this->LoadBitmaps(IDB_BITMAP7, NULL, NULL, NULL);
		this->SizeToContent();
	}
	
	Invalidate();
	CBitmapButton::OnMouseHover(nFlags, point);
}


void MyButton::OnMouseLeave()
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int id = this->GetDlgCtrlID();
	if (id == close_button) {
		this->LoadBitmaps(IDB_BITMAP2, NULL, NULL, NULL);
		this->SizeToContent();
	}
	else if (id == full_button) {
		if (this->isMini) {
			this->LoadBitmaps(IDB_BITMAP3, NULL, NULL, NULL);
			this->SizeToContent();
		}
		else {
			this->LoadBitmaps(IDB_BITMAP5, NULL, NULL, NULL);
			this->SizeToContent();
		}
	}
	else if (id == hide_button) {
		this->LoadBitmaps(IDB_BITMAP6, IDB_BITMAP7, NULL, NULL);
		this->SizeToContent();
	}
	m_bCursorOnButton = FALSE;
	Invalidate();
	CBitmapButton::OnMouseLeave();
}


void MyButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_bCursorOnButton == FALSE)
	{
		TRACKMOUSEEVENT tme;
		ZeroMemory(&tme, sizeof(TRACKMOUSEEVENT));
		tme.cbSize = sizeof(tme);
		tme.hwndTrack = m_hWnd;
		tme.dwFlags = TME_LEAVE | TME_HOVER;
		tme.dwHoverTime = 1;
		m_bCursorOnButton = _TrackMouseEvent(&tme);
	}
	CBitmapButton::OnMouseMove(nFlags, point);
}
