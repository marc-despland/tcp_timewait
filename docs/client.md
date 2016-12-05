#The client
The client implements several tests cases that could be used with the server one to generate several tests scenarios. The client tries to establish connection to a server on port 666 from port 667
##To build the client:
```
docker build -t timewait/client https://github.com/marc-despland/tcp_timewait.git#:/docker/client
```
##To run it
To run a test (the scripts execute a git pull then a make)  

```
docker run -it --rm --name client --link backend:server timewait/client num
```

Replacing num with the code of the test case to use. By default, the client tries to connect to a container name server on port 666. Here we tell it to use the container backend as the server.  
The tests cases are some special configuration of the default value of the client configuration:  


- **readwait**=0 : Wait x second before reading after EPOLLIN event, default no wait
- **nbrequest**=2 : Number of try (request) to make. Default we execute one request then try to make a new one
- **close_after_read**=false : Indicate  to close after the first read of data, default don't close.
- **use\_shutdown**=false : Use shutdown instead of close on EPOLLRDHUP, default use close
- **not\_closing\_on\_close\_detected**=false : Don't close the connection on EPOLLRDHUP, default close it
- **close\_after\_connect**=false : Close the connection after connect, default don't
- **is\_an\_http\_client**=false : Simulate an HTTP client, default don't
- **http\_keepalive**=false : Simulate an HTTP client with KeepAlive, default don't
- **http\_close\_after\_response**=false Simulate an HTTP client that close after response, default don't  

So the tests cases code:  
**0**  - default mode  
**1**  - Delay the read for 10 seconds  
**2**  - Delay the read for 10 seconds and use shutdown instead of close on EPOLLRDHUP  
**3** - Same as 2 ???  
**4** - Same as 2 but close the connection after last read  
**5** - Delay the read for 10 seconds and wait the last read to close the connection  
**6** - Close after connect  
**7** - Same as 5 without waiting 10 seconds  
**8** - Execute 1 request as HTTP Client  
**9** - Execute 1 request as HTTP Client and close after reading response  
**10** - Execute 1 request as HTTP Client that use keep-alive.  

