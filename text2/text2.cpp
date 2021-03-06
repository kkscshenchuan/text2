// text2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream";
using namespace std;

struct node
{
	char data;
	node *next;
};

node *Create();   //创建列表函数，返回表头
void Showlist(node *head);  //遍历链表函数 返回表头
node *Search(node *head, char keyword);   //查询
void Insert(node * &head, char keyword, char newdata);//插入数据
void Delete(node * &head, char keyword);              //删除结点
void Destory(node *head);                             //清除链表


int main()
{
	node *head;
	head = Create();
	Showlist(head);
	//Search(head, 'k');
	//Insert(head, 'k', 'm');
    //Delete(head,'k');
	Destory(head);
	Showlist(head);
    return 0;
}

node *Create()
{
	node *head = nullptr;  //表头指针，开始没有结点，所以为空`
	node *pEnd = head;      //表尾指针，开始没有结点，所以指向表头
	node *pS;              //创建新结点时所用指针
	char temp;             //用于存放从键盘输入的字符
	do
	{
		cin >> temp;
		if (temp != '*')  //如果链表中没有任何结点存在
		{
			pS = new node;
			pS->data = temp;     //新结点的数据为temp
			pS->next = nullptr;  //新结点将成为表尾，所以next为空
			if (head == nullptr)
			{
				head = pS;       //则表头指向这个新结点
			}
			else
		    {
			    pEnd->next = pS;  //将新结点连接在表尾
		    }
	     	pEnd = pS;            //新结点成为新的表尾
		}
	} while (temp != '*');
	return head;
}

void Showlist(node *head)
{
	node *pRead = head;        //开始访问时指向表头
	cout << "显示数据：";
	while (pRead != nullptr)
	{
		cout << pRead->data; //输出当前访问数据
		pRead = pRead->next; //访问指针后移
	}
	cout << endl;
}

node *Search(node *head, char keyword)
{
	node *pRead = head;
	while (pRead != nullptr)
	{
		if (pRead->data == keyword)
		{
			cout << "查找成功" << endl;
			return pRead;       //返回当前结点的指针
		}
		else
		{
			pRead = pRead->next;   //数据不匹配，则指针后移
		}
	}
	return nullptr;
}

void Insert(node * &head, char keyword, char newdata)     //插入数据操作

{
	node *newnode = new node;  //新结点
	newnode->data = newdata; 
	node *pGuard = Search(head, keyword);
	if (head == nullptr || pGuard == nullptr)      //如果链表没有结点或找不到关键字结点
	{                                              //则插入表头位置
		newnode->next = head;                      //先连 
		head = newnode;                            //后断
	}
	else
	{
		newnode->next = pGuard->next;
		pGuard->next = newnode;
	}
	cout << "插入成功" << endl;
}

void Delete(node * &head, char keyword)
{
	if (head != nullptr)
	{
		node *p;
		node *pGuard = head;
		if (head->data == keyword)
		{
			p = head;
			head = head->next;
			delete p;
			cout << "删除结点为：" << keyword << endl;
			return;
		}
		else
		{
			while (pGuard->next != nullptr)
			{
				if (pGuard->next->data == keyword)
				{
					p = pGuard->next;
					pGuard->next = p->next;
					delete p;
					cout << "删除结点为：" << keyword<<endl;
					return;
				}
				pGuard = pGuard->next;
			}
		}
	}
	cout << "关键字没找到或者链表为空" << endl;
}

void Destory(node *head)
{
	node *p;
	while (head != nullptr)
	{
		p = head;
		head = head->next;
		delete p;
	}
	cout << "链表已清除" << endl;
}