#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bcm2835.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>

/* define the GPIO PIN */
#define PIN03 RPI_V2_GPIO_P1_03
#define PIN05 RPI_V2_GPIO_P1_05
#define PIN07 RPI_V2_GPIO_P1_07
#define PIN08 RPI_V2_GPIO_P1_08
#define PIN10 RPI_V2_GPIO_P1_10
#define PIN11 RPI_V2_GPIO_P1_11
#define PIN12 RPI_V2_GPIO_P1_12
#define PIN13 RPI_V2_GPIO_P1_13
#define PIN15 RPI_V2_GPIO_P1_15
#define PIN16 RPI_V2_GPIO_P1_16
#define PIN18 RPI_V2_GPIO_P1_18
#define PIN19 RPI_V2_GPIO_P1_19
#define PIN21 RPI_V2_GPIO_P1_21
#define PIN22 RPI_V2_GPIO_P1_22
#define PIN23 RPI_V2_GPIO_P1_23
#define PIN24 RPI_V2_GPIO_P1_24
#define PIN26 RPI_V2_GPIO_P1_26
#define PIN29 RPI_V2_GPIO_P1_29
#define PIN31 RPI_V2_GPIO_P1_31
#define PIN32 RPI_V2_GPIO_P1_32
#define PIN33 RPI_V2_GPIO_P1_33
#define PIN35 RPI_V2_GPIO_P1_35
#define PIN36 RPI_V2_GPIO_P1_36
#define PIN37 RPI_V2_GPIO_P1_37
#define PIN38 RPI_V2_GPIO_P1_38
#define PIN40 RPI_V2_GPIO_P1_40

/* for server */
#define SERVER_PORT 8000
#define LENGTH_OF_LISTEN_QUEUE 2
#define BUFFER_SIZE 1024

