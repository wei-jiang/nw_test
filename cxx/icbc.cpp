
#include "icbc.h"

using namespace std;
TGetDllVersion g_GetDllVersion = NULL;
TBank_Sale g_Bank_Sale = NULL;
TBank_Charge g_Bank_Charge = NULL;
TBank_Balance g_Bank_Balance = NULL;
TBank_Reversal g_Bank_Reversal = NULL;
TBank_Logon g_Bank_Logon = NULL;
TBank_Void g_Bank_Void = NULL;
TBank_UpdateEmvPara g_Bank_UpdateEmvPara = NULL;
TUpdateCAKey g_UpdateCAKey = NULL;
TScriptAdvice g_ScriptAdvice = NULL;
TBatchUp_TC g_BatchUp_TC = NULL;
TBank_Settlement g_Bank_Settlement = NULL;
TBank_PreAuth g_Bank_PreAuth = NULL;
TBank_PreAuthEnd g_Bank_PreAuthEnd = NULL;
TBank_PreAuthVoid g_Bank_PreAuthVoid = NULL;
TBank_AddPreAuth g_Bank_AddPreAuth = NULL;
TBank_GetBankTrace g_Bank_GetBankTrace = NULL;
TBank_UploadOfflineTrans g_Bank_UploadOfflineTrans = NULL;
TBank_JiFenDuiJiang g_Bank_JiFenDuiJiang = NULL;
TBank_Refund g_Bank_Refund = NULL;
TBank_UpdateCtlsEmvPara g_Bank_UpdateCtlsEmvPara = NULL;
TBank_DataUnpack g_Bank_DataUnpack = NULL;

