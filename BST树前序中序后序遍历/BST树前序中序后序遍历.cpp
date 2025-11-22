#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
template<typename T,typename Comppare = less<T>>

class BstTree
{
public:
	BstTree() :root_(nullptr)
	{

	}
	~BstTree()
	{
		if (root_ != nullptr)
		{
			queue<Node*>q;
			q.push(root_);
			while (!q.empty())
			{
				Node* front = q.front();
				q.pop();

				if (front->left_ != nullptr)
				{
					q.push(front->left_);
				}

				if (front->right_ != nullptr)
				{
					q.push(front->right_);
				}
				delete front;
			}
		}
	}
	//非递归插入操作
	void n_insert(const T& val)
	{
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return;
		}
		Node* father = nullptr;
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (cur->data_ > val)
			{
				father = cur;
				cur = cur->left_;
			}
			else if (cur->data_ < val)
			{
				father = cur;
				cur = cur->right_;
			}
			else
			{
				break;
			}
		}
		if (father->data_ < val)
		{
			father->right_ = new Node(val);
		}
		else
		{
			father->left_ = new Node(val);
		}

	}
	//递归插入操作
	void insert(const T& val)
	{
		insert(nullptr,root_ , val);
	}
	//递归查询操作
	void find(const T& val)
	{
		if (find(root_, val))
		{
			cout << "找到了" << endl;
		}
		else
		{
			cout << "没找到" << endl;
		}
	}
	//非递归删除操作
	void n_remove(const T& val)
	{
		if (root_ == nullptr)
		{
			cout << "没找到" << endl;
			return;
		}
		Node* parent = nullptr;
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (cur->data_ == val)
			{
				break;
			}
			else if (come_(cur->data_, val))
			{
				parent = cur;
				cur = cur->right_;
			}
			else
			{
				parent = cur;
				cur = cur->left_;
			}
		}
		if (cur == nullptr)
		{
			cout << "没找到" << endl;
			return;
		}
		if (cur->left_ != nullptr && cur->right_ != nullptr)
		{
			Node* pre = cur->left_;
			while (pre->right_ != nullptr)
			{
				parent = pre;
				pre = pre->right_;
			}
			cur->data_ = pre->data_;
			cur = pre;
		}
		Node* child = cur->left_;
		if (child == nullptr)
		{
			child = cur->right_;
		}
		if (parent == nullptr)
		{
			cur = child;
		}
		else
		{
			if (parent->left_ == cur)
			{
				parent->left_ = child;
			}
			else
			{
				parent->right_ = child;
			}
		}
		delete(cur);
		
	}
	//递归删除操作
	void remove(const T& val)
	{
		root_ = remove(root_, val);
	}
	//用户调用接口 前序递归遍历
	void printfVLR()
	{
		cout << "前序排序：";
		printfVLR(root_);
		cout << endl;
	}
	//前序非递归遍历
	void preOrder()
	{
		preOrder(root_);
	}
	//用户调用接口 中序递归遍历
	void printfLVR()
	{
		cout << "中序排序：";
		printfLVR(root_);
		cout << endl;
	}
	//中序非递归遍历
	void inOrder()
	{
		cout << "非递归中序遍历";
		if (root_ == nullptr)
		{
			return;
		}
		stack<Node*> s;
		Node* cur = root_;
		while (cur != nullptr)
		{
			s.push(cur);
			cur = cur->left_;
		}
		while (!s.empty())
		{
			Node* top = s.top();
			s.pop();
			printf("%d\x20", top->data_);
			cur = top->right_;
			while (cur != nullptr)
			{
				s.push(cur);
				cur = cur->left_;
			}
		}
		cout << endl;
	}
	//用户调用接口 后序递归遍历
	void printfLRV()
	{
		cout << "后序排序：";
		printfLRV(root_);
		cout << endl;
	}
	//非递归后序 LRV->VRL
	void posOrder()
	{
		if (root_ == nullptr)
		{
			return;
		}
		cout << "非递归后序遍历";
		stack<Node*> s1;
		stack<Node*> s2;
		s1.push(root_);
		while (!s1.empty())
		{
			Node* top = s1.top(); 
			s1.pop(); // V

			s2.push(top);
			if (top->left_ != nullptr)
			{
				s1.push(top->left_); // L
			}
			if (top->right_ != nullptr)
			{
				s1.push(top->right_); //R
			}
		}
		while (!s2.empty())
		{
			cout << s2.top()->data_ << " ";
			s2.pop();
		}
		cout << endl;
	}
	//递归层序遍历
	void levelOrder()
	{
		int hig = high();
		for (int i = 0; i < hig; i++)
		{
			cout << "第" << i + 1 << "层";
			levelOrder(root_, i);
			cout << endl;
		}
	}
	//非递归层序遍历
	void n_levelOrder()
	{
		cout << "非递归层序遍历";
		if (root_ == nullptr)
		{
			return;
		}
		queue<Node*> q;
		q.push(root_);
		while (!q.empty())
		{
			Node* front = q.front();
			q.pop();
			cout << front->data_ << " ";
			if (front->left_ != nullptr)
			{
				q.push(front->left_);
			}
			if (front->right_ != nullptr)
			{
				q.push(front->right_);
			}
		}
		cout << endl;
	}
	//递归层数遍历
	int high()
	{
		return high(root_);
	}
	//递归个数遍历
	int number()
	{
		return number(root_);
	}
	//求满足区间的元素值[i,j]
	void findVectors(vector<T>& vec, int i, int j)
	{
		findVectors(root_, vec, i, j);
	}
	//判断是否是BSTTREE
	bool isBstTree()
	{
		Node* pre = nullptr;
		return isBstTree(root_ , pre);
	}
	bool isChildTree(BstTree<T, Comppare> child)
	{
		if (child.root_ == nullptr)
		{
			return true;
		}
		Node* cur = this->root_;
		while (cur != nullptr)
		{
			if (cur->data_ == child.root_->data_)
			{
				break;
			}
			else if (come_(cur->data_, child.root_->data_))
			{
				cur = cur->right_;
			}
			else
			{
				cur = cur->left_;
			}
		}
		if (cur == nullptr)
		{
			return false;
		}
		return isChildTree(cur, child.root_);
	}
	//公共祖先 LCA
	int getLCA(int val1, int val2)
	{
		Node* node = getLCA(root_, val1, val2);
		if (node == nullptr)
		{
			throw "no LCA";
		}
		else
		{
			return node->data_;
		}
	}
	//镜像反转
	void mirror01()
	{
		mirror01(root_);
	}
