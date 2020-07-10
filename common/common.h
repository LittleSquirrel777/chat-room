/*************************************************************************
	> File Name: common.h
	> Author: 
	> Mail: 
	> Created Time: Tue 07 Jul 2020 03:54:22 PM CST
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H
//char comf_ans[50] = {0};

int socket_create(int port);
void make_non_block(int fd);
void make_block(int fd);
char *get_conf_value(char *path, char *key);
#ifdef _D
#define DBG(fmt, args...) printf(fmt, ##args)
#else
#define DBG(fmt, args...)
#endif

#endif
