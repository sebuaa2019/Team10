#include <stdio.h>
#include <io.h>

int check_pssword(char *pssword)
{
    FILE *check;
    char right[10];
    check = fopen("settings","r");
    fgets(right,10,check);
    if(strcmp(right,pssword) == 0) return 1;
    else return 0;
    //��ѯ�����û����Ƿ�ƥ�䣬�ɹ�return 1, ʧ�� -1
}
void login_info(char* pssword)
{
    printf("��ӭ�����ͥ����ϵͳ�����������룬��ೢ�����\n");
    int limittime = 5; //����������
    int i = 0;
    while(i<5){
        printf("����: ");
        scanf("%s",pssword);
        int check = check_pssword(pssword);
        if(check==1) {
            printf("��½�ɹ���\n");
            break;
        }
        printf("�����������������\n");
        i++;
    }
    if(i == 5) exit(0);
}
int choose_func()
{
    int id;
    printf("����������Ҫ�Ĺ���:(�����Ӧ���)\n");
    printf("1: ��װϵͳ\n");
    printf("2: ���ϵͳ\n");
    printf("3: ������ͷ���ӷ���\n");
    printf("4: �������\n");
    printf("5: ��������ϵͳ�򴫸���\n");
    printf("6: �޸�����������\n");
    printf("7: �û���Ϣ��ѯ���޸�\n");
    printf("8: �ǳ�ϵͳ\n");
    scanf("%d",&id);
    return id;
}



