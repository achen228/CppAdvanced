#pragma once
#include <iostream>
using namespace std;

template<class T>
struct BSTreeNode
{ 
	BSTreeNode(const T& data = T())
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _data(data)
	{}
	BSTreeNode<T>* _pLeft;
	BSTreeNode<T>* _pRight;
	T _data;
};

template<class T>
class BSTree
{
	typedef BSTreeNode<T> Node;
public:
	BSTree()
		: _pRoot(nullptr)
	{}

	~BSTree()
	{
		_Destroy(_pRoot);
	}

	Node* Find(const T& data)
	{
		Node* pCur = _pRoot;
		while (pCur)
		{
			if (data == pCur->_data)
				return pCur;
			else if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else
				pCur = pCur->_pRight;
		}
		return nullptr;
	}

	bool Insert(const T& data)
	{
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}

		// 非空
		// 找当前结点在二叉搜索树中的位置
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight;
			else
				return false;
		}

		// 插入结点
		pCur = new Node(data);
		if (data < pParent->_data)
		{
			pParent->_pLeft = pCur;
		}
		else
		{
			pParent->_pRight = pCur;
		}

		return true;
	}

	bool Erase(const T& data)
	{
		// 找data在二叉搜索树中的位置
		Node* pCur = _pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			if (data < pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pLeft;
			}
			else if (data > pCur->_data)
			{
				pParent = pCur;
				pCur = pCur->_pRight;
			}
			else
				break;
		}

		if (nullptr == pCur)
			return false;

		// 删除结点
		//	可以直接删除-->叶子结点(没有孩子)、结点只有左孩子、结点只有右孩子
		//	不能直接删除-->左右孩子均存在
		if (nullptr == pCur->_pRight)
		{
			// ***pCur 没有孩子 || 只有左孩子

			if (nullptr == pParent)
			{
				// pCur的双亲不存在即pCur为根结点
				_pRoot = pCur->_pLeft;
			}
			else
			{
				if (pCur == pParent->_pLeft)
				{
					// pCur的双亲存在且pCur为其双亲的左孩子
					pParent->_pLeft = pCur->_pLeft;
				}
				else
				{
					// pCur的双亲存在且pCur为其双亲的右孩子
					pParent->_pRight = pCur->_pLeft;
				}
			}
			delete pCur;
		}
		else if (nullptr == pCur->_pLeft)
		{
			// ***pCur 只有右孩子

			if (nullptr == pParent)
			{		
				// pCur的双亲不存在即pCur为根结点
				_pRoot = pCur->_pRight;
			}
			else
			{
				if (pCur == pParent->_pLeft)
				{
					// pCur的双亲存在且pCur为其双亲的左孩子
					pParent->_pLeft = pCur->_pRight;
				}
				else
				{
					// pCur的双亲存在且pCur为其双亲的右孩子
					pParent->_pRight = pCur->_pRight;
				}
			}
			delete pCur;
		}
		else
		{
			// ***pCur 左右孩子均存在
			// 找替代结点
			//	左子树找最大（最右侧）结点 || 右子树找最小（最左侧）结点
			// 将替代结点中的值-->待删除结点
			// 将问题转换为删除替代结点

			// 右子树找最小（最左侧）结点
			Node* pDel = pCur->_pRight;
			pParent = pCur;
			while (pDel->_pLeft)
			{
				pParent = pDel;
				pDel = pDel->_pLeft;
			}
			// 将替代结点中的值域赋值给非待删除结点
			pCur->_data = pDel->_data;

			if (pDel == pParent->_pLeft)
			{
				pParent->_pLeft = pDel->_pRight;
			}
			else
			{
				pParent->_pRight = pDel->_pRight;
			}
			delete pDel;
		}
		
		return true;
	}

	void InOrder()
	{
		_InOrder(_pRoot);
	}
private:
	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}

	void _Destroy(Node*& pRoot)
	{
		if (pRoot)
		{
			_Destroy(pRoot->_pLeft);
			_Destroy(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}
private:
	Node* _pRoot;
};


// ***将二叉搜索树转换为排序的双向链表
//void _BSTreeTwoDList(Node* pRoot, Node*& prev)
//{
//	if (nullptr == pRoot)
//	{
//		return;
//	}
//
//	_BSTreeTwoDList(pRoot->_pLeft, prev);
//	pRoot->_pLeft = prev;
//	if (prev)
//	{
//		prev->_pRight = pRoot;
//	}
//	prev = pRoot;
//	_BSTreeTwoDList(pRoot->_pRight, prev);
//}
//
//Node* BSTreeTwoDList(Node* pRoot)
//{
//	if (nullptr == pRoot)
//	{
//		return nullptr;
//	}
//	// 获取链表的第一个结点
//	Node* pHead = pRoot;
//	while (pHead->_Left)
//	{
//		pHead = pHead->_pLeft;
//	}
//
//	Node* prev = nullptr; // 保存刚刚遍历过的结点
//	_BSTreeTwoDList(pRoot，prev);
//	return pHead;
//}
