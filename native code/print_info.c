#include <stdio.h>
#include <string.h>

int check_pssword(char *pssword)
{
    /*FILE *check;
    char right[10];
    check = fopen("settings","r");
    fgets(right,10,check);
    right[strlen(right)-1] = '\0';
    fclose(check);
    if(strcmp(right,pssword) == 0) return 1;
    else return 0;*/
	return 1;
    /*��ѯ�����û����Ƿ�ƥ�䣬�ɹ�return 1, ʧ�� -1*/
}

void login_info(char* pssword)
{
    int limittime = 5;
    int i = 0;
    int check;
    printf("��ӭ�����ͥ����ϵͳ�����������룬��ೢ�����\n");
    while(i<5){
        printf("����: ");
        strcpy(pssword,keyboard_long());
	/*scanf("%s",pssword);*/
        check = check_pssword(pssword);
        if(check==1) {
            printf("��½�ɹ���\n");
            break;
        }
        printf("�����������������\n");
        i++;
    }
    if(i == 5) exit(0);
}

void open_close(char* pssword,int type)
{
    int limittime = 5;
    int i = 0;
    int check;
    char type_char[50];

    if(type==0){
        strcpy(type_char,"����");
    }
    else if(type==1){
        strcpy(type_char,"�ر�");
    }
    printf("%sϵͳ�����������룬��ೢ�����\n",type_char);
    while(i<5){
        printf("����: ");
        /*scanf("%s",pssword);*/
	strcpy(pssword,keyboard_code());
        check = check_pssword(pssword);
        if(check==1) {
            printf("%s�ɹ���\n",type_char);
            break;
        }
        printf("�����������������\n");
        i++;
    }
    if(i == 5) {
        printf("%sʧ��\n");
    };
}

int choose_func()
{
    int id;
    printf("����������Ҫ�Ĺ���:(�����Ӧ���)\n");
    printf("ARM��װϵͳ\n");
    printf("DISARM���ϵͳ\n");
    printf("1: ������ͷ���ӷ���\n");
    printf("2: �������\n");
    printf("3: ��������ϵͳ�򴫸���\n");
    printf("4: �޸�����������\n");
    printf("5: �û���Ϣ��ѯ���޸�\n");
    printf("6: �ǳ�ϵͳ\n");
    id = keyboard_single();
    return id;
}



