
## test 001 : server: 3 - client:0 Keep connections open
The idea of this scenario is to check that we can't established 2 sockets in destination of 2 differents host from the same source port.
We start two server in two differents containers in two terminals:
./timewait_server -p 667 -s3
./timewait_server -p 668 -s3

And we try to start 2 clients from the same container
./timewait_client -c 667 -f 666 -t 172.17.0.1 -s 0
./timewait_client -c 668 -f 666 -t 172.17.0.2 -s 0

The first one will established
The second will failed, even the destination host and port are different

So this demonstrate we are limited on how much simultaneous connections we can established from a host with the number of available port on an interface.

We can also saw that a Ctrl+C on client where the connection is established generated a FIN, ACK packet and close the socket.


## test 002 : server: 4 - client: 0 Not closing socket properly
so we start server on scenario 4, client on scenario 0
then after 13s, we type Ctrl+C on client and after 25s Ctrl+C on server
On scneario.pcap file we saw that two Ctrl+C generate the apropriate FIN, ACK packet to close the connection.

## test 003 : server: 3 - client: Close initiate by client
The client failed to create second socket : error 98 : Address already in use
The socket is in timewait on client side
tcp        0      0 172.17.0.3:666          172.17.0.1:667          TIME_WAIT   timewait (50.36/0/0)

So we have to wait 60s after the close to be able to reuse the port.
As we can see in the scenario.pcap file the close process is correct, but initiate by the client.

on Ubuntu container: net.ipv4.ip_local_port_range = 32768	60999
so we have only 28231 ports available to open a socket from an IP. If it's the client that initiate the close of the sockets, we have to wait 60s to reuse the port so we are limited to 470 requests per second.

## test 004 : server 5 - client 6 Sending data on socket closed by other end
The idea is to send data on a socket after receiving the close event generate by the close socket on the other end.
On the scenario.pcap we see that the client that initiate the close send a RST packet to force the close of the socket on the server side even we don't call the close on the application side.
![Sequence diagram][5_6/sequence.png]