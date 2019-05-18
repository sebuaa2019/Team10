#include <stdlib.h>
#include "print_info.h"
#include "safety.h"
#include "controller.h"
#include "sys_setting.h"

void init_sys(){
    char setting[20];
    FILE *code;
	FILE *setall;
	if((code = fopen("settings","w")) == NULL){
 		creat("settings",00700);
		code = fopen("settings","w");
        	fprintf(code,"123456\n");
		fprintf(code,"20\n");
		fprintf(code,"13900000000\n");
		fprintf(code,"15\n");
		fprintf(code,"100\n");
		fprintf(code,"10\n");
        	fclose(code);
	}
	setall = fopen("settings","r");

	fgets(setting,20,setall);
    	setting[strlen(setting)-1] = '\0';

	fgets(setting,20,setall);
    	setting[strlen(setting)-1] = '\0';

	fgets(setting,20,setall);
    	setting[strlen(setting)-1] = '\0';

	fgets(setting,20,setall);
    	setting[strlen(setting)-1] = '\0';
	code_delay = atoi(setting);

	fgets(setting,20,setall);
    	setting[strlen(setting)-1] = '\0';
	smoke_limit = atoi(setting);

	fgets(setting,20,setall);
    	setting[strlen(setting)-1] = '\0';
	start_delay = atoi(setting);

	fclose(setall);
}

void modify_settings(){
    int choice;
    printf("��ѡ��Ҫ�޸ĵ���Ŀ\n");
    printf("1: �޸�����\n");
    printf("2: �޸Ĳ��ż��\n");
    printf("3: �޸ı����绰\n");
    printf("4: �޸�����������ʱ��\n");
    printf("5: �޸�����Ũ����ֵ\n");
    printf("6: �޸Ŀ���ϵͳʱ��\n");
    printf("7: �޸Ĵ���������\n");
    printf("8: �����޸�\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            change_code();
            break;
        case 2:
            modify_delay();
            break;
        case 3:
            modify_phonenum();
            break;
	case 4:
	    modify_codedelay();
	    break;
	case 5:
	    modify_smokelimit();
	    break;
	case 6:
	    modify_startdelay();
	    break;
	case 7:
	    modify_sensor_setting();
	    break;
    }
    case 8:
        break;
}

void change_code(){
    char former[10]; /*��ǰ����*/
    char newcode[10]; /*������*/
    int limittime = 5; /*����������*/
    int check;
    int i = 0;
    printf("�����뵱ǰ����\n");
    while(i<5){
        printf("��ǰ����: ");
        scanf("%s",former);
        check = check_pssword(former);
        if(check==1) {
            printf("������ȷ��\n");
            write_new_code();
            break;
        }
        printf("�����������������\n");
        i++;
    }
}

void write_new_code(){
    char once[10];
    char twice[10];
    char line2[20];
    char line3[20];
    char line4[20];
    char line5[20];
    char line6[20];
    printf("�����������룺");
    scanf("%s",once);
    printf("ȷ�������룺");
    scanf("%s",twice);
    if(strcmp(once,twice) == 0){
	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line2,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fgets(line4,20,codein);
	fgets(line5,20,codein);
	fgets(line6,20,codein);
	fclose(codein);

	codeout = fopen("settings","w");
        fprintf(codeout,"%s\n",once);
	fprintf(codeout,"%s",line2);
	fprintf(codeout,"%s",line3);
	fprintf(codeout,"%s",line4);
	fprintf(codeout,"%s",line5);
	fprintf(codeout,"%s",line6);
        fclose(codeout);

        printf("�޸�����ɹ���\n");
    }
    else{
        printf("���벻һ�£��޸�ʧ��\n");
    }
}

void modify_delay(){
    char once[10];
    char line1[20];
    char line2[20];
    char line3[20];
    char line4[20];
    char line5[20];
    char line6[20];

	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line1,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fgets(line4,20,codein);
	fgets(line5,20,codein);
	fgets(line6,20,codein);
	fclose(codein);

	printf("��ǰ�������Ϊ(��λ��s)��%s",line2);
	printf("�������±��������");
	scanf("%s",once);

	codeout = fopen("settings","w");
        fprintf(codeout,"%s",line1);
	fprintf(codeout,"%s\n",once);
	fprintf(codeout,"%s",line3);
	fprintf(codeout,"%s",line4);
	fprintf(codeout,"%s",line5);
	fprintf(codeout,"%s",line6);
        fclose(codeout);

        printf("�޸ļ���ɹ���\n");

}

