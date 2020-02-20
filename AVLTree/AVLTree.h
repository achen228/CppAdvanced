#pragma once
#include <iostream>
using namespace std;

template<class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& data)
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _bf(0)
	{}
	AVLTreeNode<T>* _pLeft;
	AVLTreeNode<T>* _pRight;
	AVLTreeNode<T>* _pParent;
	T _data;
	int _bf; // 该节点的平衡因子
};

// AVL:二叉搜索树 + 平衡因子
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		:_pRoot(nullptr)
	{}

	Node* Find(const T& data)
	{
		Node *pCur = _pRoot;
		while (pCur)
		{
			if (pCur->_data == data)
				return pCur;
			else if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight;
		}
		return nullptr;
	}

	bool Insert(const T& data)
	{
		// 1.按照二叉搜索树的规则插入新结点
		if (nullptr == _pRoot)
		{
			_pRoot = new Node(data);
			return true;
		}

		// 按照二叉搜索树的规则找待插入结点在AVLTree中的位置
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

		// 插入新结点
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;

		pCur->_pParent = pParent;

		// 2.更新pParent的平衡因子
		while (pParent)
		{
			if (pCur == pParent->_pLeft)
				pParent->_bf--;
			else
				pParent->_bf++;

			if (pParent->_bf == 0)
				return true;
			else if (pParent->_bf == -1 || pParent->_bf == 1)
			{
				pCur = pParent;
				pParent = pCur->_pParent;
			}
			else
			{
				// 说明双亲结点已经不满足AVLTree的性质了
				// 对以双亲为根的二叉树进行旋转处理
				if (pParent->_bf == 2)
				{
					// 右子树高-->左单旋
					if (pCur->_bf == 1)
						RotateLeft(pParent);
					else
						RotateRL(pParent);
				}
				else
				{
					// 左子树高-->右单旋
					if (pCur->_bf == -1)
						RotateRight(pParent);
					else
						RotateLR(pParent);
				}

				break;
			}
		}

		return true;
	}

	void InOrder()
	{
		_InOrder(_pRoot);
	}

private:
	void RotateRight(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;

		pParent->_pLeft = pSubLR;
		if (pSubLR)
			pSubLR->_pParent = pParent;
		pSubL->_pRight = pParent;

		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubL;
		pSubL->_pParent = pPParent;

		if (pPParent == nullptr)
			_pRoot = pSubL;
		else
		{
			if (pParent == pPParent->_pLeft)
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}	
		pParent->_bf = pSubL->_bf = 0;
	}

	void RotateLeft(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
			pSubRL->_pParent = pParent;

		pSubR->_pLeft = pParent;
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubR;
		pSubR->_pParent = pPParent;

		if (pPParent == nullptr)
			_pRoot = pSubR;
		else
		{
			if (pPParent->_pLeft == pParent)
				pPParent->_pLeft = pSubR;
			else
				pPParent->_pRight = pSubR;
		}
		pParent->_bf = pSubR->_bf = 0;
	}

	void RotateLR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;
		int bf = pSubLR->_bf;

		RotateLeft(pSubL);
		RotateRight(pParent);

		if (bf == -1)
			pParent->_bf = 1;
		else if(bf == 1)
			pSubL->_bf = -1;
	}

	void RotateRL(Node* pParent)
	{
		Node* pSubL = pParent->_pRight;
		Node* pSubLR = pSubL->_pLeft;
		int bf = pSubLR->_bf;

		RotateRight(pParent);
		RotateLeft(pSubL);

		if (bf == -1)
			pParent->_bf = 1;
		else if (bf == 1)
			pSubL->_bf = -1;
	}

	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}

private:
	Node* _pRoot;
};
