#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <pthread.h>

#define DEV_NAME  "/dev/ttymxc3"

int speed_arr[] = { B38400, B19200, B9600, B4800, B2400, B1200, B300, B38400, B19200, B9600, B4800, B2400, B1200, B300, };
int name_arr[] = {38400, 19200, 9600, 4800, 2400, 1200, 300, 38400, 19200, 9600, 4800, 2400, 1200, 300, };

void SetSpeed(int fd, int speed)
{
    int i;
    struct termios Opt;    //定义termios结构

    if(tcgetattr(fd, &Opt) != 0)
    {
        perror("tcgetattr fd");
        return;
    }
    for(i = 0; i < sizeof(speed_arr) / sizeof(int); i++)
    {
        if(speed == name_arr[i])
        {
            tcflush(fd, TCIOFLUSH);
            cfsetispeed(&Opt, speed_arr[i]);
            cfsetospeed(&Opt, speed_arr[i]);
            if(tcsetattr(fd, TCSANOW, &Opt) != 0)
            {
                perror("tcsetattr fd");
                return;
            }
            tcflush(fd, TCIOFLUSH);
        }
    }
}


void *uart_send_data(void *arg)
{
	int fd = *(int *)arg;
	char buf[] = "hello world\n";
	int ret = 0;
	while(1)
	{
		ret = write(fd,buf,12);
		if(ret<0)
			printf("write failed\n");
		else
			printf("write ok\n");
		sleep(3);
	}
	return NULL;
}

void *uart_get_data(void *arg)
{
	int fd = *(int*)arg;
	ssize_t cnt = 0;
	fd_set rfds;
	struct timeval time;
	unsigned char rbuf[100]={0};
	int ret = 0;

	while(1)
	{
		FD_ZERO(&rfds);
		FD_SET(fd,&rfds);

		time.tv_sec = 15;
		time.tv_usec = 0;
		ret = select(fd+1,&rfds,NULL,NULL,&time);
		switch(ret)
		{
			case -1:
				printf("error -1\n");
				break;
			case 0:
				printf("time over\n");
				break;
			default:
				cnt = read(fd,rbuf,12);
				if(cnt < 0)
					printf("read failed!\n");
				else
					printf("read data = %s\n",rbuf);
				break;
		}
	}
	return NULL;
}
 
int main (int argc, char *argv[])
{
	int fd;
	int len, i,ret;
        char buf[100] = "hello i.mx8mq evk!i\n";
 	pthread_t t1 = 0,t2 = 0;
 
	fd = open(DEV_NAME, O_RDWR | O_NOCTTY | O_NDELAY);
        if(fd < 0) {
                perror(DEV_NAME);
                return -1;
        }
	printf("open file ok ,fd=%d\n",fd); 
	
	usleep(200000);	
	tcflush(fd,TCIOFLUSH);

	//SetSpeed(fd,115200);

	pthread_create(&t1,NULL,uart_get_data,&fd);
	pthread_create(&t2,NULL,uart_send_data,&fd);
	

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return(0);
}
