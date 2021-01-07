#ifndef _STDLIB_H_
#	define _STDLIB_H_
#	include <stdlib.h>
#	define new_init()	(char*)malloc(sizeof(char))
	typedef char* String;
#else
#	define new_init()	(char*)malloc(sizeof(char))
	typedef char* String;
#endif

#ifndef _STDIO_H_
#	define _STDIO_H_
#	include <stdio.h>
#endif

void str_input(String s)
{
	*s=getchar();	
	for(size_t i=0;s[i]!='\n';++i){
		s[i+1]=getchar();
	}
}

int str_fout(String s,const char* __namefile)
{
	FILE* fp=fopen(__namefile,"w"); //apro il file in modalià scrittura
	int done=0;
	
	if(fp){ //se il file è stato aperto allora
		fputs(s,fp); //scrivi la stringa dentro il file puntato da fp
	}else{
		done=EOF; //altrimenti ritorna EOF
	}
	fclose(fp);
	
return done;
}

int str_fin(String s,const char* __namefile)
{
	//input riga iniziale (no spazio)
	
	int done=0;
	
	FILE* fp=fopen(__namefile,"r"); //apro il file in modalià scrittura
	if(fp){
		fscanf(fp,"%s",s);
	}else{
		done=EOF;
	}
	fclose(fp);
return done;
}
	
	
