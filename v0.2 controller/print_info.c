#include <stdio.h>

int check_pssword(char *usrname, char *pssword)
{
    //��ѯ�����û����Ƿ�ƥ�䣬�ɹ�return 1, ʧ�� -1
    return 1;
}
void login_info(char* usrname, char* pssword)
{
    printf("��ӭ�����ͥ����ϵͳ�����ȵ�½\n");
    while(1){
        printf("�û�����");
        scanf("%s",usrname);
        printf("����: ");
        scanf("%s",pssword);
        int check = check_pssword(usrname,pssword);
        if(check==1) {
            printf("��½�ɹ���\n");
            break;
        }
        printf("�û����������������������\n");
    }
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
    printf("6: �ǳ�ϵͳ\n");
    scanf("%d",&id);
    return id;
}



