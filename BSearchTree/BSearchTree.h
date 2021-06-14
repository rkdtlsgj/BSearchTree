#pragma once

struct st_NODE
{
	st_NODE* stp_Left;
	st_NODE* stp_Right;
	int iData;
};

class BSearchTree
{

public:
	BSearchTree();
	~BSearchTree();

	bool InsertNode(int iData);
	void DeleteNode(int iData);
	void Clear();

	void PreorderPrint();	//전위 순회
	void InorderPirnt();	//중위 순회
	void PostorderPrint();	//후위 순회
	

private:
	void preorderPrint(st_NODE* node);
	void inorderPirnt(st_NODE* node);
	void postorderPrint(st_NODE* node);

	void clear(st_NODE* pNode);
	bool linkNode(st_NODE* pParent, st_NODE* pChild);
	st_NODE* findNode(st_NODE* pNode, int iData);
	void deleteNode(st_NODE* pNode, st_NODE * pParent,int iData);
	st_NODE* findDeleteNode(st_NODE* pNode, st_NODE* pParent);

	st_NODE* m_pRoot;
	int m_iNodeCount;
};