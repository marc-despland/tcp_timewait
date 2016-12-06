#How to close a socket ?
It could looks obvious, but I always found some situation where I don't remember how to handle the TIMEWAIT, so I decide to write a series of test to check that and I put it here to share with everyone who is interested.  
My tests programs are written in C++, to allow the use of API "closed" to the kernel. I use them with docker to have real client/server configurations on my host easier to manage than Virtual Machine.  

The computer I use to host the tests run under centos, without tcp\_reuse or tcp\_recycle configured (both at 0), and it's a bi-processor quad-core with 64Go of RAM and lot of disk (not really used here)

##The different part of the tests

1. [A quick description of TCP/IP and the close process](docs/tcpip.md)
2. [Simples tests to examin the impacts of the chosen process](scenarii/simple_tests.md)
3. [A bench test to check the impacts on performance](scenarii/bench_tests.md)
4. [Conclusion of the tests](docs/conclusions.md)

##The Docker images

The images used for simple tests:

-	[timewait/client](docs/client.md)
-	[timewait/server](docs/server.md)

If you want to run the benchs tests, you will also need those one:

-	[timewait/haproxy](docs/haproxy.md)
-	[timewait/ab](docs/ab.md)
-	[timewait/nginx](docs/nginx.md)
-	[timewait/apache](docs/apache.md)


##How to run tools


###Tcpdump
I have install tcpdump, netstat and scp on all container. So to run for example a tcpdump on a running container named "server" capturing everything on port 666:

```
docker exec -it server tcpdump -s0 -w /tmp/server.pcap port 666
```

To copy it on your host that have the IP 172.17.42.1 on its docker0 interfaces  and a user me:  

```
docker exec -it server scp /tmp/server.pcap me@172.17.42.1:/tmp.server.pcap
```

Or you could just mount a shared volume for this purpose betwwen your host and the containers.
###Netstat 
To run a netstat on a container named server:  

```
docker exec -it server netstat -ano
```

To check how much you have socket stuck in TIMEWAIT

```
docker exec -it server netstat -ano |grep TIMEWAIT | wc -l
```