void modify_phonenum(){
    char once[10];
    char line1[20];
    char line2[20];
    char line3[20];
    char line4[20];
    char line5[20];
    char line6[20];

	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line1,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fgets(line4,20,codein);
	fgets(line5,20,codein);
	fgets(line6,20,codein);
	fclose(codein);

	printf("��ǰ�����绰Ϊ��%s",line3);
	printf("�������±����绰��");
	scanf("%s",once);

	codeout = fopen("settings","w");
        fprintf(codeout,"%s",line1);
	fprintf(codeout,"%s",line2);
	fprintf(codeout,"%s\n",once);
	fprintf(codeout,"%s",line4);
	fprintf(codeout,"%s",line5);
	fprintf(codeout,"%s",line6);
        fclose(codeout);

        printf("�޸ĵ绰�ɹ���\n");
}

void modify_codedelay(){
    char once[10];
    char line1[20];
    char line2[20];
    char line3[20];
    char line4[20];
    char line5[20];
    char line6[20];

	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line1,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fgets(line4,20,codein);
	fgets(line5,20,codein);
	fgets(line6,20,codein);
	fclose(codein);

	printf("��ǰ������ʱ��Ϊ��%s",line4);
	printf("��������ʱ����");



    while(1){
        scanf("%s",once);

        if(atoi(once)<=0){
            printf("�������ֵ���Ϸ�������������: ");
        }
        else{
            code_delay = atoi(once);
            break;
        }
    }

	codeout = fopen("settings","w");
        fprintf(codeout,"%s",line1);
	fprintf(codeout,"%s",line2);
	fprintf(codeout,"%s",line3);
	fprintf(codeout,"%s\n",once);
	fprintf(codeout,"%s",line5);
	fprintf(codeout,"%s",line6);
        fclose(codeout);

        printf("�޸ĳɹ���\n");
}

void modify_smokelimit(){
    char once[10];
    char line1[20];
    char line2[20];
    char line3[20];
    char line4[20];
    char line5[20];
    char line6[20];

	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line1,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fgets(line4,20,codein);
	fgets(line5,20,codein);
	fgets(line6,20,codein);
	fclose(codein);

	printf("��ǰ����Ũ����ֵΪ��%s",line5);
	printf("����������ֵ��");

	 while(1){
        scanf("%s",&once);
        if(atoi(once)<=0){
            printf("�������ֵ���Ϸ�������������: ");
        }
        else{
            smoke_limit = atoi(once);
            break;
        }
    }

	codeout = fopen("settings","w");
        fprintf(codeout,"%s",line1);
	fprintf(codeout,"%s",line2);
	fprintf(codeout,"%s",line3);
	fprintf(codeout,"%s",line4);
	fprintf(codeout,"%s\n",once);
	fprintf(codeout,"%s",line6);
        fclose(codeout);

        printf("�޸ĳɹ���\n");
}

void modify_startdelay(){
    char once[10];
    char line1[20];
    char line2[20];
    char line3[20];
    char line4[20];
    char line5[20];
    char line6[20];

	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line1,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fgets(line4,20,codein);
	fgets(line5,20,codein);
	fgets(line6,20,codein);
	fclose(codein);

	printf("��ǰϵͳ����ʱ�ӣ�%s",line6);
	printf("��������ʱ�ӣ�");
	scanf("%s",once);
	start_delay = atoi(once);

	codeout = fopen("settings","w");
        fprintf(codeout,"%s",line1);
	fprintf(codeout,"%s",line2);
	fprintf(codeout,"%s",line3);
	fprintf(codeout,"%s",line4);
	fprintf(codeout,"%s",line5);
	fprintf(codeout,"%s\n",once);
        fclose(codeout);

        printf("�޸ĳɹ���\n");
}


