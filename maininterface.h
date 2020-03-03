typedef struct netinfo1
{char use[50],username[100],emailid[100],phonenumber[100],pin[5];
char userkey[11];
char pass[11];
int use_i[50],username_i[100],emailid_i[100],phonenumber_i[100],pin_i[5];
int userkey_i[11];
int pass_i[11];}
netinfo;

typedef struct pass_dat1
{netinfo info;
struct pass_dat *link;}
pass_dat;

