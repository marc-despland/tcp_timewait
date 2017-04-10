#Nginx

Provide an Nginx server that listen on port 666 and able to proxify traffic to one or two servers 
##To build the image
```
docker build -t timewait/nginx https://github.com/marc-despland/tcp_timewait.git#:/docker/nginx
``` 
 
##Start Nginx connected to 1 backend
Backend is the container we want to connect to.

```
docker run -it --rm --name nginx --link backend:server timewait/nginx 1
```

##Start Nginx connected to 2 backends
Backend1 and backend2 are the containers we want to connect to.

```
docker run -it --rm --name nginx --link backend1:server1 --link backend2:server2 timewait/nginx 2
```