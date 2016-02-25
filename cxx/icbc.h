#pragma once
#include <Windows.h>
#include <iostream>
#include <string>

typedef unsigned char byte;
typedef struct
{
	byte  Track2[37]; /*二磁道信息 ，asc格式 最长37个字节 */
	byte  Track3[104];  /*三磁道信息 ,  asc 格式  最长 104个字节*/
	byte  Pwd[8]; /*加密后的密码  8个字节 */
	byte  Amount[12];  /* 金额， 分为单位000000000001 代表1分,不允许0金额,积分兑奖时为积分*/
	byte  Trace[6];     /* 终端流水，不是动态库的流水*/
	byte  OtherData[60];   /* 第三方关联数据 ，不足60位后补空格  见说明1*/
	byte  MerId[12];/*商户号*/
	byte  TerminalId[15];/*终端号*/
	byte  OrdTrace[6];/*原终端流水号，脱机批上送的时候为做脱机交易时调用 Bank_GetBankTrace取到的流水*/
	byte  OrgRetRefNo[8]; /* 原交易检索参考号 */
	byte  AccumulateCountAmount[108];	/* 仅结算交易有,格式见说明3*/
	byte  PrmVersionInfo[12 + 1];     /*参数版本号 ,初始值为010101000000*/
	byte  CAVersionInfo[8 + 1];     /* 公钥版本号.初始值01010100 */
	byte  InputMode;         /* 刷卡为0x31 ,fallback 为0x32, 插ic卡为0x33*/
	byte  PinInFlag;          /* 是否输密，0x31为输入密码, 0x30 未输密*/
	byte  Field55[255];        /*IC卡55域信息 见说明6*/
	byte  Field55len;          /*55域长度 */
	byte  SeqNum[2];         /*第一个字节:是否有卡序列号标志, 0x01 表示有0x00表示没有，第二个字节：实际卡序列号 */
	byte  OTranDate[8];        /* 原交易日期 YYYYMMDD*/
	byte  OTranTime[6];       /* 原交易时间 */
	byte  PreRetRefNo[15];     /* 检索参考号前缀，TC批上送，脚本通知需要,与检索参考号加起来是23位检索参考号*/
	byte  BatchNum[6];		/* 批次号 */
	byte  Pan[20];              /* 以0x00 结尾的卡号，TC 批上送,脚本通知要传*/
	byte  CtlsPrmVersionInfo[12 + 1];     /*非接参数版本号 ,初始值为010101000000*/
	byte  AuthID[6];          /*授权码 */
	byte  OrgTermId[15];          /* 原交易终端号，退货用*/
	byte  PaymentCode[40];     /* (有卡自助交易)付款代码，格式：14位YYYYMMDDHHMMSS+15位银行终端号，其余位右补空格填满40字节*/
	byte  JifenType;           /* 积分类型 取值积分标志：0－综合贡献 1－特定活动1  2－特定活动2  3－特定活动3  4－特定活动4  5－特定活动5  6－特定活动6  －联名积分 ,类型为 ascii 如果为0则为0x30 */
	byte  OfflineFlag;            /* 脱机交易标志 说明1：0x31为正常交易，0x30为已当日撤销交易  0x33 被撤销的固定金额，0x32 固定金额，0x34 扣钱且转联机  */
	byte  CupContactlessCard;     /* 是否银联电子现金卡 ,取值0x0 或0x1
								  电子现金，非'4','5'打头的卡*/
	byte  ExpDate[4];            /* 有效期, 脱机交易批上送的时候送*/
	byte  ContactlessSupFlg;     /* 是否支持非接，签到时传入 ,取值0x0 或0x1*/
	byte  CNPCFlag;            /* 是否中油终端,默认不是，送1是中油终端取值0x0 或0x1*/
	byte  FCardFlag;            /* 是否支持外卡 ,默认不支持,送1支持取值0x0 或0x1*/
	byte  Reverse[256];          /* 保留*/
} BANK_Input;

