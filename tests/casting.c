main(){
	short s = 256;
	char i = s;
	printf("%d %d %d\n",1<<8*(sizeof(int)-1),1<<8*(sizeof(short))-1,1<<8*(sizeof(char))-1);}
