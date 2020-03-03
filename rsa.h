typedef struct str{
    char msg[100];
    int msg_int[100];
}str;

str encry_inter(int choice, str src);

void num_to_str(char * output, long num); //to convert the numbers in the user struct into strings 

long int p,q,n,t,flag,e[100],d[100],j,m[100],en[100]; 
char msg[100]; 
int prime(long int); 
void ce(); 
long int cd(long int); 
str encrypt(); 
str decrypt(); 
