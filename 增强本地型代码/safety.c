#include<stdio.h>
#include "safety.h"
#include "sys_setting.h"

int switch_smoke_sensor = 1;
int switch_invade_sensor = 1;
int switch_tem_sensor=1;

double get_smoke_concen(){
    return 50;
}

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

    /*scanf("%d",&id);*/
    id = keyboard_single();

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
        if(OnSmooke(0)>=smoke_limit){
            return 1;
        }
        if(OnSmooke(1)>=smoke_limit){
            return 2;
        }
    }
    else return 0;
    return 0;
}

int detect_water(){

    if(switch_smoke_sensor){
        if(OnWater(0)){
            return 1;
        }
        if(OnWater(1)){
            return 2;
        }
    }
    else return 0;
    return 0;
}

int detect_invade(){
    if(switch_invade_sensor){
        if(OnMovement(0)){
            return 1;
        }
        if(OnMovement(1)){
            return 2;
        }
        if(Ondoor(0)){
            return 3;
        }
        if(Ondoor(1)){
            return 4;
        }
    }
    else return 0;
    return 0;
}

int detect_tem(){
    if(switch_tem_sensor){
        if(OnFire(0)>tem_limit) return 1;
        if(OnFire(1)>tem_limit) return 2;
    }
    else return 0;
    return 0;
}
