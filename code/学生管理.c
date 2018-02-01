#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#pragma warning(disable: 4996)	//添加的定义排除警告
/*
**************************************************

使用结构体存储学生的学号、姓名和成绩信息，
实现对学生成绩类的基本操作：增加、删除、查询、排序

**************************************************
*/


/*学生结构体*/
struct student{
    char name[10];
    char no[10];
    double couse[4];
    double sum ;
};

/*链表节点*/
typedef struct node{
    struct student st;
    struct node *Next;
}Node;

int Add(Node *Head);/*增加学生*/
void Print(Node *Head);/*打印学生信息*/
int Find(Node *Head);/*查询学生*/
int Del(Node *Head);/*删除学生*/
void sort_sum(Node *Head);/*按总成绩排序*/
void sort_no(Node *Head);/*按学号排序*/
void main_remid();/*主要提示信息*/
void score_remind();/*成绩提示信息*/

int main()
{
    Node* Head = (struct node *)malloc(sizeof (Node));
    Head->Next = NULL;
    char op = ' ';
    main_remid();
    while(op != 'q')
    {
        scanf("%c", &op);
        switch(op)
        {
            case '1':
                sort_no(Head);
                break;
            case '2':    
                Add(Head);
                break;
            case '3':
                Find(Head);
                break;
            case '4':
                Del(Head);
                break;
            case '5':
                sort_sum(Head);
                break;
            case '6':
                main_remid();
                break;
            default:
                printf("输入指令未知，请重新输入\n");
                break;            
        }
        printf("请继续选择您想要的操作:\n");
        fflush(stdin);
    }
    return 0;
}

/*增加学生*/
int Add(Node *Head)
{        
    Node* p = (struct node*)malloc(sizeof (Node));
    p->st.sum = 0.0;
    printf("请输入学生的学号\n");
    scanf("%s", p->st.no);
    printf("请输入学生的姓名\n");
    scanf("%s", p->st.name);
    printf("请输入学生的英语成绩\n");
    scanf("%lf", &p->st.couse[0]);
    p->st.sum += p->st.couse[0];
    printf("请输入学生的数学成绩\n");
    scanf("%lf", &p->st.couse[1]);
    p->st.sum += p->st.couse[1];
    printf("请输入学生的语文成绩\n");
    scanf("%lf", &p->st.couse[2]);
    p->st.sum += p->st.couse[2];
    printf("请输入学生的C语言成绩\n");
    scanf("%lf", &p->st.couse[3]);
    fflush(stdin);
    p->st.sum += p->st.couse[3];
    if(Head->Next == NULL)
    {
        p->Next = NULL;
        Head ->Next = p;
    }
    else
    {
        p->Next = Head ->Next;
        Head->Next = p;
    }
    return 0;
}

/*按总成绩排序*/
void sort_sum(Node *Head)
{
    Node *p = Head;
    Node *temp = (struct node*)malloc(sizeof (Node));
    Node *first = (struct node*)malloc(sizeof (Node));
    memcpy(first, p->Next ,sizeof (Node));
    temp->Next = first;
    first->Next = NULL;
    p = p->Next;
    while(p->Next != NULL)
    {
        Node *t = temp;
        while(t->Next!=NULL && p->Next->st.sum < t->Next->st.sum)
            t = t->Next;
        Node *q = (struct node*)malloc(sizeof (Node));
        memcpy(q, p->Next, sizeof(Node));
        q->Next = t->Next;
        t->Next = q;        
        p = p->Next;
    }
    Print(temp);
    p = temp;
    Node *q = temp->Next;
    while(q->Next != NULL)
    {
        free(p);
        p = q;
        q = q->Next;        
    }
    free(p);
    free(q); 
}

