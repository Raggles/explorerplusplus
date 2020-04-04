// Copyright (C) Explorer++ Project
// SPDX-License-Identifier: GPL-3.0-only
// See LICENSE in the top level directory

#pragma once

#include <functional>

class FileProgressSink : public IFileOperationProgressSink
{
public:

	static FileProgressSink *CreateNew();

	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject) override;
	ULONG STDMETHODCALLTYPE AddRef() override;
	ULONG STDMETHODCALLTYPE Release() override;

	void SetPostNewItemObserver(std::function<void(PIDLIST_ABSOLUTE)> f);

	HRESULT STDMETHODCALLTYPE StartOperations() override;
	HRESULT STDMETHODCALLTYPE FinishOperations(HRESULT hrResult) override;
	HRESULT STDMETHODCALLTYPE PreRenameItem(DWORD dwFlags, IShellItem *psiItem, LPCWSTR pszNewName) override;
	HRESULT STDMETHODCALLTYPE PostRenameItem(DWORD dwFlags, IShellItem *psiItem, LPCWSTR pszNewName, HRESULT hrRename, IShellItem *psiNewlyCreated) override;
	HRESULT STDMETHODCALLTYPE PreMoveItem(DWORD dwFlags, IShellItem *psiItem, IShellItem *psiDestinationFolder, LPCWSTR pszNewName) override;
	HRESULT STDMETHODCALLTYPE PostMoveItem(DWORD dwFlags, IShellItem *psiItem, IShellItem *psiDestinationFolder, LPCWSTR pszNewName, HRESULT hrMove, IShellItem *psiNewlyCreated) override;
	HRESULT STDMETHODCALLTYPE PreCopyItem(DWORD dwFlags, IShellItem *psiItem, IShellItem *psiDestinationFolder, LPCWSTR pszNewName) override;
	HRESULT STDMETHODCALLTYPE PostCopyItem(DWORD dwFlags, IShellItem *psiItem, IShellItem *psiDestinationFolder, LPCWSTR pszNewName, HRESULT hrCopy, IShellItem *psiNewlyCreated) override;
	HRESULT STDMETHODCALLTYPE PreDeleteItem(DWORD dwFlags, IShellItem *psiItem) override;
	HRESULT STDMETHODCALLTYPE PostDeleteItem(DWORD dwFlags, IShellItem *psiItem, HRESULT hrDelete, IShellItem *psiNewlyCreated) override;
	HRESULT STDMETHODCALLTYPE PreNewItem(DWORD dwFlags, IShellItem *psiDestinationFolder, LPCWSTR pszNewName) override;
	HRESULT STDMETHODCALLTYPE PostNewItem(DWORD dwFlags, IShellItem *psiDestinationFolder, LPCWSTR pszNewName, LPCWSTR pszTemplateName, DWORD dwFileAttributes, HRESULT hrNew, IShellItem *psiNewItem) override;
	HRESULT STDMETHODCALLTYPE UpdateProgress(UINT iWorkTotal, UINT iWorkSoFar) override;
	HRESULT STDMETHODCALLTYPE ResetTimer() override;
	HRESULT STDMETHODCALLTYPE PauseTimer() override;
	HRESULT STDMETHODCALLTYPE ResumeTimer() override;

private:

	FileProgressSink();
	virtual ~FileProgressSink() = default;

	ULONG m_refCount;

	std::function<void(PIDLIST_ABSOLUTE)> m_postNewItemObserver;
};