#include <stdio.h>
#include "sys_setting.h"

void react(int type,int loc){
	while(1){
	switch(type){
		case 0:
		    if(loc==0){
                SetCall(call_phone,3,0);
                printf("��⵽��������Ũ�ȳ���\n");
		    }
		    else if(loc==1){
                SetCall(call_phone,3,1);
                printf("��⵽��������Ũ�ȳ���\n");
		    }
			break;
		case 1:
		    if(loc==0){
                SetCall(call_phone,0,0);
                printf("δ��ʱ�������룬��Ϊ������������\n");
		    }
		    else if(loc==1){
                SetCall(call_phone,0,1);
                printf("δ��ʱ�������룬��Ϊ������������\n");
		    }
			break;
		case 2:
		    if(loc==0){
                SetCall(call_phone,2,0);
                printf("������������\n");
		    }
		    else if(loc==1){
                SetCall(call_phone,2,1);
                printf("δ������������\n");
		    }
			break;
        case 3:
		    if(loc==0){
                SetCall(call_phone,1,0);
                printf("����ˮ��\n");
		    }
		    else if(loc==1){
                SetCall(call_phone,1,1);
                printf("����ˮ��\n");
		    }
			break;
        case 4:
		    if(loc==0){
                SetCall(call_phone,4,0);
                printf("�����¶ȹ���\n");
		    }
		    else if(loc==1){
                SetCall(call_phone,4,1);
                printf("�����¶ȹ���\n");
		    }
			break;
	}
	taskDelay(10);
	}
}

void judge_offence(int switch_judge, int loc){
	if(switch_judge == 1){
        if(loc==0){
            react(1,0);
        }
        else{
            react(1,1);
        }
	}
}