/*按学号排序*/
void sort_no(Node *Head)
{
    Node *p = Head;
    Node *temp = (struct node*)malloc(sizeof (Node));
    Node *first = (struct node*)malloc(sizeof (Node));
    memcpy(first, p->Next ,sizeof (Node));
    temp->Next = first;
    first->Next = NULL;
    p = p->Next;
    while(p->Next != NULL)
    {
        Node *t = temp;
        while(t->Next!=NULL && atoi(p->Next->st.no)>atoi(t->Next->st.no))
            t = t->Next;
        Node *q = (struct node*)malloc(sizeof (Node));
        memcpy(q, p->Next, sizeof(Node));
        q->Next = t->Next;
        t->Next = q;
        
        p = p->Next;
    }
    Print(temp);
    p = temp;
    Node *q = temp->Next;
    while(q->Next != NULL)
    {
        free(p);
        p = q;
        q = q->Next;        
    }
    free(p);
    free(q); 
}

/*void sort_sum1(Node *Head)
{
    Node *temp;
    Node *p = Head;
    temp->Next2 = p->Next;


    p = p->Next;
    p->Next2 = NULL;
    while(p->Next != NULL)
    {
        Node *t = temp;
        while(t->Next2!=NULL && p->Next->st.sum<t->Next2->st.sum)
            t = t->Next2;
        p->Next->Next2 = t->Next2;
        t->Next2 = p->Next;    
        
        p = p->Next;    
    }
    Print(temp);
    
}*/

/*打印学生信息*/
void Print(Node *Head)
{
    Node* p = Head;
    score_remind();
    while(p->Next != NULL)
    {
        printf("\t%s", p->Next->st.no);
        printf("\t%s", p->Next->st.name);
        printf("\t%.1lf", p->Next->st.couse[0]);
        printf("\t%.1lf", p->Next->st.couse[1]);
        printf("\t%.1lf", p->Next->st.couse[2]);
        printf("\t%.1lf", p->Next->st.couse[3]);
        printf("\t%.1lf\n", p->Next->st.sum);
        p = p->Next;
    }    
    p = NULL;
}

/*查询学生*/
int Find(Node *Head)
{
    Node* p = Head;
    printf("请输入要查找学生的学号：\n");
    char no[10];
    scanf("%s", no);
    while(p->Next != NULL)
    {
        if(!strcmp(no, p->Next->st.no))
        {
            score_remind();
            printf("\t%s", p->Next->st.no);
            printf("\t%s", p->Next->st.name);
            printf("\t%.1lf", p->Next->st.couse[0]);
            printf("\t%.1lf", p->Next->st.couse[1]);
            printf("\t%.1lf", p->Next->st.couse[2]);
            printf("\t%.1lf", p->Next->st.couse[3]);
            printf("\t%.1lf\n", p->Next->st.sum);    
            p = NULL;
            return 1;        
        }        
        p = p->Next;
    }
    printf("查找失败，不存在次学号\n");
    p = NULL;
    return 0;
}

/*删除学生*/
int Del(Node *Head)
{
    Node* p = Head;
    printf("请输入要删除学生的学号：\n");
    char no[10];
    scanf("%s", no);
    while(p->Next != NULL)
    {    
        if(!strcmp(no, p->Next->st.no))
        {
            Node *q = p->Next;
            p->Next = p->Next->Next;
            printf("%s  %s删除成功\n",q->st.no, q->st.name);
            free(q);
            q = NULL;        
            return 1; 
        }
        p = p->Next;
    }
    printf("不存在此学号\n");
}

/*主要提示信息*/
void main_remid()
{
    printf("\t\t\t学生成绩类\n");
    printf("\t\t1.查询所有学生的成绩信息\n");
    printf("\t\t2.增加学生\n");
    printf("\t\t3.查找学生\n");
    printf("\t\t4.删除学生\n");
    printf("\t\t5.查看总分排名\n");
    printf("\t\t6.查看此提示\n");
    printf("\t\tq.退出系统\n\n"); 
}

/*成绩提示信息*/
void score_remind()
{
    printf("\t\t\t 学生成绩信息\n");
    printf("\t学号\t姓名\t数学\t英语\t语文\tC语言\t总成绩\n");
}