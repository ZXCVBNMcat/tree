#include<iostream>

#include<queue>
#include<cmath>
using namespace std;
template<typename T>

class AvlTree
{
public:
	AvlTree():_root(nullptr)
	{ }
	~AvlTree()
	{
		if (_root != nullptr)
		{
			queue<Node*>q;
			q.push(_root);
			while (!q.empty())
			{
				Node* front = q.front();
				q.pop();

				if (front->_left != nullptr)
				{
					q.push(front->_left);
				}

				if (front->_right != nullptr)
				{
					q.push(front->_right);
				}
				delete front;
			}
		}
	}
	//插入操作
	void inserter(T val)
	{
		_root = inserter(_root, val);
		//printf("%d", val);
	}
	//删除操作
	void remove(T val)
	{
		_root = remove(_root, val);
	}
private:
	struct Node
	{
		Node(T data = T())
			:_data(data)
			,_right(nullptr)
			,_left(nullptr)
			,_height(1)
		{};
		T _data;
		Node* _left;
		Node* _right;
		int _height;
	};
	//左旋
	Node* leftRotate(Node* node)
	{
		//节点旋转
		Node* child = node->_right;
		node->_right = child->_left;
		child->_left = node;
		//跟新高度
		node->_height = max(heightTree(node->_left), heightTree(node->_right)) + 1;
		child->_height = max(heightTree(child->_left), heightTree(child->_right)) + 1;
		//返回新的子树根节点
		return child;
	}
	//返回高度
	int heightTree(Node* node)
	{
		return node == nullptr ? 0 : node->_height;
	}
	//右旋
	Node* rightRotate(Node* node)
	{
		//节点旋转
		Node* child = node->_left;
		node->_left = child->_right;
		child->_right = node;
		//跟新高度
		node->_height = max(heightTree(node->_left), heightTree(node->_right)) + 1;
		child->_height = max(heightTree(child->_left), heightTree(child->_right)) + 1;
		//返回新的子树根节点
		return child;
	}
	//左平衡
	Node* leftBalanc(Node* node)
	{
		node->_left = leftRotate(node->_left);
		return rightRotate(node);
	}
	//右平衡
	Node* rightBalanc(Node* node)
	{
		node->_right = rightRotate(node->_right);
		return leftRotate(node);
	}
	//插入的实现
	Node* inserter(Node* tree, T val)
	{
		if (tree == nullptr)
		{
			tree = new Node(val);
			tree->_height = max(heightTree(tree->_left), heightTree(tree->_right)) + 1;
			return tree;
		}
		if (tree->_data > val)
		{
			tree->_left = inserter(tree->_left, val);
			if (heightTree(tree->_left) - heightTree(tree->_right) > 1)
			{
				if (heightTree(tree->_left->_left) >= heightTree(tree->_left->_right))
				{
					tree = rightRotate(tree);
				}
				else
				{
					tree = leftBalanc(tree);
				}
			}
		}
		else if(tree->_data < val)
		{
			tree->_right = inserter(tree->_right, val);
			if (heightTree(tree->_right) - heightTree(tree->_left) > 1)
			{
				if (heightTree(tree->_right->_right) >= heightTree(tree->_right->_left))
				{
					tree = leftRotate(tree);
				}
				else
				{
					tree = rightBalanc(tree);
				}
			}
		}
		else
		{
			;
		}
		tree->_height = max(heightTree(tree->_left), heightTree(tree->_right)) + 1;
		return tree;
		//return nullptr;
	}
	//删除操作
	Node* remove(Node* tree, T val)
	{
		if (tree == nullptr)
		{
			return nullptr;
		}
		if (tree->_data < val)
		{
			tree->_right = remove(tree->_right, val);
			if (heightTree(tree->_left) - heightTree(tree->_right) > 1)
			{
				if (heightTree(tree->_right->_right) > heightTree(tree->_right->_left))
				{
					tree = leftRotate(tree);
				}
				else
				{
					tree = rightBalanc(tree);
				}
			}
		}
		else if (tree->_data > val)
		{
			tree->_left = remove(tree->_left, val);
			if (heightTree(tree->_right) - heightTree(tree->_left) > 1)
			{
				if (heightTree(tree->_left->_left) > heightTree(tree->_left->_right))
				{
					tree = rightRotate(tree);
				}
				else
				{
					tree = leftBalanc(tree);
				}
			}
		}
		else
		{
			if (tree->_left != nullptr && tree->_right != nullptr)
			{
				if (heightTree(tree->_left) > heightTree(tree->_right))
				{
					//前驱 左子树大
					Node* pre = tree->_left;
					while (pre->_right != nullptr)
					{
						pre = pre->_right;
					}
					tree->_data = pre->_data;
					tree->_left = remove(tree->_left, pre->_data);
				}
				else
				{
					//后继 右子树大
					Node* pre = tree->_right;
					while (pre->_left != nullptr)
					{
						pre = pre->_left;
					}
					tree->_data = pre->_data;
					tree->_right = remove(tree->_right, pre->_data);
				}
			}
			else if (tree->_left != nullptr)
			{
				//左节点
				Node* left = tree->_left;
				delete tree;
				return left;
			}
			else if (tree->_right != nullptr)
			{
				//右节点
				Node* right = tree->_right;
				delete tree;
				return right;
			}
			else
			{
				//是叶子节点
				delete tree;
				return nullptr;
			}
		}
		tree->_height = max(heightTree(tree->_left), heightTree(tree->_right)) + 1;
		return tree;
	}

	Node* _root;
};

int main()
{
	AvlTree<int> a;
	for (int i = 1; i < 11; ++i)
	{
		a.inserter(i);
	}
	a.remove(9);
	a.remove(10);
	a.remove(6);
	a.remove(1);
	a.remove(2);
	a.remove(3);

	return 0;
}