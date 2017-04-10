#The Apache Bench utility
To execute the bench we use the ab utility that allows performing http bench tests.
##To build the image
```
docker build -t timewait/ab https://github.com/marc-despland/tcp_timewait.git#:/docker/ab
```  
##Run a bench
The default command used by this container is to run ```ab -n 120000 -c 100   http://server:666/```  
So to run a bench on a container simply links it to the backend you want to test
```
docker run -it --rm --name bench --link backend:server timewait/ab
```