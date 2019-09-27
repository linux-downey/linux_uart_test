#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include     <termios.h>



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


 
int main (int argc, char *argv[])
{
	int fd;
	int len, i,ret;
        char buf[100] = "hello i.mx8mq evk!i\n";
 
 
	fd = open(DEV_NAME, O_RDWR | O_NOCTTY);
        if(fd < 0) {
                perror(DEV_NAME);
                return -1;
        }
	printf("open file ok ,fd=%d\n",fd); 
 	
	SetSpeed(fd,115200);
	
	while(1){

		len = write(fd, buf, sizeof(buf));
		if (len < 0) {
			printf("write data error \n");
		}
		printf("write file ok,len=%d\n",len);
		sleep(1);	
 
	}
	return(0);
}
