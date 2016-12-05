

## test 008 : default haproxy with Server 6 and Client 8
For this test the client and the server doesn't initiate the close of the socket, but close it if haproxy initiate it
The request is sent with the HTTP header "Connection: Close"

The network capture show us that the default behavior on HTTP request with Connection close is to send a RST as a client to reset the connection without TIMEWAIT, and to close it propeperly on its server side
the FIN, ACK packet is sent with the HTPP response.

To run the test, start in 4 terminals  
```
docker run -it --rm --name backend timewait/server 6
docker run -it --rm --link backend:server --name haproxy timewait/haproxy
docker exec -it haproxy tcpdump -s0 -w scenario_haproxy_default_6_8.pcap port 666
docker run -it --rm --link haproxy:server timewait/client 8
```

## test 009 : default haproxy with Server 8 and Client 10
The request is sent with the HTTP header "Connection: Keep-Alive"
After few second, we quit the server that initiate the close of the socket on client side of haproxy
The connection between client and haproxy stay open

## test 010 : httpclose haproxy with Server 8 and Client 10
The request is sent with the HTTP header "Connection: Keep-Alive"
Haproxy replace this header with "Connection: close"
But as the backend is not a real HTTP server ... it don't care and replys with Connection: keep-alive"
And Haproxy send the answer to the client with "Connection: close".  
Both of the socket are keep open.  

When we quit the server, it send a close (FIN, ACK) to haproxy that close the socket and initiate the close with the client

## test 011 : httpclose haproxy with Server 6 and Client 10
Same as test 010 but this time server answer with a proper Connection: close

Same behavior


## test 012 : http-server-close haproxy with Server 8 and Client 10
Haproxy force connection close with backend with a RST packet, and keep client open

## test 013 : closeclose haproxy with Server 8 and Client 10
Haproxy force connection close with backend with a RST packet, and close client side


HAproxy doc https://www.haproxy.com/doc/aloha/7.0/haproxy/http_modes.html

## test 014 : nginx with Server 8 and Client 10
By default nginx transform the request to an HTTP/1.0 request and close the connection when it received the response even if the server haven't close the connection on its side

So the socket is stuck in TIMEWAIT on nginx server and you can't have more than 450r/s


## Bench

### Direct bench with server 9 

```
Server Software:        fast
Server Hostname:        server
Server Port:            666

Document Path:          /
Document Length:        13 bytes

Concurrency Level:      100
Time taken for tests:   48.101 seconds
Complete requests:      120000
Failed requests:        0
Total transferred:      18480000 bytes
HTML transferred:       1560000 bytes
Requests per second:    2494.74 [#/sec] (mean)
Time per request:       40.084 [ms] (mean)
Time per request:       0.401 [ms] (mean, across all concurrent requests)
Transfer rate:          375.19 [Kbytes/sec] received

```

### HaProxy PCL bench (http_close) with server 9 

```
Server Software:        fast
Server Hostname:        server
Server Port:            666

Document Path:          /
Document Length:        13 bytes

Concurrency Level:      100
Time taken for tests:   47.770 seconds
Complete requests:      120000
Failed requests:        0
Total transferred:      18480000 bytes
HTML transferred:       1560000 bytes
Requests per second:    2512.03 [#/sec] (mean)
Time per request:       39.808 [ms] (mean)
Time per request:       0.398 [ms] (mean, across all concurrent requests)
Transfer rate:          377.79 [Kbytes/sec] received
```


### Nginx bench with server 9 :

```
Server Software:        nginx/1.10.0
Server Hostname:        server
Server Port:            666

Document Path:          /
Document Length:        13 bytes

Concurrency Level:      100
Time taken for tests:   209.633 seconds
Complete requests:      120000
Failed requests:        14867
   (Connect: 0, Receive: 0, Length: 14867, Exceptions: 0)
Non-2xx responses:      14867
Total transferred:      23077124 bytes
HTML transferred:       4072523 bytes
Requests per second:    572.43 [#/sec] (mean)
Time per request:       174.694 [ms] (mean)
Time per request:       1.747 [ms] (mean, across all concurrent requests)
Transfer rate:          107.50 [Kbytes/sec] received

```

```
[crit] 7#7: *239994 connect() to 172.17.0.190:666 failed (99: Cannot assign requested address) while connecting to upstream, client: 172.17.0.192, server: , request: "GET / HTTP/1.0", upstream: "http://172.17.0.190:666/", host: "server:666"
```