void setGPIOPin(int pin, int state)
{
	if(bcm2835_init())
	{
   // set pin in/out
	if(pin == 3)
		bcm2835_gpio_fsel(PIN03,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 5)
		bcm2835_gpio_fsel(PIN05,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 7)
		bcm2835_gpio_fsel(PIN07,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 8)
		bcm2835_gpio_fsel(PIN08,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 10)
		bcm2835_gpio_fsel(PIN10,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 11)
		bcm2835_gpio_fsel(PIN11,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 12)
		bcm2835_gpio_fsel(PIN12,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 13)
		bcm2835_gpio_fsel(PIN13,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 15)
		bcm2835_gpio_fsel(PIN15,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 16)
		bcm2835_gpio_fsel(PIN16,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 18)
		bcm2835_gpio_fsel(PIN18,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 19)
		bcm2835_gpio_fsel(PIN19,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 21)
		bcm2835_gpio_fsel(PIN21,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 22)
		bcm2835_gpio_fsel(PIN22,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 23)
		bcm2835_gpio_fsel(PIN23,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 24)
		bcm2835_gpio_fsel(PIN24,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 26)
		bcm2835_gpio_fsel(PIN26,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 29)
		bcm2835_gpio_fsel(PIN29,BCM2835_GPIO_FSEL_OUTP);	
	else if(pin == 31)
		bcm2835_gpio_fsel(PIN31,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 32)
		bcm2835_gpio_fsel(PIN32,BCM2835_GPIO_FSEL_OUTP);	
	else if(pin == 33)
		bcm2835_gpio_fsel(PIN33,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 35)
		bcm2835_gpio_fsel(PIN35,BCM2835_GPIO_FSEL_OUTP);	
	else if(pin == 36)
		bcm2835_gpio_fsel(PIN36,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 37)
		bcm2835_gpio_fsel(PIN37,BCM2835_GPIO_FSEL_OUTP);	
	else if(pin == 38)
		bcm2835_gpio_fsel(PIN38,BCM2835_GPIO_FSEL_OUTP);
	else if(pin == 40)
		bcm2835_gpio_fsel(PIN40,BCM2835_GPIO_FSEL_OUTP);	
   // set state
	if(state)
	{
	/* choose the PIN */
	if(pin == 3)
		bcm2835_gpio_write(PIN03,HIGH);
	else if(pin == 5)
		bcm2835_gpio_write(PIN05,HIGH);
	else if(pin == 7)
		bcm2835_gpio_write(PIN07,HIGH);
	else if(pin == 8)
		bcm2835_gpio_write(PIN08,HIGH);
	else if(pin == 10)
		bcm2835_gpio_write(PIN10,HIGH);
	else if(pin == 11)
		bcm2835_gpio_write(PIN11,HIGH);
	else if(pin == 12)
		bcm2835_gpio_write(PIN12,HIGH);
	else if(pin == 13)
		bcm2835_gpio_write(PIN13,HIGH);
	else if(pin == 15)
		bcm2835_gpio_write(PIN15,HIGH);
	else if(pin == 16)
		bcm2835_gpio_write(PIN16,HIGH);
	else if(pin == 18)
		bcm2835_gpio_write(PIN18,HIGH);
	else if(pin == 19)
		bcm2835_gpio_write(PIN19,HIGH);
	else if(pin == 21)
		bcm2835_gpio_write(PIN21,HIGH);
	else if(pin == 22)
		bcm2835_gpio_write(PIN22,HIGH);
	else if(pin == 23)
		bcm2835_gpio_write(PIN23,HIGH);
	else if(pin == 24)
		bcm2835_gpio_write(PIN24,HIGH);
	else if(pin == 26)
		bcm2835_gpio_write(PIN26,HIGH);
	else if(pin == 29)
		bcm2835_gpio_write(PIN29,HIGH);	
	else if(pin == 31)
		bcm2835_gpio_write(PIN31,HIGH);
	else if(pin == 32)
		bcm2835_gpio_write(PIN32,HIGH);	
	else if(pin == 33)
		bcm2835_gpio_write(PIN33,HIGH);
	else if(pin == 35)
		bcm2835_gpio_write(PIN35,HIGH);	
	else if(pin == 36)
		bcm2835_gpio_write(PIN36,HIGH);
	else if(pin == 37)
		bcm2835_gpio_write(PIN37,HIGH);	
	else if(pin == 38)
		bcm2835_gpio_write(PIN38,HIGH);
	else if(pin == 40)
		bcm2835_gpio_write(PIN40,HIGH);	
	}
	else
	{
	if(pin == 3)
		bcm2835_gpio_write(PIN03,LOW);
	else if(pin == 5)
		bcm2835_gpio_write(PIN05,LOW);
	else if(pin == 7)
		bcm2835_gpio_write(PIN07,LOW);
	else if(pin == 8)
		bcm2835_gpio_write(PIN08,LOW);
	else if(pin == 10)
		bcm2835_gpio_write(PIN10,LOW);
	else if(pin == 11)
		bcm2835_gpio_write(PIN11,LOW);
	else if(pin == 12)
		bcm2835_gpio_write(PIN12,LOW);
	else if(pin == 13)
		bcm2835_gpio_write(PIN13,LOW);
	else if(pin == 15)
		bcm2835_gpio_write(PIN15,LOW);
	else if(pin == 16)
		bcm2835_gpio_write(PIN16,LOW);
	else if(pin == 18)
		bcm2835_gpio_write(PIN18,LOW);
	else if(pin == 19)
		bcm2835_gpio_write(PIN19,LOW);
	else if(pin == 21)
		bcm2835_gpio_write(PIN21,LOW);
	else if(pin == 22)
		bcm2835_gpio_write(PIN22,LOW);
	else if(pin == 23)
		bcm2835_gpio_write(PIN23,LOW);
	else if(pin == 24)
		bcm2835_gpio_write(PIN24,LOW);
	else if(pin == 26)
		bcm2835_gpio_write(PIN26,LOW);
	else if(pin == 29)
		bcm2835_gpio_write(PIN29,LOW);	
	else if(pin == 31)
		bcm2835_gpio_write(PIN31,LOW);
	else if(pin == 32)
		bcm2835_gpio_write(PIN32,LOW);	
	else if(pin == 33)
		bcm2835_gpio_write(PIN33,LOW);
	else if(pin == 35)
		bcm2835_gpio_write(PIN35,LOW);	
	else if(pin == 36)
		bcm2835_gpio_write(PIN36,LOW);
	else if(pin == 37)
		bcm2835_gpio_write(PIN37,LOW);	
	else if(pin == 38)
		bcm2835_gpio_write(PIN38,LOW);
	else if(pin == 40)
		bcm2835_gpio_write(PIN40,LOW);		
	}
	printf("set GPIO %d to %d\n",pin,state);
	bcm2835_close();
	}
}
int readGPIOPin(int pin)
{	int state = -1;
	if(bcm2835_init())
	{
	if(pin == 3)
		state = bcm2835_gpio_lev(PIN03);
	else if(pin == 5)
		state = bcm2835_gpio_lev(PIN05);
	else if(pin == 7)
		state = bcm2835_gpio_lev(PIN07);
	else if(pin == 8)
		state = bcm2835_gpio_lev(PIN08);
	else if(pin == 10)
		state = bcm2835_gpio_lev(PIN10);
	else if(pin == 11)
		state = bcm2835_gpio_lev(PIN11);
	else if(pin == 12)
		state = bcm2835_gpio_lev(PIN12);
	else if(pin == 13)
		state = bcm2835_gpio_lev(PIN13);
	else if(pin == 15)
		state = bcm2835_gpio_lev(PIN15);
	else if(pin == 16)
		state = bcm2835_gpio_lev(PIN16);
	else if(pin == 18)
		state = bcm2835_gpio_lev(PIN18);
	else if(pin == 19)
		state = bcm2835_gpio_lev(PIN19);
	else if(pin == 21)
		state = bcm2835_gpio_lev(PIN21);
	else if(pin == 22)
		state = bcm2835_gpio_lev(PIN22);
	else if(pin == 23)
		state = bcm2835_gpio_lev(PIN23);
	else if(pin == 24)
		state = bcm2835_gpio_lev(PIN24);
	else if(pin == 26)
		state = bcm2835_gpio_lev(PIN26);
	else if(pin == 29)
		state = bcm2835_gpio_lev(PIN29);	
	else if(pin == 31)
		state = bcm2835_gpio_lev(PIN31);
	else if(pin == 32)
		state = bcm2835_gpio_lev(PIN32);	
	else if(pin == 33)
		state = bcm2835_gpio_lev(PIN33);
	else if(pin == 35)
		state = bcm2835_gpio_lev(PIN35);	
	else if(pin == 36)
		state = bcm2835_gpio_lev(PIN36);
	else if(pin == 37)
		state = bcm2835_gpio_lev(PIN37);	
	else if(pin == 38)
		state = bcm2835_gpio_lev(PIN38);
	else if(pin == 40)
		state = bcm2835_gpio_lev(PIN40);	

	bcm2835_close();
	return state;
	
	}else
		return 0;
}
char* choose_motion(char *input) {
	char const* pin;
	char const* state;
	char const* data;
	char const* comma = ",";
	int dy_pin;
	int temp;
	static char result[100];
	state = strtok(input, "?");

	if (strcmp("setGPIO", state) == 0)
	{
		if (pin = strtok(NULL, comma)) 
		{
			// 確認是否有輸入Pin
			dy_pin = atoi(pin);
			// 確認是否有輸入Data
			if (data = strtok(NULL, comma)) 
			{
				printf("pin:%d,state:%s\n",dy_pin,data);
				if (strcmp("on", data) == 0)
					setGPIOPin(dy_pin, 1);
				else if(strcmp("off", data) == 0)
					setGPIOPin(dy_pin, 0);
			}	
		}

		return "-1";
	}
	else if (strcmp("readGPIO", state) == 0)
	{	
		//確認是否有Pin輸入
		if (pin = strtok(NULL, comma)) {
			dy_pin = atoi(pin);
			temp = readGPIOPin(dy_pin);
       	if(temp == 1)
				sprintf(result, "true");
       	else
          	sprintf(result, "false");
			return result;
		}
		return "-1";
	}
	else
		return "-1";

}


