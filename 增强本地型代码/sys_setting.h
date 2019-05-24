#ifndef SYS_SETTING_H_INCLUDED
#define SYS_SETTING_H_INCLUDED
#include "print_info.h"
#include "safety.h"

int code_delay; /*��Ӧ�����Ժ������û��������ʱ��*/
int start_delay;
int smoke_limit; /*����Ũ�ȱ�������*/

void init_sys(); /*����ϵͳʱ�ĳ�ʼ��*/
void change_code(); /*�޸�����*/
void write_new_code(); /*��������洢����*/
void modify_settings();/*�޸ĸ�������*/
void modify_delay();/*�޸ı������*/
void modify_phonenum();/*�޸ı����绰*/
void modify_codedelay(); /*�޸����������������ʱ�䳤��*/
void modify_smokelimit(); /*�޸�����Ũ����ֵ*/
void modify_startdelay(); /*�޸Ŀ���ϵͳʱ��*/

#endif // SYS_SETTING_H_INCLUDED
