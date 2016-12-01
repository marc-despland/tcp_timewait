FROM ubuntu
MAINTAINER Marc Despland <marc.despland@art122-5.net>
ARG http_proxy
ARG https_proxy
RUN apt-get update && apt-get install -y net-tools tcpdump openssh-client vim nginx
COPY start.sh /
RUN chmod a+rx /start.sh
COPY config /config/
ENTRYPOINT ["/start.sh"]
CMD []