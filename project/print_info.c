#include <stdio.h>

int check_pssword(char *pssword)
{
    return 1;

}
void login_info(char* pssword)
{
    int limittime = 5;
    int i = 0;
    int check;
    printf("��ӭ�����ͥ����ϵͳ�����������룬��ೢ�����\n");
    while(i<5){
        printf("����: ");
        scanf("%s",pssword);
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



