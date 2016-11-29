FROM ubuntu
MAINTAINER Marc Despland <marc.despland@art122-5.net>
RUN apt-get update && apt-get install -y net-tools tcpdump openssh-client vim haproxy
COPY haproxy.cfg /etc/haproxy/
CMD /usr/sbin/haproxy -f /etc/haproxy/haproxy.cfg -db