#Apache

Provide an Apache server that listen on port 666 and able to proxify traffic to one backend.
##To build the image
```
docker build -t timewait/apache https://github.com/marc-despland/tcp_timewait.git#:/docker/apache
``` 
 
##Start Apache connected to 1 backend
Backend is the container we want to connect to.

```
docker run -it --rm --name apache --link backend:server timewait/apache
```