#include <stdio.h>

void react(int type){
	while(1){
	switch(type){
		case 0: SetCall("13612345678",0,0);
			printf("��⵽����Ũ�ȳ���\n");
			break;
		case 1: printf("δ��ʱ�������룬��Ϊ����\n");
			break;
		case 2: printf("��������\n");
			break;
	}
	taskDelay(10);
	}
}

void judge_offence(int switch_judge){
	if(switch_judge == 1) react(1);
}



