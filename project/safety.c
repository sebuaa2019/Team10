#include<stdio.h>
#include "safety.h"
int switch_smoke_sensor = 1;
int switch_invade_sensor = 1;

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

int detect_smoke(){
/*need basic sensor data to analyze*/
/*return 0 means no smoke*/
    if(switch_smoke_sensor){

        return 1;
    }
    else return 0;

}

int detect_invade(){
    if(switch_invade_sensor){

        return 1;
    }
    else return 0;
}
