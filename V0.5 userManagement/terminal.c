#include <stdio.h>
#include "controller.h"
#include "print_info.h"
#include "sys_setting.h"
#include "user_management.h"

char pssword[16];
//void arm_sys(){}
//void disarm_sys(){}
void monitor_room(){}
void report_errs(){}

//void exit_sys(){}

int main()
{
    int choose_id;
    int err;

    init_sys();

    login_info(pssword);
    choose_id = choose_func();
    while(1){
        switch(choose_id)
        {
        case 1:     //��װϵͳ
            err=arm_sys();
            if(err!=1){
                printf("ϵͳ����ʧ��\n");   //������������
            }
            break;
        case 2:     //���ϵͳ
            err=disarm_sys();
            if(err!=1){
                printf("ϵͳ�ر�ʧ��\n");   //������������
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
        case 6:
            change_code();
            break;
        case 7:
            err=user_information();
            if(err!=1){
                printf("�����û�ϸ��Ϣ����ϵͳʧ��\n");   //������������
            }
            break;
        case 8:     //�˳�ϵͳ
            err=exit_sys();
            if(err!=1){
                printf("ϵͳ�ر�ʧ��\n");   //������������
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
