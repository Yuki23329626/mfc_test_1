
// 2018W_P_FinalExamDoc.h : CMy2018W_P_FinalExamDoc ���O������
//


#pragma once


class CMy2018W_P_FinalExamDoc : public CDocument
{
protected: // �ȱq�ǦC�ƫإ�
	CMy2018W_P_FinalExamDoc();
	DECLARE_DYNCREATE(CMy2018W_P_FinalExamDoc)

// �ݩ�
public:
   
// �@�~
public:

// �мg
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �{���X��@
public:
	virtual ~CMy2018W_P_FinalExamDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ͪ��T�������禡
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ���j�M�B�z�`���]�w�j�M���e�� Helper �禡
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL CanCloseFrame(CFrameWnd* pFrame);
};
