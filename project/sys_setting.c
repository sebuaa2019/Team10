#include "print_info.h"
#include "safety.h"

void init_sys(); /*����ϵͳʱ�ĳ�ʼ��*/
void change_code(); /*�޸�����*/
void write_new_code(); /*��������洢����*/
void modify_settings();/*�޸ĸ�������*/
void modify_delay();/*�޸ı������*/
void modify_phonenum();/*�޸ı����绰*/

void init_sys(){
    FILE *code;
	if((code = fopen("settings","w")) == NULL){
 		creat("settings",00700);       
		code = fopen("settings","w");
        	fprintf(code,"123456\n");
		fprintf(code,"20\n");
		fprintf(code,"13900000000\n");
        	fclose(code);
	}
}

void modify_settings(){
    int choice;
    printf("��ѡ��Ҫ�޸ĵ���Ŀ\n");
    printf("1: �޸�����\n");
    printf("2: �޸Ĳ��ż��\n");
    printf("3: �޸ı����绰\n");
    printf("4: �����޸�\n");
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
	    break;
    }
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
	fclose(codein);

	codeout = fopen("settings","w");	
        fprintf(codeout,"%s\n",once);
	fprintf(codeout,"%s",line2);
	fprintf(codeout,"%s",line3);
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

	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line1,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fclose(codein);

	printf("��ǰ�������Ϊ(��λ��s)��%s",line2);
	printf("�������±��������");
	scanf("%s",once);

	codeout = fopen("settings","w");	
        fprintf(codeout,"%s",line1);
	fprintf(codeout,"%s\n",once);
	fprintf(codeout,"%s",line3);
        fclose(codeout);
	
        printf("�޸ļ���ɹ���\n");

}

void modify_phonenum(){
    char once[10];
    char line1[20];
    char line2[20];
    char line3[20];

	FILE *codein;
        FILE *codeout;

        codein = fopen("settings","r");
	fgets(line1,20,codein);
	fgets(line2,20,codein);
	fgets(line3,20,codein);
	fclose(codein);

	printf("��ǰ�����绰Ϊ��%s",line3);
	printf("�������±����绰��");
	scanf("%s",once);

	codeout = fopen("settings","w");	
        fprintf(codeout,"%s",line1);
	fprintf(codeout,"%s",line2);
	fprintf(codeout,"%s\n",once);
        fclose(codeout);
	
        printf("�޸ĵ绰�ɹ���\n");
}

void modify_sys(){
    int id;
    printf("���ѽ���ϵͳ�����޸�����\n");
    printf("����������Ҫ�Ĺ���:(�����Ӧ���)\n");
    printf("1: �޸Ĵ���������\n");
    printf("2: �˳�ϵͳ�����޸�����\n");
    scanf("%d",&id);
    switch(id)
    {
        case 1:{
            modify_sensor_setting();
            break;
        }
        case 2:{
            printf("�����˳�ϵͳ�����޸�����\n");
            break;
        }
    }
}