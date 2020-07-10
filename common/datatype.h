/*************************************************************************
	> File Name: datatype.h
	> Author: 
	> Mail: 
	> Created Time: Thu 09 Jul 2020 10:09:56 AM CST
 ************************************************************************/

#ifndef _DATATYPE_H
#define _DATATYPE_H

#define MAX 300 //用户数的二分之一
#define NTHREAD 3
//球相关
struct Score {
    int red;
    int blue;
};
struct Bpoint {
    double x;
    double y;
};

struct Speed {
    double x;
    double y;
};

struct Aspeed {
    double x;
    double y;
};

struct BallStatus {
    struct Speed v;
    struct Aspeed a;
    int who;    //which 队伍
    char name[20];
};
//球员相关
struct Point {
    int x;
    int y;
};

struct User {
    int team;   //0 红队 1 蓝队
    int fd;     //该玩家对应的连接
    char name[20];
    int online;     //1 在线 0 不在线
    int flag;   //未响应次数
    struct Point loc;
};
        //数据交互相关

//登录相关
struct LogRequest {
    char name[20];
    int team;
    char msg[512];

};

struct LogResponse {
    int type;   //0 OK 1 NO
    char msg[512];
};

//游戏期间交互
#define MAX_MSG 4096
//日常的消息交互，如聊天消息，统一为512长度
#define FT_HEART 0x01 //心跳
#define FT_WALL 0x02 //公告
#define FT_MSG 0x04 //聊天信息
#define FT_ACK 0x08 //用来确认在不在
#define FT_CTL 0x10 //控制信息
#define FT_GAME 0x20 //游戏场景数据
#define FT_SCORE 0x40 //比分变换
#define FT_GAMEOVER 0x80//gameover
#define FT_FIN 0x100 //离场

#define ACTION_KICK 0x01
#define ACTION_CARRY 0x02
#define ACTION_STOP 0x04
struct Ctl {
    int action;
    int dirx;
    int diry;
    int strength;
};

struct FootBallMsg {
    int type; //type & FT_HEART
    int size;
    int team;
    char name[20];
    struct Ctl ctl;
};

#define CHAT_FIN 0x01 //断开
#define CHAT_HEART 0x02
#define CHAT_ACK 0x04
#define CHAT_WALL 0x08 //公聊
#define CHAT_MSG 0x10 //私聊
#define CHAT_FUNC 0x20 //功能
struct ChatMsg {
    int type;
    char msg[1024];

};
//球场相关
struct Map {
    int width;
    int height;
    struct Point start;
    int gate_width;
    int gate_height;
};
#endif