private:
	//节点定义
	struct Node
	{
		Node(T data = T())
			:data_(data)
			, left_(nullptr)
			, right_(nullptr)
		{
		}
		T data_;
		Node* left_;
		Node* right_;
	};
	//递归插入操作实现
	void insert(Node* parent, Node* tree, const T& val)
	{
		if (tree == nullptr)
		{
			if (parent == nullptr)
			{
				root_ = new Node(val);
				return;
			}
			else
			{
				if (come_(parent->data_, val))
				{
					parent->right_ = new Node(val);
					return;
				}
				else
				{
					parent->left_ = new Node(val);
					return;
				}
			}
		}
		if (tree->data_ == val)
		{
			cout << "已经有了" << endl;
			return;
		}
		if (come_(tree->data_, val))
		{
			insert(tree, tree->right_, val);
		}
		else
		{
			insert(tree, tree->left_, val);
		}
	}
	Node* insert(Node* tree, const T& val)
	{
		if (tree == nullptr)
		{
			return new Node(val);
		}
		if (tree->data_ == val)
		{
			cout << val << "已经村存在" << endl;
			return tree;
		}
		else if (come_(tree->data_, val))
		{
			tree->right_ = insert(tree->right_, val);
			return tree;
		}
		else
		{
			tree->left_ = insert(tree->left_, val);
			return tree;
		}
	}
	//递归查询操作
	bool find(Node* tree,const T& val)
	{
		if (tree == nullptr)
		{
			return false;
		}
		if (tree->data_ == val)
		{
			return true;
		}
		if (come_(tree->data_, val))
		{
			return find(tree->right_, val);
		}
		else
		{
			return find(tree->left_, val);
		}
	}
	//递归删除操作
	Node* remove(Node* tree, const T& val)
	{
		if (tree == nullptr)
		{
			return nullptr;
		}
		if (tree->data_ == val)
		{
			//两个孩子
			if (tree->left_ != nullptr && tree->right_ != nullptr)
			{
				Node* pre = tree->left_;
				while (pre != nullptr)
				{
					pre = pre->right_;
				}
				tree->data_ = pre->data_;
				//通过递归删除前驱节点
				tree->left_ = remove(tree->left_, pre->data_);
			}
			else if (tree->left_ != nullptr) //只有一个孩子
			{
				Node* left = tree->left_;
				delete(tree);
				return left;
			}
			else if (tree->right_ != nullptr)
			{
				Node* right = tree->right_;
				delete(tree);
				return right;
			}
			else
			{
				//删除没有孩子的节点
				delete(tree);
				return nullptr;
			}
		}
		else if (come_(tree->data_, val))
		{
			tree->right_ = remove(tree->right_, val);
		}
		else
		{
			tree->left_ = remove(tree->left_, val);
		}
		return tree;
	}
	//前序 VLR
	void printfVLR(Node *tree)
	{
		if (tree == nullptr)
		{
			return;
		}
		printf("%d\x20", tree->data_);
		printfVLR(tree->left_);
		printfVLR(tree->right_);
	}
	//前序非递归遍历实现
	void preOrder(Node* root_)
	{
		cout << "非递归前序排列";
		if (root_ == nullptr)
		{
			return;
		}
		stack<Node*> s;
		s.push(root_);
		while (!s.empty())
		{
			Node* top = s.top(); // V
			s.pop();
			printf("%d\x20", top->data_);
			if (top->right_ != nullptr)
			{
				s.push(top->right_); // R
			}
			if (top->left_ != nullptr)
			{
				s.push(top->left_); //L
			}
			
		}
		cout << endl;
	}
	//中序 LVR
	void printfLVR(Node *tree)
	{
		if (tree == nullptr)
		{
			return;
		}
		printfLVR(tree->left_);
		printf("%d\x20", tree->data_);
		printfLVR(tree->right_);
	}
	//后序 LRV
	void printfLRV(Node* tree)
	{
		if (tree == nullptr)
		{
			return;
		}
		printfLRV(tree->left_);
		printfLRV(tree->right_);
		printf("%d\x20", tree->data_);
	}
	//递归层序遍历实现
	void levelOrder(Node* tree, int i)
	{
		if (tree == nullptr)
		{
			return;
		}
		if (i == 0)
		{
			cout << tree->data_ << " ";
			return;
		}
		levelOrder(tree->left_, i - 1);
		levelOrder(tree->right_, i - 1);
		return;
	}
	//递归层数遍历实现
	int high(Node* tree)
	{
		if (tree == nullptr)
		{
			return 0;
		}
		int left = high(tree->left_) + 1;
		int right = high(tree->right_) + 1;
		return left > right ? left: right;
	}
	//递归个数遍历实现
	int number(Node* tree)
	{
		if (tree == nullptr)
		{
			return 0;
		}
		int left = number(tree->left_); //+ 1是加上当前节点
		int right = number(tree->right_);
		return left + right + 1;
	}
	//判断是否是BSTTREE实现
	bool isBstTree(Node* tree, Node*& pre)
	{
		if (tree == nullptr)
		{
			return true;
		}
		if (!isBstTree(tree->left_, pre))
		{
			return false;
		}
		//L

		if (pre != nullptr)
		{
			if (come_(tree->data_, pre->data_))
			{
				return false;
			}
		}
		pre = tree;
		//V
		return isBstTree(tree->right_, pre);//R
	}
	//求满足区间的元素值[i,j]实现
	void findVectors(Node* tree, vector<T>& vec, int i, int j)
	{
		if (tree == nullptr)
		{
			return;
		}
		if (tree->data_ > i)
		{
			findVectors(tree->left_, vec, i, j);
		}
		
		if (tree->data_ >= i && tree->data_ <= j)
		{
			vec.push_back(tree->data_);
		}
		if (tree->data_ < j)
		{
			findVectors(tree->right_, vec, i, j);
		}
	}
	//判断是否是BST树的子树实现
	bool isChildTree(Node* tree,Node* child)
	{
		if (child == nullptr && tree == nullptr)
		{
			return true;
		}
		if (tree == nullptr)
		{
			return false;
		}
		if (child == nullptr)
		{
			return true;
		}
		if (child->data_ != tree->data_)
		{
			return false; // V
		}
		return isChildTree(tree->left_, child->left_) && isChildTree(tree->right_, child->right_); // L R
	}
	//公共祖先 LCA
	Node* getLCA(Node* tree,int val1,int val2)
	{
		if (tree == nullptr)
		{
			return nullptr;
		}
		if (come_(tree->data_, val1) && come_(tree->data_, val2))
		{
			return getLCA(tree->right_, val1, val2);
		}
		else if (come_(val1, tree->data_) && come_(val2, tree->data_))
		{
			return getLCA(tree->left_, val1, val2);
		}
		else
		{
			return tree;
		}
	}
	//镜像反转
	void mirror01(Node* tree)
	{
		if (tree == nullptr)
		{
			return;
		}

		Node* temp = tree->left_;
		tree->left_ = tree->right_;
		tree->right_ = temp;
		mirror01(tree->left_);
		mirror01(tree->right_);
	}
	Node* root_;
	Comppare come_;
};
void test01()
{
	int a[] = { 58,24,67,0,34,62,5,41,64,78 };
	BstTree<int> bst;
	for (int v : a)
	{
		bst.n_insert(v);
	}
	//bst.n_insert(12);
	//bst.find(12);
	//bst.n_remove(12);
	//bst.find(12);
	//bst.insert(12);
	//bst.remove(12);
	bst.printfVLR();	//preOrder();
	bst.preOrder();
	bst.printfLVR();	//inOrder();
	bst.inOrder();
	bst.printfLRV();	//postOrder();
	bst.posOrder();
	bst.levelOrder();
	bst.n_levelOrder();
	vector<int> vec;
	bst.findVectors(vec, 10, 70);
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << bst.isBstTree() << endl;
	cout << bst.high() << endl;
	cout << bst.number() << endl;
	BstTree<int> bst1;
	bst1.insert(67);
	bst1.insert(62);
	bst1.insert(69);
	cout << bst.isChildTree(bst1) << endl;
}
void test02()
{
	int a[] = { 58,24,67,0,34,62,5,41,64,78 };
	BstTree<int> bst;
	for (int v : a)
	{
		bst.n_insert(v);
	}
	BstTree<int> bst1;
	bst1.insert(67);
	bst1.insert(62);
	bst1.insert(78);
	cout << bst.isChildTree(bst1) << endl;
}
void test03()
{
	int a[] = { 58,24,67,0,34,62,5,41,64,78 };
	BstTree<int> bst;
	for (int v : a)
	{
		bst.n_insert(v);
	}
	cout << bst.getLCA(62, 64) << endl;
}
void test04()
{
	int a[] = { 58,24,67,0,34,62,5,41,64,78 };
	BstTree<int> bst;
	for (int v : a)
	{
		bst.n_insert(v);
	}
	BstTree<int> bst1;
	bst.mirror01();
	bst.inOrder();
}
int main()
{
	//test03();
	//test02();
	test04();
	return 0;
}