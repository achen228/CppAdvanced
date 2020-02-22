#pragma once
#include <iostream>
using namespace std;

enum COLOR{RED, BLACK};

template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data = T(), COLOR color = RED)
		: _pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _data(data)
		, _color(color = RED)
	{}
	RBTreeNode<T>* _pLeft;
	RBTreeNode<T>* _pRight;
	RBTreeNode<T>* _pParent;
	T _data;
	COLOR _color;
};

template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		_pHead = new Node;
		_pHead->_pParent = nullptr;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}

	bool Insert(const T& data)
	{
		// 先按照BSTree的方式插入新结点
		Node*& pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
			_pHead->_pLeft = pRoot;
			_pHead->_pRight = pRoot;
			return true;
		}

		// 按照BSTree的规则找待插入结点在RBTree中的位置
		Node* pCur = pRoot;
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

		// 检测是否满足RBTree的性质-->不能有连在一起的红色结点
		// pParent结点的颜色是红色
		while (pParent != _pHead && RED == pParent->_color)
		{
			Node* grandFather = pParent->_pParent;
			// 所有左侧情况（pParent为grandFather的左孩子）
			if (pParent == grandFather->_pLeft)
			{
				Node* uncle = grandFather->_pRight;
				// 情况一：叔叔结点存在且为红
				if (uncle && RED == uncle->_color)
				{
					pParent->_color = BLACK;
					uncle->_color = BLACK;
					grandFather->_color = RED;

					pCur = grandFather;
					pParent = pCur->_pParent;
				}
				else
				{
					// 叔叔结点不存在 || 叔叔结点存在且为黑色
					// 先处理情况三（pCur是pParent的右孩子）,转换为情况二处理
					if (pCur == pParent->_pRight)
					{
						RotateLeft(pParent);
						swap(pParent, pCur);
					}

					// 情况二（pCur是pParent的左孩子）
					pParent->_color = BLACK;
					grandFather->_color = RED;
					RotateRight(grandFather);
				}
			}
			// 所有右侧情况（pParent为grandFather的右孩子）
			else
			{
				Node* uncle = grandFather->_pLeft;
				// 情况一：叔叔结点存在且为红
				if (uncle && RED == uncle->_color)
				{
					pParent->_color = BLACK;
					uncle->_color = BLACK;
					grandFather->_color = RED;

					pCur = grandFather;
					pParent = pCur->_pParent;
				}
				else
				{
					// 叔叔结点不存在 || 叔叔结点存在且为黑色
					// 先处理情况三（pCur是pParent的左孩子）,转换为情况二处理
					if (pCur == pParent->_pLeft)
					{
						RotateRight(pParent);
						swap(pParent, pCur);
					}

					// 情况二（pCur是pParent的右孩子）
					pParent->_color = BLACK;
					grandFather->_color = RED;
					RotateLeft(grandFather);
				}
			}
		}

		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();

		return true;
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

		if (pPParent == _pHead)
		{
			_pHead->_pParent = pSubR;
		}
		else
		{
			if (pPParent->_pLeft == pParent)
				pPParent->_pLeft = pSubR;
			else
				pPParent->_pRight = pSubR;
		}
	}

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

		if (pPParent == _pHead)
		{
			_pHead->_pParent = pSubL;
		}
		else
		{
			if (pParent == pPParent->_pLeft)
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}
	}

	void InOrder()
	{
		_InOrder(GetRoot());
	}

	bool IsValidRBTree()
	{
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
			return true;

		if (pRoot->_color != BLACK)
		{
			cout << "违反RBTree性质2:根结点不是黑色" << endl;
			return false;
		}

		// 获取一条路径中黑色结点的个数
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (pCur->_color == BLACK)
				blackCount++;

			pCur = pCur->_pLeft;
		}

		size_t pathCount = 0;
		return _IsValidRBTree(pRoot, blackCount, pathCount);
	}
private:
	bool _IsValidRBTree(Node* pRoot, size_t blackCount, size_t pathCount)
	{
		if (nullptr == pRoot)
			return true;

		if(pRoot->_color == BLACK)
			++pathCount;

		// 验证性质3
		Node* pParent = pRoot->_pParent;
		if (pParent != _pHead && pParent->_color == RED && pRoot->_color == RED)
		{
			cout << "违反RBTree性质3:存在连在一起的红色结点" << endl;
			return false;
		}

		if (nullptr == pRoot->_pLeft && nullptr == pRoot->_pRight)
		{
			// 验证性质4
			if (blackCount != pathCount)
			{
				cout << "违反RBTree性质4:路径中黑色结点个数不相同" << endl;
				return false;
			}
		}

		return _IsValidRBTree(pRoot->_pLeft, blackCount, pathCount)
			&& _IsValidRBTree(pRoot->_pRight, blackCount, pathCount);
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

	Node*& GetRoot()
	{
		return _pHead->_pParent;
	}

	Node* LeftMost()
	{
		Node* pCur = GetRoot();
		if (pCur == nullptr)
			return _pHead;

		while (pCur->_pLeft)
			pCur = pCur->_pLeft;

		return pCur;
	}

	Node* RightMost()
	{
		Node* pCur = GetRoot();
		if (pCur == nullptr)
			return _pHead;

		while (pCur->_pRight)
			pCur = pCur->_pRight;

		return pCur;
	}
private:
	Node* _pHead;
};
