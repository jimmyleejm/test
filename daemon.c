//���ߣ�jdh  
//ʱ�䣺2012-2-27  
#include <stdio.h>  
#include <unistd.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <fcntl.h>  
#include <syslog.h>  
#include <signal.h>
#include <string.h>
/*  
int daemon1(int nochdir,int noclose)  
{  
    pid_t pid;  
  
    //��init���̳�Ϊ�²������̵ĸ�����  
    pid = fork();  
    //�����������ʧ��  
    if (pid < 0)  
    {  
        perror("fork");  
        return -1;  
    }  
    //�������˳�����  
    if (pid != 0)  
    {  
        exit(0);  
    }  
    //�����µĻỰ  
    pid = setsid();  
    if (pid < -1)  
    {  
        perror("set sid");  
        return -1;  
    }  
    //���ĵ�ǰ����Ŀ¼,������Ŀ¼�޸ĳɸ�Ŀ¼  
    if (!nochdir)  
    {  
        chdir("/");  
    }  
    //�ر��ļ������������ض����׼���룬����ϴ������  
    //����׼��������ض��򵽿��豸  
    
    if (!noclose)  
    {  
        int fd;  
        fd = open("/dev/null",O_RDWR,0);  
        if (fd != -1)  
        {  
            dup2(fd,STDIN_FILENO);  
            dup2(fd,STDOUT_FILENO);  
            dup2(fd,STDERR_FILENO);  
            if (fd > 2)  
            {  
                close(fd);  
            }  
        }  
    }  
    //�����ػ����̵��ļ�Ȩ�޴�������  
    umask(0027);  
  
    return 0;  
}  
 */ 

int main(int argc,char *argv[])  
{  

    char buf[100];  
  	FILE*fp_check ;
    //�����ػ�����  
  //  daemon1(0,0); 
    int pid; 
  
    while (1)  
    {  
        //����־  
      //  openlog(argv[0],LOG_CONS|LOG_PID,LOG_USER);  
          
        //�鿴�����Ƿ�����  
        //�½�����ļ�  
        system("touch /mnt/nand1-1/daemon_file");  
        //��ó���ID  
        system("pgrep mtest2 >> /mnt/nand1-1/daemon_file");  
        //������ļ�  
        fp_check=fopen("/mnt/nand1-1/daemon_file","r");
        //��ջ���  
        memset(buf,0,100);  
        //��ȡȫ��  
      	fgets(buf,sizeof(buf),fp_check);
      	
      	
				if(strlen(buf)>0)
					{
						printf("buf is %s\n",buf);
						//pid=atoi(buf);
					}
				else
					{
						printf( "it's dead.\n");
						 system("cd /mnt/nand1-1/"); 
						 system("./mtest2");  
				//	sleep(5); 
				//	continue;
					}
				/*						
				if(kill(pid,0)!=0)  
					{
			   printf( "it's dead.\n");
			    }
			else  
				{
						 printf( "it's alive.\n"); 
			   }*/
    
    
    	/*					
        if (match(buf,NAME,90))  
        {  
            syslog(LOG_INFO,"jdh success!!!!!!!!!!");  
        }  
        else  
        {  
            syslog(LOG_INFO,"jdh fail!!!!!!!!!!");  
            //���г���  
            system(RUN_NAME);  
        }  */
  

        system("rm /mnt/nand1-1/daemon_file");  
          
        //����  
        sleep(5);  
    }  
  
  show132
    return 0;  
}  
  