int init_icbc() {
	HINSTANCE icbcLibHandle = LoadLibrary("c:\\ICBCTRansLib");;
	if (icbcLibHandle)
	{
		cout << "load icbc library(ICBCTRansLib) succeed\n";
		g_GetDllVersion = (TGetDllVersion)GetProcAddress(icbcLibHandle, "GetDllVersion");
		g_GetDllVersion ? cout << "get GetDllVersion succeed\n" : cout << "get GetDllVersion failed\n";
		g_Bank_Sale = (TBank_Sale)GetProcAddress(icbcLibHandle, "Bank_Sale");
		g_Bank_Sale ? cout << "get Bank_Sale succeed\n" : cout << "get Bank_Sale failed\n";
		g_Bank_Charge = (TBank_Charge)GetProcAddress(icbcLibHandle, "Bank_Charge");
		g_Bank_Charge ? cout << "get Bank_Charge succeed\n" : cout << "get Bank_Charge failed\n";
		g_Bank_Balance = (TBank_Balance)GetProcAddress(icbcLibHandle, "Bank_Balance");
		g_Bank_Balance ? cout << "get Bank_Balance succeed\n" : cout << "get Bank_Balance failed\n";
		g_Bank_Reversal = (TBank_Reversal)GetProcAddress(icbcLibHandle, "Bank_Reversal");
		g_Bank_Reversal ? cout << "get Bank_Reversal succeed\n" : cout << "get Bank_Reversal failed\n";
		g_Bank_Logon = (TBank_Logon)GetProcAddress(icbcLibHandle, "Bank_Logon");
		g_Bank_Logon ? cout << "get Bank_Logon succeed\n" : cout << "get Bank_Logon failed\n";
		g_Bank_Void = (TBank_Void)GetProcAddress(icbcLibHandle, "Bank_Void");
		g_Bank_Void ? cout << "get Bank_Void succeed\n" : cout << "get Bank_Void failed\n";
		g_Bank_UpdateEmvPara = (TBank_UpdateEmvPara)GetProcAddress(icbcLibHandle, "Bank_UpdateEmvPara");
		g_Bank_UpdateEmvPara ? cout << "get Bank_UpdateEmvPara succeed\n" : cout << "get Bank_UpdateEmvPara failed\n";
		g_UpdateCAKey = (TUpdateCAKey)GetProcAddress(icbcLibHandle, "UpdateCAKey");
		g_UpdateCAKey ? cout << "get UpdateCAKey succeed\n" : cout << "get UpdateCAKey failed\n";
		g_ScriptAdvice = (TScriptAdvice)GetProcAddress(icbcLibHandle, "ScriptAdvice");
		g_ScriptAdvice ? cout << "get ScriptAdvice succeed\n" : cout << "get ScriptAdvice failed\n";
		g_BatchUp_TC = (TBatchUp_TC)GetProcAddress(icbcLibHandle, "BatchUp_TC");
		g_BatchUp_TC ? cout << "get BatchUp_TC succeed\n" : cout << "get BatchUp_TC failed\n";
		g_Bank_Settlement = (TBank_Settlement)GetProcAddress(icbcLibHandle, "Bank_Settlement");
		g_Bank_Settlement ? cout << "get Bank_Settlement succeed\n" : cout << "get Bank_Settlement failed\n";
		g_Bank_PreAuth = (TBank_PreAuth)GetProcAddress(icbcLibHandle, "Bank_PreAuth");
		g_Bank_PreAuth ? cout << "get Bank_PreAuth succeed\n" : cout << "get Bank_PreAuth failed\n";
		g_Bank_PreAuthEnd = (TBank_PreAuthEnd)GetProcAddress(icbcLibHandle, "Bank_PreAuthEnd");
		g_Bank_PreAuthEnd ? cout << "get Bank_PreAuthEnd succeed\n" : cout << "get Bank_PreAuthEnd failed\n";
		g_Bank_PreAuthVoid = (TBank_PreAuthVoid)GetProcAddress(icbcLibHandle, "Bank_PreAuthVoid");
		g_Bank_PreAuthVoid ? cout << "get Bank_PreAuthVoid succeed\n" : cout << "get Bank_PreAuthVoid failed\n";
		g_Bank_AddPreAuth = (TBank_AddPreAuth)GetProcAddress(icbcLibHandle, "Bank_AddPreAuth");
		g_Bank_AddPreAuth ? cout << "get Bank_AddPreAuth succeed\n" : cout << "get Bank_AddPreAuth failed\n";
		g_Bank_GetBankTrace = (TBank_GetBankTrace)GetProcAddress(icbcLibHandle, "Bank_GetBankTrace");
		g_Bank_GetBankTrace ? cout << "get Bank_GetBankTrace succeed\n" : cout << "get Bank_GetBankTrace failed\n";
		g_Bank_UploadOfflineTrans = (TBank_UploadOfflineTrans)GetProcAddress(icbcLibHandle, "Bank_UploadOfflineTrans");
		g_Bank_UploadOfflineTrans ? cout << "get Bank_UploadOfflineTrans succeed\n" : cout << "get Bank_UploadOfflineTrans failed\n";
		g_Bank_JiFenDuiJiang = (TBank_JiFenDuiJiang)GetProcAddress(icbcLibHandle, "Bank_JiFenDuiJiang");
		g_Bank_JiFenDuiJiang ? cout << "get Bank_JiFenDuiJiang succeed\n" : cout << "get Bank_JiFenDuiJiang failed\n";
		g_Bank_Refund = (TBank_Refund)GetProcAddress(icbcLibHandle, "Bank_Refund");
		g_Bank_Refund ? cout << "get Bank_Refund succeed\n" : cout << "get Bank_Refund failed\n";
		g_Bank_UpdateCtlsEmvPara = (TBank_UpdateCtlsEmvPara)GetProcAddress(icbcLibHandle, "Bank_UpdateCtlsEmvPara");
		g_Bank_UpdateCtlsEmvPara ? cout << "get Bank_UpdateCtlsEmvPara succeed\n" : cout << "get Bank_UpdateCtlsEmvPara failed\n";
		g_Bank_DataUnpack = (TBank_DataUnpack)GetProcAddress(icbcLibHandle, "Bank_DataUnpack");
		g_Bank_DataUnpack ? cout << "get Bank_DataUnpack succeed\n" : cout << "get Bank_DataUnpack failed\n";

	}
	else
	{
		cout << "load icbc library failed! exit\n";
		return -1;
	}	
	
	return 0;
}
std::string GetDllVersion()
{
	if (g_GetDllVersion)
	{
		char v[256] = { 0 };
		g_GetDllVersion(v);
		return v;
	}
	cout << "GetDllVersion uninitiliazed\n";
	return "api未初始化";
}
void test1(char *in, size_t in_sz)
{
	for (size_t i = 0; i < in_sz; ++i)
	{
		printf("%x", in[i]);
	}
	cout << endl;
}
int Bank_Sale(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_Bank_Sale)
	{
		cout << "Bank_Sale api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_Bank_Sale(in, (byte*)PacketData, Datalen);
}
int Bank_Charge(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_Bank_Charge)
	{
		cout << "Bank_Charge api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_Bank_Charge(in, (byte*)PacketData, Datalen);
}
int Bank_Balance(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_Bank_Balance)
	{
		cout << "Bank_Balance api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_Bank_Balance(in, (byte*)PacketData, Datalen);
}
int Bank_Reversal(char *OrgPackData, int OrgDatalen, char * PacketData, int *Datalen)
{
	if (!g_Bank_Reversal)
	{
		cout << "Bank_Reversal api uninitialized\n";
		return -1;
	}
	return g_Bank_Reversal( (byte*)OrgPackData, OrgDatalen, (byte*)PacketData, Datalen);
}
int Bank_Logon(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_Bank_Logon)
	{
		cout << "Bank_Logon api uninitialized\n";
		return -1;
	}
	
	BANK_Input *in = (BANK_Input*)p_Input;
	//test1((char*)in->PrmVersionInfo, 13);
	//test1((char*)in->CAVersionInfo, 9);
	return g_Bank_Logon(in, (byte*)PacketData, Datalen);
}
int Bank_Void(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_Bank_Void)
	{
		cout << "Bank_Void api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_Bank_Void(in, (byte*)PacketData, Datalen);
}
int Bank_UpdateEmvPara(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_Bank_UpdateEmvPara)
	{
		cout << "Bank_UpdateEmvPara api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_Bank_UpdateEmvPara(in, (byte*)PacketData, Datalen);
}
int UpdateCAKey(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_UpdateCAKey)
	{
		cout << "UpdateCAKey api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_UpdateCAKey(in, (byte*)PacketData, Datalen);
}
int ScriptAdvice(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_ScriptAdvice)
	{
		cout << "ScriptAdvice api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_ScriptAdvice(in, (byte*)PacketData, Datalen);
}
int BatchUp_TC(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_BatchUp_TC)
	{
		cout << "BatchUp_TC api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_BatchUp_TC(in, (byte*)PacketData, Datalen);
}
int Bank_Settlement(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_Bank_Settlement)
	{
		cout << "Bank_Settlement api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_Bank_Settlement(in, (byte*)PacketData, Datalen);
}
int Bank_PreAuth(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_Bank_PreAuth)
	{
		cout << "Bank_PreAuth api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_Bank_PreAuth(in, (byte*)PacketData, Datalen);
}
int Bank_PreAuthEnd(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_Bank_PreAuthEnd)
	{
		cout << "Bank_PreAuthEnd api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_Bank_PreAuthEnd(in, (byte*)PacketData, Datalen);
}
int Bank_PreAuthVoid(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_Bank_PreAuthVoid)
	{
		cout << "Bank_PreAuthVoid api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_Bank_PreAuthVoid(in, (byte*)PacketData, Datalen);
}
int Bank_AddPreAuth(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_Bank_AddPreAuth)
	{
		cout << "Bank_AddPreAuth api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_Bank_AddPreAuth(in, (byte*)PacketData, Datalen);
}
int Bank_GetBankTrace( int *Trace)
{
	if (!g_Bank_GetBankTrace)
	{
		cout << "Bank_GetBankTrace api uninitialized\n";
		return -1;
	}
	return g_Bank_GetBankTrace(Trace);
}
int Bank_UploadOfflineTrans(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_Bank_UploadOfflineTrans)
	{
		cout << "Bank_UploadOfflineTrans api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_Bank_UploadOfflineTrans(in, (byte*)PacketData, Datalen);
}
int Bank_JiFenDuiJiang(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_Bank_JiFenDuiJiang)
	{
		cout << "Bank_JiFenDuiJiang api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_Bank_JiFenDuiJiang(in, (byte*)PacketData, Datalen);
}
int Bank_Refund(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_Bank_Refund)
	{
		cout << "Bank_Refund api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_Bank_Refund(in, (byte*)PacketData, Datalen);
}
int Bank_UpdateCtlsEmvPara(char * p_Input, char * PacketData, int *Datalen)
{
	if (!g_Bank_UpdateCtlsEmvPara)
	{
		cout << "Bank_UpdateCtlsEmvPara api uninitialized\n";
		return -1;
	}
	BANK_Input *in = (BANK_Input*)p_Input;
	return g_Bank_UpdateCtlsEmvPara(in, (byte*)PacketData, Datalen);
}
int Bank_DataUnpack(char * p_res, char * PacketData, int Datalen)
{
	if (!g_Bank_DataUnpack)
	{
		cout << "Bank_DataUnpack api uninitialized\n";
		return -1;
	}
	BANK_Res *out = (BANK_Res*)p_res;
	return g_Bank_DataUnpack(out, (byte*)PacketData, Datalen);
}