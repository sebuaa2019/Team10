#include<stdio.h>
#include "safety.h"
#include "sys_setting.h"

int switch_smoke_sensor = 1;
int switch_invade_sensor = 1;



int cancel_invade = 0;

int onMovement(){
	return 0;
}

int onDoor(){
	return 0;
}

void modify_sensor_setting(){
    int id;
    printf("���ѽ��봫���������޸�����\n");
    printf("����������Ҫ�Ĺ���:(�����Ӧ���)\n");
    printf("1: ������������\n");
    printf("2: �ر���������\n");
    printf("3: �������⴫����\n");
    printf("4: �رպ��⴫����\n");
    printf("5: �˳�\n");
    scanf("%d",&id);
    switch(id)
    {
        case 1:{
            turn_on_smoke_sensor();
            break;
        }
        case 2:{
            turn_off_smoke_sensor();
            break;
        }
        case 3:{
            turn_on_invade_sensor();
            break;
        }
        case 4:{
            turn_off_invade_sensor();
            break;
        }
        default:{
            printf("�����˳������������޸�����\n");
        }
    }
}
void double get_smoke_concen(){
    return 50;
}


void turn_on_smoke_sensor(){
    switch_smoke_sensor = 1;
    printf("���������ɹ�����\n");
}
void turn_off_smoke_sensor(){
    switch_smoke_sensor = 0;
    printf("���������ɹ��ر�\n");

}
void turn_on_invade_sensor(){
    switch_invade_sensor = 1;
    printf("���⴫�����ɹ�����\n");
}
void turn_off_invade_sensor(){
    switch_invade_sensor = 0;
    printf("���⴫�����ɹ��ر�\n");
}
void cancel_invade_by_owner(){
    cancel_invade = 1;
    printf("�����ؼң���������Ȿ��ȡ��\n");
}
int detect_smoke(){
/*need basic sensor data to analyze*/
/*return 0 means no smoke*/
    double data = get_smoke_concen();
    if(switch_smoke_sensor){
        if(data >= smoke_limit){
            return 1;
        }
        else {
            return 0;
        }

    }
    else return 0;

}

int delay_time = 0;
int detect_invade(){
    delay_time+=5;
    if(switch_invade_sensor){
        if(1){
            if(cancel_invade==0){
                if(delay_time>=code_delay){ /* �ӳټ��ʱ�䣬��������*/
                    delay_time = 0;
                    return 1;
                }
                delay_time = 0;
                return 0;

            }
            else {  /*�û����ţ�ȡ�����*/
                cancel_invade = 0;/*��ʼ����������һ��Ҳ��ȡ��*/
                delay_time = 0;
                return 0;
            }
        }
        else{
             return 0;
        }
    }
    else return 0;
}

