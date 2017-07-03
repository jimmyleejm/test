//作者：jdh  
//时间：2012-2-27  
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
  
    //让init进程成为新产生进程的父进程  
    pid = fork();  
    //如果创建进程失败  
    if (pid < 0)  
    {  
        perror("fork");  
        return -1;  
    }  
    //父进程退出运行  
    if (pid != 0)  
    {  
        exit(0);  
    }  
    //创建新的会话  
    pid = setsid();  
    if (pid < -1)  
    {  
        perror("set sid");  
        return -1;  
    }  
    //更改当前工作目录,将工作目录修改成根目录  
    if (!nochdir)  
    {  
        chdir("/");  
    }  
    //关闭文件描述符，并重定向标准输入，输出合错误输出  
    //将标准输入输出重定向到空设备  
    
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
    //设置守护进程的文件权限创建掩码  
    umask(0027);  
  
    return 0;  
}  
 */ 

int main(int argc,char *argv[])  
{  

    char buf[100];  
  	FILE*fp_check ;
    //开启守护进程  
  //  daemon1(0,0); 
    int pid; 
  
    while (1)  
    {  
        //打开日志  
      //  openlog(argv[0],LOG_CONS|LOG_PID,LOG_USER);  
          
        //查看程序是否运行  
        //新建输出文件  
        system("touch /mnt/nand1-1/daemon_file");  
        //获得程序ID  
        system("pgrep mtest2 >> /mnt/nand1-1/daemon_file");  
        //打开输出文件  
        fp_check=fopen("/mnt/nand1-1/daemon_file","r");
        //清空缓存  
        memset(buf,0,100);  
        //读取全部  
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
            //运行程序  
            system(RUN_NAME);  
        }  */
  

        system("rm /mnt/nand1-1/daemon_file");  
          
        //休眠  
        sleep(5);  
    }  
  
  show132
    return 0;  
}  
  