typedef struct
{
	byte  Trace[6];           /*行业应用流水号*/
	byte  DllTrace[6];        /* 动态库流水，即银行流水号  */
	byte  Amount[12];       /* 金额， 分为单位000000000001 代表1分 ,不一定与输入一致*/
	byte  BalanceAmount[13];  /* 卡片余额(查余额交易时返回)，第1位为正负标志，‘0’为正余额，‘1’为负余额；后12为余额值，分为单位*/

	byte  RetRefNo[8];  /*检索参考号 */
	byte  AuthID[6];          /*授权码 */
	byte  PrintPANnum[20];  /* 卡号,屏蔽后的 */
	byte  PANnum[20];      /* 未屏蔽的卡号，用于校验，不能打印出来 */
	byte  TranDate[8];        /* 交易日期 YYYYMMDD (BCD) */
	byte  TranTime[6];        /* 交易时间 HHMMSS (BCD)*/
	byte  CardTypeName[18]; /*卡类别名称（由主机直接从58域返回）*/
	byte  ExpDate[4];         /* 有效期 YYMM (BCD)*/
	byte  TerminalID[3];    /* 终端号后3位*/
	byte  MerchantID[12];    /*商户号 */
	byte  MerchantName[41];  /* 商户名称 */
	byte  Msg[20];            /* 错误提示信息,前两位错误码*/
	byte  IssueName[41];      /* 发卡行名称 */
	byte    BatchNum[6];		/* 批次号，结账类型为结账POS时返回*/
	byte    cardAccountType[2];   /*卡片主帐户类型，定义见说明2，如果第1字节为9表示外卡，否则表示国内卡*/
	byte  AccumulateCountAmount[108];	/*结账交易时，银行主机返回的累计数，格式与BANK_SettlementInputRes中同名字段一致 ,仅结算交易有.*/
	byte  PrmVersionInfo[12 + 1];     /*参数版本号 ,初始值为010101000000*/
	byte  CAVersionInfo[8 + 1];     /* 公钥版本号.初始值01010100 */
	byte  EMV_Info[999];         /* EMV参数和公钥信息,非接参数信息, 下参数时为EMV 参数 格式见说明4，下公钥时为公钥信息格式见说明5, 下非接参数时为非接参数信息，格式见说明7 */
	byte  EMV_InfoLen[2];        /*bcd 格式的长度，268 表示为 0x02 0x68 */
	byte  Ctrl_Flag[8];          /* 签到时返回是否下载参数和公钥,非接参数,下参数和公钥和非接参数时也会返回，用于控制是否下载结束，第一个字节（Ctrl_Flag[0]）为0x31 需要下参数，第二个字节（Ctrl_Flag[1]）为0x31,需要下载公钥,
								 第三个字节(Ctls_Flag[2])为0x31,需要下载非接参数。目前只在签到,下参数，下公钥,下非接参数交易使用*/
	byte  Field55[255];        /*IC卡55域信息 见说明6*/
	byte  Field55len;          /*55域长度 */
	byte  PreRetRefNo[15];     /* 检索参考号前缀，日志需保存，TC批上送,脚本通知需要*/
	byte  CtlsPrmVersionInfo[12 + 1];     /*非接参数版本号 ,初始值为010101000000*/
	byte OrgTermId[15];          /* 原交易终端号，跨商户的退货，预授权确认，撤销会有*/
	byte OrgTermName[41];        /* 原商户名称， 跨商户的退货，预授权确认，撤销会有*/
	byte  Reverse[256];          /* 保留*/
} BANK_Res;

typedef void(*TGetDllVersion)(char*);
typedef int(*TBank_Sale)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBank_Charge)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBank_Balance)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBank_Reversal)(byte *OrgPackData, int OrgDatalen, byte * PacketData, int *Datalen);
typedef int(*TBank_Logon)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBank_Void)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBank_UpdateEmvPara)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TUpdateCAKey)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TScriptAdvice)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBatchUp_TC)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBank_Settlement)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBank_PreAuth)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBank_PreAuthEnd)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBank_PreAuthVoid)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBank_AddPreAuth)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBank_GetBankTrace)(int *Trace);
typedef int(*TBank_UploadOfflineTrans)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBank_JiFenDuiJiang)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBank_Refund)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBank_UpdateCtlsEmvPara)(BANK_Input * p_Input, byte * PacketData, int *Datalen);
typedef int(*TBank_DataUnpack)(BANK_Res * p_res, byte * PacketData, int Datalen);

int init_icbc();
std::string GetDllVersion();
void test1(char *in, size_t in_sz);
