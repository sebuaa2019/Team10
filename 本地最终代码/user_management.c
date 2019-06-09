#include <stdio.h>
#include <string.h>
#include "user_management.h"

char name[500]; 
char address[500]; 
char user_phone[500]; 
char alarm_phone[500]; 
char file_path[500]; 
FILE *fp;   
int user_init=0;

int user_information(){
    int number;
    char content[500];
    if(user_init==0){
	creat("user.txt",00700);
    	if((fp=fopen("user.txt","w"))==NULL){
            printf("�޷����û���Ϣ�ļ�\n");
    	}
   	fputs("user001\n",fp);
    	fputs("beihang\n",fp);
    	fputs("15652580010\n",fp);
    	fputs("110\n",fp);
    	fclose(fp);
    }
    user_init=1;
    printf("���ѽ����û���Ϣ����ϵͳ\n");
    while(1){
        printf("����1:��ѯ�û���Ϣ\n����2:�޸��û���Ϣ\n����3:�˳��û���Ϣ����ϵͳ\n");
        number = keyboard_single();
        if(number==1){
            printf("����1:��ѯ�û�����\n");
            printf("����2:��ѯ�û���ַ\n");
            printf("����3:��ѯ�û��绰\n");
            printf("����4:��ѯ�����绰\n");
            number = keyboard_single();
            if(number==1){
                printf("�û�����Ϊ:%s\n",query_name());
            }
            else if(number==2){
                printf("�û���ַΪ:%s\n",query_address());
            }
            else if(number==3){
                printf("�û��绰Ϊ:%s\n",query_user_phone());
            }
            else if(number==4){
                printf("�����绰Ϊ:%s\n",query_alarm_phone());
            }
        }
        else if(number==2){
            printf("����1:�޸��û�����\n");
            printf("����2:�޸��û���ַ\n");
            printf("����3:�޸��û��绰\n");
            printf("����4:�޸ı����绰\n");
            number = keyboard_single();
            if(number==1){
                printf("�������µ��û�����\n");
                scanf("%s",content);
                save_name(content);
            }
            else if(number==2){
                printf("�������µ��û���ַ\n");
                scanf("%s",content);
                save_address(content);
            }
            else if(number==3){
                printf("�������µ��û��绰\n");
                scanf("%s",content);
                save_user_phone(content);
            }
            else if(number==4){
                printf("�������µı����绰\n");
                scanf("%s",content);
                save_alarm_phone(content);
            }
        }
        else if(number==3){
            printf("�ѳɹ��˳��û�����ϵͳ\n");
            break;
        }
    }

    return 1;
}

int change_user_file_path(char* new_path)
{
    strcpy(file_path,new_path);
    return 1;
}

int open_file_for_read()
{
    if((fp=fopen(file_path,"r"))==NULL){
        printf("�޷����û���Ϣ�ļ�\n");
        return 0;
    }
    else{
      
        return 1;
    }
}

int open_file_for_write()
{
    if((fp=fopen(file_path,"r+"))==NULL){
        printf("�޷����û���Ϣ�ļ�\n");
        return 0;
    }
    else{
        
        return 1;
    }
}

int close_file(){
    fclose(fp);
    return 1;
}

int save_name(char* name_to_save)
{
    int err;

    if((err=change_line(1,name_to_save))==1){
        printf("�û������޸ĳɹ���\n");
        return 1;
    }
    else{
        printf("�û������޸�ʧ�ܣ�\n");
        return 0;
    }
}

int save_address(char* address_to_save)
{
    int err;
    if((err=change_line(2,address_to_save))==1){
        printf("�û���ַ�޸ĳɹ���\n");
        return 1;
    }
    else{
        printf("�û���ַ�޸�ʧ�ܣ�\n");
        return 0;
    }
}

int save_user_phone(char* user_phone_to_save)
{
    int err;
    if((err=change_line(3,user_phone_to_save))==1){
        printf("�û��绰�޸ĳɹ���\n");
        return 1;
    }
    else{
        printf("�û��绰�޸�ʧ�ܣ�\n");
        return 0;
    }
}

int save_alarm_phone(char* alarm_phone_to_save)
{
    int err;
    if((err=change_line(4,alarm_phone_to_save))==1){
        printf("�����绰�޸ĳɹ���\n");
        return 1;
    }
    else{
        printf("�����绰�޸�ʧ�ܣ�\n");
        return 0;
    }
}


int change_line(int line,char* content)

{
    int i=0;
    char str[10][100]={0},linedata[100]={0};
    FILE *fpw;
    fp=fopen("user.txt","r");
    while (fgets(linedata,sizeof(linedata)-1,fp))
    {
        if(i>=4){
            break;
        }
        if (i==line-1)
        {
            strcpy(str[i],content);
            strcat(str[i],"\n");

        }else
        {
            strcpy(str[i],linedata);
        }
        i++;
    }
    fpw = fopen("user.txt","w");
    for (i=0;i<4;i++)
    {
        fputs(str[i],fpw);
    }
    fclose(fpw);
    return 1;
}

int check_file(){
    int i=0;
    char linedata[100]={0};
    change_user_file_path("user.txt");
    open_file_for_read();
    while (fgets(linedata,sizeof(linedata)-1,fp))
    {
        i++;
        if(i==1){
            strcpy(name,linedata);
        }
        else if(i==2){
            strcpy(address,linedata);
        }
        else if(i==3){
            strcpy(user_phone,linedata);
        }
        else if(i==4){
            strcpy(alarm_phone,linedata);
        }
    }
    close_file();
    if(i<4){
        printf("�û���Ϣ��ȫ���벹������!\n");
        return 0;
    }
    else{
        return 1;
    }
}

char* query_name(){
    if(check_file()==1){
        return name;
    }
    else{
        return "�û���Ϣ��ȫ����ѯʧ��";
    }
}

char* query_address(){
    if(check_file()==1){
        return address;
    }
    else{
        return "�û���Ϣ��ȫ����ѯʧ��";
    }
}

char* query_user_phone(){
    if(check_file()==1){
        return user_phone;
    }
    else{
        return "�û���Ϣ��ȫ����ѯʧ��";
    }
}

char* query_alarm_phone(){
    if(check_file()==1){
        return alarm_phone;
    }
    else{
        return "�û���Ϣ��ȫ����ѯʧ��";
    }
}
