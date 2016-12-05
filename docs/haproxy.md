#HaProxy
Install the haproxy load balancer on docker with a configuration script to change the way it close the connection.

If you want a good explaination of all modes, you can have a look to the [haproxy documentation](https://www.haproxy.com/doc/aloha/7.0/haproxy/http_modes.html)

##To build the image
```
docker build -t timewait/haproxy https://github.com/marc-despland/tcp_timewait.git#:/docker/haproxy
```  
##Run it as load balancer with 1 server
Start an haproxy that listen on port **666** and redirect traffic to **server** 
```
docker run -it --rm --name haproxy --link backend:server timewait/haproxy mode
```

Where you replace **mode** with the desire choosen one.

- **kal** : The Keep-alive mode **default**: ```option http-keep-alive```
- **fcl** : The Force Close mode: ```option forceclose```
- **pcl** : Run in Passive Close mode: ```option httpclose```
- **scl** : Run in Server Close mode: ```option http_force_close```

##Run it as load balancer with 2 servers
Start an haproxy that listen on port **666** and redirect traffic to **server1** and **server2**
```
docker run -it --rm --name haproxy --link backend1:server1  --link backend2:server2 timewait/haproxy mode
```

Where you replace **mode** with the desire choosen one.


- **pcl2** : Run in Passive Close mode: ```option httpclose```
- **scl2** : Run in Server Close mode: ```option http_force_close```
