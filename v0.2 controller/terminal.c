#include <stdio.h>
#include "controller.h"
#include "print_info.h"

char usrname[16], pssword[16];
//void arm_sys(){}
//void disarm_sys(){}
void monitor_room(){}
void report_errs(){}
void modify_sys(){}
//void exit_sys(){}

int main()
{
    int choose_id;
    int err;

    login_info(usrname,pssword);
    choose_id = choose_func();
    while(1){
        switch(choose_id)
        {
        case 1:     //��װϵͳ
            err=arm_sys();
            if(err!=1){
                printf("ϵͳ����ʧ��");   //������������
            }
            break;
        case 2:     //���ϵͳ
            err=disarm_sys();
            if(err!=1){
                printf("ϵͳ�ر�ʧ��");   //������������
            }
            break;
        case 3:      //����ͷ
            monitor_room();
            break;
        case 4:     //�������
            report_errs();
            break;
        case 5:     //�������ô�������ϵͳ
            modify_sys();
            break;
        case 6:     //�˳�ϵͳ
            err=exit_sys();
            if(err!=1){
                printf("ϵͳ�ر�ʧ��");   //������������
            }
            else{
                return 0;
            }
            break;
        }

        printf("��������Ĳ���(�������)\n");
        scanf("%d",&choose_id);
    }
    return 0;
}
