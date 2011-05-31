#ifndef ADDBOOKMARKDIALOG_INCLUDED
#define ADDBOOKMARKDIALOG_INCLUDED

#include <set>
#include "../Helper/BaseDialog.h"
#include "../Helper/ResizableDialog.h"
#include "../Helper/DialogSettings.h"
#include "../Helper/Bookmark.h"

class CAddBookmarkDialog;

class CAddBookmarkDialogPersistentSettings : public CDialogSettings
{
public:

	~CAddBookmarkDialogPersistentSettings();

	static CAddBookmarkDialogPersistentSettings &GetInstance();

private:

	friend CAddBookmarkDialog;

	static const TCHAR SETTINGS_KEY[];

	CAddBookmarkDialogPersistentSettings();

	CAddBookmarkDialogPersistentSettings(const CAddBookmarkDialogPersistentSettings &);
	CAddBookmarkDialogPersistentSettings & operator=(const CAddBookmarkDialogPersistentSettings &);

	UINT			m_uIDSelected;
	std::set<UINT>	m_setExpansion;
};

class CAddBookmarkDialog : public CBaseDialog
{
public:

	CAddBookmarkDialog(HINSTANCE hInstance,int iResource,HWND hParent,CBookmarkFolder *pAllBookmarks,CBookmark *pBookmark);
	~CAddBookmarkDialog();

	LRESULT CALLBACK	TreeViewEditProc(HWND hwnd,UINT Msg,WPARAM wParam,LPARAM lParam);

protected:

	BOOL	OnInitDialog();
	BOOL	OnCommand(WPARAM wParam,LPARAM lParam);
	BOOL	OnNotify(NMHDR *pnmhdr);
	BOOL	OnClose();
	BOOL	OnDestroy();

	void	SaveState();

	void	GetResizableControlInformation(CBaseDialog::DialogSizeConstraint &dsc,std::list<CResizableDialog::Control_t> &ControlList);

private:

	void		SetDialogIcon();

	void		OnRClick(NMHDR *pnmhdr);
	void		OnNewFolder();

	void		OnTvnBeginLabelEdit();
	BOOL		OnTvnEndLabelEdit(NMTVDISPINFO *pnmtvdi);
	void		OnTvnKeyDown(NMTVKEYDOWN *pnmtvkd);

	void		OnTreeViewRename();

	void		OnOk();
	void		OnCancel();

	void		SaveTreeViewState();
	void		SaveTreeViewExpansionState(HWND hTreeView,HTREEITEM hItem);

	HICON			m_hDialogIcon;

	CBookmarkFolder	*m_pAllBookmarks;
	CBookmark		*m_pBookmark;
	HIMAGELIST		m_himlTreeView;

	CAddBookmarkDialogPersistentSettings	*m_pabdps;
};

#endif