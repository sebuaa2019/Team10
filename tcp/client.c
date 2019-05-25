#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<unistd.h> 
#include<arpa/inet.h>
 
 
#define DEST_PORT 1500//Ŀ���ַ�˿ں� 
#define DEST_IP "127.0.0.1"/*Ŀ���ַIP��������Ϊ����*/ 
#define MAX_DATA 100//���յ����������̶� 
 
int main(){
	int sockfd,new_fd;/*cocket����ͽ��ܵ����Ӻ�ľ�� */
	struct sockaddr_in dest_addr;/*Ŀ���ַ��Ϣ*/
	char buf[MAX_DATA];//����������� 
 
	sockfd=socket(AF_INET,SOCK_STREAM,0);/*����socket*/
	if(sockfd==-1){
		printf("socket failed:%d",errno);
	}
 
 
	//�������������������� 
	dest_addr.sin_family=AF_INET;
 	dest_addr.sin_port=htons(DEST_PORT);
	dest_addr.sin_addr.s_addr=inet_addr(DEST_IP);
	bzero(&(dest_addr.sin_zero),8);
	
	if(connect(sockfd,(struct sockaddr*)&dest_addr,sizeof(struct sockaddr))==-1){//���ӷ�������������Ŀ���ַ�ʹ�С 
		printf("connect failed:%d",errno);//ʧ��ʱ���Դ�ӡerrno 
	} else{
		printf("connect success\n");
		recv(sockfd,buf,MAX_DATA,0);//���������ݴ���buf�������ֱ��Ǿ�������洦����󳤶ȣ�������Ϣ����Ϊ0���ɣ��� 
		printf("Received:%s",buf);
	}
	close(sockfd);//�ر�socket 
	return 0;
} 

