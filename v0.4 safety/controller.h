#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

int sys_switch;
int arm_sys(); //��ϵͳ
void* pthread_func(void *arg); //�̺߳���
void print_thread(char *str);  //����̺߳źͽ��̺�
int disarm_sys(); //�ر�ϵͳ
int exit_sys(); //�˳�ϵͳ



#endif // CONTROLLER_H_INCLUDED
