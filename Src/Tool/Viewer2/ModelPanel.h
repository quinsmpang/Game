#pragma once
#include "afxcmn.h"
#include "PanelBase.h"
#include "BoneTreeCtrl.h"


namespace graphic  {
	class cBoneNode;
}


// CModelPanel ��ȭ �����Դϴ�.
class CModelPanel : public CPanelBase
								, public common::iObserver2
{
public:
	CModelPanel(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CModelPanel();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_MODEL };

	virtual void Update(int type) override;


protected:
	void UpdateModelInfo();
	void UpdateMeshInfo();
	void UpdateMaterialInfo();
	void UpdateBoneInfo();
	void UpdateRawBoneInfo();
	string GetMeshTokenizeName(const string &name);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.


	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_MeshTree;
	CTreeCtrl m_MaterialTree;
	CTreeCtrl m_RawBoneTree;
	CBoneTreeCtrl m_BoneTree;
	CString m_FilePath;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CString m_FileName;
	afx_msg void OnBnClickedButtonShowBoneTree();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnPanelShowhideMesh();
	afx_msg void OnSelchangedMaterialTree(NMHDR *pNMHDR, LRESULT *pResult);
};