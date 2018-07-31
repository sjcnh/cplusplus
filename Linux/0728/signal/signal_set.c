 ///
 /// @file    signal_set.c
 /// @author  LJW
 /// @date    2018-07-28 21:37:51
 ///
 
#include "func.h"

int main()
{
	// 手动屏蔽信号
	// 自定义信号集集合
	sigset_t myset;
	// 1.因为是栈上变量，所以内容随机，要清空
	sigemptyset(&myset);
	// 2.添加需要阻塞的信号
	sigaddset(&myset, SIGINT); // CTRL + c
	sigaddset(&myset, SIGQUIT); // CTRL + 反斜杠
	sigaddset(&myset, SIGKILL); 
	// 3.自定义集合数据设置给内核的阻塞信号集
	sigprocmask(SIG_BLOCK, &myset, NULL);

	// 每隔1s读一次内存的未决信号集
	while(1)
	{
		sigset_t pendset;
		sigpending(&pendset);
		// 1-31
		for(int i = 1; i < 32; ++i)
		{
			if(sigismember(&pendset, i))
			{
				printf("1");
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
		sleep(1);
	}
	return 0;
}
