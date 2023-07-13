/*
1.教师入口密码可以在UI函数中修改
2.该程序有彩蛋
3.ReadFile函数文件地址改成text1的地址
可以先录入几个同学成绩
就会在文件夹中发现text1这个文件
4.教师密码正确后享有全部功能
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <tchar.h>



typedef struct Student //学生信息储存用
{
    int order ;
    char name[20];
    long long idnumber ;
    int mathlinear ;
    int mathcalculus ;
    int english ;
    int computer ;
    int polotics ;
    int total ;         //total score
    float aver ;        //average score
    int ranks ;         //ranking
} STU;


typedef struct LinkedList  //数据结构链表
{
    STU data;
    LinkedList * next ;

} LL ;

void color(short x) //UI调色用
{
    if(x>=0 && x<=15)//参数在0-15的范围颜色
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x); //只有一个参数，改变字体颜色
    else//默认的颜色白色
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

float f(float x, float y, float z) //画图用
{
float a = x * x + 9.0f / 4.0f * y * y + z * z - 1;
return a * a * a - x * x * z * z * z - 9.0f / 80.0f * y * y * z * z * z;
}

float h(float x, float z)  //画图用
{
  for (float y = 1.0f; y >= 0.0f; y -= 0.001f)
if (f(x, y, z) <= 0.0f)
return y;
return 0.0f;
}


void    UI();                //显示主页面
void    FilePuts(LL* phead); // 文件存储（追加）
void    FilePutsChange(LL *phead) ;//文件存储（替换，排序后用）
void    AllstuTotalAAver (LL* phead ,long long * alltotal ,float  * allaver)  ;//输出总平均分
void    SortAllScore (LL* phead)  ;//成绩排序（高分在前）
void    Changescore(LL* phead)  ;//成绩修改
void    Addscore(LL* phead)  ; //添加成绩
void    SeekScore(LL* phead)  ; //成绩查询
void    DeleteScore(LL *phead)  ;//成绩删除
void    OutputScore(LL *phead)   ;//输出成绩
void    FriendPK(LL *phead)  ; //好友pk
void    Xxxxxxx(); //轻松一下
LL*     ReadFile()  ; //文件读取
LL*     PutsScore();    //文件输入

int main()
{
    long long  allstutotal  ;
    int        totalstunum  ;
    float      allstuaver   ;
    LL *       phead = NULL ;//链表头
    LL *       p = NULL     ;

    UI();//主界面显示
while(1){
        int ii;
        scanf("%d",&ii);
        switch(ii){
		 case 1:phead=PutsScore();break;
		 case 2:phead=ReadFile();
                OutputScore(phead);break;
	 	 case 3:phead=ReadFile();
                SortAllScore(phead);break;
	 	 case 4:phead=ReadFile();
	 	        AllstuTotalAAver(phead,&allstutotal,&allstuaver);break;
	 	 case 5:phead=ReadFile();
	 	        SeekScore(phead);break;
		 case 6:phead=ReadFile();
		        Changescore(phead);break;
		 case 7:phead=ReadFile();
		        DeleteScore(phead);
		        FilePutsChange(phead);break;
		 case 8:Xxxxxxx();break;
		 case 9:phead=ReadFile();
		        FriendPK(phead);break;
		 case 0:exit(0);
		 default:  printf("wrong input\ninput again\n");
		 }
	}



}

void UI()//评测员您好，可以在下面改密码
{
    system("color 9E");
    int i=4;
    char code[20]={'8','8','8','8','8','8'},password[20];      //密码可定义
	int x;
	char c;
    LL* phead ;
//规格严格 功夫到家
    printf("\t★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n\n");
    printf("\t★\t\t\t\t Strict specification Kung Fu home\t\t\t\t        ★\n\n");
    printf("\t★\t\t\t*****************************************************\t\t\t\t★\n\n");
    printf("\t★\t\t\t\t\t    SCORE SYSTEM     \t\t\t\t\t\t★\n\n");
    printf("\t★\t\t\t*****************************************************\t\t\t\t★\n\n");
    printf("\t★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n\n");
    while(1){
            printf("\n\nWho are you ,teacher(please input 9) or student(please input 0)\n");//输入你的身份
            int in = 5 ;
            scanf("%d",&in) ;
            if(in==9)
                break;
            ////////////////////////////////////////////////////////////
            if(in==0)//学生功能只有三个，无法增删改
            {
                    while(1)

                {
                         printf("\t\t★————————————————————————————————————————★\n\n");
                         printf("\t\t\t   | 1. 成绩查找\t\t2. 好友PK \t\t3. 休息一下  |\n\n");
                         printf("\t\t\t   |            \t\t0. 退出系统\t\t             |\n\n");
                         printf("\t\t★————————————————————————————————————————★\n");
                int ii;
                scanf("%d",&ii);
                switch(ii){
                     case 1:phead=ReadFile();
                            SeekScore(phead);break;
                     case 2:phead=ReadFile();
                            FriendPK(phead);break;
                     case 3:Xxxxxxx();break;

                     case 0:exit(0);
                     default:  printf("wrong input");
                     }
                }
            }
        }



	printf("please input the key(6)！\n");
	q:
	x=0;
	while(x<6)
	{
		c=getch();
		putchar('*');
		password[x++]=c;
	}
	password[x]='\0';
    if(strcmp(password,code)!=0)
    {
    	fflush(stdin);
        printf("\n输入密码有误，您还有%d次机会，请重新输入：\n",i--);
        if(i==-1) //爱心彩蛋
        {
            printf("\n要诚实！！！别想改成绩！！！\a\a\a\a\a\a\a");
            	float a,xx,y;
        for(y=1.5f; y>-1.5f; y-=0.1f)
        {
            for(xx=-1.5f; xx<1.5f; xx+=0.05f)
            {
                a = xx*xx+y*y-1;

                char ch = a*a*a-xx*xx*y*y*y<=0.0f?'*':' ';
                putchar(ch);

            }
            printf("\n");
        }

;
            exit(0);
        }
        goto q;
    }


	 printf("\t\t★————————————————————————————————————————★\n\n");
     printf("\t\t\t   | 1. 成绩录入\t\t2. 成绩显示\t\t3. 成绩排序  |\n\n");
     printf("\t\t\t   | 4. 总分均分\t\t5. 成绩查找\t\t6. 成绩修改  |\n\n");
     printf("\t\t\t   | 7. 删除成绩\t\t8. 休息一下\t\t9. 好友PK    |\n\n");
     printf("\t\t\t   |            \t\t0. 退出系统\t\t             |\n\n");
     printf("\t\t★————————————————————————————————————————★\n");
}

LL* PutsScore()
{
    int i = 1 ;
        LL * pcur = NULL ;
        LL * phead = NULL ;
        LL * pfront = NULL ;
    for( i ; i > 0 ; i ++)
    {
        LL * p = NULL;
        p = (LL*)malloc(sizeof(LL));
        if(p == NULL)
        {
            printf("cannot allocation in putscore");
            exit(-1);
        }
        p->next=NULL;
        printf("Please input NO.%d student's score\n",i);
        printf("Please input the name\n");
        scanf("%s",p->data.name);
        p->data.order =  i ;
        printf("Please input the idnumber\n");
        scanf("%lld",&p->data.idnumber);
        printf("Please input the mathlinear score\n");
        scanf("%d",&p->data.mathlinear);
        printf("Please input the mathcalculus score\n");
        scanf("%d",&p->data.mathcalculus);
        printf("Please input the english score\n");
        scanf("%d",&p->data.english);
        printf("Please input the computer score\n");
        scanf("%d",&p->data.computer);
        printf("Please input the polotics score\n");
        scanf("%d",&p->data.polotics);
        p->data.total = p->data.mathlinear+p->data.mathcalculus+p->data.english
                            +p->data.computer+p->data.polotics;
        p->data.aver = (1.0*p->data.total)/5 ;



        if(i == 1)
        {
            phead = p ;
            pcur = p ;
            pfront = p ;

        }
        else{
            pfront ->next = p ;
            pfront = p ;
        }
        int trin ;//是否继续输入
        printf("If you want to conutine ,please input 0,else input 9\n///////////////////////////////\n///////////////////////////////\n");
        scanf("%d",&trin);

                            if(trin == 9)
                            break ;//exit inputscore ;
    }

    FilePuts(phead);


    return phead ;
}


void OutputScore(LL *phead)
{
    LL* p = NULL ;
    p = phead ;
    if(p==NULL)
    {
        printf("cannot find the head in the outputscore");
        exit(-11);
    }
    while(p!=NULL)
    {
        printf(" %10s %15lld %5d %5d %5d %5d %5d %5d %.5f\n",
                p->data.name,p->data.idnumber,p->data.mathlinear,p->data.mathcalculus,
                p->data.english,p->data.computer,p->data.polotics,p->data.total,p->data.aver);
        p = p->next;

    }
}


void AllstuTotalAAver (LL* phead ,long long * alltotal ,float  * allaver) //计算总分的平均分
{
    LL * p = NULL ;
    p = phead ;
    int n =  0 ;
    long long total = 0 ;
    if(p == NULL)
    {
        printf("cannot find head in AllstuTotalAAver");
        exit(-4);
    }
    while(p!=NULL)
    {
        total = total + p->data.total ;
        p = p->next ;
        n++ ;
    }
    *allaver = (1.0*total /6)/n ;
    printf("%f\n",*allaver);

}


void SortAllScore (LL* phead) //对所有成绩进行排序
{
    LL * pi = NULL ;
    LL * pj = NULL ;
    STU  tem  ;
    LL * pt = NULL ;
    LL * p = NULL ;
    p = phead ;
    pi = phead ;

    pj = phead->next  ;
    if(pi == NULL||pj == NULL)
    {
        printf("cannot find head in SortAllScore");
        exit(-5);
    }
    int i = 1 ;
    while(pi!=NULL)
    {
            LL * pk = pi ;
            pj = pi-> next ;
            while(pj!=NULL)
            {
                if(pk->data.total<pj->data.total)
                {
                    pk = pj ;
                }
                pj=pj->next;
            }
            tem = pi->data ;
            pi->data = pk->data ;
            pk->data = tem ;
            pi->data.ranks=i;
            i++  ;              //get the rank
            printf("\nrank : %d\n",pi->data.ranks);
            pi=pi->next;


    }
    FilePutsChange(phead) ;
    OutputScore(phead)    ;



}


void Changescore(LL* phead) //改成绩
{
    printf("please input the students ID");
    long long id = 0 ;
    scanf("%lld",&id) ;

    LL * p = NULL ;
    p = phead ;
    if(p== NULL)
    {
        printf("cannot find the head in Changescore");
        exit(-6);
    }
    int flag = 0 ;
    while(p!=NULL)
    {
        if(id==p->data.idnumber)
            {
                flag = 1 ;
                break ;
            }
        p = p->next ;
    }
    if(flag==0)
    {
        printf("not find this student");

    }
    else{
        printf("Please input the name\n");
        scanf("%s",p->data.name);
        printf("Please input the idnumber\n");
        scanf("%lld",&p->data.idnumber);
        printf("Please input the mathlinear score\n");
        scanf("%d",&p->data.mathlinear);
        printf("Please input the mathcalculus score\n");
        scanf("%d",&p->data.mathcalculus);
        printf("Please input the english score\n");
        scanf("%d",&p->data.english);
        printf("Please input the computer score\n");
        scanf("%d",&p->data.computer);
        printf("Please input the polotics score\n");
        scanf("%d",&p->data.polotics);
        p->data.total = p->data.mathlinear+p->data.mathcalculus+p->data.english
                            +p->data.computer+p->data.polotics;
        p->data.aver = (1.0*p->data.total)/5 ;

        }
    printf("have changed \n");
    FilePutsChange(phead);//存入文件
}


void  Addscore(LL* phead)//加成绩
{
    printf("Now let's add a student");
    LL* p = NULL ;
    p = (LL*)malloc(sizeof(LL));
    if(p == NULL)
    {
        printf("cannot allocation p in the Addscore");
        exit(-8);
    }
        printf("Please input the mathlinear score\n");
        scanf("%d",&p->data.mathlinear);
        printf("Please input the mathcalculus score\n");
        scanf("%d",&p->data.mathcalculus);
        printf("Please input the english score\n");
        scanf("%d",&p->data.english);
        printf("Please input the computer score\n");
        scanf("%d",&p->data.computer);
        printf("Please input the polotics score\n");
        scanf("%d",&p->data.polotics);
        p->data.total = p->data.mathlinear+p->data.mathcalculus+p->data.english
                            +p->data.computer+p->data.polotics;
        p->data.aver = (1.0*p->data.total)/5 ;
    p->next = phead ;
    phead = p ;

}


void SeekScore(LL* phead)//查成绩
{
    LL *p = NULL ;
    p = phead ;
    if(p == NULL)
    {
        printf("cannot find the head\n");
        exit(-9);
    }
    long long id = 0;

    printf("Please input the student's ID which you wanna find.\n");
    scanf("%lld",&id);
    int flag = 0 ;
    while(p!=NULL)
    {
        if(p->data.idnumber==id)
        {

            flag = 1 ;
            printf("Name: %10s ID: %15lld mathlinear: %5d mathcalculus: %5d english: %5d computer: %5d polotics:%5d \n total: %5d\naverage: %.2f\n ",
                p->data.name,p->data.idnumber,p->data.mathlinear,p->data.mathcalculus,
                p->data.english,p->data.computer,p->data.polotics,p->data.total,p->data.aver);
            break ;
        }
        p= p->next;
    }
    if(flag == 0)
    printf("cannot find this student\n");
}



void DeleteScore(LL *phead)//删除成绩
{
    LL* p = NULL ;
    LL* pfront = NULL ;
    p = phead ;
    pfront = p ;
    if(p == NULL)
    {
        printf("cannot find the head");
        exit(-10);
    }
    int flag = 0 ;
    long long id ;
    printf("please input the student's id which you wanna delete\n");
    scanf("%lld",&id);
    for(int i = 1 ; p != NULL ; i ++)
    {

        if(id==p->data.idnumber)
        {
            printf("have deleted");
            if(i == 1)
            {
                phead= p->next ;
            }
            else{
                pfront->next =p->next ;
            }
            flag = 1 ;
            break ;
        }

            pfront= p;
            p = p->next;
    }
    if(flag==0)
    {
        printf("cannot find the student");
    }
}


void FilePuts(LL *phead)  //追加存入文件
{
    FILE * pf = NULL ;
    LL * p = NULL ;
    p = phead ;
    pf = fopen("text1.txt","a+");
    if(pf==NULL)
    {
        printf("cannot build file");
    }
    while(p!=NULL)
    {
        fprintf(pf," %10s %15lld %5d %5d %5d %5d %5d %5d %.5f\n",
                p->data.name,p->data.idnumber,p->data.mathlinear,p->data.mathcalculus,
                p->data.english,p->data.computer,p->data.polotics,p->data.total,p->data.aver);
        p = p->next;

    }
    fclose(pf);


}

void FilePutsChange(LL *phead)  //格式化后存入文件
{
    FILE * pf = NULL ;
    LL * p = NULL ;
    p = phead ;
    pf = fopen("text1.txt","w");
    if(pf==NULL)
    {
        printf("cannot build file");
    }
    while(p!=NULL)
    {
        fprintf(pf," %10s %15lld %5d %5d %5d %5d %5d %5d %.5f\n",
                p->data.name,p->data.idnumber,p->data.mathlinear,p->data.mathcalculus,
                p->data.english,p->data.computer,p->data.polotics,p->data.total,p->data.aver);
        p = p->next;

    }
    fclose(pf);


}
/////////////////////////////////////////ATTENTION//////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
LL* ReadFile()//////////////////////////////////////////////////////////////请不要忘记改地址
{
    FILE * fp = NULL ;
    fp = fopen("C:\\Users\\51625\\Desktop\\大作业\\text1.txt","r");  /////////////////////////////////////////////////////在这里改地址
    if(fp == NULL )
    {
        printf("cannot open file");
        exit(-1);
    }
    LL * pcur = NULL ;
    LL * pfront = NULL;
    LL * phead = NULL;

    int i = 0;
    for(i = 0 ; feof(fp)==0 ; i ++)
    {
        pcur = (LL*) malloc (sizeof(LL));
        if(pcur == NULL)
        {
            printf("cannot allocation in readfile");
            exit(-7);
        }
        fscanf(fp," %10s %15lld %5d %5d %5d %5d %5d %5d %f\n",
                pcur->data.name,&pcur->data.idnumber,&pcur->data.mathlinear,&pcur->data.mathcalculus,
                &pcur->data.english,&pcur->data.computer,&pcur->data.polotics,&pcur->data.total,&pcur->data.aver);


        pcur->next = NULL ;
        if(i == 0 )
        {
            phead = pcur ;
            pfront = pcur ;

        }
        else{
            pfront->next = pcur ;
            pfront = pcur ;

        }
    }
    fclose(fp);

    return phead ;
}

void FriendPK(LL *phead)
{
    LL *p = NULL ;
    p = phead ;
    if(p==NULL)
    {
        printf("Cannot allocation in friendPK");
        exit(-14);
    }
    long long id1 = 0 ;
    long long id2 = 0 ;
    int flag1 = 0 ,flag2 = 0 ;
     LL id_1 , id_2 ;


    printf("Please input your ID");
    scanf("%lld",&id1);

    while(p!=NULL)
    {
        if(id1==p->data.idnumber)
        {
            flag1=1 ;
            id_1.data.total=p->data.total ;
            break ;
        }
        p = p->next ;
    }
    if(flag1==0)
    {
        printf("cannot find your ID");
        exit(-55);
    }
    p =phead ;
    printf("Please input your friend's ID");
    scanf("%lld",&id2);

    while(p!=NULL)
    {
        if(id2==p->data.idnumber)
        {
            flag2=1 ;
            id_2.data.total=p->data.total ;
            break ;
        }
        p = p->next ;
    }
    if(flag1==0)
    {
        printf("cannot find your friend's ID");
        exit(-55);
    }
    if(id_1.data.total>id_2.data.total)
    {
        printf("Great!!!\nYou are the winner\n");
        return ;
    }
    if(id_1.data.total==id_2.data.total)
    {
        printf("Great!!!\nYou have the same scores \n");
        return ;
    }
    if(id_1.data.total<id_2.data.total)
    {
        printf("Hurry up!!!\nYou're just one step behind\n");
        return ;
    }
}

void Xxxxxxx()//小彩蛋
{

    system("color 9E");
    int i=2;
    char code[20]={'h','u','t','i','a','n','y','u'},password[20];//密码可定义
	int x;
	char c;
	printf("please input the key(my name QAQ)！\n");
	q:
	x=0;
	while(x<8)
	{
		c=getch();
		putchar('*');
		password[x++]=c;
	}
	password[x]='\0';
    if(strcmp(password,code)!=0)
    {
    	fflush(stdin);
        printf("\n输入密码有误，您还有%d次机会，请重新输入：\n",i--);
        if(i==-1)
        {
           printf("I know that you don't know my name ,so \n I love three things : the sun ,the moon and the pig\nThe sun is for the day,the moon is for the night\nand the pig forever\n\n\n");
           return ;
        }
        goto q;
    }

//跳动的心，祝你幸福欧
color(4);
HANDLE o = GetStdHandle(STD_OUTPUT_HANDLE);
_TCHAR buffer[25][80] = { _T(' ') };
_TCHAR ramp[] = _T(".:-=+*#%@");

for (float t = 0.0f;; t += 0.1f) {
     int sy = 0;
     float s = sinf(t);
     float a = s * s * s * s * 0.2f;
 for (float z = 1.3f; z > -1.2f; z -= 0.1f) {
    _TCHAR* p = &buffer[sy++][0];
 float tz = z * (1.2f - a);
 for (float x = -1.5f; x < 1.5f; x += 0.05f) {
 float tx = x * (1.2f + a);
 float v = f(tx, 0.0f, tz);
 if (v <= 0.0f) {
 float y0 = h(tx, tz);
 float ny = 0.01f;
 float nx = h(tx + ny, tz) - y0;
 float nz = h(tx, tz + ny) - y0;
 float nd = 1.0f / sqrtf(nx * nx + ny * ny + nz * nz);
 float d = (nx + ny - nz) * nd * 0.5f + 0.5f;
 *p++ = ramp[(int)(d * 5.0f)];
}
else
 *p++ = ' ';
}
}

 for (sy = 0; sy < 25; sy++) {
         COORD coord = { 0, sy };
         SetConsoleCursorPosition(o, coord);
         WriteConsole(o, buffer[sy], 79, NULL, 0);
}
Sleep(33);
}

}
