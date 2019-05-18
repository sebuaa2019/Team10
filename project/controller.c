#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <loglib.h>
#include <stddef.h>
#include <time.h>
#include <tasklib.h>
#include "controller.h"
#include "safety.h"
#include "sys_setting.h"
int task;
int task_open=0;
int task_time=0;

int arm_sys()
{
    int err;

    if(sys_switch==0){
        printf("���ڴ�ϵͳ\n");
	taskDelay(start_delay*60);
	if(task_open==0){
		task=taskSpawn("task1",200,0,1000,(FUNCPTR)pthread_func,0,0,0,0,0,0,0,0,0,0);
		if(task == ERROR)
        	{
            		printf("�����߳�ʧ��\n");
            		return 0;
        	}
        	else{
			task_open=1;
            		printf("ϵͳ�ɹ���\n");
        	} 
	}
	else{
		printf("ϵͳ�ɹ���\n");
	}
        sys_switch=1;
	task_time=0;
        return 1;
    }
    else{
        printf("ϵͳ�Ѿ��򿪣������ظ�����\n");
        return 1;
    }
    return 0;
}

void* pthread_func(void *arg)
{
    printf("ϵͳ���������У��ɼ������������\n");
    for(;;){
        taskDelay(300);
	if(sys_switch==1){
		task_time+=5;
		printf("ϵͳ���������У�������%d��\n",task_time);
		if(detect_smoke() == 1){
			react(0);
		}
		if(detect_invade() == 1){
			taskDelay(code_delay*60);
			judge_offence(sys_switch);	
		}
		else if(detect_invade() == 2){
			react(2);
		}
	}
    }

    return NULL;
}

int disarm_sys()
{
    if(sys_switch==1){
        sys_switch=0;
        printf("ϵͳ�ѳɹ��ر�\n");
    }
    else{
        printf("ϵͳδ�򿪣�����ر�\n");
    }
    return 1;
}

int exit_sys()
{
    printf("�ɹ��˳�ϵͳ���ڴ������´�ʹ��\n");
    return 1;
}
