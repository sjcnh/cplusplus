 ///
 /// @file    semget.c
 /// @author  LJW
 /// @date    2018-07-26 16:46:41
 ///
 
#include "../func.h" 


int main()
{
	int semid;
	semid = semget(1000, 1, IPC_CREAT | 0600);
#ifdef DEBUG
	if(-1 == semid)
	{
		perror("semget");
		return -1;
	}
#endif
	// 设置信号量为1 (测试时改为9，查看打印结果）
	int ret = semctl(semid, 0, SETVAL, 1);
	if(-1 == ret)
	{
		perror("semctl");
		return -1;
	}
	// 测试是否设置成功，可以通过semctl的GETVAL获取查看
	ret = semctl(semid, 0, GETVAL);
	printf("ret = %d\n", ret);

	return 0;

}
