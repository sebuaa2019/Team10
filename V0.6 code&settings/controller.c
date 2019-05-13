
#include <stdio.h>
#include <pthread.h>��
#include "controller.h"
#include "safety.h"

int arm_sys()
{
    int err;
    pthread_t ntid;

    if(sys_switch==0){
        printf("���ڴ�ϵͳ\n");
        err=pthread_create(&ntid,NULL,pthread_func,NULL);
        if(err!=0)
        {
            printf("�����߳�ʧ��\n");
            return 0;
        }
        else{
            printf("ϵͳ�ɹ���\n");
        }
        print_thread("���߳�"); //��ӡ���̺߳�
        sys_switch=1;
        return 1;
    }
    else{
        printf("ϵͳ�Ѿ��򿪣������ظ�����\n");
        return 1;
    }
    return 0;
}

void* pthread_func(void *arg) //ϵͳ�����̺߳���
{
    int time=0;  //ϵͳ�����е�ʱ��
    printf("ϵͳ���������У��ɼ������������\n");
    print_thread("���߳�");  //��ӡ�½��̺߳�
    for(;;){
        if(sys_switch==0){
             pthread_exit(0);
        }
        else{
            Sleep(5000);
            time+=5;
            printf("ϵͳ���������У�������%d��(��Ϊ������Ϊһ����λ�������ڹرպ���ʾһ��)\n",time);
            if(detect_invade()){

                printf("��⵽���֣�����\n");
            }
            if(detect_smoke()){
                printf("��⵽��������\n");
            }
        }
    }

    return NULL;
}

void print_thread(char *str) //����̺߳źͽ��̺ţ����ڲ���
{
    pid_t pid; //���̱�ʶ��
    pthread_t tid; //�̱߳�ʶ��

    pid=getpid();   //��ý��̺�
    tid=pthread_self(); //����̺߳�
    printf("%s�Ľ��̺�:%u �̺߳�:%u\n",str,(unsigned int)pid,(unsigned int)tid); //��ӡ���̺ź��̺߳�
}

int disarm_sys()//�ر�ϵͳ
{
    if(sys_switch==1){
        printf("ϵͳ�ѳɹ��ر�\n");
    }
    else{
        printf("ϵͳδ�򿪣�����ر�\n");
    }
    sys_switch=0;
    return 1;
}

int exit_sys()//�˳�ϵͳ
{
    printf("�ɹ��˳�ϵͳ���ڴ������´�ʹ��\n");
    return 1;
}
