# Simple client and Server program to test close socket

## How to build

### Directly on your linux host :

'''
git clone https://github.com/marc-despland/tcp_timewait.git
cd tcp_timewait
make
'''

### Using Docker
With docker it will be easy to have a separate server and client. So this way is easier to execute the test.

'''
docker build -t timewait/client --no-cache https://github.com/marc-despland/tcp_timewait.git#:/docker/client
docker build -t timewait/server --no-cache https://github.com/marc-despland/tcp_timewait.git#:/docker/server
'''

## How to run 

### Without docker

* Starting the server :

'''
./timewait_server -p \<port\> -s \<scenario\>
'''

**\<port\>**  is the port to listen.
**\<scenario\>** is the code of the scenario to run.

* Starting the client

'''
./timewaite_client -c \<dstport\> -t \<target\> -f \<fromport\> -s \<scenario\>
'''

**\<dstport\>**  is the port to to connect to on target host
**\<target\>** the host to connect to
**\<fromport\>** the port source on client side
**\<scenario\>** is the code of the scenario to run

### With docker
The docker images are configured to use port **666** as the listen port and port **667* as the source one. 

* Starting the server

'''
docker run -it --name timewait_server --rm timewait/server \<scenario\>
'''

**\<scenario\>** is the code of the scenario to run

* Starting the client

'''
docker run -it --name timewait_client --rm --link timewait_server:server timewait/client \<scenario\>
'''

**\<scenario\>** is the code of the scenario to run

