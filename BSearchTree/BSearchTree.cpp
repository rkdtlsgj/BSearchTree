#include "BSearchTree.h"
#include <stdio.h>

BSearchTree::BSearchTree()
{
	m_iNodeCount = 0;
	m_pRoot = NULL;
}

BSearchTree::~BSearchTree()
{
	Clear();
}

bool BSearchTree::InsertNode(int iData)
{
	st_NODE* pNewNode = new st_NODE;

	pNewNode->iData = iData;
	pNewNode->stp_Left = NULL;
	pNewNode->stp_Right = NULL;

	if (m_pRoot == NULL)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		linkNode(m_pRoot, pNewNode);
	}

	return true;
}

void BSearchTree::DeleteNode(int iData)
{
	if (m_pRoot != NULL)
	{
		deleteNode(m_pRoot, m_pRoot,iData);
	}
}

void BSearchTree::Clear()
{
	if (m_pRoot != NULL)
	{
		printf("\n");
		clear(m_pRoot);
	}
}


void BSearchTree::PreorderPrint()
{
	if (m_pRoot != NULL)
		preorderPrint(m_pRoot);
}

void BSearchTree::InorderPirnt()
{
	if(m_pRoot != NULL)
		inorderPirnt(m_pRoot);
}

void BSearchTree::PostorderPrint()
{
	if (m_pRoot != NULL)
		postorderPrint(m_pRoot);
}


void BSearchTree::inorderPirnt(st_NODE* node)
{
	if (node != NULL)
	{
		inorderPirnt(node->stp_Left);
		printf("%d ", node->iData);
		inorderPirnt(node->stp_Right);
	}
}

void BSearchTree::postorderPrint(st_NODE* node)
{
	if (node != NULL)
	{
		postorderPrint(node->stp_Left);		
		postorderPrint(node->stp_Right);
		printf("%d ", node->iData);
	}
}

void BSearchTree::preorderPrint(st_NODE* node)
{
	if (node != NULL)
	{
		printf("%d ", node->iData);
		preorderPrint(node->stp_Left);
		preorderPrint(node->stp_Right);		
	}
}


st_NODE* BSearchTree::findNode(st_NODE* pNode, int iData)
{
	if (pNode == NULL) 
		return NULL;

	if (pNode->iData > iData)
		return findNode(pNode->stp_Left, iData);
	else if (pNode->iData > iData)
		return findNode(pNode->stp_Right, iData);
	else
		return pNode;
	
}
void BSearchTree::clear(st_NODE* pNode)
{
	if (pNode->stp_Left != NULL)
		clear(pNode->stp_Left);

	if(pNode->stp_Right != NULL)
		clear(pNode->stp_Right);

	printf("%d delete\n", pNode->iData);

	delete pNode;
}
bool BSearchTree::linkNode(st_NODE* pParent, st_NODE* pChild)
{
	if (pParent->iData > pChild->iData)
	{
		if (pParent->stp_Left == NULL)
		{
			pParent->stp_Left = pChild;
			return true;
		}
		else
		{
			linkNode(pParent->stp_Left, pChild);
		}
	}
	else if (pParent->iData < pChild->iData)
	{
		if (pParent->stp_Right == NULL)
		{
			pParent->stp_Right = pChild;
			return true;
		}
		else
		{
			linkNode(pParent->stp_Right, pChild);
		}
	}

	return false;
}

void BSearchTree::deleteNode(st_NODE* pNode, st_NODE* pParent, int iData)
{
	if (pNode->iData < iData)
	{
		deleteNode(pNode->stp_Right, pNode, iData);
	}
	else if (pNode->iData > iData)
	{
		deleteNode(pNode->stp_Left, pNode, iData);
	}
	else
	{
		//값은 찾았고 3개자의 경우를 확인해봐야함

		//자식이 아무도 없을때
		if (pNode->stp_Left == NULL && pNode->stp_Right == NULL)
		{
			if (pParent->stp_Left == pNode)
				pParent->stp_Left = NULL;
			else
				pParent->stp_Right = NULL;

			printf("%d delete\n", pNode->iData);
			delete pNode;
		}
		//자식이 둘다 있을때
		//자기 자리를 대체할 기준
		//자기보다 작은값중 큰 값 (O)
		//자기보다 큰값중 작은 값
		else if(pNode->stp_Left != NULL && pNode->stp_Right != NULL)
		{
			st_NODE* tempNode = findDeleteNode(pNode->stp_Left, pNode);

			printf("%d delete\n", pNode->iData);

			pNode->iData = tempNode->iData;
			
			delete tempNode;
		}
		//자식이 하나만 있을때
		else
		{			
			if (pNode->stp_Left != NULL)
			{
				if(pParent->stp_Left == pNode)
				{
					pParent->stp_Left = pNode->stp_Left;
				}
				else
				{
					pParent->stp_Right = pNode->stp_Left;
				}
			}
			else
			{
				if (pParent->stp_Left == pNode)
				{
					pParent->stp_Left = pNode->stp_Right;
				}
				else
				{
					pParent->stp_Right = pNode->stp_Right;
				}
			}

			printf("%d delete\n", pNode->iData);
			delete pNode;
		}

		
	}
}

st_NODE* BSearchTree::findDeleteNode(st_NODE* pNode, st_NODE* pParent)
{
	if (pNode->stp_Right == NULL)
	{
		pParent->stp_Right = NULL;
		return pNode;
	}

	return findDeleteNode(pNode->stp_Right, pNode);
}