int main(int argc, char **argv)
{
	 struct sockaddr_in server_addr, client_addr;
    int server_socket,client_socket;
    socklen_t client_len;
    char buf[BUFFER_SIZE] = "";
    char *response_type =
"HTTP/1.1 200 OK\r\n"
"Server: Apache/2.47 (Ubuntu)\r\n"
"Content-type: application/octet-stream\r\n"
"Content-Length: %d\r\n"
"Access-Control-Allow-Origin: *\r\n"
"\r\n";
    char response[BUFFER_SIZE];


    //bzero(&server_addr,sizeof(server_addr));


    /* create a socket */
    server_socket = socket(AF_INET,SOCK_STREAM,0);
    if( server_socket < 0)
    {
        printf("Create Socket Failed!");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(SERVER_PORT);

    printf("creat socket done\n");

    /* bind socket to a specified address*/
    //setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));  //設置為可重複使用
    if( bind(server_socket,(struct sockaddr*)&server_addr,sizeof(server_addr))==-1)  //把地址綁定
    {
        printf("Server Bind Port : %d Failed!", SERVER_PORT);
        exit(1);
    }
    printf("bind done\n");
	 // If you call this, it will not actually access the GPIO
    // Use for testing
	if (!bcm2835_init())
   return 1;

    /* listen a socket */
    if(listen(server_socket, LENGTH_OF_LISTEN_QUEUE)==-1)
    {
        printf("Server Listen Failed!");
        exit(1);
    }
    printf("start to listen\n");

    char *command;
    char *temp_buf;

    /* run server */
  while (1)
    {
        client_len = sizeof(client_addr);
        /* accept socket from client */
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
   if( client_socket < 0)
        {
            printf("Server Accept Failed!\n");
            break;
        }
   if(recv(client_socket, buf, 1024, 0) >0)
	{
		//find special string
		command = strtok(buf,"/");
		printf("received:%s\n",command);
		if(command != NULL)
		{
			command = strtok(NULL," ");
			printf("received:%s\n",command);
			temp_buf = choose_motion(command);

			printf("temp%s\n",temp_buf);
			
			if (strcmp(temp_buf,"-1") != 0)
			{
					strcpy(buf,temp_buf); //initial buf;
					//printf("buf:%s",buf);
					/* send data to client*/
					sprintf(response, response_type, strlen(buf));
					strcat(response,buf);
					send(client_socket, response, (int)strlen(response),0);
		 	}else
			{
				strcpy(buf,"succeed write data");
				sprintf(response,response_type, strlen(buf));
				strcat(response,buf);
				send(client_socket, response, (int)strlen(response),0);
			}

		}
	}

	printf("succeed\n");
	fflush(stdout);
  	close(client_socket);
    }

    close(server_socket);
    return 0;
	
}