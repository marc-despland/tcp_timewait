FROM ubuntu
MAINTAINER Marc Despland <marc.despland@art122-5.net>
ARG http_proxy
ARG https_proxy
RUN apt-get update && apt-get install -y apache2-utils net-tools tcpdump openssh-client
CMD ab -n 120000 -c 100   http://server:666/