### HaProxy pcl with 2 server 9

```
Server Software:        fast
Server Hostname:        server
Server Port:            666

Document Path:          /
Document Length:        13 bytes

Concurrency Level:      100
Time taken for tests:   23.651 seconds
Complete requests:      120000
Failed requests:        0
Total transferred:      18480000 bytes
HTML transferred:       1560000 bytes
Requests per second:    5073.77 [#/sec] (mean)
Time per request:       19.709 [ms] (mean)
Time per request:       0.197 [ms] (mean, across all concurrent requests)
Transfer rate:          763.05 [Kbytes/sec] received
```

### HaProxy scl with 2 server 9

```
Server Software:        fast
Server Hostname:        server
Server Port:            666

Document Path:          /
Document Length:        13 bytes

Concurrency Level:      100
Time taken for tests:   22.796 seconds
Complete requests:      120000
Failed requests:        0
Total transferred:      18480000 bytes
HTML transferred:       1560000 bytes
Requests per second:    5264.14 [#/sec] (mean)
Time per request:       18.996 [ms] (mean)
Time per request:       0.190 [ms] (mean, across all concurrent requests)
Transfer rate:          791.68 [Kbytes/sec] received

```


### Nginx with 2 server 9

```
tcp        0      0 172.17.0.222:35068      172.17.0.202:666        TIME_WAIT   timewait (52.48/0/0)
tcp        0      0 172.17.0.222:35068      172.17.0.210:666        TIME_WAIT   timewait (52.71/0/0)
```

```
Server Software:        nginx/1.10.0
Server Hostname:        server
Server Port:            666

Document Path:          /
Document Length:        13 bytes

Concurrency Level:      100
Time taken for tests:   61.779 seconds
Complete requests:      120000
Failed requests:        0
Total transferred:      20520000 bytes
HTML transferred:       1560000 bytes
Requests per second:    1942.42 [#/sec] (mean)
Time per request:       51.482 [ms] (mean)
Time per request:       0.515 [ms] (mean, across all concurrent requests)
Transfer rate:          324.37 [Kbytes/sec] received
```


### Nginx with 2 server 7

```
Server Software:        nginx/1.10.0
Server Hostname:        server
Server Port:            666

Document Path:          /
Document Length:        13 bytes

Concurrency Level:      100
Time taken for tests:   21.898 seconds
Complete requests:      120000
Failed requests:        0
Total transferred:      20520000 bytes
HTML transferred:       1560000 bytes
Requests per second:    5479.94 [#/sec] (mean)
Time per request:       18.248 [ms] (mean)
Time per request:       0.182 [ms] (mean, across all concurrent requests)
Transfer rate:          915.11 [Kbytes/sec] received
```


 ## Nginx with 2 server 8

Server Software:        nginx/1.10.0
Server Hostname:        server
Server Port:            666

Document Path:          /
Document Length:        13 bytes

Concurrency Level:      100
Time taken for tests:   77.090 seconds
Complete requests:      120000
Failed requests:        7269
   (Connect: 0, Receive: 0, Length: 7269, Exceptions: 0)
Non-2xx responses:      7269
Total transferred:      21770268 bytes
HTML transferred:       2788461 bytes
Requests per second:    1556.62 [#/sec] (mean)
Time per request:       64.242 [ms] (mean)
Time per request:       0.642 [ms] (mean, across all concurrent requests)
Transfer rate:          275.78 [Kbytes/sec] received


Reason : we have a capbility to open 28231 * 2 before having no more available ports. This part should had take arround 10s (5500r/s)
After that we will have to wait the end of the TIMEWAIT (60s) so arround 50S without request
We have 7269 failed request, so at after 60s we still have to send  56269 



## Haproxy SCL with 2 server 8

Server Software:        fast
Server Hostname:        server
Server Port:            666

Document Path:          /
Document Length:        13 bytes

Concurrency Level:      100
Time taken for tests:   14.196 seconds
Complete requests:      120000
Failed requests:        0
Total transferred:      18480000 bytes
HTML transferred:       1560000 bytes
Requests per second:    8453.24 [#/sec] (mean)
Time per request:       11.830 [ms] (mean)
Time per request:       0.118 [ms] (mean, across all concurrent requests)
Transfer rate:          1271.29 [Kbytes/sec] received
