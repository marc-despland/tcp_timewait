FROM ubuntu
MAINTAINER Marc Despland <marc.despland@art122-5.net>
RUN apt-get update && apt-get install -y net-tools tcpdump openssh-client vim nginx
COPY nginx.conf /etc/nginx/
CMD /usr/sbin/nginx