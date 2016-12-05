#The server

The server implements several tests cases that could be used with the client one to generate several tests scenarios. By default the server listen on port 666.
##To build the server
```
docker build -t timewait/server https://github.com/marc-despland/tcp_timewait.git#:/docker/server
```
##To run it
To run a test (the scripts execute a git pull then a make)

```
docker run -it --rm --name backend timewait/server num
```

Replacing num with the code of the test case to use.
The tests cases are some special configuration of the default value of the server configuration:  


- **send\_bip**=false : Send a Bip to the client when it connects, default don't
- **direct\_close**=false : Close the connection just after the client connect, default don't
- **closewait**=0 Wait before sending the close, default don't
- **not\_closing\_on\_close\_detected**=false : Don't close the connection on EPOLLRDHUP, default close it
- **send\_bip\_on\_close**=false : Send a bip after receiving a close event, default don't
- **is\_an\_http\_server**=false : Act as an HTTP server,  default don't
- **http\_keepalive**=false : Act as an HTTP server that accept keepalive,  default don't
- **http\_close\_after_response**=false : Act as an http server and close after sending the response
- **short\_close_wait**=0 wait x microsecond before closing the connection

So the tests cases code:  

**0** -  Direct close after connect  
**1** -  Send bip then close  
**2** -  Send bip then close after 5s  
**3** -  Default : don't send bip and don't close, but close on close event  
**4** -  Default : don't send bip and never  close  
**5** -  Send bip on close event but don't close  
**6** -  Act as an HTTP Server, don't close after response but on close event  
**7** -  Act as an HTTP Server, close after response and on close event  
**8** -  Act as an HTTP Server, with keep alive and not closing after response sent.  
**9** -  Act as an HTTP server, wait 0,2 ms before closing, close on close event  
